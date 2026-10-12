#define BLYNK_TEMPLATE_ID "TMPL6DYSAszvR"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

char auth[] = "000000000000000";
char ssid[] = "00";
char pass[] = "11223344";

#define DHTPIN 4
#define DHTTYPE DHT22
#define PIN_GAS    34
#define LED_G      25
#define LED_Y      26
#define LED_R      33
#define BUZZER     27
#define MUTE_BTN   14

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// ----------- Variables -----------
bool alertSent = false;
bool gasBaseReady = false;
int gasBase = 0;

bool muted = false;
bool lastBtnState = HIGH;

unsigned long bootMs = 0;
unsigned long lastSend = 0;

// ----------- Thresholds -----------
const int GAS_WARN_DELTA   = 167;
const int GAS_DANGER_DELTA = 253;
const float TEMP_WARN_C    = 50.0;
const float TEMP_DANGER_C  = 60.0;

// ----------- System State -----------
enum State { ST_NORMAL, ST_WARN, ST_DANGER };
State state = ST_NORMAL;

// ----------- Blynk Button (Mute Control) -----------
BLYNK_WRITE(V1) {
  muted = param.asInt(); // 1 = Mute ON
}

// ----------- Functions -----------
void setLeds(State s) {
  digitalWrite(LED_G, s == ST_NORMAL);
  digitalWrite(LED_Y, s == ST_WARN);
  digitalWrite(LED_R, s == ST_DANGER);
}

void alarmOn() { 
  if (!muted) tone(BUZZER, 2000); // Activate buzzer if not muted
  else noTone(BUZZER);            // Stop buzzer if muted
}

void alarmOff() { 
  noTone(BUZZER); // Ensure buzzer is OFF
}

void setup() {
  Serial.begin(115200);
  bootMs = millis();

  pinMode(LED_G, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(MUTE_BTN, INPUT_PULLUP);

  setLeds(ST_NORMAL);
  alarmOff();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  dht.begin();

  // Connect to WiFi without blocking forever
  WiFi.begin(ssid, pass);
  int timeout = 0;
  while (WiFi.status() != WL_CONNECTED && timeout < 20) {
    delay(500);
    Serial.print(".");
    timeout++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi Connected");
    Blynk.config(auth);
    Blynk.connect();
  } else {
    Serial.println("WiFi Failed");
  }
}

void loop() {

  // Run Blynk only if WiFi is connected
  if (WiFi.status() == WL_CONNECTED) {
    Blynk.run();
  }

  // Read sensors
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int gasRaw = analogRead(PIN_GAS);

  // MQ-2 warm-up period (ignore readings during this time)
  if (millis() - bootMs < 20000) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("MQ2 WARMING UP...");
    display.display();
    return;
  }

  // Set baseline (clean air reference)
  if (!gasBaseReady) {
    gasBase = gasRaw;
    gasBaseReady = true;
  }

  // Calculate gas difference from baseline
  int gasDelta = gasRaw - gasBase;
  if (gasDelta < 0) gasDelta = 0;

  // Determine system state
  if (gasDelta >= GAS_DANGER_DELTA || t >= TEMP_DANGER_C) state = ST_DANGER;
  else if (gasDelta >= GAS_WARN_DELTA || t >= TEMP_WARN_C) state = ST_WARN;
  else state = ST_NORMAL;

  // Send notification once when entering danger state
  if (state == ST_DANGER && !alertSent) {
    Blynk.logEvent("gas_alert");
    alertSent = true;
  }
  if (state != ST_DANGER) alertSent = false;

  // Physical mute button handling (edge detection)
  bool currentBtn = digitalRead(MUTE_BTN);
  if (lastBtnState == HIGH && currentBtn == LOW && state == ST_DANGER) {
    muted = !muted; // Toggle mute
  }
  lastBtnState = currentBtn;

  // Control outputs
  setLeds(state);
  if (state == ST_DANGER) alarmOn();
  else alarmOff();

  // OLED display
  display.clearDisplay();
  display.setCursor(0, 0);

  display.print("Temp: "); 
  if(isnan(t)) display.println("Err"); else {display.print(t, 1); display.println(" C");}
  
  display.print("Hum:  "); 
  if(isnan(h)) display.println("Err"); else {display.print(h, 1); display.println(" %");}
  
  display.print("Gas:  "); display.println(gasDelta);

  display.print("Stat: "); 
  if(state == ST_NORMAL) display.println("NORMAL");
  else if(state == ST_WARN) display.println("WARNING");
  else display.println("DANGER!!");

  if (muted) display.println("MUTED");

  display.display();

  // Send data to Blynk every 1 second
  if (millis() - lastSend > 1000 && WiFi.status() == WL_CONNECTED) {

    Blynk.virtualWrite(V2, t);
    Blynk.virtualWrite(V3, h);
    Blynk.virtualWrite(V4, gasDelta);

    if(state == ST_NORMAL) Blynk.virtualWrite(V5, "NORMAL");
    else if(state == ST_WARN) Blynk.virtualWrite(V5, "WARNING");
    else Blynk.virtualWrite(V5, "DANGER");

    lastSend = millis();
  }

  delay(200);

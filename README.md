# A System for Early Detection of Gas Leaks and Fires with IoT Alerts

## Project Overview

This project presents an Internet of Things (IoT)-based system designed to detect potential gas leaks, smoke, and abnormal temperature conditions at an early stage.

The system uses an ESP32 microcontroller connected to environmental sensors to collect readings and evaluate surrounding conditions. Based on predefined thresholds, the system classifies the current status into three states: **Normal, Warning, and Danger**.

When a potentially dangerous condition is detected, the system activates local warning indicators, including LEDs and a buzzer. It can also send remote notifications through the Blynk platform using Wi-Fi connectivity.

The main goal is to demonstrate how IoT technology can improve environmental safety monitoring through continuous sensing, local alerts, and remote notifications.

---

## Table of Contents

- [Problem Statement](#problem-statement)
- [Project Objectives](#project-objectives)
- [Key Features](#key-features)
- [Hardware Components](#hardware-components)
- [System Architecture](#system-architecture)
- [How It Works](#how-it-works)
- [Operating States](#operating-states)
- [Software and Technologies](#software-and-technologies)
- [Repository Structure](#repository-structure)
- [Installation and Setup](#installation-and-setup)
- [Testing and Evaluation](#testing-and-evaluation)
- [Project Report Chapters](#project-report-chapters)
- [Limitations](#limitations)
- [Future Improvements](#future-improvements)
- [Safety Notice](#safety-notice)
- [License](#license)

---

## Problem Statement

Gas leaks, smoke, and fire-related hazards can create dangerous situations when they are not detected promptly.

Traditional warning systems may rely primarily on local alarms, which can be less effective when occupants are away from the monitored location.

This project addresses this problem by combining environmental sensors, a microcontroller, local warning indicators, and IoT-based remote notifications into a single monitoring prototype.

The system is designed to provide early warnings and help users become aware of potentially dangerous environmental conditions.

## Project Objectives

The main objectives of this project are:

1. To monitor environmental conditions continuously using connected sensors.
2. To detect potential gas leaks and smoke-related conditions.
3. To monitor ambient temperature and humidity.
4. To classify environmental conditions into Normal, Warning, and Danger states.
5. To provide visual alerts through LEDs.
6. To provide audible alerts through a buzzer.
7. To display sensor readings and system status on an OLED screen.
8. To send remote notifications through the Blynk IoT platform.
9. To demonstrate a practical and expandable IoT-based safety monitoring system.

---

## Key Features

- Continuous environmental monitoring.
- Gas and smoke sensing using the MQ-2 sensor.
- Temperature and humidity monitoring using the DHT22 sensor.
- Three system states: Normal, Warning, and Danger.
- Visual alerts using LEDs.
- Audible warnings using a buzzer.
- Local information display using an OLED screen.
- Wi-Fi connectivity through the ESP32.
- Remote monitoring and notifications through Blynk.
- Expandable architecture for future enhancements.

---

## Hardware Components

| Component | Purpose |
|---|---|
| ESP32 Microcontroller | Processes sensor readings and manages system operations and Wi-Fi communication. |
| MQ-2 Sensor | Detects changes associated with combustible gases and smoke. |
| DHT22 Sensor | Measures ambient temperature and relative humidity. |
| OLED Display | Displays sensor readings and the current system status. |
| LEDs | Indicate normal, warning, and danger conditions. |
| Buzzer | Provides audible warnings when configured danger conditions are detected. |
| Supporting Electronic Components | Enable the required electrical connections between components. |
| Wi-Fi Network | Enables communication with the remote monitoring platform. |
| Blynk Platform | Supports remote monitoring and mobile notifications. |

*Note: Exact wiring details, GPIO assignments, and electrical specifications depend on the final hardware implementation.*

---

## System Architecture

The system consists of four main functional layers.

### 1. Sensing Layer

The MQ-2 and DHT22 sensors collect environmental information. The MQ-2 provides readings associated with gas and smoke, while the DHT22 measures temperature and humidity.

### 2. Processing Layer

The ESP32 reads the sensor data and compares the readings against predefined thresholds. Based on these readings, the firmware determines the current operating state.

### 3. Local Alert Layer

The OLED display shows the sensor readings and system status. LEDs provide visual indications, while the buzzer provides an audible warning when configured danger conditions occur.

### 4. IoT Communication Layer

The ESP32 uses Wi-Fi to communicate with the Blynk platform, enabling remote monitoring and notifications when the device and platform are configured correctly.

### System Workflow

```text
Environmental Conditions
          |
          v
   MQ-2 and DHT22
          |
          v
      ESP32
          |
          v
  Threshold Evaluation
          |
          v
  Determine System State
          |
     +----+----+
     |         |
     v         v
 OLED / LEDs  Buzzer
     |
     v
 Wi-Fi Connection
     |
     v
 Blynk Platform
     |
     v
Remote Notifications
```

*The diagram illustrates the general functional flow of the system.*

---

## How It Works

The system follows a continuous monitoring process:

1. **Initialization:** The ESP32 initializes the sensors, display, and other connected components.
2. **Sensor Reading:** The system collects gas/smoke, temperature, and humidity readings.
3. **Threshold Evaluation:** The firmware compares the readings with configured threshold values.
4. **State Classification:** The system identifies the current state as Normal, Warning, or Danger.
5. **Local Alerts:** The OLED display and LEDs indicate the current state, and the buzzer is activated when configured danger conditions are met.
6. **Remote Notifications:** The ESP32 communicates with Blynk over Wi-Fi to support remote monitoring and notifications.
7. **Continuous Monitoring:** The process repeats to monitor changes in environmental conditions.

The system's behavior depends on sensor readings, threshold configuration, and the availability of the hardware and network connection.

---

## Operating States

The system uses three primary operating states.

| State | Description | General Response |
|---|---|---|
| **Normal** | Readings remain within the configured normal range. | The green LED indicates normal operation. |
| **Warning** | Readings reach a predefined warning threshold. | The yellow LED indicates that attention may be required. |
| **Danger** | Readings reach a configured danger threshold. | The red LED and buzzer provide local alerts, and a remote notification can be sent through Blynk. |

The exact threshold values and state-transition rules should be documented using the final source code.

---

## Software and Technologies

### ESP32

The ESP32 serves as the main controller. It collects sensor readings, evaluates conditions, controls the alert indicators, and manages network communication.

### Blynk IoT Platform

Blynk supports remote monitoring and mobile notifications when the device is connected and correctly configured.

### Wi-Fi

Wi-Fi provides the communication link between the ESP32 and the Blynk platform.

### Embedded Systems

The firmware integrates sensor readings, decision-making logic, display output, and alert control into one embedded application.

### Internet of Things (IoT)

IoT connectivity allows the monitoring system to communicate with a remote platform instead of relying exclusively on local indicators.

---

## Repository Structure

The following is a suggested repository structure:

```text
gas-leak-fire-iot-alert-system/
│
├── README.md
│
├── Graduation Report Ver [3].pdf
│
├── src/
│   └── main.ino
│
├── hardware/
│   ├── components.md
│   └── wiring-diagram.png
│
├── images/
│   ├── system-overview.png
│   ├── hardware-prototype.jpg
│   └── system-testing/
│         └── System Output in Normal State.png
│         └── System Output in Warning State.png
│          └── System Output in Danger State with IoT Notification.png
│
├── .gitignore
│
└── LICENSE
```

This structure is a recommendation. Replace example filenames with the actual files included in the repository. Do not include files that do not exist.

---

## Installation and Setup

The following steps describe the general setup process. Some details may vary depending on the final firmware and hardware configuration.

### Requirements

- ESP32 development board.
- MQ-2 gas and smoke sensor.
- DHT22 temperature and humidity sensor.
- OLED display.
- LEDs and buzzer.
- Supporting electronic components and wiring.
- Arduino IDE or a compatible ESP32 development environment.
- Required software libraries.
- A Wi-Fi network.
- A configured Blynk device for remote monitoring.

### Setup Steps

1. Clone or download this repository.
2. Open the firmware file from the `src/` directory in the appropriate development environment.
3. Install ESP32 board support.
4. Install the libraries required by the source code.
5. Configure the Wi-Fi and Blynk settings.
6. Verify that the GPIO assignments match the actual circuit.
7. Compile the firmware and resolve any errors.
8. Upload the firmware to the ESP32.
9. Check the initialization messages and sensor readings using the available diagnostic interface.
10. Test the display, LEDs, buzzer, and remote notifications under controlled conditions.

### Configuration and Security

**Do not publish private credentials in a public repository.**

Wi-Fi passwords, Blynk authentication tokens, API keys, and other sensitive values must not be committed to public source code.

Use a separate local configuration file or another suitable method to supply credentials securely. Exclude private configuration files from version control.

If a credential has already been exposed, revoke or regenerate it as appropriate. Removing it from the latest source file does not necessarily remove it from the repository's history.

---

## Testing and Evaluation

Testing should verify the operation of the sensors, system states, local indicators, and remote communication.

| Test Scenario | Expected Behavior |
|---|---|
| Normal environmental readings | The system displays readings and indicates the Normal state. |
| Readings reach the warning threshold | The system enters the Warning state and activates the configured warning indication. |
| Readings reach the danger threshold | The system activates the configured danger indicators and buzzer. |
| Wi-Fi and Blynk are available | Remote communication and configured notifications operate as expected. |
| Wi-Fi is unavailable | Local monitoring and alert behavior can be evaluated independently of remote notifications. |
| Sensor initialization or readings fail | The system's handling of invalid or unavailable sensor data should be evaluated. |

The project report describes testing of the normal, warning, and danger states, including local indicators, audible alerts, and remote notifications.

Actual measurements, response times, accuracy figures, and reliability statistics should only be included when supported by recorded test results.

---

## Project Report Chapters

The original graduation project report is organized into five chapters.

### Chapter 1: Introduction

Introduces the project background, explains the problem of gas leaks and fire-related hazards, and presents the project's objectives and scope.

### Chapter 2: Literature Review and Related Work

Reviews existing approaches to gas, smoke, and temperature monitoring, including traditional warning systems and IoT-based solutions.

### Chapter 3: System Design and Methodology

Explains the system architecture, hardware components, circuit connections, sensor integration, operating logic, and communication with the Blynk platform.

### Chapter 4: Results and Discussion

Describes the prototype's operating behavior and the reported testing of the Normal, Warning, and Danger states. It discusses sensor readings, local indicators, audible alerts, and remote notifications.

### Chapter 5: Conclusion and Future Work

Summarizes the project and its overall objectives. It also identifies possible improvements, including additional sensors, backup power, automated ventilation, and gas shutoff integration.

---

## Limitations

This project is an educational prototype for environmental monitoring and early warning. Its limitations include:

- Sensor readings may be affected by calibration, placement, environmental conditions, and component characteristics.
- MQ-2 readings should not be treated as precise gas concentration measurements without appropriate calibration and validation.
- Remote notifications depend on power, Wi-Fi connectivity, and the availability of the configured IoT service.
- Network or service interruptions may delay or prevent remote notifications.
- The prototype does not automatically extinguish fires or physically eliminate gas leaks.
- The system has not been established as a replacement for certified fire alarms, gas detectors, or professional safety systems.

These limitations should be considered when evaluating the prototype or adapting it for real-world applications.

---

## Future Improvements

Potential improvements include:

1. Adding specialized sensors for additional environmental hazards.
2. Improving sensor calibration and validating threshold values through controlled experiments.
3. Adding backup power for operation during power interruptions.
4. Improving fault detection and handling of disconnected or malfunctioning sensors.
5. Implementing data logging and historical trend visualization.
6. Improving network-failure handling and notification reliability.
7. Exploring automated ventilation or gas shutoff integration using suitable, safety-rated equipment.
8. Conducting more extensive testing to measure response time, false alarms, and detection reliability.

These are proposed improvements and should not be interpreted as features already implemented in the current prototype.

---

## Safety Notice

This project is intended for educational and demonstration purposes.

It should not be used as the sole safety mechanism in homes, laboratories, industrial facilities, or other environments where gas leaks or fires could cause harm.

Do not deliberately release combustible gas or create real fires to test the prototype. Use controlled testing procedures and follow appropriate safety guidance.

For real-world protection, use certified detection and alarm equipment installed and maintained according to applicable safety requirements.

---

## Contributions

Contributions, suggestions, and improvements are welcome, subject to applicable academic requirements and the rights of the project contributors.

When proposing changes, document hardware modifications, software dependencies, and testing procedures to help others understand and reproduce the results.

---

## License

No license has been specified for this repository.

Before distributing or reusing the source code, documentation, diagrams, or other project materials, confirm that the project contributors and relevant university policies permit publication.

Once the appropriate permissions have been confirmed, add the selected license file to the repository.

---

## Acknowledgment

This graduation project demonstrates the application of embedded systems and Internet of Things technology to environmental monitoring and safety alerts.

By combining sensor data collection, microcontroller-based processing, local warning mechanisms, and remote notifications, the project provides a foundation for further learning and development in IoT-based safety systems.

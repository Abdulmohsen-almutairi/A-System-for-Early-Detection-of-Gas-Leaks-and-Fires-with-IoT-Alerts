# A-System-for-Early-Detection-of-Gas-Leaks-and-Fires-with-IoT-Alerts
A System for Early Detection of Gas Leaks and Fires with IoT Alerts

Project Overview

A System for Early Detection of Gas Leaks and Fires with IoT Alerts is an Internet of Things (IoT)-based safety monitoring project designed to detect potential gas leaks, smoke, and abnormal temperature conditions at an early stage.

The system uses an ESP32 microcontroller connected to environmental sensors to collect readings and evaluate the surrounding conditions. Based on predefined thresholds, it classifies the current status as Normal, Warning, or Danger.

When a potentially dangerous condition is detected, the system provides local alerts through LEDs and a buzzer. It also uses Wi-Fi connectivity and the Blynk platform to send notifications to a connected mobile device, allowing users to monitor the system remotely.

The main purpose of this project is to demonstrate how IoT technology can be used to improve safety monitoring through continuous sensing, local warnings, and remote notifications.

⸻

Table of Contents

* Project Overview
* Problem Statement
* Project Objectives
* Key Features
* System Components
* System Architecture
* How the System Works
* Operating States
* Software and Technologies
* Repository Structure
* Setup and Configuration
* Testing and Evaluation
* Summary of the Five Chapters
* Limitations
* Future Improvements
* Safety Notice
* Contributions
* License

⸻

Problem Statement

Gas leaks, smoke, and fires can create dangerous situations when they are not detected promptly. Traditional warning systems may rely primarily on local alarms, which can be less effective when occupants are away from the monitored location.

IoT technology provides an opportunity to combine environmental monitoring with remote notifications, helping users become aware of potential hazards even when they are not physically near the monitoring device.

This project addresses the need for an accessible monitoring prototype that combines sensor-based detection, local warning indicators, and mobile notifications in one system.

Project Objectives

The main objectives of the project are:

1. Continuous monitoring: Collect environmental readings using connected sensors.
2. Early warning: Identify potentially unsafe conditions based on predefined thresholds.
3. Multiple alert methods: Provide visual and audible warnings when necessary.
4. Remote notifications: Send alerts through the Blynk platform using Wi-Fi connectivity.
5. Real-time status display: Display sensor readings and the current system state on an OLED screen.
6. Affordable implementation: Demonstrate a practical IoT safety-monitoring solution using accessible electronic components.
7. Expandable design: Provide a foundation for future improvements in environmental monitoring and safety automation.

Key Features

* Continuous environmental monitoring.
* Gas and smoke indication using the MQ-2 sensor.
* Temperature and humidity monitoring using the DHT22 sensor.
* Three operating states: Normal, Warning, and Danger.
* Visual alerts using LEDs.
* Audible alerts using a buzzer.
* Local display of readings and system status using an OLED screen.
* Wi-Fi connectivity through the ESP32.
* Remote monitoring and notifications through Blynk.
* Modular design that can be extended with additional sensors and safety features.

⸻

System Components

The project uses the following main hardware components:

Component	Purpose
ESP32 Microcontroller	Processes sensor readings and manages the system’s operation and Wi-Fi communication.
MQ-2 Gas and Smoke Sensor	Detects changes associated with combustible gases and smoke.
DHT22 Sensor	Measures ambient temperature and relative humidity.
OLED Display	Displays sensor readings and the current system state.
LEDs	Provide visual indications of normal, warning, and danger conditions.
Buzzer	Provides an audible warning when a dangerous condition is detected.
Supporting Electronic Components	Enable safe and appropriate electrical connections between the system components.
Wi-Fi Network	Enables communication between the ESP32 and the remote monitoring platform.
Blynk Platform	Supports remote monitoring and mobile notifications.

The exact wiring, GPIO assignments, and electrical specifications should be documented using the final hardware configuration of the project.

⸻

System Architecture

The system consists of four main functional layers.

1. Sensing Layer

The MQ-2 and DHT22 sensors collect environmental information. The MQ-2 provides readings associated with gas and smoke, while the DHT22 measures temperature and humidity.

2. Processing Layer

The ESP32 reads the sensor data and compares the readings with predefined thresholds. The results are used to determine the current operating state.

3. Local Alert Layer

The OLED display communicates the current readings and system state. LEDs and a buzzer provide local visual and audible warnings when the system identifies a warning or danger condition.

4. IoT Communication Layer

The ESP32 uses Wi-Fi to communicate with Blynk. This connection supports remote monitoring and the delivery of notifications when configured conditions are met.

System Workflow

Environmental Conditions
          |
          v
   MQ-2 and DHT22
          |
          v
      ESP32
          |
          v
 Readings and Thresholds
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

Note: This diagram represents the system’s general functional flow. The final implementation may handle local alerts and remote communication in parallel.

⸻

How the System Works

The system follows a continuous monitoring process:

1. Initialization: The ESP32 starts the connected components and initializes the sensors, display, and communication settings.
2. Sensor Reading: The system reads the available gas/smoke, temperature, and humidity measurements.
3. Threshold Evaluation: The readings are evaluated against the configured threshold values.
4. State Classification: The program determines whether the current conditions are Normal, Warning, or Danger.
5. Local Feedback: The OLED display and LEDs indicate the current state. The buzzer is activated when the configured danger conditions are met.
6. Remote Communication: The ESP32 communicates with Blynk through Wi-Fi to support remote monitoring and notifications.
7. Continuous Operation: The process repeats so that changes in environmental conditions can be detected.

The system’s behavior depends on the sensor readings, configured thresholds, and successful operation of its hardware and network connection.

Operating States

The project uses three main operating states.

State	Description	General System Response
Normal	Readings remain within the configured normal range.	Green LED indicates normal operation.
Warning	Readings reach a predefined warning threshold.	Yellow LED indicates that attention may be required.
Danger	Readings reach a configured danger threshold.	Red LED and buzzer provide local alerts, and a remote notification can be sent through Blynk.

The exact threshold values and transition rules should be taken from the final source code and documented separately if they are relevant to reproducing the project.

⸻

Software and Technologies

ESP32 Firmware

The firmware runs on the ESP32 microcontroller. It reads sensor data, evaluates operating conditions, controls the local indicators, and manages communication with the IoT platform.

Blynk IoT Platform

Blynk provides the remote monitoring and notification functionality. When the device is connected and configured correctly, users can receive alerts and monitor the system remotely.

Wi-Fi Connectivity

Wi-Fi provides the communication link between the ESP32 and Blynk. Remote functionality depends on network availability and valid configuration settings.

Embedded Systems and IoT

The project combines embedded programming, sensor integration, real-time monitoring, and network communication to demonstrate a connected safety-monitoring application.

⸻

Repository Structure

A suggested GitHub repository structure is:

gas-leak-fire-iot-alert-system/
│
├── README.md
│
├── report/
│   └── project-summary.pdf
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
│   └── system-testing.jpg
│
├── .gitignore
│
└── LICENSE

Important: This is a suggested structure. Include only files that actually exist in the repository, and replace example filenames with the names of your real files. Do not add a LICENSE until you have decided which license you are authorized to use.

⸻

Setup and Configuration

The following steps describe the general setup process. Exact instructions may vary depending on the final firmware and hardware configuration.

Hardware Requirements

Prepare the ESP32, MQ-2 sensor, DHT22 sensor, OLED display, LEDs, buzzer, and the supporting electronic components used in the prototype.

Before powering the circuit, verify the wiring, voltage requirements, and electrical compatibility of all components.

Software Requirements

Depending on the implementation, you may need:

* Arduino IDE or a compatible ESP32 development environment.
* ESP32 board support.
* The software libraries required by the source code.
* A Blynk account and the appropriate device configuration.
* A Wi-Fi network for remote communication.

The exact library names and versions should be documented after verifying the actual source code.

General Configuration Steps

1. Clone or download this repository.
2. Open the firmware file from the src/ directory in the appropriate development environment.
3. Install the required board support and libraries.
4. Configure the Wi-Fi connection and Blynk settings.
5. Verify that the sensor pins and other GPIO assignments match the physical circuit.
6. Compile the firmware and resolve any configuration or library errors.
7. Upload the firmware to the ESP32.
8. Open the serial monitor or other available diagnostic interface to check initialization and connectivity.
9. Verify sensor readings, display output, LEDs, buzzer, and remote notifications under controlled conditions.

Security and Credentials

Never publish real credentials in the source code.

Wi-Fi passwords, Blynk authentication tokens, API keys, and other private configuration values should be stored outside the public repository or supplied through a secure local configuration method.

If a credential has previously been included in a public file or repository, remove it from the published files and rotate or revoke the exposed credential as appropriate. Removing it from the latest version alone may not remove it from Git history.

⸻

Testing and Evaluation

Testing should verify that the hardware, firmware, and remote communication work together as intended.

The following scenarios can be used as a testing checklist:

Test Scenario	Expected Behavior
Normal environmental readings	The system displays the readings and indicates the Normal state.
Readings reach the warning threshold	The system changes to the Warning state and activates the configured warning indication.
Readings reach the danger threshold	The system activates the configured danger indicators and buzzer.
Remote connection is available	Blynk communication and configured notifications operate as expected.
Wi-Fi connection is unavailable	The local monitoring and alert behavior should be checked independently of remote communication.
Sensor initialization or readings fail	The system’s handling of invalid or unavailable sensor data should be evaluated.

The project report describes testing of the normal, warning, and danger states, including the corresponding visual and audible indicators and remote notifications.

Actual measured performance, response times, accuracy, and reliability figures should only be added when supported by recorded test results.

⸻

Summary of the Five Chapters

The original graduation project report is organized into five chapters.

Chapter 1: Introduction

Introduces the background of gas leaks and fire-related hazards, explains the problem addressed by the project, and presents its objectives and scope.

Chapter 2: Literature Review and Related Work

Reviews existing approaches to gas, smoke, and temperature monitoring, including traditional warning systems and IoT-based solutions. It provides context for the proposed monitoring and alert system.

Chapter 3: System Design and Methodology

Describes the proposed system architecture, hardware components, circuit connections, sensor integration, operating logic, and communication with the Blynk platform.

Chapter 4: Results and Discussion

Presents the prototype’s operating behavior and the reported testing of its normal, warning, and danger states. It discusses the sensor readings, local indicators, audible alerts, and remote notification functionality.

Chapter 5: Conclusion and Future Work

Summarizes the project and its overall objectives, then discusses potential improvements, such as additional sensors, backup power, automated ventilation, or gas shutoff integration.

⸻

Limitations

The project is an educational prototype for environmental monitoring and early warning. Its limitations include:

* Sensor readings may be affected by calibration, environmental conditions, sensor placement, and component characteristics.
* MQ-2 readings should not automatically be interpreted as precise gas concentration measurements without appropriate calibration and validation.
* Remote notifications depend on power, Wi-Fi connectivity, and the availability of the configured IoT service.
* A notification may be delayed or unavailable if the network or platform is interrupted.
* The prototype does not automatically extinguish fires or physically eliminate gas leaks.
* The system has not been established as a replacement for certified fire alarms, gas detectors, or professional safety systems.

These limitations should be considered when evaluating the system or adapting it for real-world use.

Future Improvements

Potential areas for further development include:

1. Integrating additional sensors for more specialized gas or fire detection.
2. Improving sensor calibration and validating thresholds under controlled test conditions.
3. Adding backup power to support operation during power interruptions.
4. Improving fault detection and handling of disconnected or malfunctioning sensors.
5. Adding data logging and historical trend visualization.
6. Improving notification reliability and network-failure handling.
7. Exploring automated ventilation or gas shutoff integration using suitable, safety-rated equipment.
8. Conducting more extensive testing to measure response time, false alarms, and detection reliability.

These are proposed improvements and should not be interpreted as features already implemented in the current prototype.

⸻

Safety Notice

This project is intended for educational and demonstration purposes. It should not be used as the sole safety mechanism in a home, laboratory, industrial facility, or other environment where gas leaks or fires could cause harm.

Do not deliberately release combustible gas or create real fires to test the prototype. Use controlled, appropriate testing procedures and follow relevant safety guidance.

For real-world protection, use certified detection and alarm equipment installed and maintained according to applicable safety requirements.

Contributions

Contributions, suggestions, and improvements are welcome, provided they are consistent with the project’s goals and the applicable academic and licensing requirements.

If you propose changes, document the hardware modifications, software dependencies, and testing procedures so that others can understand and reproduce the results.

License

A license has not been specified in this README. Before distributing or reusing the source code, documentation, diagrams, or other project materials, confirm the rights of all contributors and any applicable university requirements.

Once the appropriate permissions have been confirmed, add the selected license file to the repository.

⸻

Acknowledgment

This project demonstrates the application of embedded systems and Internet of Things technology to environmental monitoring and safety alerts. It combines sensor data collection, microcontroller-based processing, local warning mechanisms, and remote notifications into a single prototype.

The repository is intended to document the project, explain its design, and provide a clear starting point for further learning and development.

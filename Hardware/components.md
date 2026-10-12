# Hardware Components

This document lists the hardware components used in the Gas Leak and Fire Early Detection System.

## Components List

| Component | Description |
|---|---|
| ESP32 Development Board | Main controller responsible for processing sensor data and connecting to Wi-Fi. |
| MQ-2 Gas and Smoke Sensor | Detects gas and smoke levels in the surrounding environment. |
| DHT22 Temperature and Humidity Sensor | Measures ambient temperature and humidity. |
| OLED Display | Displays sensor readings and system status. |
| Green LED | Indicates normal operating conditions. |
| Yellow LED | Indicates a warning condition. |
| Red LED | Indicates a danger condition. |
| Buzzer | Provides an audible alert when a warning or danger condition is detected. |
| Wi-Fi Connection | Enables remote monitoring and notifications through the Blynk platform. |
| Jumper Wires | Connect the electronic components. |
| Breadboard | Supports prototyping and component connections. |
| USB Cable and Power Supply | Used to power and program the ESP32. |

## Notes

- The exact wiring and pin assignments should be verified against the implemented hardware.
- Sensor readings and alert thresholds depend on the system configuration.
- This project is an educational prototype and is not a replacement for certified gas detection or fire alarm systems.

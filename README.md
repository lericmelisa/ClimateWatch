# ClimateWatch IoT Project

## Overview

Welcome to ClimateWatch, an IoT project developed as part of the IoT course at Faculty of Information technologies. This project utilizes the ESP8266 microcontroller and DS18B20 temperature sensor to monitor and control temperature, providing a flexible and efficient solution for device automation in various scenarios.

## Features

1. **Control Panel**
   
   This is a web application (HTML and JS) accessible from a browser, allowing users to control temperature settings remotely.

3. **Temperature Monitoring:**
   - The DS18B20 temperature sensor is employed to accurately monitor the ambient temperature.
   - Real-time temperature data is collected and made available for analysis.

4. **Device Control:**
   - ClimateWatch allows you to control devices based on temperature conditions.
   - Turn devices on or off automatically when the temperature crosses specified thresholds.

5. **Scheduled Activation:**
   - Set specific times for devices to turn on automatically, providing a scheduled and energy-efficient operation.

6. **Manual Control:**
   - Enjoy the flexibility of manually turning devices on or off, regardless of temperature conditions or schedules.

## Components Used

- **ESP8266 Microcontroller:** The brain of the system, responsible for collecting data and controlling devices.
- **DS18B20 Temperature Sensor:** Provides accurate temperature readings for decision-making.

## Setup Instructions

1. **Hardware Setup:**
   - Connect the ESP8266 microcontroller and DS18B20 temperature sensor.

2. **Software Configuration:**
   - Upload the provided Arduino sketch to the ESP8266 using the Arduino IDE.
   - Modify the configuration parameters in the sketch to match your preferences (Wi-Fi credentials, device IDs, temperature thresholds, etc.).

3. **Power On:**
   - Power up the system and wait for the ESP8266 to connect to the Wi-Fi network.

4. **Accessing ClimateWatch:**
   - Once connected, access the ClimateWatch dashboard through a web browser using the assigned IP address or domain.

## Usage

1. **Temperature-Based Automation:**
   - Set temperature thresholds to automatically control devices.
   - Define specific activation and deactivation temperatures as per your requirements.

2. **Scheduled Operation:**
   - Use the scheduler feature to set specific times for device activation.

3. **Manual Control:**
   - Toggle devices on or off manually through the dashboard.


Thank you for using ClimateWatch!

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ClimateWatch IoT Project</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }

        header {
            text-align: center;
            margin-bottom: 20px;
        }

        section {
            margin-bottom: 30px;
        }

        h2 {
            border-bottom: 2px solid #333;
            padding-bottom: 5px;
            margin-top: 20px;
        }

        ul {
            list-style-type: none;
            padding: 0;
        }

        li {
            margin-bottom: 10px;
        }

        footer {
            text-align: center;
            margin-top: 30px;
            font-size: 12px;
        }
    </style>
</head>

<body>

    <header>
        <h1>ClimateWatch IoT Project</h1>
    </header>

    <section>
        <h2>Overview</h2>
        <p>Welcome to ClimateWatch, an IoT project developed as part of the IoT course at Faculty of Information Technologies. This project utilizes the ESP8266 microcontroller and DS18B20 temperature sensor to monitor and control temperature, providing a flexible and efficient solution for device automation in various scenarios.</p>
    </section>

    <section>
        <h2>Features</h2>
        <ul>
            <li><strong>Temperature Monitoring:</strong> The DS18B20 temperature sensor is employed to accurately monitor the ambient temperature. Real-time temperature data is collected and made available for analysis.</li>
            <li><strong>Device Control:</strong> ClimateWatch allows you to control devices based on temperature conditions. Turn devices on or off automatically when the temperature crosses specified thresholds.</li>
            <li><strong>Scheduled Activation:</strong> Set specific times for devices to turn on automatically, providing a scheduled and energy-efficient operation.</li>
            <li><strong>Manual Control:</strong> Enjoy the flexibility of manually turning devices on or off, regardless of temperature conditions or schedules.</li>
        </ul>
    </section>

    <section>
        <h2>Components Used</h2>
        <ul>
            <li><strong>ESP8266 Microcontroller:</strong> The brain of the system, responsible for collecting data and controlling devices.</li>
            <li><strong>DS18B20 Temperature Sensor:</strong> Provides accurate temperature readings for decision-making.</li>
          
        </ul>
    </section>

    <section>
        <h2>Setup Instructions</h2>
        <ol>
            <li><strong>Hardware Setup:</strong>
                <ul>
                    <li>Connect the ESP8266 microcontroller and DS18B20 temperature sensor.</li>
                </ul>
            </li>
            <li><strong>Software Configuration:</strong>
                <ul>
                    <li>Upload the provided Arduino sketch to the ESP8266 using the Arduino IDE.</li>
                    <li>Modify the configuration parameters in the sketch to match your preferences (Wi-Fi credentials, device IDs, temperature thresholds, etc.).</li>
                </ul>
            </li>
            <li><strong>Power On:</strong>
                <ul>
                    <li>Power up the system and wait for the ESP8266 to connect to the Wi-Fi network.</li>
                </ul>
            </li>
            <li><strong>Accessing ClimateWatch:</strong>
                <ul>
                    <li>Once connected, access the ClimateWatch dashboard through a web browser using the assigned IP address or domain.</li>
                </ul>
            </li>
        </ol>
    </section>

    <section>
        <h2>Usage</h2>
        <ul>
            <li><strong>Dashboard:</strong> The web-based dashboard displays real-time temperature data and allows you to interact with the system.</li>
            <li><strong>Temperature-Based Automation:</strong> Set temperature thresholds to automatically control devices. Define specific activation and deactivation temperatures as per your requirements.</li>
            <li><strong>Scheduled Operation:</strong> Use the scheduler feature to set specific times for device activation.</li>
            <li><strong>Manual Control:</strong> Toggle devices on or off manually through the dashboard.</li>
        </ul>
    </section>
    <footer>
        <p>Thank you for using ClimateWatch!</p>
    </footer>

</body>

</html>

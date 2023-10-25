# Fish Pond Control System with ESP32

The Fish Pond Control System is a prototype designed to maintain and monitor the conditions of a fish pond. It utilizes an ESP32 controller along with various sensors, including a DHT11 temperature sensor, a pH probe, and a TDS (Turbidity) probe. 


## Project Structure

The project consists of several code files:

- `client.h`: Defines functions for setting up and interacting with the Firebase client.
- `http.h`: Implements an HTTP server for controlling the pond system.
- `sonar.h`: Contains functions related to the ultrasonic sensor for measuring water level.
- `temp.h`: Manages temperature sensing with the DHT11 sensor.
- `wifi.h`: Handles Wi-Fi configurations.
- `ph.h`: Contains functions for pH measurement.
- `tds.h`: Manages TDS measurement.
- `valve_relays.h`: Controls the relays for input and output valves.
- `Fish_Pond_Module.ino`: The main project file that combines these components and controls the behavior of the system.

## Code Overview

### Firebase Client (`client.h`)

The `client.h` file defines functions for setting up and interacting with the Firebase client. It is responsible for establishing a connection to Firebase, sending data, and handling system values.

### HTTP Server (`http.h`)

The `http.h` file contains an HTTP server setup to control the pond system. It includes functions to toggle input and output valves, enable manual override, reset the system, and retrieve system status data.

### Ultrasonic Sensor (`sonar.h`)

The `sonar.h` file deals with the ultrasonic sensor used to measure the water level in the pond.

### Temperature Sensor (`temp.h`)

The `temp.h` file is responsible for managing the DHT11 temperature sensor to monitor the water temperature in the fish pond.

### Wi-Fi Configuration (`wifi.h`)

The `wifi.h` file handles Wi-Fi configurations and setup, including creating an access point for connecting to the system.

### pH Measurement (`ph.h`)

The `ph.h` file contains functions to measure the pH of the water in the fish pond.

### TDS Measurement (`tds.h`)

The `tds.h` file manages the TDS (Turbidity) probe for measuring the water's turbidity, with compensation based on temperature.

### Valve Control (`valve_relays.h`)

The `valve_relays.h` file controls the input and output valves using relays.

### Main Code (`Fish_Pond_Module.ino`)

The `Fish_Pond_Module.ino` file combines all the components and functions to control the behavior of the fish pond system. It sets up the various sensors, handles control logic for the valves and water level, and manages the interaction between the sensors and the Firebase database.

- `setup()`: Initializes the sensors, access point, server, and other components.
- `loop()`: Executes the control logic, including auto-control based on pH, TDS, and temperature, and water level control. It also handles HTTP requests and updates system values on Firebase.

## Usage

1. Ensure you have the necessary libraries installed in your Arduino IDE, including the FirebaseESP32 library and any other dependencies used in the project.

2. Modify the Wi-Fi credentials, Firebase settings, and other parameters in the `Fish_Pond_Module.ino` code to match your specific requirements.

3. Upload the project code to your ESP32 controller.

4. Connect the sensors and relays according to your hardware setup and configure pin mappings as needed.

5. Power on the ESP32 and the connected sensors.

6. The ESP32 will start monitoring the fish pond's conditions and controlling the system based on the logic specified in the code.

7. Use the HTTP server endpoints to control the system and retrieve status information.

# Relay Control System 🔄📡

This project involves two modules: `ESP32_SPU` and `Pond_Control_System`, aimed at controlling relays and monitoring sensor data using ESP32 and ESP8266 microcontrollers. The ESP32 drives an Ultrasonic sensors and sends the data to the ESP8266 main controller which drives relays and also runs the main logic

## Project Structure 📂

### `ESP32_SPU Module`
```
- ESP32_SPU.ino
- sonar.h
```

### `Pond_Control_System Module`
```
- http.h
- Pond_Control_System.ino
- relays.h
- wifi.h
```

## ESP32_SPU Module 🛠️

### Code 🧩

#### `void initNet()`
- Connects to the ESP8266 WiFi access point.
- Handles connection retries with LED blinking feedback.

#### `void sendRangeData()`
- Sends Ultrasonic sensor data (range value from sonar sensor) to the specified host.
- Utilizes an HTTP GET request.

#### `void setupSonar()`
- Sets up the ultrasonic sensor for distance measurement.
- Provides functions to calculate distance based on sensor readings.

## Pond_Control_System Module 🏞️

### Code 🧩

#### Server Configuration and Functionality

- The `Pond_Control_System` module establishes an HTTP server for managing relay control and Ultrasonic sensor data retrieval.

#### `void setControlSignal()`
- Receives and processes requests to change relay states based on ID and state.
- Sends updated relay state information as an HTTP response.

#### `void setRangeSensorValue()`
- Accepts and updates the ultrasonic sensor range value received from the sonar sensor.

#### `void getStatusInformation()`
- Gathers status information including sensor range and relay states.
- Responds with collected information.

## Summary ℹ️

- `ESP32_SPU` module establishes a connection to the ESP8266 WiFi network and sends ultrasonic sensor data to a specified host using HTTP GET requests.
- `Pond_Control_System` module sets up an HTTP server for managing relay states and retrieving ultrasonic sensor range values.
- Access the relay control and sensor status information by sending HTTP requests to respective endpoints on the ESP8266 server.

# IoT-controlled-smart-socket-

1. Introduction
This project demonstrates how to control an AC socket (via a relay module) remotely using an ESP32 microcontroller and the Blynk IoT platform. The system allows users to turn devices ON/OFF from anywhere in the world using the Blynk mobile app or web dashboard.

2. Objectives
To design a simple IoT-enabled smart socket.
To control an electrical load (bulb, fan, socket, etc.) from a smartphone.
To provide real-time monitoring and control via Blynk IoT Cloud.
To gain practical experience in ESP32 programming, IoT communication, and mobile app integration.

3. Components Required
Component	Quantity	Description
ESP32 Devkit V1	1	Wi-Fi-enabled microcontroller
Relay Module (5V/3.3V)	1	Controls AC load (active LOW)
AC Socket / Lamp Load	1	Device to be controlled
Jumper Wires	Several	Connections
Smartphone with Blynk App	1	User interface
Laptop with Arduino IDE	1	For programming ESP32


4. System Design
4.1 Block Diagram

Smartphone (Blynk App) ⇄ Blynk Cloud ⇄ ESP32 (WiFi) ⇄ Relay Module ⇄ AC Load

4.2 Working Principle
1. The ESP32 connects to Wi-Fi and authenticates with the Blynk Cloud using an Auth Token.
2. The user presses a button on the Blynk app.
3. The command is sent via Blynk Cloud to the ESP32.
4. The ESP32 activates/deactivates the relay, turning the AC load ON or OFF.


5. Circuit Diagram
Relay IN → GPIO25 of ESP32
Relay VCC → 3.3V / 5V (depending on relay module)
Relay GND → ESP32 GND
AC Load connected through relay contacts (NO/NC + COM).

6. Software Implementation
6.1 Libraries Required
Blynk (BlynkSimpleEsp32.h)
WiFi.h (comes with ESP32 core)


6.2 Blynk Setup
1. Create a new template in Blynk IoT Cloud.
2. Note down:
Template ID
Template Name
Auth Token
3. Create a datastream (V1, type: switch).
4. In the Blynk App, create a button widget linked to V1.


7. Results
Successfully controlled an AC load using the Blynk mobile app.
Relay responded instantly to ON/OFF commands.
Real-time synchronization between app, cloud, and ESP32 was achieved.

8. Applications

Smart home automation (lights, fans, appliances).
Remote farm equipment control.
Industrial machine switching.
Energy-saving systems.

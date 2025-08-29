# Obstacle Avoiding Robot with Servo (Arduino)

This project is an **Arduino-based obstacle avoiding robot** using:

- **HC-SR04 ultrasonic sensor**
- **Servo motor** to scan left/center/right
- **L298N motor driver**
- **Two DC motors**

## Features
- Servo-based scanning (looks left & right)
- Smart obstacle avoidance (turns towards free path)
- Adjustable speed & distance threshold

## Hardware
- Arduino Uno/Nano
- HC-SR04 Ultrasonic Sensor
- SG90/MG90 Servo Motor
- L298N Motor Driver
- 2x DC Motors + chassis + wheels + caster
- Battery pack (6–9V for motors, 5V for Arduino)

## Pin Connections
| Component | Arduino Pin |
|-----------|-------------|
| Servo     | D6 |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D8 |
| L298N ENA | D12 (PWM) |
| L298N IN1 | D2 |
| L298N IN2 | D3 |
| L298N IN3 | D4 |
| L298N IN4 | D5 |
| L298N ENB | D11 (PWM) |

## Project Structure

obstacle-avoiding-robot-servo/
├─ README.md
├─ .gitignore
├─ src/
│ └─ obstacle_avoider_servo.ino
└─ docs/
└─ wiring.md    

## Usage
1. Open `src/obstacle_avoider_servo.ino` in Arduino IDE
2. Select your board & port
3. Upload and power your robot

👨‍💻 Author: [ADITYA RAJ](https://github.com/muddycode-tech)  
⭐ If you like this project, don’t forget to star the repo!


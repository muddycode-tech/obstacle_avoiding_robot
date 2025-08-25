# Wiring Guide (Servo Version)

## Power
- Motors powered via L298N `12V` pin (6–9V battery pack)
- Arduino powered via 5V regulated supply
- Common GND required between Arduino, L298N, HC-SR04, Servo

## Connections
- Servo signal → D6
- HC-SR04 TRIG → D9
- HC-SR04 ECHO → D8
- L298N ENA → D12 (PWM)
- L298N IN1 → D2
- L298N IN2 → D3
- L298N IN3 → D4
- L298N IN4 → D5
- L298N ENB → D11 (PWM)

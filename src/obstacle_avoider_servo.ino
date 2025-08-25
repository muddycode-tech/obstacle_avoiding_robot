#include <Servo.h>

// --- Motor driver pins ---
const int IN1 = 2;      // Left motor direction
const int IN2 = 3;
const int IN3 = 4;      // Right motor direction
const int IN4 = 5;
const int ENA = 12;     // Left motor speed
const int ENB = 11;     // Right motor speed

// --- Ultrasonic Sensor Pins ---
const int trigPin = 9;
const int echoPin = 8;

// --- Servo ---
const int servoPin = 6;
Servo myServo;

// --- Parameters ---
const int motorSpeed = 120;         // Adjust 0–255
const int obstacleDistance = 25;    // Distance to react (cm)

void setup() {
  Serial.begin(9600);

  // Motor pins
  pinMode(IN1, OUTPUT);  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);  pinMode(ENB, OUTPUT);

  // Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo
  myServo.attach(servoPin);
  myServo.write(90); // center
  delay(500);
}

void loop() {
  myServo.write(90);
  delay(300);
  int centerDist = getDistance();
  Serial.print("Center: "); Serial.println(centerDist);

  if (centerDist < obstacleDistance) {
    stopMotors();
    delay(300);

    // Look right
    myServo.write(150);
    delay(400);
    int rightDist = getDistance();
    Serial.print("Right: "); Serial.println(rightDist);

    // Look left
    myServo.write(30);
    delay(400);
    int leftDist = getDistance();
    Serial.print("Left: "); Serial.println(leftDist);

    myServo.write(90); // center
    delay(300);

    if (leftDist > rightDist) {
      turnLeft();
    } else {
      turnRight();
    }
    delay(400);
    stopMotors();
    delay(300);
  } else {
    moveForward();
  }
}

// --- Movement Functions ---
void moveForward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

// --- Distance Function ---
int getDistance() {
  digitalWrite(trigPin, LOW);  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  int distance = duration * 0.034 / 2;

  if (distance <= 0) return 400;  // fallback
  return distance;
}

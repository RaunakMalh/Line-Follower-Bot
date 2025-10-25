int sensors[5] = {1,2,3,4,7}; 

// Motor pins
int enA = 5;  // Left motor 
int in1 = 8;
int in2 = 9;
int enB = 6;  // Right motor
int in3 = 10;
int in4 = 11;

// PID constants (tune these)
float Kp = 25;
float Ki = 0;
float Kd = 15;

// PID variables
float error = 0, lastError = 0, integral = 0;
int baseSpeed = 120;  // Actual motor speed

void setup() {
  for (int i = 0; i < 5; i++) pinMode(sensors[i], INPUT);

  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
}

void loop() {
  // IR values
  int s[5];
  for (int i = 0; i < 5; i++) s[i] = digitalRead(sensors[i]);

  // Calculate weighted position
  int weights[5] = {-2, -1, 0, 1, 2};
  int sum = 0, weightedSum = 0;
  for (int i = 0; i < 5; i++) {
    weightedSum += s[i] * weights[i];
    sum += s[i];
  }

  // Avoid division by zero (line lost)
  float position = 0;
  if (sum != 0) position = (float)weightedSum / sum;

  // Error = desired (0) - actual position
  error = 0 - position;

  // PID
  integral += error;
  float derivative = error - lastError;
  float correction = Kp * error + Ki * integral + Kd * derivative;
  lastError = error;

  // Calculate motor speeds
  int leftSpeed = baseSpeed - correction;
  int rightSpeed = baseSpeed + correction;

  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  moveMotors(leftSpeed, rightSpeed);
  delay(10);
}

void moveMotors(int leftSpeed, int rightSpeed) {
  // Left motor forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, leftSpeed);

  // Right motor forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, rightSpeed);
}

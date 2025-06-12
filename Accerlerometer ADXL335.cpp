const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

float voltageRef = 5.0;        // Using 5V reference on Uno
float zeroG = 2.5;             // 0g corresponds to ~2.5V
float sensitivity = 0.33;      // 330 mV/g

void setup() {
  Serial.begin(9600);
}

void loop() {
  int xRaw = analogRead(xPin);
  int yRaw = analogRead(yPin);
  int zRaw = analogRead(zPin);

  float xVolt = xRaw * (voltageRef / 1023.0);
  float yVolt = yRaw * (voltageRef / 1023.0);
  float zVolt = zRaw * (voltageRef / 1023.0);

  float ax = (xVolt - zeroG) / sensitivity;
  float ay = (yVolt - zeroG) / sensitivity;
  float az = (zVolt - zeroG) / sensitivity;

  // Calculate total acceleration (magnitude of vector)
  float totalAccel = sqrt(ax*ax + ay*ay + az*az);

  Serial.print("X: "); Serial.print(ax); Serial.print(" g, ");
  Serial.print("Y: "); Serial.print(ay); Serial.print(" g, ");
  Serial.print("Z: "); Serial.print(az); Serial.print(" g, ");
  Serial.print("Total: "); Serial.print(totalAccel); Serial.println(" g");

  // Detect sudden acceleration
  if (totalAccel > 2.0) {
    Serial.println("⚠️ Sudden acceleration detected!");
  }

  delay(300);
}

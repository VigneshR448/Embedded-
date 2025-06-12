  #include <Servo.h>
Servo Rotate;

void setup() {
  Serial.begin(9600);     
  Rotate.attach(3);
  Serial.println("Enter the Angle (0 to 180):");
}

void loop() {
  if (Serial.available() > 0)
  {
    int angle = Serial.parseInt(); 
    if (angle >= 0 && angle <= 360)
    {
      Rotate.write(angle); 
      Serial.println("Servo moved to angle:");
      Serial.println(angle);
    }
    else {
      Serial.println("Invalid angle! Enter 0 to 180.");
    }
  }
}

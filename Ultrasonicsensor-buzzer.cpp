#define trigPin 9
#define echoPin 10
int buzzerPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  int distance;

  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  if (distance <= 200 && distance > 0) {
    digitalWrite(buzzerPin, HIGH);  
    Serial.println("Object Detected!");
  } else {
    digitalWrite(buzzerPin, LOW);  
    Serial.println("No object nearby.");
  }

  delay(500);
}

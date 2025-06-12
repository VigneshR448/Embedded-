void setup() {
  pinMode(13, OUTPUT);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),prio, LOW);
  attachInterrupt(digitalPinToInterrupt(3),slowb, LOW);
Serial.begin(9600);
}
void loop() {
  Serial.println("Under Normal Process");
  while(1){
digitalWrite(13,HIGH);
Serial.println("Led in On Condition");
delay(2000);
digitalWrite(13,LOW);
Serial.println("Led in Off Condition");
delay(2000);
}
}
void prio(){
  digitalWrite(13,HIGH);
Serial.println("Under High Priority Process");
delay(1000);
}

void slowb(){
  digitalWrite(13,LOW);
Serial.println("Under Low Priority Process");
delay(1000);
}

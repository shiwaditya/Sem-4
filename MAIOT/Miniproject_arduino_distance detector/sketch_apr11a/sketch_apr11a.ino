int trigpin = 8;
int echopin = 7; // set to the pin number you are using for the echo signal

void setup() {
  pinMode(echopin, INPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delay(100);
  digitalWrite(trigpin, HIGH);
  delay(100);
  digitalWrite(trigpin, LOW);
  int echo = digitalRead(echopin);
  int duration = pulseIn(echopin, HIGH);
  float distance = (duration / 2) * 0.0346;
  Serial.print("Distance: ");
  if (distance <= 10) {
    // print distance in millimeters
    Serial.print(distance * 10, 1);
    Serial.println(" mm");
    digitalWrite(2, HIGH);
    tone(2, 220, 100);
  } else {
    // print distance in centimeters
    Serial.print(distance, 1);
    Serial.println(" cm");
    digitalWrite(2, LOW);
  }
}
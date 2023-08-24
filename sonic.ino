const int trigPin = 3; // GPIO 32 (D32)
const int echoPin = 2; // GPIO 33 (D33)
int buzzer = 12;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echoPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {

  float distance = readDistance();
  Serial.println(distance);
  if (distance <= 20.0){
    digitalWrite(buzzer, HIGH); 
    Serial.println("valid");

  }

  else {

    digitalWrite(buzzer, LOW); 
    Serial.println("not valid");
  }

  delay(1000);                      // wait for a second
}
float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

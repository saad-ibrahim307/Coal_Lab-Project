#define trigPin 9
#define echoPin 10

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  // Clear trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance
  distance = duration * 0.034 / 2;

  // Filter bad readings
  if (duration == 0 || distance <= 0 || distance > 200) {
    Serial.println("No object detected");
  } 
  else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(400);
}
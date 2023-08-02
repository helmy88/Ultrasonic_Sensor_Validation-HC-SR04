// HC-SR04 pins
const int trigPin = 2;
const int echoPin = 3;

// Minimum and maximum valid distance readings (in centimeters)
const int minValidDistance = 2;
const int maxValidDistance = 400;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.println("HC-SR04 Sensor Check");
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Calculate the duration of the pulse
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance based on the duration
  float distance_cm = duration * 0.0343 / 2.0;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  // Check sensor status
  if (distance_cm >= minValidDistance && distance_cm <= maxValidDistance) {
    Serial.println("Sensor is good.");
  } else {
    Serial.println("Sensor is not functioning properly.");
  }
  
  delay(1000); // Delay for stability
}

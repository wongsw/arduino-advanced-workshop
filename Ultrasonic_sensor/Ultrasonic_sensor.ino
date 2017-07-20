
/* Ultrasonic sensor demo code for RExPerience '17
 *  Lights up different LEDs based on proximity of object
 *  utilizes ultrasonic sensor HC-SR04
 *  
 *  Based on http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
 *  Modified by Song Wei 7 July 2017
 */
 
#define trigPin 5 // GPIO5
#define echoPin 4 // GPIO4
#define greenLED 12
#define yellowLED 13
#define redLED 0

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  // Printing of distance on Serial Monitor 
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  // LED lighting control
  if (distance < 5) { 
    digitalWrite(redLED, LOW); // Red LED lights up and the rest turn off
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, HIGH);
  }
  else if (distance >= 5 && distance <= 10) {
    digitalWrite(redLED, HIGH); 
    digitalWrite(yellowLED, LOW); // Yellow LED lights up and the rest turn off
    digitalWrite(greenLED, HIGH);
  }
  else {
    digitalWrite(redLED, HIGH); 
    digitalWrite(yellowLED, HIGH); 
    digitalWrite(greenLED, LOW); // Green LED lights up and the rest turn off
  }
  delay(500);
}

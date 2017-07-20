
/* Water level sensor demo code for RExPerience '17
 *  Lights up different LEDs based on water level
 *  utilizes water level sensor for Arduino
 *  
 *  Modified by Song Wei 20 July 2017
 */
 
#define waterSensor A0
#define greenLED 0 // GPIO 0
#define yellowLED 13 // GPIO 13
#define redLED 12 //GPIO 12

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT); 
  pinMode(yellowLED, OUTPUT); 
  pinMode(redLED, OUTPUT); 
}

void loop() {
  int value = analogRead(waterSensor);
  Serial.println(value);
  if (value >= 350) {
    digitalWrite(redLED, HIGH); 
    digitalWrite(yellowLED, HIGH); 
    digitalWrite(greenLED, LOW); // Green LED lights up and the rest turn off
  }
  else if (value < 350 && value > 300) {
    digitalWrite(redLED, HIGH); 
    digitalWrite(yellowLED, LOW); // Yellow LED lights up and the rest turn off
    digitalWrite(greenLED, HIGH);
  }
  else {
    digitalWrite(redLED, LOW); // Red LED lights up and the rest turn off
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, HIGH);
  }
  delay(50);
}

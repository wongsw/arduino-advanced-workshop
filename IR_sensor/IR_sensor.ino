
/* IR sensor demo code for RExPerience '17
 *  Trip sensor alarm that sounds/lights when object passes between IR sensors
 *  utilizes IR Emitter-Receiver, buzzer, LED
 *  
 *  Modified by Song Wei 2 August 2017
 */
 
#define IRreceiver A0 //A0
#define greenLED 13 //GPIO 13
#define redLED 12 //GPIO 12

int val = 0; // define analog variable val 

void setup() {
  Serial.begin(9600);
  pinMode(IRreceiver, INPUT);
  pinMode(greenLED, OUTPUT); 
  pinMode(redLED, OUTPUT);
}

void loop() {
  val = analogRead(IRreceiver); //read analog value assigned to val
  Serial.println(val);
  if (val < 800) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
}

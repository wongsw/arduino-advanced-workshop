/*  LDR sensor demo code for RExPerience '17
 *   Creates a LED circuit that turns on more light when it's darker
 *   utilizes Light Dependent Resistor (LDR) 
 *   
 *   Modified By Song Wei 7 July 2017
 */

#define LDR A0 // A0
#define LED1 0 // GPIO 0
#define LED2 13 // GPIO 13
#define LED3 12 //GPIO 12

int val = 0;  //define analog variable val

void setup() {
  Serial.begin(9600);
  pinMode(LDR, INPUT); 
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  pinMode(LED3, OUTPUT); 
}

void loop() { 
  val = analogRead(LDR); //read the analog value assigned to val 
  Serial.println(val);
  delay(250);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  
  // LED lighting control
  if (val < 80) {
    digitalWrite(LED1, LOW);
    if (val < 70) {
      digitalWrite(LED2, LOW);
      if (val < 30) {
        digitalWrite(LED3, LOW);
      }
    }
  }
}

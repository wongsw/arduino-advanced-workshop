
/* Servo demo code for RExPerience '17
 *  Activates different servo motions with button input 
 *  utilizes Tower Pro Micro Servo SG90
 *  
 *  Based on https://github.com/wemos/D1_mini_Examples/blob/master/examples/02.Special/Servo/Sweep/Sweep.ino
 *  Modified by Song Wei 17 July 2017
 */

#include <Servo.h> 
#define buttonPin 13 // GPIO13 connects to button
Servo myservo;  // create servo object to control a servo
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int pos = 0; //position of the servo output shaft

void setup() {
  //Serial.begin(9600);
  myservo.attach(2);  // attaches the servo on GPIO2 to the servo object as output
  pinMode(buttonPin, INPUT); // initialize button as input 
}

void loop() {
  buttonState = digitalRead(buttonPin); // read the pushbutton input pin (LOW when unpressed, HIGH when pressed)
  //Serial.println(pos);
  if (buttonState != lastButtonState) { // compare the buttonState to its previous state
    if (buttonState == HIGH) { 
      buttonPushCounter++; // if the state has changed, increment the counter
    } 
    delay(50); // Delay a little bit to avoid bouncing
  }
  lastButtonState = buttonState; // save the current state as the last state, for next time through the loop

  // servo movement when pressed once
  if (buttonPushCounter == 1) {
    myservo.write(pos);
    delay(10);
    pos++;
    if (pos > 180) {
      pos = 0;
      myservo.write(pos);
      delay(500);
    }
  }
  
  // servo movement when pressed again 
  else if (buttonPushCounter == 2) {
    pos = 0;
    myservo.write(pos); // returns to initial position
    buttonPushCounter = 0; //resets counter 
  }
}


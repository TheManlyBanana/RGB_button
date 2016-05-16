const int buttonPin = 2; //button with pulldown resistor to digital 2
const int redPin = 9; //red RGB to pin 9
const int greenPin = 10; //green RGB to pin 10
const int bluePin = 11; //blue RGB to pin 11
int buttonState = 0; //button state variable
int colourState = 0; //colour state variable

void setup() {
  Serial.begin(9600); //start serial monitor for testing purposes, ignore when product is finished
  pinMode(buttonPin, INPUT); //button as input
  pinMode(redPin, OUTPUT); //redPin as output
  pinMode(greenPin, OUTPUT); //greenPin as output
  pinMode(bluePin, OUTPUT); //bluePin as output
  digitalWrite(redPin, HIGH); //As the RGB is common cathode, writing the redPin high will turn it off
  digitalWrite(greenPin, HIGH); //As the RGB is common cathode, writing the greenPin high will turn it off
  digitalWrite(bluePin, HIGH); //As the RGB is common cathode, writing the bluePin high will turn it off
}

void loop() {
  buttonState = digitalRead(buttonPin); //set the buttonstate variable to read the button
  if(buttonState == HIGH) { //check for button press
    colourState++; //if button is pressed, add 1 to colour state
    delay(500); //delay of .5 seconds to prevent spam and bad things
    Serial.println(colourState); //print to serial monitor, for testing
  }
  
  if(colourState > 6) { //check for colour state greater than 6
    colourState == 0; //when colours have cycled through, switch back to colour state 0, or off
  }

  if(colourState == 0){ //check for colourState 0
    analogWrite(redPin, 255); //red off
    analogWrite(greenPin, 255); // green off
    analogWrite(bluePin, 255); //blue off
  }
  
  if(colourState == 1){ //check for colourState 1
    analogWrite(redPin, 0); //red on
    analogWrite(greenPin, 255); //green off
    analogWrite(bluePin, 255); //blue off
  }

  if(colourState == 2){ //check for colourState 2
    analogWrite(redPin, 127); //red half
    analogWrite(greenPin, 127); //green half
    analogWrite(bluePin, 255); //blue off
  }
  
  if(colourState == 3){ //check for colourState 3
    analogWrite(redPin, 255); //red off
    analogWrite(greenPin, 0); //blue on
    analogWrite(bluePin, 255); //green off
  }
  
  if(colourState == 4){ //check for colourState 4
    analogWrite(redPin, 255); //red off
    analogWrite(greenPin, 127); //green half
    analogWrite(bluePin, 127); //blue half
  }

  if(colourState == 5){ //check for colourState 5
    analogWrite(redPin, 255); //red off
    analogWrite(greenPin, 255); //green off
    analogWrite(bluePin, 0); //blue off
  }

  if(colourState == 6){ //check for colourState 6
    analogWrite(redPin, 127); //red half
    analogWrite(greenPin, 255); //green off
    analogWrite(bluePin, 127); //blue half
  }
}

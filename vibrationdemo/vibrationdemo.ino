// constants won't change. Used here to
// set pin numbers:
const int ledPin =  13;      // the number of the LED pin
const int vib = 4;
const int freqAnalog = A0;
const int durAnalog = A1;

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
int duration = 1000;
int frequency = 1000;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT); 
  pinMode(vib, OUTPUT);
}

void loop()
{
  int inputValue = analogRead(durAnalog);
  duration = map(inputValue, 0,1023, 100, 2000);
  inputValue = analogRead(freqAnalog);
  frequency = map(inputValue, 0, 1023, 100, 2000);
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > duration && ledState == HIGH) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;  

    // if the LED is off turn it on and vice-versa:

      ledState = LOW;
      
    // set the LED with the ledState of the variable:
      digitalWrite(ledPin, ledState);
      digitalWrite(vib, ledState);  

    
  } else if (currentMillis - previousMillis > frequency && ledState == LOW) {
    previousMillis = currentMillis; 
  
      ledState = HIGH;
    // set the LED with the ledState of the variable:
      digitalWrite(ledPin, ledState);
      digitalWrite(vib, ledState);    
  }
}

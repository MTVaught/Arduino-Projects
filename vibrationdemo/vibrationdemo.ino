int led = 13;

int ledState = LOW;
long previousMillis = 0;

long interval = 1000;

void setup() {
  pinMode(led, OUTPUT);

}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    if (ledState == LOW){
      ledState = HIGH;
    } 
    else {
      ledState = LOW;
    }
  }
  digitalWrite(led, ledState);
}


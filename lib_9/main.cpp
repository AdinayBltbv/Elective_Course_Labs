char degree = 176;
int led = 11;          
int buzzer = 12;       
const int tempSensor = A1; 
const int lightSensor = A0; 
const int potPin = A2; 

void setup() {
  pinMode(tempSensor, INPUT);
  pinMode(lightSensor, INPUT);
  pinMode(potPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int tmp = analogRead(tempSensor);
  float voltage = (tmp * 5.0) / 1024;
  float milliVolt = voltage * 1000;
  float tmpCel = (milliVolt - 500) / 10;

  int lightVal = analogRead(lightSensor);

  int potValue = analogRead(potPin);
  float tempThreshold = map(potValue, 0, 1023, 20, 50);

  if (tmpCel > tempThreshold || lightVal < 300) {
    digitalWrite(led, HIGH);
    tone(buzzer, 1000);  
  } else {
    digitalWrite(led, LOW);
    noTone(buzzer);     
  }

  delay(1000);
}

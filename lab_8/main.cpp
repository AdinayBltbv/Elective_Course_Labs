const int ldrPin = A0;
const int ledPin = 9;
const int buzzerPin = 10;
const int buttonPin = 11;

bool isMuted = false;
int lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin);
  int currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    isMuted = !isMuted;
  }

  lastButtonState = currentButtonState;

  if (lightValue < 400) {
    digitalWrite(ledPin, HIGH);
    if (!isMuted) {
      tone(buzzerPin, 1000);
    } else {
      noTone(buzzerPin);
    }
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(200);
}

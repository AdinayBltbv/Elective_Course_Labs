const int led_red = 7;
const int led_yellow = 6;
const int led_green = 5;

int buttonStart = 12;
int buttonStop  = 13;

bool running = false; 

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
  
  pinMode(buttonStart, INPUT_PULLUP);
  pinMode(buttonStop, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonStart) == LOW) {
    running = true;
  }

  if (digitalRead(buttonStop) == LOW) {
    running = false;
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);
  }

  if (running) {
    digitalWrite(led_red, HIGH);
    delay(3000);

    if (!running) return;

    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, HIGH);
    delay(1000);

    if (!running) return;

    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, HIGH);
    delay(3000);

    if (!running) return;

    digitalWrite(led_green, LOW);
  }
}

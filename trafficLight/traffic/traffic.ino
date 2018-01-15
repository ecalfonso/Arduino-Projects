#define RED_LIGHT_PIN 13
#define YEL_LIGHT_PIN 12
#define GRE_LIGHT_PIN 11
#define BUTTON_LIGHT_PIN 10
#define BUTTON_PIN 9

int lightState = 0;

void setup() {
  // Set PINs
  pinMode(RED_LIGHT_PIN, OUTPUT);
  pinMode(YEL_LIGHT_PIN, OUTPUT);
  pinMode(GRE_LIGHT_PIN, OUTPUT);
  pinMode(BUTTON_LIGHT_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  // Set Lights
  digitalWrite(RED_LIGHT_PIN, HIGH);
  digitalWrite(YEL_LIGHT_PIN, LOW);
  digitalWrite(GRE_LIGHT_PIN, LOW);
  digitalWrite(BUTTON_LIGHT_PIN, LOW);

  
}

void lightSwitch(uint8_t red, uint8_t yellow, uint8_t green) {
  digitalWrite(RED_LIGHT_PIN, red);
  digitalWrite(YEL_LIGHT_PIN, yellow);
  digitalWrite(GRE_LIGHT_PIN, green);
}

void redLight() {
  lightSwitch(HIGH, LOW, LOW);
}

void yellowLight() {
  lightSwitch(LOW, HIGH, LOW);
}

void greenLight() {
  lightSwitch(LOW, LOW, HIGH);
}

void turnRedLight(){
  yellowLight();
  delay(2500);
  redLight();
}

void turnGreenLight(){
  yellowLight();
  delay(2500);
  greenLight();
}

void loop() {
  turnGreenLight();
  delay(5000);
  turnRedLight();
  delay(5000);
}

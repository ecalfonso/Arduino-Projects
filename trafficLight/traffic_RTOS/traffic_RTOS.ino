#include <Arduino_FreeRTOS.h>

#define RED_LIGHT_PIN 13
#define YEL_LIGHT_PIN 12
#define GRE_LIGHT_PIN 11

#define BUTTON_LIGHT_PIN 10
#define BUTTON_PIN 2

volatile byte BUTTON_LIGHT_STATE = LOW;

// Define Tasks
void TaskBlinkLights( void *pvParameters );

void setup() {
  pinMode(BUTTON_PIN,INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonLightInt, RISING);

  interrupts();
  
  xTaskCreate(
    TaskBlinkLights,
    (const portCHAR *) "Blink",
    128,
    NULL,
    2,
    NULL);
}

void loop() {
  // Empty
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
  vTaskDelay( 5000 / portTICK_PERIOD_MS ); // wait for 5 seconds
  redLight();
}

void turnGreenLight(){
  yellowLight();
  vTaskDelay( 5000 / portTICK_PERIOD_MS ); // wait for 5 seconds
  greenLight();
  interrupts();
}

void TaskBlinkLights(void *pvParameters) {
  (void) pvParameters;

  // Setup PINs
  pinMode(RED_LIGHT_PIN, OUTPUT);
  pinMode(YEL_LIGHT_PIN, OUTPUT);
  pinMode(GRE_LIGHT_PIN, OUTPUT);

  greenLight();

  for (;;) {
    vTaskDelay( 5000 / portTICK_PERIOD_MS ); // wait for 2.5 seconds

    if (BUTTON_LIGHT_STATE == HIGH) {
      turnRedLight();
      vTaskDelay( 10000 / portTICK_PERIOD_MS ); // wait for 5 seconds
      turnGreenLight();
      BUTTON_LIGHT_STATE = LOW;
      digitalWrite(BUTTON_LIGHT_PIN, BUTTON_LIGHT_STATE);
    }
  }
}

void buttonLightInt() {
  noInterrupts();
  BUTTON_LIGHT_STATE = HIGH;
  digitalWrite(BUTTON_LIGHT_PIN, BUTTON_LIGHT_STATE);
}

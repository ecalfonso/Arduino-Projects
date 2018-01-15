#include <Arduino_FreeRTOS.h>
#include <SoftwareSerial.h>

#define SW1 2
#define SW2 3
#define SW3 4

#define LED1 11
#define LED2 12
#define LED3 13

/*
 * Define tasks
 */

TaskHandle_t xTaskArduinoIsOn = NULL;
TaskHandle_t xTaskBlinkLED1 = NULL;
TaskHandle_t xTaskBlinkLED2 = NULL;

void vTaskArduinoIsOn (void *pvParamters);
void vTaskBlinkLED1 (void *pvParameters);
void vTaskBlinkLED2 (void *pvParameters);

/*
 * Setup Bluetooth
 */

SoftwareSerial BT (9, 8);

void setupBT() {
  BT.begin(9600);
  delay(1500);

  BT.println("Bluetooth up");
}

/*
 * Setup Call
 */

void setup() {
  // Setup Serial for debugging
  Serial.begin(9600);
  Serial.println("Setup function");

  // Setup Bluetooth
  setupBT();
  
  // Setup LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.println("Setup LEDs");

  // Setup Switches
  pinMode(SW1, INPUT);
  attachInterrupt(digitalPinToInterrupt(SW1), sw1Int, RISING);
  pinMode(SW2, INPUT);
  attachInterrupt(digitalPinToInterrupt(SW2), sw2Int, RISING);
  pinMode(SW3, INPUT);
  Serial.println("Setup Switches");

  interrupts();
  Serial.println("Enabled Interrupts");

  // Create Tasks
  xTaskCreate(vTaskArduinoIsOn, "System On", 512, NULL, 1, &xTaskArduinoIsOn);
  Serial.println("Created Tasks");

  // Start FreeRTOS Scheduler
  vTaskStartScheduler();
  Serial.println("Started Scheduler");
}

void loop() 
{
  // Empty
}

/*
 * Tasks
 */

void vTaskArduinoIsOn(void *pvParameters) {
  (void) pvParameters;

  // LED3 will blink infinitely designating the machine is on
  for (;;) {
    Serial.println("Red LED loop");
    digitalWrite(LED3, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay(pdMS_TO_TICKS(1000)); // wait for one second
    digitalWrite(LED3, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay(pdMS_TO_TICKS(1000)); // wait for one second

    //xTaskCreate(vTaskBlinkLED1, "Blink LED 1", 512, NULL, 2, &xTaskBlinkLED1);
    //xTaskCreate(vTaskBlinkLED2, "Blink LED 1", 512, NULL, 2, &xTaskBlinkLED2);
  }
}

void vTaskBlinkLED1(void *pvParameters) {
  Serial.println("LED1 Task");
  digitalWrite(LED1, HIGH);
  vTaskDelay(pdMS_TO_TICKS(5000)); // wait for 5 second
  digitalWrite(LED1, LOW);

  // Destroy current task after execution
  vTaskDelete(vTaskBlinkLED1);
}

void vTaskBlinkLED2(void *pvParameters) {
  Serial.println("LED2 Task");
  digitalWrite(LED2, HIGH);
  vTaskDelay(pdMS_TO_TICKS(5000)); // wait for 5 second
  digitalWrite(LED2, LOW);

  // Destroy current task after execution
  vTaskDelete(vTaskBlinkLED2);
}

// Interrupt Functions

void sw1Int() {
  Serial.println("SW1 Int");
  BT.println("SW1 Pressed");
}

void sw2Int() {
  Serial.println("SW2 Int");
  BT.println("SW2 Pressed");
}


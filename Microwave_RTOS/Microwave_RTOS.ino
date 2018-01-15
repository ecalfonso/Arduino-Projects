#include <Arduino_FreeRTOS.h>

#define LED_PIN         13
#define BUZZER_PIN      8

#define START_SW        2  
#define TIME_SW         3
#define EXTRA_SW        4

#define IDLE_ST         0
#define ON_ST           1
#define PAUSE_ST        2

volatile int STATE = IDLE_ST;
volatile int TIME = 0;

/*
 * Setup Routine
 */

void setup() {
  //Setup LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Setup Switches
  pinMode(START_SW, INPUT);
  attachInterrupt(digitalPinToInterrupt(START_SW), startSwitchInt, RISING);
  
  pinMode(TIME_SW, INPUT);
  attachInterrupt(digitalPinToInterrupt(TIME_SW), timeSwitchInt, RISING);

  pinMode(EXTRA_SW, INPUT);

  // Create Microwave Task
  xTaskCreate(
    TaskMicrowave,
    (const portCHAR *) "Microwaving",
    128,
    NULL,
    2,
    NULL);
  
  // Turn on Interrupts
  interrupts();
}

void loop() {
  // Do nothing
}

/*
 * FreeRTOS Tasks
 */

void TaskMicrowave(void *pvParameters) {
  (void) pvParameters;

  
}

/*
 * Interrupt Routines
 */
 
void startSwitchInt() {
  noInterrupts();
  tone(8, 1000);
/*
  switch(STATE) {
    case IDLE_ST:

      break;
    case ON_ST:

      break;
    case PAUSE_ST:

      break;
  }
  */
  interrupts();
}

void timeSwitchInt() {
  noInterrupts();
  if (TIME < 15)
    TIME += 5;
  interrupts();
}


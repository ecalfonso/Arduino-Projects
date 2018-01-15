const int sensorPin = A0;
const float baseline = 20.0;

void setup() {
  Serial.begin(9600);
  
  // Set Output pins
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  // Set pins to low
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
  // Read TMP Sensor
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Val: ");
  Serial.print(sensorVal);
  Serial.print('\n');
  
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print('\n');
  
  float temp = (voltage -.5) * 100;
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print('\n');
  
  delay(3000); // Delay 250 ms
}

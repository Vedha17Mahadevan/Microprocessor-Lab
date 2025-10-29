int potPin = A0;           
int adc = 0;      
float voltage = 0.0; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  adc = analogRead(potPin);          
  voltage = adc * (3.3 / 4095.0);        

  Serial.print("Analog Value: ");
  Serial.print(adc);
  Serial.print("  |  Voltage: ");
  Serial.print(voltage, 2);
  Serial.print("V");
  Serial.println("");
  delay(200);
}

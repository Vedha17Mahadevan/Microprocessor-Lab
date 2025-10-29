int potPin = A0;     
int ledPin = 9;      
int adc = 0;    
int brightness = 0;  
float voltage = 0.0; 

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Potentiometer-controlled LED Brightness");
}

void loop() {
  adc = analogRead(potPin);          
  voltage = adc * (3.3 / 4095.0);        
  brightness = map(adc, 0, 4095, 0, 255);

  analogWrite(ledPin, brightness);           
=
  Serial.print("Analog Value: ");
  Serial.print(adc);
  Serial.print("  |  Voltage: ");
  Serial.print(voltage, 2);
  Serial.print("V  |  Brightness (PWM): ");
  Serial.println(brightness);

  delay(200); 
}

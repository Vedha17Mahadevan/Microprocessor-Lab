#define ledpin 8
#define switchpin 7

void setup() {
  Serial.begin(115200);
  pinMode(ledpin, OUTPUT);
  pinMode(switchpin, INPUT);
}

void loop() {
  if(digitalRead(switchpin)==LOW){    //Switch -> active low!!
    digitalWrite(ledpin, HIGH);
  }
  else{
    digitalWrite(ledpin, LOW);
  }
}

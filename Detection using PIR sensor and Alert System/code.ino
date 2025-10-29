#define ledpin 2
#define pir 8

void setup(){
  Serial.begin(115200);
  pinMode(ledpin, OUTPUT);
  pinMode(pir, INPUT);
}

void loop(){
  if(digitalRead(pir)==HIGH){
    digitalWrite(ledpin, HIGH);
  }else{
    digitalWrite(ledpin,LOW);
  }
}

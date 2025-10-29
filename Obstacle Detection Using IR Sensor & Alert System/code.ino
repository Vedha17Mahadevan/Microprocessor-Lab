#define ir 2
#define buzz 8

void setup(){
  Serial.begin(115200);
  pinMode(ir, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop(){
  if(digitalRead(ir)==LOW){
	digitalWrite(buzz, HIGH);
  }
  else{
    digitalWrite(buzz, LOW);
  }
}

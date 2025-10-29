#define trig 10
#define echo 9

void setup(){
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
  long duration;
  float distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delay(100);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration*0.034)/2;
  Serial.print("Distance : ");
  Serial.print(distance);
  
  if (distance >0 && distance <=20){
    Serial.println("UNSAFE");
  }
  else{
    Serial.println("SAFE");
  }
}

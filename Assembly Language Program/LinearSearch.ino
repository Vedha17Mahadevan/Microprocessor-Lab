void setup() {
  Serial.begin(115200);
  Serial.println("Linear Search");
  delay(1000);
  int16_t arr[] = {0x01, 0x45, 0x78, 0x23, 0x96};
  int len = 5;
  int16_t key = 0x45;
  int flag;
  int index;

  asm volatile(
    "mv t0, %4\n"   //key
    "li t1, 0\n"    //index=0
    "mv t2, %2\n"   //arr
    "mv t3, %3\n"   //len
    "li t4, 0\n"    //flag=0
    
    "Search:\n"    //search loop
    "beq t1, t3, end\n"    //loop end index==len => end
    "lh t5, 0(t2)\n"     
    "addi t2, t2, 2\n"
    "addi t1, t1, 1\n"
    "beq t5, t0, l1\n"    //if element in array, go to Loop l1, else continue search
    "j Search\n"
    
    "l1:\n"
    "li t4, 1\n"
    
    "end:\n"
    "mv %0, t4\n"
    "mv %1, t1\n"
    
    :"=r"(flag), "=r"(index)
    :"r"(arr), "r"(len), "r"(key)
  );
  if(flag==1){
    Serial.println("Element 0x45 found at index: ");
    Serial.print(index);
  }
  else{
    Serial.println("Element NOT Found!!");
  }
}

void loop() {
}

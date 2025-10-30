void setup(){
  Serial.begin(115200);
  delay(1000);
  int32_t num=97;
  int flag;

  asm volatile(
    "mv t0, %1\n"   //load number
    "li t1, 1\n"    //flag=1
    "li t2, 2\n"

    "blt t0, t2,notPrime\n"   //numb < 2 => NOT PRIME
    "beq t0, t2, Prime\n"     //numb = 2 => PRIME
    
    "rem t3, t0, t2\n"        // if divisible by 2 => NOT PRIME
    "beq t3, zero, notPrime\n"

    "li t4, 3\n"
    "CheckLoop:\n"
    "mul t5, t4, t4\n"
    "bgtu t5, t0, Prime\n"
    "rem t6, t0, t4\n"
    "beq t6, zero, notPrime\n"
    "addi t4, t4, 2\n"
    "j CheckLoop\n"

    "notPrime:\n"
    "li t1, 0\n"

    "Prime:\n"
    "mv %0, t1\n"

    :"=r"(flag)
    :"r"(num)
    :"t0", "t1", "t2", "t3", "t4", "t5", "t6"
  );
  if(flag==1){
    Serial.println("Number is Prime");
  }
  else{
    Serial.println("Number is NOT Prime");
  }
}
void loop(){}

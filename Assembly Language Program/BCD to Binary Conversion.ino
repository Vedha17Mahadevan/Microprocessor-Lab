void setup() {
  Serial.begin(115200);
  int8_t result;
  Serial.println("Conversion : BCD to BINARY");
  asm volatile(
    "li a0, 0x25\n"         //load BCD Number
    "andi a1, a0, 0x0F\n"   //LSD
    "andi a2, a0, 0xF0\n"   // MSD
    "srli a3, a2, 4\n"      //Logical Immediate RIGHT shift the MSD
    "li t0, 10\n"
    "mul a4, a3, t0\n"
    "add a5, a4, a1\n"
    "mv %0, a5\n"
    :"=r"(result)
  );
  Serial.print("BCD to Binary of 0x25 : ");
  Serial.print(result);
}

void loop() {
}

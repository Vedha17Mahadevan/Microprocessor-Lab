void setup() {

  Serial.begin(115200);
  int32_t a;
  Serial.println("Addition");
  asm volatile(
    "li a1, 12345678\n"
    "li a2,87654321\n"
    "sub a3, a2, a1\n"
    "mv %0, a3\n"
    :"=r"(a)
  );
  Serial.print("Sum : ");
  Serial.print(a);
}

void loop() {
}

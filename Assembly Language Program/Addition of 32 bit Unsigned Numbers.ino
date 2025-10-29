void setup() {
  Serial.begin(115200);
  int32_t a;
  Serial.println("Addition");
  asm volatile(
    "li a1, 12345678\n"
    "li a2,87654321\n"
    "add a3, a1, a2\n"
    "mv %0, a3\n"
    :"=r"(a)
  );
  Serial.print("Sum : ");
  Serial.print(a);
}

void loop() {
}

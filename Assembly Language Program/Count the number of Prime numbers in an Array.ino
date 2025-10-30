void setup() {
  Serial.begin(115200);
  delay(1000);

  int32_t arr[] = {2, 3, 4, 5, 9, 11, 13, 15, 17};
  int len = sizeof(arr) / sizeof(arr[0]);
  int flag;
  int primeCount = 0;

  for (int i = 0; i < len; i++) {
    int32_t num = arr[i];

    asm volatile(
      "mv t0, %1\n"        // load number
      "li t1, 1\n"         // assume prime
      "li t2, 2\n"

      "blt t0, t2, notPrime\n"  // num < 2 → not prime
      "beq t0, t2, Prime\n"     // num == 2 → prime

      "rem t3, t0, t2\n"
      "beq t3, zero, notPrime\n"  // divisible by 2 → not prime

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

      : "=r"(flag)
      : "r"(num)
      : "t0", "t1", "t2", "t3", "t4", "t5", "t6"
    );

    if (flag == 1) {
      primeCount++;
      Serial.print(num);
      Serial.println(" is Prime");
    } else {
      Serial.print(num);
      Serial.println(" is NOT Prime");
    }
  }

  Serial.print("Total Prime Numbers = ");
  Serial.println(primeCount);
}

void loop() {}

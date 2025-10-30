void setup() {
  Serial.begin(115200);
  delay(1000);

  int16_t arr[] = {10, 20, 30};
  int len = sizeof(arr) / sizeof(arr[0]);
  int16_t sum = 0;

  asm volatile(
    "mv t0, %1\n"        // t0 = base address of array
    "mv t1, zero\n"      // t1 = sum = 0
    "mv t2, %2\n"        // t2 = length (counter)
    "mv t3, zero\n"      // t3 = index = 0

    "loop:\n"
    "lh t4, 0(t0)\n"
    "add t1, t1, t4\n"
    "addi t0, t0, 2\n"
    "addi t3, t3, 1\n"
    "blt t3, t2, loop\n"

    "done:\n"
    "mv %0, t1\n"        // move sum → C variable

    : "=r"(sum)           // output
    : "r"(arr), "r"(len)  // inputs
    : "t0", "t1", "t2", "t3","a0"  // clobbered registers
  );

  Serial.print("Sum of array elements = ");
  Serial.println(sum);
}

void loop() {}

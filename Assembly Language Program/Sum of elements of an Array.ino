void setup() {
  Serial.begin(115200);
  delay(1000);

  int32_t arr[] = {10, 20, 30, 40, 50};
  int len = sizeof(arr) / sizeof(arr[0]);
  int32_t sum = 0;

  asm volatile(
    "mv t0, %1\n"        // t0 = base address of array
    "mv t1, zero\n"      // t1 = sum = 0
    "mv t2, %2\n"        // t2 = length (counter)
    "mv t3, zero\n"      // t3 = index = 0

    "loop:\n"
    "beq t3, t2, done\n" // if index == len → done
    "slli t4, t3, 2\n"   // offset = index * 4 (since int = 4 bytes)
    "add t5, t0, t4\n"   // address = base + offset
    "lw t6, 0(t5)\n"     // load arr[index]
    "add t1, t1, t6\n"   // sum += arr[index]
    "addi t3, t3, 1\n"   // index++
    "j loop\n"

    "done:\n"
    "mv %0, t1\n"        // move sum → C variable

    : "=r"(sum)           // output
    : "r"(arr), "r"(len)  // inputs
    : "t0", "t1", "t2", "t3", "t4", "t5", "t6"  // clobbered registers
  );

  Serial.print("Sum of array elements = ");
  Serial.println(sum);
}

void loop() {}

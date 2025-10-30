void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("-- FIND SMALLEST NUMBER IN ARRAY --");

  // Array of 16-bit unsigned elements
  uint16_t arr[] = {0x10, 0x20, 0x45, 0x05, 0x60};
  int smallest;

  asm volatile(
    "li t1, 1\n"          // t1 = index = 1 (start from 2nd element)
    "li t2, 5\n"          // t2 = size = 5
    "mv t3, %1\n"         // t3 = pointer to array base address
    "lh a0, 0(t3)\n"      // a0 = arr[0] → current smallest
    "addi t3, t3, 2\n"    // move pointer to next element

    "Loop:\n"
    "lh t5, 0(t3)\n"      // load arr[index]
    "bge t5, a0, skip\n"  // if arr[index] >= smallest → skip
    "mv a0, t5\n"         // else update smallest = arr[index]
    "skip:\n"
    "addi t3, t3, 2\n"    // pointer → next element (2 bytes)
    "addi t1, t1, 1\n"    // index++
    "blt t1, t2, Loop\n"  // loop while index < size

    "mv %0, a0\n"         // move result into C variable

    : "=r"(smallest)      // output
    : "r"(arr)            // input
    : "t1", "t2", "t3", "t5", "a0" // clobbered regs
  );

  Serial.print("Smallest: 0x");
  Serial.println(smallest, HEX);
}

void loop() {
  // Empty loop
}

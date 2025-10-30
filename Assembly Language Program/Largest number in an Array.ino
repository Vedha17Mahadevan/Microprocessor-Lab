void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("-- FIND LARGEST NUMBER IN ARRAY --");

  // Array of 16-bit unsigned elements
  uint16_t arr[] = {0x10, 0x20, 0x45, 0x55, 0x60};
  int largest;

  asm volatile(
    "li t1, 1\n"          // t1 = index = 1 (start from 2nd element)
    "li t2, 5\n"          // t2 = size = 5
    "mv t3, %1\n"         // t3 = base address of array
    "lh t4, 0(t3)\n"      // t4 = arr[0], assume first element is largest

    "loop:\n"
    "beq t1, t2, done\n"  // if index == size -> done
    "slli t5, t1, 1\n"    // offset = index * 2 (since 16-bit)
    "add t6, t3, t5\n"    // address = base + offset
    "lh t7, 0(t6)\n"      // t7 = arr[index]
    "ble t7, t4, skip\n"  // if arr[index] <= current largest -> skip
    "mv t4, t7\n"         // else update largest = arr[index]

    "skip:\n"
    "addi t1, t1, 1\n"    // index++
    "j loop\n"

    "done:\n"
    "mv %0, t4\n"         // move result into C variable

    : "=r"(largest)       // output
    : "r"(arr)            // input
    : "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"  // clobbered regs
  );

  Serial.print("Largest: 0x");
  Serial.println(largest, HEX);
}

void loop() {
  // Empty loop
}

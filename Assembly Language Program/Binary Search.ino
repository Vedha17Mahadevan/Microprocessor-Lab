void setup() {
  Serial.begin(115200);
  delay(1000);

  int16_t arr[] = {10, 20, 30, 40, 50, 60};
  int len = 6;
  int key = 40;
  int index;

  asm volatile(
    "mv t0, %1\n"      // t0 = arr
    "mv t1, %2\n"      // t1 = len
    "mv a0, %3\n"      // a0 = key
    "li t4, -1\n"      // t4 = result (init to -1)
    "li t5, 0\n"       // t5 = low = 0
    "addi t6, t1, -1\n"// t6 = high = len - 1

    "loop:\n"
    "bgt t5, t6, end\n"   // if low > high → end
    "add t7, t5, t6\n"    // t7 = low + high
    "srai t7, t7, 1\n"    // t7 = mid = (low + high)/2

    "slli a1, t7, 1\n"    // offset = mid * 2 (for int16_t)
    "add a1, a1, t0\n"    // address = arr + offset
    "lh a2, 0(a1)\n"      // a2 = arr[mid]

    "beq a2, a0, found\n" // if arr[mid] == key → found
    "blt a2, a0, right\n" // if arr[mid] < key → search right
    "addi t6, t7, -1\n"   // else high = mid - 1
    "j loop\n"

    "right:\n"
    "addi t5, t7, 1\n"    // low = mid + 1
    "j loop\n"

    "found:\n"
    "mv t4, t7\n"         // save index
    "j end\n"

    "end:\n"
    "mv %0, t4\n"         // output result

    : "=r"(index)
    : "r"(arr), "r"(len), "r"(key)
    : "t0","t1","t4","t5","t6","t7","a0","a1","a2"
  );

  if (index >= 0) {
    Serial.print("Found key ");
    Serial.print(key);
    Serial.print(" at index ");
    Serial.println(index);
  } else {
    Serial.print("Key ");
    Serial.print(key);
    Serial.println(" not found");
  }
}

void loop() {}

void setup() {
  Serial.begin(9600);
  delay(1000);

  int num = 13;          // Number to check
  int count = 0;         // To store the number of 1s

  asm volatile (
    "mv t0, %[num]\n"     // t0 = num
    "li t1, 0\n"          // t1 = count

    "count_loop:\n"
    "beq t0, zero, end_count\n" // if num == 0, exit loop

    "andi t2, t0, 1\n"     // t2 = t0 & 1
    "add t1, t1, t2\n"     // count += (t0 & 1)

    "srli t0, t0, 1\n"     // t0 = t0 >> 1
    "j count_loop\n"

    "end_count:\n"
    "mv %[res], t1\n"      // move result to output variable
    : [res] "=r" (count)
    : [num] "r" (num)
    : "t0", "t1", "t2"
  );

  Serial.print("Number of 1s in ");
  Serial.print(num);
  Serial.print(" = ");
  Serial.println(count);
}

void loop() {
  // Do nothing
}

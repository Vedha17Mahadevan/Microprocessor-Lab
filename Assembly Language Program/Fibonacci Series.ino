#define MAX 10  // Number of Fibonacci numbers
int fib[MAX];
void setup() {
  Serial.begin(9600);
  delay(1000); // Give time for Serial monitor to open

  asm volatile (
    "li t0, 0\n"              // t0 = a = 0
    "li t1, 1\n"              // t1 = b = 1
    "li t2, 0\n"              // t2 = index = 0

    "fib_loop:\n"
    "bge t2, %[max], done\n" // if index >= MAX, exit loop

    // Store t0 (current Fibonacci value) into fib[t2]
    "slli t3, t2, 2\n"        // t3 = index * 4 (byte offset)
    "la t4, %[array]\n"       // t4 = base address of array
    "add t4, t4, t3\n"        // t4 = &fib[index]
    "sw t0, 0(t4)\n"          // store t0 into fib[index]

    // Fibonacci logic
    "add t5, t0, t1\n"        // t5 = a + b
    "mv t0, t1\n"             // a = b
    "mv t1, t5\n"             // b = t5

    "addi t2, t2, 1\n"        // index++
    "j fib_loop\n"

    "done:\n"
    :
    : [array] "r" (fib), [max] "i" (MAX)
    : "t0", "t1", "t2", "t3", "t4", "t5"
  );
  // Print the series
  Serial.println("Fibonacci series:");
  for (int i = 0; i < MAX; i++) {
    Serial.println(fib[i]);
  }
}

void loop() {
  // Do nothing
}


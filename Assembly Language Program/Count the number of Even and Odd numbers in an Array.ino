void setup(){
	Serial.begin(115200);
	delay(1000);
	
	int16_t arr[] = {1, 2, 3, 4, 5, 6};
	int len = 6;
	int even;
	int odd;
	asm volatile(
	"mv t0, %2\n" 	//arr
	"mv t1, %3\n" 	//len
	"li t2, 0\n"	//ind
	"li t3, 0\n"	//eve
	"li t4, 0\n"	//odd
	
	"loop:\n"
	"beq t2, t1, end\n"
	"slli t5, t2, 1\n"
	"add t6, t5, t0\n"
	"lh t7, 0(t6)\n"
	"li a0, 2\n"
	"rem a1, t7, a0\n"
	"beq a1, zero, even\n"
	"addi t4, t4, 1\n"
	"j next\n"
	
	"even:\n"
	"addi t3, t3, 1\n"
	
	"next:\n"
	"addi t2, t2, 1\n"
	"j loop\n"

	"end:\n"
	"mv %0, t3\n"
	"mv %1, t4\n"
	
	:"=r"(even), "=r"(odd)
	:"r"(arr), "r"(len)
	:"t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "a0", "a1"
);
  Serial.print("Even count = ");
  Serial.println(even);
  Serial.print("Odd count = ");
  Serial.println(odd);
}

void loop() {
  // Empty loop
}

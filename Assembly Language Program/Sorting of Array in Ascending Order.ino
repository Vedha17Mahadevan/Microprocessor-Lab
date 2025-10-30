void setup(){

	delay(1000);
	Serial.begin(115200);
	int16_t arr[] = {0x23, 0x05, 0x17, 0x89, 0x01, 0x45, 0x32, 0x08, 0x13, 0x02};
	int len = 10;
	Serial.println("Original Array : ");
	for(int i=0; i<10; i++){
		Serial.print(arr[i], HEX);
    Serial.print(" ");
	}
	asm volatile(
		"mv t0, %0\n"
		"mv t1, %1\n"
		"li t2, 0\n"
		"addi t1, t1, -1\n"
		
		"1:\n"
		"li t3, 0\n"
		"sub t4, t1, t2\n"
		
		"2:\n"
		"slli t5, t3, 1\n"
		"add t6, t5, t0\n"
		"lh a0, 0(t6)\n"
		"lh a1, 2(t6)\n"
		"ble a0, a1, 3f\n"
		
		"sh a1, 0(t6)\n"
		"sh a0, 2(t6)\n"

		"3:\n"
		"addi t3, t3, 1\n"
		"blt t3, t4, 2b\n"
		"addi t2, t2, 1\n"
		"blt t2, t1, 1b\n"
		
		:
		:"r"(arr), "r"(len)
		:"t0", "t1", "t2", "t3", "t4", "t5", "t6", "a0", "a1"
	);
	Serial.println(" ");
	Serial.println("Sorted Array : ");
	for(int i=0; i<10; i++){
		Serial.print(arr[i], HEX);
    Serial.print(" ");
	}
}

void loop(){}

void setup(){
	int8_t result;
	Serial.println("Binary to BCD : Conversion");
	Serial.begin(115200);
	asm volatile(
		"li a0, 0xFE\n"    //load the number
		"li a1, 0x64\n"    //load 100
		"li a2, 0x0A\n"    //load 10
		"div a3, a0, a1\n"
		"rem a4, a0, a1\n"
		"div a5, a4, a2\n"
		"rem a6, a4, a2\n"
		"slli a3, a3, 8\n"
		"slli a5, a5, 4\n"
		"add a7, a3, a5\n"
		"add a7, a7, a6\n"
		"mv %0, a7\n"
		:"=r"(result)
	);
	Serial.println("Binary to BCD for 0xFE: ");
	Serial.print(result, HEX);
}

void loop(){}

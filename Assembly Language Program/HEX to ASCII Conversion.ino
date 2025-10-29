void setup(){
	int8_t result;
	Serial.begin(115200);
	Serial.println("HEX to ASCII : Conversion");
	asm volatile(
		"li a0, 0x09\n"    //load number
		"li a1, 0x0A\n"    //oad 10
		"blt a0, a1, l1\n"  
		"addi a2, a0, 0x37\n"    //execute for number > 10
		"j result1\n"
		"l1: addi a2, a0, 0x30\n"    //execute for number < 10
		"result1: mv %0, a2\n"
		:"=r"(result)
	);
	Serial.println("HEX to ASCII for 0x09 : ");
	Serial.print(result, HEX);
}
void loop(){}

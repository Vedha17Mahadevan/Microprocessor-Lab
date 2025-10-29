void setup(){
	int8_t result;
	Serial.begin(115200);
	Serial.println("ASCII to HEX : Conversion");
	asm volatile(
		"li a0, 0x41\n"    //load number
		"li a1, 0x0A\n"    //load 10 for comparison
		"li a2, 0x30\n"  //load 30 for subtraction
    "li a3, 0x07\n"  //load 7 for subtraction
    "sub a4, a0, a2\n"
    "blt a4, a1, l1\n"
    "sub a4,a4, a3\n"
    "j result1\n"
    "l1: mv %0, a4"
    "result1: mv %0, a4\n"
    :"=r"(result)
	);
	Serial.println("ASCII to HEX for 0x41 : ");
	Serial.print(result, HEX);
}
void loop(){}

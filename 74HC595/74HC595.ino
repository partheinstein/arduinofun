// 74HC595 shift register
// based on shiftOut tutorial

int dataPin = 7;
int latchPin = 8; 
int clockPin = 9;

void setup() {
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
}

void loop() {
	digitalWrite(clockPin, LOW);
	for (int i = 0; i < 256; i++) {
		digitalWrite(latchPin, LOW);
		shiftOut(dataPin, clockPin, MSBFIRST, i);
		digitalWrite(latchPin, HIGH);
		delay(500);				
   }                                                                                                                                               
}

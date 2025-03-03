// 74HC595 shift register
// based on shiftOut tutorial

const int dataPin = 7;
const int latchPin = 8; 
const int clockPin = 9;

const int d1 = 3;
const int d2 = 4;
const int d3 = 5;
const int d4 = 6;
int dPins[4] = {d1, d2, d3, d4};

unsigned char segments[10] = {0b00000001, // 0
															0b01001111, // 1
															0b00010010,
															0b00000110,
															0b01001100,
															0b00100100,
															0b00100000,
															0b00001111,
															0b00000000,
															0b00001100}; // 9

void setup() {
	//4 digit 7 segment display
	pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
	pinMode(d3, OUTPUT);
	pinMode(d4, OUTPUT);
	
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
}

void loop() {
	display4(109);
	/* for(int i=0;i<9999;i++) { */
	/* 	display4(i); */
	/* 	delay(100); */
	/* } */
}

void display1(int dPin, int num) {
	switch(dPin) {
	case d1:
		digitalWrite(d1, HIGH);
		digitalWrite(d2, LOW);
		digitalWrite(d3, LOW);
		digitalWrite(d4, LOW);
		break;
	case d2:
		digitalWrite(d1, LOW);
		digitalWrite(d2, HIGH);
		digitalWrite(d3, LOW);
		digitalWrite(d4, LOW);
		break;
	case d3:
		digitalWrite(d1, LOW);
		digitalWrite(d2, LOW);
		digitalWrite(d3, HIGH);
		digitalWrite(d4, LOW);
		break;
	case d4:
		digitalWrite(d1, LOW);
		digitalWrite(d2, LOW);
		digitalWrite(d3, LOW);
		digitalWrite(d4, HIGH);
		break;
	}

	if (num < 0 || num > 9) {
		return;
	}

	char toDisplay = segments[num];	
	digitalWrite(clockPin, LOW);
	digitalWrite(latchPin, LOW);	
	shiftOut(dataPin, clockPin, LSBFIRST, toDisplay);
	digitalWrite(latchPin, HIGH);                            
	
	return;
}

int display4(int num) {
	if (num < 0 || num > 9999) {
		return;
	}

	int divisor = 1000;
	int q, r = 0;
	for (int i = 0; i < 4; i++) {
		q = num / divisor;
		r = num % divisor;
		display1(dPins[i], q);
		delay(5);
		divisor /= 10;
		num = r;
	}
}

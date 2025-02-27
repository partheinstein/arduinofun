const int d1 = 7;
const int d2 = 10;
const int d3 = 11;
const int d4 = 5;
int A = 8;
int B = 12;
int C = 3;
int D = 2;
int E = 13;
int F = 9;
int G = 4;

// HIGH = 1 = segment light off
// LOW = 0 = segment light on

unsigned char segments[10] = {0b00000001,
															0b01001111,
															0b00010010,
															0b00000110,
															0b01001100,
															0b00100100,
															0b00100000,
															0b00001111,
															0b00000000,
															0b00001100};

int segmentPins[7] = {A, B, C, D, E, F, G};
int dPins[4] = {d1, d2, d3, d4};

void setup() {
	pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
	pinMode(d3, OUTPUT);
	pinMode(d4, OUTPUT);
	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);
	pinMode(E, OUTPUT);
	pinMode(F, OUTPUT);
	pinMode(G, OUTPUT);
	Serial.begin(9600);
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
	// 1 -> 0b01001111
	for (int i = 6; i >= 0; i--) {
		// 01001111
		//&       1
		//---------
		//        1
		//---------
		boolean isHigh = toDisplay & 1;
		Serial.print(isHigh);
		digitalWrite(segmentPins[i], isHigh);
		toDisplay = toDisplay >> 1;
		// 00100111
	}
	Serial.println();
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
		divisor /= 10;
		num = r;
		delay(10);
	}
}

void loop() {
	display4(3816);	
}

void loop1() {

	digitalWrite(d1, HIGH);
	digitalWrite(d2, LOW);
	digitalWrite(d3, LOW);
	digitalWrite(d4, LOW);

	digitalWrite(A, LOW);
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);
	digitalWrite(E, LOW);
	digitalWrite(F, LOW);
	digitalWrite(G, HIGH);
	delay(10);

	// 1
	digitalWrite(d1, LOW);
	digitalWrite(d2, HIGH);
	digitalWrite(d3, LOW);
	digitalWrite(d4, LOW);
	
	digitalWrite(A, HIGH);
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, HIGH);
	digitalWrite(E, HIGH);
	digitalWrite(F, HIGH);
	digitalWrite(G, HIGH);
  delay(10);

	// 2
	digitalWrite(d1, LOW);
	digitalWrite(d2, LOW);
	digitalWrite(d3, HIGH);
	digitalWrite(d4, LOW);
	
	digitalWrite(A, LOW);
	digitalWrite(B, LOW);
	digitalWrite(C, HIGH);
	digitalWrite(D, LOW);
	digitalWrite(E, LOW);
	digitalWrite(F, HIGH);
	digitalWrite(G, LOW);
  delay(10);
	

}

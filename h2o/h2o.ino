// 74HC595 shift register
const byte dataPin = 7;
const byte latchPin = 8; 
const byte clockPin = 9;

// 7seg display segments map
const byte d1 = 3;
const byte d2 = 4;
const byte d3 = 5;
const byte d4 = 6;
char dPins[4] = {d1, d2, d3, d4};
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

int prevDelayTime = millis();
const int delayInterval = 2000;
byte toRead = A0;
short moistureLevel = 0;

void setup() {
	//4 digit 7 segment display
	pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
	pinMode(d3, OUTPUT);
	pinMode(d4, OUTPUT);
	
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);

	pinMode(A0, INPUT);
	pinMode(A1, INPUT);	
	Serial.begin(9600);
}

void loop() {
	displayMoistureLevel();
}

void displayMoistureLevel() {
	int currTime = millis();
	if ((currTime - prevDelayTime) >= delayInterval) {
		// send 0 to shift register so that it sends 0 to all 7 segments
		digitalWrite(clockPin, LOW);
		digitalWrite(latchPin, LOW);
		shiftOut(d4, clockPin, LSBFIRST, 0);
		digitalWrite(latchPin, HIGH);
		prevDelayTime = currTime;
		moistureLevel = analogRead(toRead);
		Serial.print("aread: " + String(toRead) + ", val:" + String(moistureLevel) + "\n");
		if (toRead == A0) {
			toRead = A1;
		} else {
			toRead = A0;
		}
	}

	display4(moistureLevel);
}

void display4(int num) {
	if (num < 0 || num > 9999) {
		return;
	}

	int divisor = 1000;
	int q, r, prev_q = 0;
	for (int i = 0; i < 4; i++) {
		q = num / divisor;
		r = num % divisor;
		
		if (i==3 || q!=0 || prev_q !=0) {
			display1(dPins[i], q);
			delay(8);
		} 
			 		
		divisor /= 10;
		num = r;
		prev_q = q;	
	}

	return;
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

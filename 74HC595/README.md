# 74HC595 Shift Register with 7-Segment Display

Improved version of the 7-segment display project using a 74HC595 shift register to reduce pin usage from 11 to 7.

## Hardware Requirements

- 4-digit 7-segment display (common anode)
- 74HC595 8-bit shift register IC
- Arduino Uno
- Appropriate current-limiting resistors

## Pin Configuration

**Shift Register:**
- D7 - Data Pin (DS)
- D8 - Latch Pin (ST_CP)
- D9 - Clock Pin (SH_CP)

**Digit Control Pins:**
- D3 - Digit 1 (leftmost)
- D4 - Digit 2
- D5 - Digit 3
- D6 - Digit 4 (rightmost)

**Shift Register Outputs (Q0-Q7):**
Connected to 7-segment pins A through G

## How It Works

The 74HC595 shift register allows control of 8 outputs (7 segments) using only 3 Arduino pins:

1. **Data Pin**: Sends serial data (segment pattern)
2. **Clock Pin**: Shifts data through the register
3. **Latch Pin**: Updates outputs when ready

The Arduino's built-in `shiftOut()` function handles the serial communication:
```cpp
shiftOut(dataPin, clockPin, LSBFIRST, segmentPattern);
```

## Features

- Counts from 0 to 9999 continuously
- 100ms delay between increments
- Suppresses leading zeros for cleaner display
- Uses multiplexing for 4-digit control

## Segment Encoding

Same encoding as the basic 7seg project:
```
0 = 0b00000001
1 = 0b01001111
...
9 = 0b00001100
```

## Advantages over Direct Pin Control

- **Pin Savings**: 7 pins vs 11 pins
- **Scalability**: Easy to add more shift registers for more segments
- **Cleaner Wiring**: Serial data transfer

## Build & Upload

From the repository root:
```bash
./cup.sh 74HC595
```

## Customization

To change the counting speed, modify the delay:
```cpp
void loop() {
    for(int i=0; i<9999; i++) {
        display4(i);
        delay(100);  // Change this value (milliseconds)
    }
}
```

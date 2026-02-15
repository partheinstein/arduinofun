# 7-Segment Display

A basic 4-digit 7-segment display driver that displays a static number using direct pin control.

## Hardware Requirements

- 4-digit 7-segment display (common anode)
- Arduino Uno
- Appropriate current-limiting resistors

## Pin Configuration

**Digit Control Pins:**
- D7 - Digit 1 (leftmost)
- D10 - Digit 2
- D11 - Digit 3
- D5 - Digit 4 (rightmost)

**Segment Pins:**
- D8 - Segment A
- D12 - Segment B
- D3 - Segment C
- D2 - Segment D
- D13 - Segment E
- D9 - Segment F
- D4 - Segment G

## How It Works

The display uses multiplexing to control 4 digits with limited pins. The `display4()` function:
1. Breaks down a number (0-9999) into individual digits
2. Rapidly cycles through each digit (10ms delay)
3. Activates one digit at a time while setting the correct segment pattern

Due to persistence of vision, all digits appear to be lit simultaneously.

## Segment Encoding

Each digit (0-9) is encoded as a binary pattern where each bit represents a segment:

```
Bit pattern: 0bGFEDCBA
```

Example: `1 = 0b01001111` (segments B and C on)

## Usage

Currently displays the static number **3816**. To change:
```cpp
void loop() {
    display4(1234);  // Change to your desired number
}
```

## Serial Output

Outputs segment binary patterns for debugging at 9600 baud.

## Build & Upload

From the repository root:
```bash
./cup.sh 7seg
```

# Arduino Fun

A collection of Arduino projects exploring digital displays and sensor integration, progressing from basic pin control to shift registers and real-world sensor applications.

## Projects Overview

### 1. [7seg](./7seg/) - Basic 7-Segment Display
Direct pin control of a 4-digit 7-segment display. Displays a static number using 11 Arduino pins.

**Key Concepts**: Multiplexing, binary segment encoding, persistence of vision

[View detailed documentation →](./7seg/README.md)

---

### 2. [74HC595](./74HC595/) - Shift Register Display
Optimized 7-segment display using a 74HC595 shift register, reducing pin usage from 11 to 7. Counts from 0 to 9999.

**Key Concepts**: Serial data transmission, shift registers, pin optimization

[View detailed documentation →](./74HC595/README.md)

---

### 3. [h2o](./h2o/) - Moisture Sensor Monitor
Dual moisture sensor system with 7-segment display output. Alternates between two sensors, displaying real-time readings and logging to serial.

**Key Concepts**: Analog input, sensor integration, non-blocking timing, serial communication

[View detailed documentation →](./h2o/README.md)

---

## Quick Start

### Prerequisites
- Arduino Uno
- arduino-cli installed
- USB connection to `/dev/ttyACM1` (adjust in scripts if different)

### Build and Upload
```bash
./cup.sh <project-name>
```
Example:
```bash
./cup.sh h2o
```

### Monitor Serial Output
```bash
./reads.sh
```

## Development Progression

1. **7seg**: Learn basic multiplexed display control with direct pin connections
2. **74HC595**: Optimize with shift register to free up Arduino pins
3. **h2o**: Apply display skills to real-world sensor monitoring

## Utilities

- **cup.sh** - Compile and upload sketches using arduino-cli
- **reads.sh** - Monitor serial output from Arduino

## Common Components

All projects use the same 7-segment encoding pattern and multiplexing technique for 4-digit displays.
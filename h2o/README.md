# H2O - Moisture Sensor Display

Dual moisture sensor reader with real-time 7-segment display output using a 74HC595 shift register.

## Hardware Requirements

- 4-digit 7-segment display (common anode)
- 74HC595 8-bit shift register IC
- 2x moisture sensors (or any analog sensors)
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

**Sensors:**
- A0 - Moisture Sensor 1
- A1 - Moisture Sensor 2

## How It Works

The system continuously displays the most recent sensor reading while alternating between sensors:

1. Reads sensor value every 2 seconds
2. Displays analog value (0-1023) on 7-segment display
3. Outputs reading to serial monitor
4. Switches to the other sensor for next reading

The display updates continuously via multiplexing while the sensor reading updates every 2 seconds.

## Serial Output Format

```
aread: A0, val:512
aread: A1, val:768
aread: A0, val:501
...
```

- `aread`: Analog read pin (A0 or A1)
- `val`: Sensor value (0-1023)
- Baud rate: 9600

## Features

- **Dual Sensor Support**: Alternates between two analog inputs
- **Real-time Display**: Shows current moisture level
- **Serial Logging**: Records all readings with timestamps
- **Leading Zero Suppression**: Clean number display
- **Non-blocking**: Display updates don't interfere with sensor timing

## Timing

- Sensor read interval: 2000ms (2 seconds)
- Display refresh: ~8ms per digit (continuous)

## Use Cases

- Soil moisture monitoring for plants
- Water level detection
- Humidity sensing
- Any dual analog sensor application

## Build & Upload

From the repository root:
```bash
./cup.sh h2o
```

## Monitor Sensor Data

View real-time sensor readings:
```bash
./reads.sh
```

## Customization

**Change sensor read interval:**
```cpp
const int delayInterval = 2000;  // Change to desired milliseconds
```

**Use different analog pins:**
```cpp
pinMode(A2, INPUT);  // Add more sensors
pinMode(A3, INPUT);
```

**Adjust display refresh rate:**
```cpp
delay(8);  // In display1() function - lower = faster refresh
```

## Sensor Values

Analog readings range from 0-1023:
- **0**: No moisture / sensor not in contact
- **~300-500**: Moderately moist
- **~700-900**: Very wet
- **1023**: Maximum moisture

(Actual values depend on your specific sensor calibration)

# Circuit Diagram - Moisture Sensor with 7-Segment Display

## Component Overview

- **Arduino Uno**
- **74HC595 8-bit Shift Register** (1x)
- **4-Digit 7-Segment Display** (Common Anode)
- **2x Moisture Sensors** (or any analog sensors)
- **Current Limiting Resistors** (220Ω - 330Ω for display, 7 total)

---

## Connection Diagram

```
                           Arduino Uno
                        ┌───────────────┐
                        │               │
                    D7  │───────────┐   │      Moisture
                    D8  │─────────┐ │   │      Sensors
                    D9  │───────┐ │ │   │         │
                        │       │ │ │   │         │
                    D3  │───┐   │ │ │   │    ┌────┴────┐
                    D4  │─┐ │   │ │ │   │    │         │
                    D5  │─│─│─┐ │ │ │   │   ┌┴┐       ┌┴┐
                    D6  │─│─│─│─│─│─│─┐ │   │ │       │ │
                        │ │ │ │ │ │ │ │ │   │ │       │ │
                    A0  │─│─│─│─│─│─│─│─│───│ │       │ │
                    A1  │─│─│─│─│─│─│─│─│───│ │───────│ │
                        │ │ │ │ │ │ │ │ │   └┬┘       └┬┘
                    5V  │─│─│─│─│─│─│─│─│────┤VCC  VCC ├─── VCC
                   GND  │─│─│─│─│─│─│─│─│────┤GND  GND ├─── GND
                        └─│─│─│─│─│─│─│─│─┘  └─────────┘
                          │ │ │ │ │ │ │ │
      ┌───────────────────┘ │ │ │ │ │ │ └──────────────────┐
      │   ┌─────────────────┘ │ │ │ │ └────────────────┐   │
      │   │   ┌───────────────┘ │ │ └──────────────┐   │   │
      │   │   │   ┌─────────────┘ └────────────┐   │   │   │
      │   │   │   │                             │   │   │   │
      │   │   │   │      74HC595                │   │   │   │
      │   │   │   │   ┌──────────────┐          │   │   │   │
      │   │   │   │   │              │          │   │   │   │
      │   │   │   │   │    ┌───┐     │          │   │   │   │
      │   │   │   └───│ DS │   │ VCC │──────────┤   │   │   │
      │   │   │       │    │   │     │          │   │   │   │
      │   │   └───────│ST_CP   │ Q0  │────┐     │   │   │   │
      │   │           │    │   │     │    │     │   │   │   │
      │   └───────────│SH_CP   │ Q1  │──┐ │     │   │   │   │
      │               │    │   │     │  │ │     │   │   │   │
      │     ┌─────────│ OE │   │ Q2  │┐ │ │     │   │   │   │
      │     │         │    │   │     ││ │ │     │   │   │   │
      │     │    ┌────│MR  │   │ Q3  │││ │ │     │   │   │   │
      │     │    │    │    │   │     ││││ │ │     │   │   │   │
      └─────│────│────│GND │   │ Q4  │││││ │ │     │   │   │   │
            │    │    │    │   │     ││││││ │ │     │   │   │   │
            │    │    │    └───┘ Q5  │││││││ │ │     │   │   │   │
            │    │    │          Q6  ││││││││ │ │     │   │   │   │
            │    │    │          Q7  │││││││││ │ │     │   │   │   │
            │    │    │         (NC) ││││││││││ │ │     │   │   │   │
            │    │    └──────────────┘│││││││││ │ │     │   │   │   │
            │    │                    │││││││││ │ │     │   │   │   │
           GND  VCC                   │││││││││ │ │     │   │   │   │
                                      │││││││││ │ │     │   │   │   │
                                      │││││││││ │ │     │   │   │   │
            4-Digit 7-Segment Display │││││││││ │ │     │   │   │   │
            ┌──────────────────────┐  │││││││││ │ │     │   │   │   │
            │   ___   ___   ___   ___│││││││││ │ │     │   │   │   │
            │  |   | |   | |   | |   ││││││││ │ │     │   │   │   │
            │  |___| |___| |___| |___|││││││││ │ │     │   │   │   │
            │  |   | |   | |   | |   ││││││││ │ │     │   │   │   │
            │  |___| |___| |___| |___|││││││││ │ │     │   │   │   │
            │                         ││││││││ │ │     │   │   │   │
            │  Common Anodes:         ││││││││ │ │     │   │   │   │
            │    D1  D2  D3  D4       ││││││││ │ │     │   │   │   │
            └────┬───┬───┬───┬────────┘│││││││ │ │     │   │   │   │
                 │   │   │   │         │││││││ │ │     │   │   │   │
                 └───│───│───│─────────│││││││ │ └─────┘   │   │   │
                     └───│───│─────────││││││└─┼───────────┘   │   │
                         └───│─────────│││││└──┼───────────────┘   │
                             └─────────││││└───┼───────────────────┘
                                       │││└────┘
           Segment pins (via resistors):
                A ──────────────────────┘││
                B ───────────────────────┘│
                C ────────────────────────┘
                D (connects to Q3)
                E (connects to Q4)
                F (connects to Q5)
                G (connects to Q6)
```

---

## Pin Mapping Table

### Arduino to 74HC595

| Arduino Pin | 74HC595 Pin | Function |
|-------------|-------------|----------|
| D7          | DS (14)     | Serial Data Input |
| D8          | ST_CP (12)  | Storage Register Clock (Latch) |
| D9          | SH_CP (11)  | Shift Register Clock |
| 5V          | VCC (16)    | Power Supply |
| GND         | GND (8)     | Ground |
| GND         | OE (13)     | Output Enable (Active LOW) |
| 5V          | MR (10)     | Master Reset (Active LOW) |

### 74HC595 to 7-Segment Display

| 74HC595 Output | Display Segment | Resistor |
|----------------|----------------|----------|
| Q0 (15)        | A              | 220-330Ω |
| Q1 (1)         | B              | 220-330Ω |
| Q2 (2)         | C              | 220-330Ω |
| Q3 (3)         | D              | 220-330Ω |
| Q4 (4)         | E              | 220-330Ω |
| Q5 (5)         | F              | 220-330Ω |
| Q6 (6)         | G              | 220-330Ω |
| Q7 (7)         | DP (optional)  | 220-330Ω |

### Arduino to Display Digit Control

| Arduino Pin | Display Digit | Function |
|-------------|---------------|----------|
| D3          | D1            | Digit 1 (Leftmost) |
| D4          | D2            | Digit 2 |
| D5          | D3            | Digit 3 |
| D6          | D4            | Digit 4 (Rightmost) |

### Arduino to Moisture Sensors

| Arduino Pin | Sensor | Function |
|-------------|--------|----------|
| A0          | Sensor 1 | Analog input (0-1023) |
| A1          | Sensor 2 | Analog input (0-1023) |

---

## Moisture Sensor Connections

### Typical Moisture Sensor Pinout

Most capacitive or resistive moisture sensors have 3 pins:

```
Sensor Module
┌─────────┐
│   ┌─┐   │
│   └─┘   │
│         │
│  ○ ○ ○  │
│  │ │ │  │
└──┴─┴─┴──┘
   │ │ │
   │ │ └── SIG (Signal) → Arduino A0/A1
   │ └──── VCC → Arduino 5V
   └────── GND → Arduino GND
```

**Sensor 1:**
- VCC → 5V
- GND → GND
- SIG → A0

**Sensor 2:**
- VCC → 5V
- GND → GND
- SIG → A1

---

## System Operation

### Data Flow

1. **Sensor Reading** (every 2 seconds):
   - Arduino reads analog value from A0 or A1
   - Value ranges from 0 (dry/no contact) to 1023 (wet/max)
   - Alternates between sensors each reading

2. **Display Update** (continuous):
   - Sensor value is displayed on 4-digit 7-segment display
   - Display refreshes continuously via multiplexing
   - Leading zeros are suppressed

3. **Serial Output** (every 2 seconds):
   - Format: `aread: A0, val:512`
   - Logs which sensor was read and its value
   - Baud rate: 9600

### Timing

- **Sensor read interval**: 2000ms (2 seconds)
- **Display refresh**: ~8ms per digit × 4 digits = ~32ms per cycle
- **Display update rate**: ~30 times per second (smooth)

---

## Wiring Steps

### 1. Power Distribution
```
Arduino 5V  → 74HC595 VCC (pin 16)
            → 74HC595 MR (pin 10)
            → Sensor 1 VCC
            → Sensor 2 VCC

Arduino GND → 74HC595 GND (pin 8)
            → 74HC595 OE (pin 13)
            → Sensor 1 GND
            → Sensor 2 GND
```

### 2. 74HC595 Control Lines
```
Arduino D7 → 74HC595 DS (pin 14)
Arduino D8 → 74HC595 ST_CP (pin 12)
Arduino D9 → 74HC595 SH_CP (pin 11)
```

### 3. Display Connections

**Digit Control (direct from Arduino):**
```
Arduino D3 → Display D1 (common anode)
Arduino D4 → Display D2 (common anode)
Arduino D5 → Display D3 (common anode)
Arduino D6 → Display D4 (common anode)
```

**Segments (via 74HC595 with resistors):**
```
74HC595 Q0 → [220Ω] → Display Segment A
74HC595 Q1 → [220Ω] → Display Segment B
74HC595 Q2 → [220Ω] → Display Segment C
74HC595 Q3 → [220Ω] → Display Segment D
74HC595 Q4 → [220Ω] → Display Segment E
74HC595 Q5 → [220Ω] → Display Segment F
74HC595 Q6 → [220Ω] → Display Segment G
```

### 4. Sensor Connections
```
Sensor 1: VCC → 5V, GND → GND, SIG → A0
Sensor 2: VCC → 5V, GND → GND, SIG → A1
```

---

## Testing

### Step 1: Upload Code
```bash
./cup.sh h2o
```

### Step 2: Verify Display
- Display should show a number (0-1023)
- Number updates every 2 seconds
- Leading zeros should be suppressed (e.g., "512" not "0512")

### Step 3: Monitor Serial Output
```bash
./reads.sh
```

Expected output:
```
aread: A0, val:345
aread: A1, val:678
aread: A0, val:341
aread: A1, val:682
```

### Step 4: Test Sensors
- **Dry**: Should read low values (0-300)
- **Moist**: Should read medium values (400-700)
- **Wet**: Should read high values (700-1000)

---

## Troubleshooting

### Display Issues

**No display:**
- Check 74HC595 power (VCC to pin 16, GND to pin 8)
- Verify OE (pin 13) is tied to GND
- Check digit control pins (D3-D6)

**Wrong segments:**
- Verify Q0-Q6 connections match A-G segments
- Check resistor placements

**Flickering:**
- Increase delay in `display1()` from 8ms to 10ms
- Ensure power supply is stable

### Sensor Issues

**Reading always 0:**
- Check sensor VCC and GND connections
- Verify sensor signal wire to A0/A1
- Test sensor with multimeter (should show voltage change when wet/dry)

**Reading always 1023:**
- Check for short circuit
- Verify sensor is working (try swapping sensors)

**Erratic readings:**
- Add small capacitor (0.1µF) between signal and GND near Arduino
- Ensure good electrical connections
- Keep sensor wires away from AC power lines

### Serial Output Issues

**No serial data:**
- Verify baud rate is 9600
- Check USB cable connection
- Try different serial monitor tool

---

## Sensor Value Interpretation

Typical ranges for capacitive soil moisture sensors:

| Reading | Condition | Description |
|---------|-----------|-------------|
| 0-300   | Dry       | Sensor not in soil or very dry |
| 300-600 | Moist     | Good moisture level for most plants |
| 600-900 | Wet       | High moisture, may be overwatered |
| 900-1023| Saturated | Sensor in water or extremely wet |

**Note:** Calibrate your specific sensors by testing in known conditions!

---

## Enhancements

### Add More Sensors
```cpp
pinMode(A2, INPUT);  // Add third sensor
pinMode(A3, INPUT);  // Add fourth sensor
```

### Change Read Interval
```cpp
const int delayInterval = 5000;  // Read every 5 seconds
```

### Add Threshold Alerts
```cpp
if (moistureLevel < 300) {
  // Too dry - trigger alert/LED
}
```

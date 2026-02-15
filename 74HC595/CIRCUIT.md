# Circuit Diagram - 74HC595 with 4-Digit 7-Segment Display

## Component Overview

- **Arduino Uno**
- **74HC595 8-bit Shift Register** (1x)
- **4-Digit 7-Segment Display** (Common Anode)
- **Current Limiting Resistors** (220Ω - 330Ω recommended)

---

## Connection Diagram

```
                           Arduino Uno
                        ┌───────────────┐
                        │               │
                    D7  │───────────┐   │
                    D8  │─────────┐ │   │
                    D9  │───────┐ │ │   │
                        │       │ │ │   │
                    D3  │───┐   │ │ │   │
                    D4  │─┐ │   │ │ │   │
                    D5  │─│─│─┐ │ │ │   │
                    D6  │─│─│─│─│─│─│─┐ │
                        │ │ │ │ │ │ │ │ │
                    5V  │─│─│─│─│─│─│─│─│──── VCC
                   GND  │─│─│─│─│─│─│─│─│──── GND
                        └─│─│─│─│─│─│─│─│─┘
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

---

## Schematic Notes

1. **Common Anode Configuration**: All digits share common segment connections (A-G) which are driven by the 74HC595. Individual digits are multiplexed via D3-D6.

2. **Current Limiting Resistors**: Place 220-330Ω resistors between each 74HC595 output (Q0-Q6) and the corresponding 7-segment pins (A-G).

3. **74HC595 Control Pins**:
   - **OE (Output Enable)**: Tied to GND for always-on outputs
   - **MR (Master Reset)**: Tied to VCC (5V) to disable reset

4. **Multiplexing**: The code rapidly cycles through digits (D3-D6 HIGH one at a time) while shifting out the appropriate segment pattern via the 74HC595.

5. **Data Flow**:
   - Arduino sends 8-bit segment pattern to 74HC595 via D7 (data)
   - D9 (clock) shifts data through the register
   - D8 (latch) updates the outputs when the byte is complete

---

## Breadboard Wiring Tips

1. Connect 74HC595 power pins first (VCC to 5V, GND to GND)
2. Tie OE (pin 13) to GND
3. Tie MR (pin 10) to VCC
4. Wire Arduino D7, D8, D9 to DS, ST_CP, SH_CP respectively
5. Connect 74HC595 outputs Q0-Q6 through resistors to segments A-G
6. Connect Arduino D3-D6 to digit common anodes
7. Verify ground connections are solid

---

## Testing

After wiring:
1. Upload the sketch using `./cup.sh 74HC595`
2. Display should count from 0 to 9999
3. If segments are inverted or scrambled, verify Q0-Q6 connections match A-G
4. If brightness is uneven, check all resistor values are consistent

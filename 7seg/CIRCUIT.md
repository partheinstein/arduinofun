# Circuit Diagram - Direct 7-Segment Display Control

## Component Overview

- **Arduino Uno**
- **4-Digit 7-Segment Display** (Common Anode)
- **Current Limiting Resistors** (220Ω - 330Ω recommended, 7 total)

---

## Connection Diagram

```
                           Arduino Uno
                        ┌───────────────┐
                        │               │
                    D2  │───────────────┼──────────────────────┐
                    D3  │───────────────┼────────────────────┐ │
                    D4  │───────────────┼──────────────────┐ │ │
                    D5  │───────────────┼────────────────┐ │ │ │
                    D7  │───────────────┼──────────┐     │ │ │ │
                    D8  │───────────────┼────────┐ │     │ │ │ │
                    D9  │───────────────┼──────┐ │ │     │ │ │ │
                   D10  │───────────────┼────┐ │ │ │     │ │ │ │
                   D11  │───────────────┼──┐ │ │ │ │     │ │ │ │
                   D12  │───────────────┼┐ │ │ │ │ │     │ │ │ │
                   D13  │───────────────││ │ │ │ │ │     │ │ │ │
                        │               ││ │ │ │ │ │     │ │ │ │
                    5V  │───────────────││─│─│─│─│─│─────│─│─│─│─── VCC
                   GND  │───────────────││─│─│─│─│─│─────│─│─│─│─── GND
                        └───────────────││─│─│─│─│─│─────│─│─│─│─┘
                                        ││ │ │ │ │ │     │ │ │ │
                                        ││ │ │ │ │ │     │ │ │ │
            4-Digit 7-Segment Display   ││ │ │ │ │ │     │ │ │ │
            ┌────────────────────────┐  ││ │ │ │ │ │     │ │ │ │
            │   ___   ___   ___   ___ ││ │ │ │ │ │     │ │ │ │
            │  |   | |   | |   | |   │││ │ │ │ │ │     │ │ │ │
            │  |___| |___| |___| |___│││ │ │ │ │ │     │ │ │ │
            │  |   | |   | |   | |   │││ │ │ │ │ │     │ │ │ │
            │  |___| |___| |___| |___│││ │ │ │ │ │     │ │ │ │
            │                         │││ │ │ │ │ │     │ │ │ │
            │  Common Anodes:         │││ │ │ │ │ │     │ │ │ │
            │    D1  D2  D3  D4       │││ │ │ │ │ │     │ │ │ │
            └────┬───┬───┬───┬────────┘││ │ │ │ │ │     │ │ │ │
                 │   │   │   │         ││ │ │ │ │ │     │ │ │ │
                 │   │   │   └─────────││─│─│─│─│─│─────┘ │ │ │
                 │   │   └─────────────││─│─│─│─│─│───────┘ │ │
                 │   └─────────────────││─│─│─│─│─│─────────┘ │
                 └─────────────────────││─│─│─│─│─│───────────┘
                                       ││ │ │ │ │ │
           Segment pins (via 220-330Ω resistors):
                                       ││ │ │ │ │ │
                A ─────────────────────┘│ │ │ │ │ │
                B ──────────────────────┘ │ │ │ │ │
                C ────────────────────────┘ │ │ │ │
                D ──────────────────────────┘ │ │ │
                E ────────────────────────────┘ │ │
                F ──────────────────────────────┘ │
                G ────────────────────────────────┘
```

---

## Pin Mapping Table

### Arduino to 7-Segment Display (Segments)

| Arduino Pin | Segment | Function | Resistor |
|-------------|---------|----------|----------|
| D8          | A       | Top horizontal | 220-330Ω |
| D12         | B       | Upper right vertical | 220-330Ω |
| D3          | C       | Lower right vertical | 220-330Ω |
| D2          | D       | Bottom horizontal | 220-330Ω |
| D13         | E       | Lower left vertical | 220-330Ω |
| D9          | F       | Upper left vertical | 220-330Ω |
| D4          | G       | Middle horizontal | 220-330Ω |

### Arduino to Display Digit Control (Common Anodes)

| Arduino Pin | Display Digit | Function |
|-------------|---------------|----------|
| D7          | D1            | Digit 1 (Leftmost) - Controls HIGH/LOW |
| D10         | D2            | Digit 2 - Controls HIGH/LOW |
| D11         | D3            | Digit 3 - Controls HIGH/LOW |
| D5          | D4            | Digit 4 (Rightmost) - Controls HIGH/LOW |

---

## Segment Layout Reference

```
     AAA
    F   B
    F   B
     GGG
    E   C
    E   C
     DDD
```

**Segment to Pin Mapping:**
- A = D8
- B = D12
- C = D3
- D = D2
- E = D13
- F = D9
- G = D4

---

## How It Works

### Common Anode Configuration

This display uses **common anode** configuration:
- **HIGH on segment pin** = segment OFF (1 in binary = off)
- **LOW on segment pin** = segment ON (0 in binary = on)

### Multiplexing

Since all 4 digits share the same segment pins (A-G), only one digit can be lit at a time:

1. Select digit by setting its common anode pin HIGH (D7, D10, D11, or D5)
2. Set all other digit pins LOW
3. Set segment pattern on pins D2, D3, D4, D8, D9, D12, D13
4. Wait ~10ms
5. Repeat for next digit

The rapid cycling (25 times per second for all 4 digits) creates the illusion that all digits are lit simultaneously due to **persistence of vision**.

---

## Wiring Steps

1. **Power connections:**
   - Connect Arduino 5V to display VCC
   - Connect Arduino GND to display GND

2. **Digit control (common anodes):**
   - Arduino D7 → Display D1
   - Arduino D10 → Display D2
   - Arduino D11 → Display D3
   - Arduino D5 → Display D4

3. **Segment connections (with resistors):**
   - Arduino D8 → [220Ω resistor] → Segment A
   - Arduino D12 → [220Ω resistor] → Segment B
   - Arduino D3 → [220Ω resistor] → Segment C
   - Arduino D2 → [220Ω resistor] → Segment D
   - Arduino D13 → [220Ω resistor] → Segment E
   - Arduino D9 → [220Ω resistor] → Segment F
   - Arduino D4 → [220Ω resistor] → Segment G

---

## Resistor Placement

**Important:** Place one current-limiting resistor on **each segment line** (A through G).

```
Arduino Pin → [Resistor 220-330Ω] → Segment Pin
```

**Why 7 resistors?**
All 4 digits share the segment pins, so you need one resistor per segment to limit current regardless of which digit is active.

---

## Binary Encoding Used in Code

The code uses bit patterns where each bit represents a segment state:

```
Bit position: 0bGFEDCBA

Example:
  0 = 0b00000001  (only A is OFF, rest are ON)
  1 = 0b01001111  (B and C are OFF, rest are ON)
  8 = 0b00000000  (all segments OFF = all lit)
```

Remember: **0 = ON, 1 = OFF** for common anode!

---

## Testing

After wiring:
1. Upload the sketch using `./cup.sh 7seg`
2. Display should show **3816** (as coded in loop)
3. Verify all segments light correctly
4. Check serial monitor (9600 baud) for segment bit patterns

### Troubleshooting

**Wrong segments lighting:**
- Verify segment pin connections match the table above
- Check resistor placements

**Dim or uneven brightness:**
- Ensure all resistors are the same value (220-330Ω)
- Check power supply is adequate

**Digits not showing:**
- Verify digit control pins (D7, D10, D11, D5) are connected
- Check common anode connections

**Ghosting between digits:**
- Reduce delay in `display1()` function
- Ensure only one digit pin is HIGH at a time

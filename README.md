# Smart AC Light Dimmer using TRIAC (ATmega32A + ESP32)

A microcontroller-based AC light dimmer that controls the brightness of an AC lamp using **TRIAC phase-angle control** with **zero-cross detection**. The project is built around the **ATmega32A** and supports three different control methods: a potentiometer, a keypad, and wireless control through an **ESP32** using UART communication.

The system synchronizes with the AC mains using a zero-cross detection circuit and precisely triggers the TRIAC after a calculated delay to regulate the RMS voltage delivered to the load, resulting in smooth and reliable brightness control.

## Features

* TRIAC-based AC light dimming using phase-angle control
* Zero-cross detection with interrupt-driven synchronization
* Three operating modes:

  * Potentiometer (ADC)
  * 4×4 Matrix Keypad
  * ESP32 serial control (UART/Blynk)
* 16×2 LCD displaying the current mode and brightness percentage
* Timer1 Compare Match interrupt for accurate TRIAC firing
* Mode switching using external interrupts
* Relay output control

## Hardware Used

* ATmega32A Microcontroller
* ESP32
* BT136 TRIAC
* MOC3021 Optocoupler (TRIAC Driver)
* Zero-Cross Detection Circuit

  * PC817 Optocoupler
  * Bridge Rectifier
  * Current-Limiting Resistors
* 16×2 LCD
* 4×4 Matrix Keypad
* Potentiometer
* Relay Module
* AC/DC Step-Down Power Supply Module
* Snubber Circuit (39 Ω Resistor + 0.01 µF Capacitor)

## How It Works

1. A zero-cross detection circuit generates an interrupt whenever the AC waveform crosses zero volts.
2. Depending on the selected operating mode, the ATmega32A reads the desired brightness from:

   * The potentiometer
   * The keypad
   * The ESP32 via UART communication
3. The selected brightness is converted into a TRIAC firing delay.
4. Timer1 generates the required delay after every zero crossing.
5. The MOC3021 optocoupler triggers the BT136 TRIAC at the calculated firing angle, controlling the RMS voltage delivered to the AC load.
6. The LCD continuously displays the current operating mode and output brightness.

## Technologies

* Embedded C
* AVR-GCC
* ATmega32A
* ESP32
* UART Communication
* Analog-to-Digital Converter (ADC)
* External Interrupts
* Timer1 Compare Match Interrupt
* TRIAC Phase-Angle Control
* Zero-Cross Detection
* Blynk IoT

## Repository Structure

```text
├── ATmega32A_Code/      # Embedded C firmware
├── ESP32_Code/          # ESP32 Blynk application
├── Circuit_Schematic/   # Circuit diagrams
├── Report/              # Project report
└── README.md
```

## Authors

* Batool Khaled
* Habiba Ali
* Yahia Haitham
* Youssif Ahmed

---

Developed as part of the **Microcontroller Engineering I** course in the **Mechatronics & Robotics Engineering Department, Alexandria University**.

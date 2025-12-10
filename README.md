# SonaSense: Gesture-Controlled Musical Glove

SonaSense is a wearable musical interface that turns hand movement, pressure, and finger bending into real-time control data for sound synthesis and processing.

![Glove Photo](img/SonaSense.png)

SonaSense uses an **Arduino** board and a set of motion and pressure sensors to capture detailed gesture information.
The data is streamed over serial and interpreted by a synthesis patch, allowing expressive control over timbre, filtering, and feedback through natural hand movement.

## Table of Contents

- [Hardware](#hardware)
- [System Architecture](#system-architecture)
  - [Max/MSP Example](#maxmsp-example)
- [Repository Layout](#repository-layout)
- [Build Instructions](#build-instructions)
- [License](#license)
- [Contact](#contact)

## Hardware

- **Arduino Nano**/**UNO**
- **ICM-20948 IMU**
- **Flex Sensor** (ZD10-100 in this example)
- **Force Sensor** (FSR402 in this example)
- **LDR** (light-dependent resistor)
- 3 Resistors (as voltage dividers for the flex sensor, force sensor, and LDR)
- Breadboard, protoboard, soldered connections depending on final assembly

All sensors are wired to the Arduino board's analog inputs, while the IMU communicates over **I²C**.

## System Architecture

![Schematic](kicad/SonaSense.svg)

The Arduino samples all analog values and IMU data every loop, bundles them into a simple serial format, and sends them to the synthesis environment.

### Max/MSP Example

The included **Max/MSP** patch listens to the serial data stream and maps the sensor values to DSP parameters in real time.
This allows performance gestures to directly shape the sound in real time.
The parameters mapping of the example patch is as follows:

|Sensor|Parameter|
|------|---------|
|LDR|Low-pass gate|
|Flex Sensor|Oscillator Ratio|
|Force Sensor|Redux|
|Accel X|Band-pass filter frequency|
|Accel Y|Panning|
|Gyro X, Y, Z|Feedback amount (via radius)|

## Repository Layout

```text
.
├── arduino/            # Arduino .ino firmware
├── kicad/              # KiCad schematic (.kicad_sch) + SVG export
├── example_max/        # Example Max/MSP patch for testing
├── img/                # Image for the README
└── README.md           # This file
```

## Build Instructions

1. Install the [Adafruit ICM20X library](https://github.com/adafruit/Adafruit_ICM20X) from the Arduino Library Manager.

2. Open the `/arduino` folder and load the `.ino` file onto your Arduino Nano/UNO.

3. Follow the wiring shown in the KiCad schematic or the SVG diagram.

4. Depending on your environment, set up a serial receiver to read the data stream from the Arduino.

## License

This project includes third-party components:

- Adafruit_ICM20X - BSD License

Ensure compliance with their licenses if distributing this software.

## Contact

© 2025 Noella Wang

[Drop a line](https://nonocut.com/contact/)

# Controlling Dot Matrix – GPIO

## Overview

This module contains practice problems for learning 8x8 dot matrix LED control using bare-metal GPIO programming on the ATmega2560 microcontroller (Arduino Mega). All programs are written in C using direct register manipulation without Arduino library functions.

## What I Learned

- 8x8 dot matrix LED architecture and row-column scanning
- Matrix addressing and LED activation control
- Character and symbol bitmap representation
- Multiplexing techniques for multi-LED display
- Text animation and multi-directional scrolling effects

## Problem Sets

- **[Set 11](./Set_11/)** - Basic dot matrix LED control (individual LEDs, rows, columns, diagonals)
- **[Set 12](./Set_12/)** - Character and symbol display (uppercase, lowercase, numbers, special symbols)
- **[Set 13](./Set_13/)** - Animated text scrolling in all directions

## Tools Used

- **Microcontroller**: ATmega2560 (Arduino Mega)
- **Language**: C (bare-metal)
- **Simulation**: Wokwi
- **Hardware**: 8x8 Dot Matrix LED Display

## Structure

Each set contains:
- Source files (`.c`)
- Helper library (`led_matrix.h`)
- README with problem descriptions and Wokwi simulation links
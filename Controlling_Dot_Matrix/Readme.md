# Controlling Dot Matrix – GPIO

## Overview

This module contains practice problems for learning 8x8 dot matrix LED control using bare-metal GPIO programming on the ATmega2560 microcontroller (Arduino Mega). All programs are written in C using direct register manipulation without Arduino library functions.

## What I Learned

- 8x8 dot matrix LED architecture and row-column scanning
- Matrix addressing and LED activation control
- Character and symbol bitmap representation
- Multiplexing techniques for multi-LED display
- Text animation and multi-directional scrolling effects
- MAX7219 LED driver chip interfacing and control

## Problem Sets

- **[Set 11](./Set_11/)** - Basic dot matrix LED control using direct row-column scanning
- **[Set 12](./Set_12/)** - Character and symbol display using direct control
- **[Set 13](./Set_13/)** - Animated text scrolling in all directions
- **[Set 14](./Set_14/)** - Basic dot matrix patterns using MAX7219 controller

## Tools Used

- **Microcontroller**: ATmega2560 (Arduino Mega)
- **Language**: C (bare-metal)
- **Simulation**: Wokwi
- **Hardware**: 8x8 Dot Matrix LED Display, MAX7219 LED Driver

## Structure

Each set contains:
- Source files (`.c`)
- Helper libraries (`led_matrix.h`, `max7219.h`)
- README with problem descriptions and Wokwi simulation links
# Controlling 7-Segment LEDs – GPIO

## Overview

This module contains practice problems for learning 7-segment display control using bare-metal GPIO programming on the ATmega2560 microcontroller (Arduino Mega). All programs are written in C using direct register manipulation (DDRx and PORTx) without Arduino library functions.

## What I Learned

- 7-segment display architecture and segment mapping
- Common cathode vs common anode configuration
- Binary to 7-segment encoding
- Direct register manipulation for display control
- Creating digit patterns using bitwise operations
- Animating sequences on 7-segment displays
- Displaying alphabets and numbers 
- Multi-digit display control and multiplexing techniques
- Decimal point control for floating-point representation

## Problem Sets

- **[Set 5](./Set_5/)** - Basic single digit display (0-9) using Common Cathode
- **[Set 6](./Set_6/)** - Sequential display patterns, Common Anode/Cathode, alphabets and special sequences
- **[Set 7](./Set_7/)** - Multi-digit displays (2-digit and 4-digit), multiplexing, and decimal point control


## Tools Used

- **Microcontroller**: ATmega2560 (Arduino Mega)
- **Language**: C (bare-metal)
- **Simulation**: Wokwi
- **Display Types**: Common Cathode & Common Anode 7-Segment Display

## Structure

Each set contains:
- Source files (`.c`)
- README with problem descriptions and Wokwi simulation links

## 7-Segment Display Basics

A 7-segment display consists of 7 LEDs (segments a-g) arranged to form digits 0-9. 

**Common Cathode**: Segments light up when their pins are set HIGH.  
**Common Anode**: Segments light up when their pins are set LOW.
```
     a
    ---
  f|   |b
    -g-
  e|   |c
    ---
     d    .(dp)
```
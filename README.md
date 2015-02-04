# arduino_spektrum_satellite_binding
Enable binding mode for spektrum compatible satellite receives using an Arduino

This is a little arduino sketch to enable binding mode for spektrum compatible satellite receivers using a sequence of low pulses on startup.

## Motivation

The aim of the project is it, to provide a simple way to enable binding mode on spektrum compatible satellite receivers for people who already own an Arduino.

## Usage

Clone the code into a folder called 'arduino_spektrum_satellite_binding', open the project in the Arduino IDE and compile and program it. Connect your satellite as follows (can be changed in code):

black wire -> gnd

orange wire -> PIN 10

grey wire -> PIN 6

Restart the Arduino. Satellite should be in binding mode now (indicated by fast blinking).

## Project status
Tested and working with Arduino Leonardo and OrangeRX R100.

## TODOs
Test with more satellites.


#/bin/bash

arduino-cli compile --fqbn arduino:avr:uno $1
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno $1

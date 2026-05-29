#!/usr/bin/env bash

if sudo arduino-cli compile --fqbn arduino:avr:uno arm-project.ino; then
  sudo arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno arm-project.ino
fi


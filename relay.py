#!/usr/bin/env python3

import serial
import time
import subprocess


arduino = serial.Serial("/dev/ttyACM0", 115200)

time.sleep(2)
while True:
    servo = subprocess.check_output(
        ["ncat", "-l", "5005"],
        text=True
    )
    angle = subprocess.check_output(
        ["ncat", "-l", "5006"],
        text=True
    )
    msg = f"{servo}{angle}"
    arduino.write(msg.encode())
    print("sent:", msg)

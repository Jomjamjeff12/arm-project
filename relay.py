#!/usr/bin/env python3

import serial
import time
import subprocess


arduino = serial.Serial("/dev/ttyACM0", 115200)

time.sleep(2)
while True:
    msg = subprocess.check_output(
        ["ncat", "-l", "5005"],
        text=True
    
    )
    arduino.write(msg.encode())

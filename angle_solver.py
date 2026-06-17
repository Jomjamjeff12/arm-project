#!/usr/bin/env python3

import math

# upper arm length, forearm length, wrist to centre of gripper length. all measurements in millimeters
L1 = 200
L2 = 200
L3 = 50

def angle_solver(x,y,z):
    # account for base and wrist displacement
    z -= 50
    relative_xy = math.sqrt(x**2 + y**2) - L3
    base_angle_rad = math.atan(x / y)
    base_to_target = math.sqrt(relative_xy**2 + z**2)
    
    if not ( 50 <= base_to_target <= 380 ):
        print("target out of range")
        exit(1)

    elbow_angle_rad = math.acos((L2**2 + L1**2 - base_to_target**2) / (2 * L1 * L2))
    shoulder_angle_rad = math.asin((math.sin(elbow_angle_rad) / base_to_target) * L2)

    # shouler servo has a 2:1 step down, so i double the output angle
    base_angle = round(math.degrees(base_angle_rad) + 90)
    elbow_angle = round(math.degrees(elbow_angle_rad))
    shoulder_angle = round(math.degrees(shoulder_angle_rad)) * 2

    if not (0 <= base_angle <= 180 or 0 <= elbow_angle <= 180 or 0 <= shoulder_angle <= 270):
        print("target out of range")
        exit(1)
       
    print(base_angle)
    print(shoulder_angle)
    print(elbow_angle)

angle_solver(50,300,100)





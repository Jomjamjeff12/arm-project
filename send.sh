#!/usr/bin/env bash

read -p "servo num: " servo
read -p "target angle: " angle

echo "$servo" | ncat 100.118.65.57 5005
echo "$angle" | ncat 100.118.65.57 5006


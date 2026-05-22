#!/usr/bin/env bash

read -p "servo num: " servo
read -p "target angle: " angle

echo "$servo,$angle" | ncat 100.118.65.57 5005



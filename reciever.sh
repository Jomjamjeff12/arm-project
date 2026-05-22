#!/usr/bin/env bash

while [ true ]; do
	servo="$(ncat -l 5005)"
	angle="$(ncat -l 5006)"
done

#!/usr/bin/env bash

while [ true ]; do
	message="$(ncat -l 5005)"
	echo "$message"
done

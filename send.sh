#!/usr/bin/env bash

echo "$1" | ncat 100.118.65.57 5005
echo "$2" | ncat 100.118.65.57 5006


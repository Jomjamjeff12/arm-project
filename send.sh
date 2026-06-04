#!/usr/bin/env bash

if ! pgrep -x ncat; then
  ssh -i ~/.ssh/id_ed25519 will@100.118.65.57 './arm-project/relay.py &'
fi

while true; do
  read -p "servo: " servo
  read -p "angle: " angle
  
  echo $servo | ncat 100.118.65.57 5005
  echo $angle | ncat 100.118.65.57 5006
  if [ "$angle" = "0" ]; then
    ssh -i id_ed25519 will@100.118.65.57 'pkill ncat'
    exit 0
  fi
done

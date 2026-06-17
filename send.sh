#!/usr/bin/env bash

ssh -i ~/.ssh/id_ed25519 will@100.118.65.57 './arm-project/relay.py &'

while true; do
  read -p "servo (q to quit): " servo
  if [ "$servo" = "q" ]; then
    
    ssh -i ~/.ssh/id_ed25519 will@100.118.65.57 'pkill ncat'
    exit 0
  fi
  read -p "angle: " angle
  if (( $servo <= 4 && $servo >= 0  && $angle <= 180 && $angle >= 0 )); then
    msg="$servo,$angle"
    echo $msg | ncat 100.118.65.57 5005
  else
    echo "value out of range"
  fi

done

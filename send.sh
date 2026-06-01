#!/usr/bin/env bash

if ! pgrep -x ncat; then
  ssh -i ~/.ssh/id_ed25519 will@100.118.65.57 './arm-project/relay.py'
fi

while true; do
  read -p "servo: " servo
  read -p "angle: " angle
  
  if [ "$servo" = "stop" ];then
    echo 1 | ncat 100.118.65.57 5005
    echo 90 | ncat 100.118.65.57 5006
    echo 2 | ncat 100.118.65.57 5005 
    echo 180 | ncat 100.118.65.57 5006

    ssh -i ~/.ssh/id_ed25519 will@100.118.65.57 'pkill -9 ncat'
    exit 0
  fi

  echo "$servo" | ncat 100.118.65.57 5005
  echo "$angle" | ncat 100.118.65.57 5006
done

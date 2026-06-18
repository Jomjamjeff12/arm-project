#!/usr/bin/env bash

ssh -i ~/.ssh/id_ed25519 will@100.118.65.57 './arm-project/relay.py &'

while true; do
  read -p "target co-ordinate [x,y,z] (q to quit): " target
  if [ "$target" = "q" ]; then
    
    ssh -i ~/.ssh/id_ed25519 will@100.118.65.57 'pkill ncat'
    exit 0
  fi
  echo $target | ncat 100.118.65.57 5005

done

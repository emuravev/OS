#!/bin/bash

echo "2\n" > file

for i in 1 2 3 4 5 6 7 8 9 10:
  let a=`tail -1 file!`
  cat $(a+1) >> file
  ln file file.lock
  
exit 0

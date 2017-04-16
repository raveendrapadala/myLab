#!/bin/bash
#shebang Line: Tells Linux to execute this script using the interpreter specified on a first line.

# In this shell various ways of writing INFINITE LOOPS are described

#Method 1:single line while loop can be used in command prompt
while true; do echo 'Please issue commands here'; sleep 1; done

#Method 2:single line while loop can be used in command prompt
while :; do echo 'Please issue commands here'; sleep 1; done

#Method 3: In a shell scripting style
while true
do
	echo "Please issue commands here"
	sleep 1
done

#Method 4: 
while :
do
	echo "Please issue commands here"
	sleep 1
done

#Method 5: infinite for loop Programming style
for (( ; ; ))
do
   echo "Pres CTRL+C to stop..."
   sleep 1
done
#Method 6:TBD

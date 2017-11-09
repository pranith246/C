#!/bin/bash
# Author	:	kirito_ys

echo "
=====================	
	MENU
=====================
1. Contents of /etc/passwd
2. Lists of users who have currently logged in
3. Present working Directory
4. Exit

Press key corresponding to option you want to select"

read option

case $option in
		"1")	cat /etc/passwd ;;
		"2")	who ;;
		"3") 	pwd ;;
		"4") 	echo "Exiting scripting..."
			exit;  ;;
	esac


	

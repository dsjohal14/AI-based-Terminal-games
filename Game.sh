clear;
while [ "1" = "1" ]
do
	
	clear
	echo -ne "\e[34m\n\n\n				 Welcome to my Gaming World\n"; tput sgr0;
	echo -ne "\n\n\n\n		1 Battleship\n\n		2 21 Flags\n\n		3 Connect-4\n\n		4 Exit\n\n\n	   Please select any option : ";
	read a;
	if [ "$a" = "1" ]; then
		./battleship;
	fi
	if [ "$a" = "2" ]; then
		./21flags;
	fi
	if [ "$a" = "3" ]; then
		./connect4;
	fi
	if [ "$a" = "4" ]; then
		clear;
		exit;
	fi
	echo -ne "		Press any key to continue.. "
	read b;
done


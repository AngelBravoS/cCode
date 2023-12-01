#include <iostream>
//https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
/*
 "\033[{FORMAT_ATTRIBUTE};{FORGROUND_COLOR};{BACKGROUND_COLOR}m{TEXT}\033[{RESET_FORMATE_ATTRIBUTE}m"
is composed of (name and codec)

FORMAT ATTRIBUTE

 { "Default", "0" },
 { "Bold", "1" },
 { "Dim", "2" },
 { "Italics", "3"},
 { "Underlined", "4" },
 { "Blink", "5" },
 { "Reverse", "7" },
 { "Hidden", "8" }
FORGROUND COLOR

 { "Default", "39" },
 { "Black", "30" },
 { "Red", "31" },
 { "Green", "32" },
 { "Yellow", "33" },
 { "Blue", "34" },
 { "Magenta", "35" },
 { "Cyan", "36" },
 { "Light Gray", "37" },
 { "Dark Gray", "90" },
 { "Light Red", "91" },
 { "Light Green", "92" },
 { "Light Yellow", "93" },
 { "Light Blue", "94" },
 { "Light Magenta", "95" },
 { "Light Cyan", "96" },
 { "White", "97" }
BACKGROUND COLOR

 { "Default", "49" },
 { "Black", "40" },
 { "Red", "41" },
 { "Green", "42" },
 { "Yellow", "43" },
 { "Blue", "44" },
 { "Megenta", "45" },
 { "Cyan", "46" },
 { "Light Gray", "47" },
 { "Dark Gray", "100" },
 { "Light Red", "101" },
 { "Light Green", "102" },
 { "Light Yellow", "103" },
 { "Light Blue", "104" },
 { "Light Magenta", "105" },
 { "Light Cyan", "106" },
 { "White", "107" }
TEXT

RESET FORMAT ATTRIBUTE

 { "All", "0" },
 { "Bold", "21" },
 { "Dim", "22" },
 { "Underlined", "24" },
 { "Blink", "25" },
 { "Reverse", "27" },
 { "Hidden", "28" }
 */

int main () {
	std::cout << "\033[1;31;43mbold red text\033[0m\n";
	std::cout << "\033[1;31mbold red text\033[21m\n";
	std::cout << "\033[2;32mbold red text\033[22m\n";
	std::cout << "\033[3;33mbold red text\033[24m\n";
	std::cout << "\033[4;34mbold red text\033[25m\n";
	std::cout << "\033[5;35mbold red text\033[27m\n";
	std::cout << "\033[7;36mbold red text\033[28m\n";
	std::cout << "\033[7;37mbold red text\033[0m\n";
	std::cout << "\033[8;38mbold red text\033[0m\n";
	return 0;
}

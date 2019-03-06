#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main (){
bool goodChoice;
char choice;

    while (!goodChoice)
    {
    std::cout << "Which stack do you want to choose from ('a', 'b', 'c') ? ";
    std::cin >> choice;
    switch (choice)
    {
        case 'a':
        case 'A': choice = 'A';
                  goodChoice = true;
                    break;
        case 'b':
        case 'B': choice = 'B';
                  goodChoice = true;
                    break;
        case 'c':
        case 'C': choice = 'C';
                  goodChoice = true;
                    break;
        default: std::cout << "Invalid choice." << std::endl;
        }
        return 0;
	}
}

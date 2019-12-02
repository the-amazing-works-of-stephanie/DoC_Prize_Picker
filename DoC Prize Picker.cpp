// DoC Prize Picker.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Header.h"
#include <iostream>
#include <string>
#include <ctime>

void selection();

using namespace std; 

int main()
{
	unsigned seed = time(0); 

	srand(seed); 

	cout << "Welcome to Raptors Who Code's Cyber Monday-themed Day of Code!" << endl; 
	cout << "\nThis program should be used to distribute prizes to random recipients." << endl; 
	cout << "Rules: " << endl; 
	cout << "1. A student cannot receive a gift unless they are present. If someone wins a prize and is not currently present, record their name and the prize they won."; 
	cout << "If they haven't returned by the next giveaway (~30 mins), remove their name from the prizeWinners file and add their prize back into the prizes file." << endl; 
	cout << "2. A person cannot win more than 1 prize. If you notice a duplicate, please notify one of the club officers *before* calling out the winners." << endl; 
	cout << "3. No exchanges are permitted." << endl; 
	cout << "4. If anyone is causing a fuss (i.e. refusing to learn, and is clearly at the event only to get free stuff), the person running this program is permitted to "; 
	cout << "remove their name from the studentNames file before running the program, thus removing their potential to win something." << endl; 
	cout << "\n\n\n" << endl; 

	//call the selection() function
	selection(); 
}

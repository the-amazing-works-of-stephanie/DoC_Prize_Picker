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

	//call the selection() function
	selection(); 
}

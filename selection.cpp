#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "Header.h"

using namespace std;

void selection()
{
	//adding the files into the program
	//"prizes1" contains the first 24 prizes
	ifstream prizes("prizes1.txt", ios::in);
	ifstream student_names("studentNames.txt", ios::in);
	ifstream winners("prizeWinners.txt", ios::out | ios::app);
	vector<string> prizeVector; 
	vector<string> studentNameVector; 
	vector<string> prizeWinnerVector; 
	string line; 
	string tempPrizeArray[5]; 
	string tempStudentArray[5];

	//check if files are valid before proceeding; print some kind of message if there's an error
	if (!prizes || !student_names || !winners)
	{
		cout << "One of the files could not be located." << endl;
	}

	else
	{
		while (getline(prizes, line))
		{
			if (line.size() > 0)
			{
				prizeVector.push_back(line);
				//cout << line << endl; 
			}
		}

		while (getline(student_names, line))
		{
			if (line.size() > 0)
			{
				studentNameVector.push_back(line);
				//cout << line << endl;
			}
		}

		while (getline(winners, line))
		{
			if (line.size() > 0)
			{
				prizeWinnerVector.push_back(line);
				//cout << line << endl;
			}
		}

		//find 5 random winners
		for (int i = 0; i < 5; i++)
		{
			//bool isSame = false;

			//tempStudentArray[i] = studentNameVector[rand(static_cast<int>(time(0)))]; 
			tempStudentArray[i] = studentNameVector[rand() % studentNameVector.size()];

			for (int j = 0; j < tempStudentArray->size(); j++)
			{
				if ((j != i) && (tempStudentArray[j] == tempStudentArray[i]))
				{
					tempStudentArray[i] = pickAWinner(studentNameVector, tempStudentArray, i);
					break;
				}

				else
					continue; 
			}
		}
		for (int i = 0; i < 5; i++)
			cout << tempStudentArray[i] << endl;

		//step 1: prizeVector[distrForPrizes]; 
		//step 2: check if the called prize is in the temp array
		//step 3: if not, add called prize to temp array
		//step 4: call the next random number

		//check winner name against the 'prizeWinners' file; if it's there, delete name from 'studentNames' file & pick another name. Test again, until name is no longer a duplicate
		//write their names into the 'prizeWinners' file
		//delete their names from the 'studentNames' file

		//find 5 random prizes
		//write the prize into the 'prizeWinners' file
		//delete the prize from the 'prizes' file

		//write vectors into files

		//close files
		prizes.close();
		student_names.close();
		winners.close();

		//print out 5 random students from student_names
		//print out 5 random prizes from prizes
	}
}

string pickAWinner(vector<string> vec, string array[], int index)
{
	bool isSame = false; 

	do
	{
		array[index] = vec[rand() % vec.size()];
		
		for (int i = 0; i < array->size(); i++)
		{
			if ((index != i) && array[index] == array[i])
				isSame = true; 
		}

	} while (isSame == true);

	if (isSame == false)
		return array[index];
}

//new theory: 
//fill all 5 names into the tempStudentArray
//use the std::count function to find where all the duplicates are
//call the pickAWinner function to replace the duplicate values
//continue this until all duplicates have been replaced
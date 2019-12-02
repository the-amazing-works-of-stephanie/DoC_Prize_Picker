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
	const int NUM = 5; 
	fstream prizes;
	fstream student_names;
	fstream winners;
	vector<string> prizeVector; 
	vector<string> studentNameVector; 
	vector<string> prizeWinnerVector; 
	string line; 
	vector<string> tempPrizeArray(NUM); 
	vector<string> tempStudentArray(NUM);

	prizes.open("prizes1.txt", ios::in);
	student_names.open("studentNames.txt", ios::in);
	winners.open("prizeWinners.txt", ios::in);

	//check if files are valid before proceeding; print some kind of message if there's an error
	if (!prizes || !student_names || !winners)
	{
		cout << "One of the files could not be located." << endl;
	}

	else
	{
		//writing contents of files into vectors
		while (getline(prizes, line))
		{
			if (line.size() > 0)
			{
				prizeVector.push_back(line);
			}
		}

		while (getline(student_names, line))
		{
			if (line.size() > 0)
			{
				studentNameVector.push_back(line);
			}
		}

		while (getline(winners, line))
		{
			if (line.size() > 0)
			{
				prizeWinnerVector.push_back(line);
			}
		}

		prizes.close();
		student_names.close();
		winners.close();

		//find 5 random winners
		for (int i = 0; i < NUM; i++)
		{
			//pick a random index in the array and assign it to the tempStudentArray
			tempStudentArray[i] = studentNameVector[rand() % studentNameVector.size()];

			//checking the entire tempStudentArray for duplicates
			for (int j = 0; j < NUM; j++)
			{
				//if the indexes don't equal one another and a duplicate is found
				if ((j != i) && (tempStudentArray[j] == tempStudentArray[i]))
				{
					//if there are fewer students in the room than there are indexes in the tempStudentArray
					if(studentNameVector.size() < NUM)
						//enter a blank value
						tempStudentArray[i] = "null"; 
					else
					{
						//otherwise, call generateAgain function to get a new value
						tempStudentArray[i] = generateAgain(studentNameVector, tempStudentArray, i);
						break;
					}
				}

				else
					continue; 
			}
		}
 
		for (int i = 0; i < NUM; i++)
		{
			//loops through studentNameVector to find each item in tempStudentArray, then deletes it from studentNameVector
			vector<string>::iterator position = find(studentNameVector.begin(), studentNameVector.end(), tempStudentArray[i]);
			if (position != studentNameVector.end())
				studentNameVector.erase(position); 
		}

		//check winner name against the 'prizeWinners' file; if it's there, delete name from 'studentNames' file & pick another name. Test again, until name is no longer a duplicate
		//issue: we have a way to check the file, but it's going to require copying code to check for duplicates within tempStudentArray
		for (int i = 0; i < NUM; i++)
		{
			for (int j = 0; j < prizeWinnerVector.size(); j++)
			{
				if (tempStudentArray[i] == prizeWinnerVector[j])
				{
					cout << "There is a duplicate: " + prizeWinnerVector[j] << endl;
					tempStudentArray[i] = studentNameVector[rand() % studentNameVector.size()];
				}
				else
					continue; 
			}
		}

		//open the prizeWinners file for writing
		winners.open("prizeWinners.txt", ios::app);
		//loops through tempStudentArray and writes each winner into the prizeWinners file
		for (auto t = tempStudentArray.begin(); t != tempStudentArray.end(); ++t)
		{
			winners << *t << '\n';
		}

		//open the studentNames file for writing -- empty contents
		student_names.open("studentNames.txt", ios::out);
		//loops through studentNameVector and writes each item into the studentNames file
		for (auto t = studentNameVector.begin(); t != studentNameVector.end(); ++t)
		{
			student_names << *t << '\n';
		}
		
		winners.close();
		student_names.close(); 
		
		//find 5 random prizes
		for (int i = 0; i < NUM; i++) 
		{
			tempPrizeArray[i] = prizeVector[rand() % prizeVector.size()];

			for (int j = 0; j < NUM; j++) 
			{
				if ((i != j) && (tempPrizeArray[i] == tempPrizeArray[j]))
				{
					if (prizeVector.size() < NUM)
						tempPrizeArray[i] = "null";
					else
					{
						tempPrizeArray[i] = generateAgain(prizeVector, tempPrizeArray, i);
						break;
					}
				}
				else
					continue; 
			}
		}

		for (int i = 0; i < NUM; i++)
		{
			//loops through prizeVector to find each item in tempPrizeArray, then deletes it from prizeVector
			vector<string>::iterator position2 = find(prizeVector.begin(), prizeVector.end(), tempPrizeArray[i]);
			if (position2 != prizeVector.end())
				prizeVector.erase(position2);
		}

		//open the prizeWinners file for writing
		winners.open("prizeWinners.txt", ios::app);
		//loops through tempPrizeArray and writes each prize into the prizeWinners file
		for (auto t = tempPrizeArray.begin(); t != tempPrizeArray.end(); ++t)
		{
			winners << *t << '\n';
		}

		//open the prize file for writing -- empty contents
		prizes.open("prizes1.txt", ios::out);
		//loops through prizeVector and writes each item into the prizes file
		for (auto t = prizeVector.begin(); t != prizeVector.end(); ++t)
		{
			prizes << *t << '\n';
		}

		//close files
		prizes.close();
		winners.close();

		//print out the winners and their prizes
		for (int i = 0; i < NUM; i++)
		{
			cout << tempStudentArray[i] + " will receive " + tempPrizeArray[i] + "!" << endl; 
		}
	}
}

/*
This function will loop through the studentNameVector until a unique name is located
*/
string generateAgain(vector<string> vec, vector<string> array, int index)
{
	bool isSame = false; 

	do
	{
		array[index] = vec[rand() % vec.size()];
		
		for (int i = 0; i < array.size(); i++)
		{
			if ((index != i) && array[index] == array[i])
				isSame = true; 
		}

	} while (isSame == true);

	if (isSame == false)
		return array[index];
}
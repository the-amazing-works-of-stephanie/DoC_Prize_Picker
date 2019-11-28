#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
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
	const int genNum = 5;
	string tempPrizeArray[genNum];
	string tempStudentArray[genNum];

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

		//Find 5 random winners
		for (int i = 0; i < genNum; i++)
		{
			//pick a random index in the array and assign it to the tempStudentArray
			tempStudentArray[i] = studentNameVector[rand() % studentNameVector.size()];

			//checking the entire tempStudentArray for duplicates
			for (int j = 0; j < genNum; j++)
			{
				//if the indexes don't equal one another and a duplicate is found
				if ((j != i) && (tempStudentArray[j] == tempStudentArray[i]))
				{
					//if there are fewer students in the room than there are indexes in the tempStudentArray
					if (studentNameVector.size() < genNum)
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

		//Erase the names from studentNames.txt file
		/*for (int i = 0; i < genNum; i++) {
			studentNameVector.erase(std::remove(studentNameVector.begin(), studentNameVector.end(), tempStudentArray[i]), studentNameVector.end());
		}
		
		for (auto t = studentNameVector.begin(); t != studentNameVector.end(); ++t)
			std::cout << "vector names: "<< *t << '\n';


		ofstream newNames;
		newNames.open("studentNames.txt", ios::app);
		for (auto t = studentNameVector.begin(); t != studentNameVector.end(); ++t)
		{
			newNames << *t << '\n';
		}*/

		/*string nameFileContenet = "";
		char ch;
		while (student_names >> std::noskipws >> ch) {
			nameFileContenet += ch;
		}
		cout << "File content: " << nameFileContenet << endl;*/

		

		//Display the 5 names
		cout << "Generate 5 names: " << endl;
		for (int i = 0; i < genNum; i++) {
			cout << (i + 1) << ". " << tempStudentArray[i] << endl;
		}
		cout << endl;


		//Find 5 random prizes
		for (int i = 0; i < genNum; i++) {
			tempPrizeArray[i] = prizeVector[rand() % prizeVector.size()];

			for (int j = 0; j < genNum; j++) {
				if (i != j) {
					if (tempPrizeArray[i] == tempPrizeArray[j]) {
						if (prizeVector.size() < genNum) {
							tempPrizeArray[i] = "null";
						}
						else {
							tempPrizeArray[i] = generateAgain(prizeVector, tempPrizeArray, i);
							break;
						}
					}
				}
			}
		}
		//Display the 5 prizes
		cout << "Generate 5 prizes: " << endl;
		for (int i = 0; i < genNum; i++) {
			cout << (i+1) << ". " << tempPrizeArray[i] << endl;
		}
		cout << endl;

		/*ofstream prizes1;
		prizes1.open("prizes1.txt");
		while (getline(prizes, line)) {
			int i = 0;
			if (line != tempPrizeArray[i])
				prizes1 << line << endl;
		}
		remove("prizes1.txt");
		rename("prizes1.txt", "prizes1.txt");
		*/

		//Save the names and prizes into prizeWinners.txt
		ofstream winnerList;
		winnerList.open("prizeWinners.txt", ios::app);
		for (int i = 0; i < genNum; i++)
		{
			winnerList << tempStudentArray[i] << ": " << tempPrizeArray[i] << endl;
		}
		

		//Renmove the names and prizes from the text files


		/*student_names.open("studentNames.txt");
		string l;
		ofstream temp;
		temp.open("newNames.txt");
		string deleteN = "Alex";
		
		while (getline(student_names, l))
		{
			
				l.replace(l.find(deleteN), deleteN.length(), "");
				temp << l << endl;
			
		}
		

		temp.close();
		student_names.close();
		remove("studentNames.txt");
		rename("newNames.txt", "studentNames.txt");*/

















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

		//return 5 winners & 5 prizes
	}
}

 string generateAgain(vector<string> vec, string array[], int index)
{
	bool isSame = false;

	do
	{
		array[index] = vec[rand() % vec.size()];

		for (int i = 0; i < 5; i++)
		{
			if ((index != i) && array[index] == array[i])
				isSame = true;
		}

	} while (isSame == true);

	if (isSame == false)
		return array[index];
}

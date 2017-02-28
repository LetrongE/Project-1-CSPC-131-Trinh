#pragma once
#include <string>
#include <stdexcept>
#include <fstream>
#include "Baby.h"
#include <iostream>
using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord();

	// destructor
	~MedicalRecord();

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName();

	// return the number of baby records loaded from the text file
	int numberOfBirths();

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight();

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s);
private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b);
	int numOfBirths; //use counter in addEntry to determine
	Baby* dataKeep; //points to dynamic memory array holding the objects
	int maxEntries; //holds inputted value of maximum entries



					// Add private member variables for your data structure along with any 
					// other variables required to implement the public member functions

};

MedicalRecord::MedicalRecord() {
	cout << "Please enter maximum number of entries allowed: ";
	cin >> maxEntries;
	/*Above is preferred method to use space only as necessary upon creation of array,
	however it does not run properly with the automated test. Code has been updated
	to automatically include a maximum array size that supports both the small and large
	baby file tests.
	*/
	//maxEntries = 200000;
	dataKeep = new Baby[maxEntries];
	numOfBirths = 0;
}//ask user to input maximum number of entries to build adequate array; creates array in heap based on input size

MedicalRecord::~MedicalRecord() {
	delete[] dataKeep;
}//delete the array

string MedicalRecord::mostPopularName() {
	int maxNameCount = 0, previousMax = 0;
	string maxName;
	for (int i = 0; i < numOfBirths; i++) {
		for (int j = 0; j < numOfBirths; j++) {
			if (dataKeep[i].getName() == dataKeep[j].getName()) {
				maxNameCount++;
			}//two for loops to check for matching names; matched names cause counter to increment
		}
		if (maxNameCount > previousMax) {
			maxName = dataKeep[i].getName();
			previousMax = maxNameCount;
			maxNameCount = 0;
		}//check to see if previous most popular name will be overridden

	}
	return maxName;
}

int MedicalRecord::numberOfBirths() {
	return numOfBirths;
}//return the numOfBirths based on number of entries added into array

int MedicalRecord::numberOfBabiesWithLowBirthWeight() {
	int lowBirthWeight = 0;
	for (int i = 0; i < numOfBirths; i++) {
		if (dataKeep[i].getWeight() < 2500) {
			lowBirthWeight++;
		}
	}
	return lowBirthWeight;
}//loop to see if weight matches criteria

int MedicalRecord::numberOfBabiesWithName(string s) {
	int numSameName = 0;
	for (int i = 0; i < numOfBirths; i++) {
		if (dataKeep[i].getName() == s)
			numSameName++;
	}
	return numSameName;
}//loop to see if name matches criteria

void MedicalRecord::addEntry(Baby b) {
	//for (int i = 0; i>numOfBirths; i++)
	
			dataKeep[numOfBirths] = b;
			numOfBirths++;
		
}//places created object into array; tracked by when object is added

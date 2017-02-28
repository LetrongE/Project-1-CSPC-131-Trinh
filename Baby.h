#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() {  // default constructor
	};

	Baby(string s, int w);

	// a "getter" method
	int getWeight();

	// a "getter" method
	string getName();

private:
	string name;
	int weight;
};

Baby::Baby(string s, int w) {
	name = s;
	weight = w;
}

int Baby::getWeight() {
	return weight;
}//returns weight of the baby

string Baby::getName() {
	return name;
}//returns name of the baby
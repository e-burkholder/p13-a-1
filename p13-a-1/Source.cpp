#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void pressEnterToContinue();
bool readFromFile(string filename);

int main() {
	string datafile;
	cout << "input file: ";
	getline(cin, datafile);
	bool status = readFromFile(datafile);
	pressEnterToContinue();

}

}

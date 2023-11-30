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

// pressEnterToContinue: used to keep the console window open long enough to see your program's output
void pressEnterToContinue() {
	char c;
	cout << "Press Enter to continue...";
	cin.ignore(1024, '\n');
	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}


bool readFromFile(string filename) {
	ifstream inFile;				 //input filestream for reading in data
	string word;					 //word info
	int letterCount = 0;			 //char count

	//ACCOUNTING FOR UNAVAILABLE FILE
	inFile.open(filename);
	if (inFile.fail()) {
		cout << "read error - sorry\n";
		return false;
	}

	while (inFile >> word) {
		bool isLetter = false;
		//FINDING THE TOTAL LETTER COUNT OF THE TEXT
		for (size_t i = 0; i < word.length(); ++i) {
			char ch = word[i];
			if (ch == 'Q' || ch == 'W' || ch == 'E' || ch == 'R' || ch == 'T' || ch == 'Y'
				|| ch == 'U' || ch == 'I' || ch == 'O' || ch == 'P' || ch == 'A'
				|| ch == 'S' || ch == 'D' || ch == 'F' || ch == 'G' || ch == 'H'
				|| ch == 'J' || ch == 'K' || ch == 'L' || ch == 'Z' || ch == 'X'
				|| ch == 'C' || ch == 'V' || ch == 'B' || ch == 'N' || ch == 'M'
				|| ch == 'q' || ch == 'w' || ch == 'e' || ch == 'r' || ch == 't'
				|| ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'p'
				|| ch == 'a' || ch == 's' || ch == 'd' || ch == 'f' || ch == 'g'
				|| ch == 'h' || ch == 'j' || ch == 'k' || ch == 'l' || ch == 'z'
				|| ch == 'x' || ch == 'c' || ch == 'v' || ch == 'b' || ch == 'n'
				|| ch == 'm') {
				isLetter = true;
				letterCount++;
			}
		}
	}

	cout << "Total number of letters: " << letterCount << "\n";
	inFile.close();
	return true;
}

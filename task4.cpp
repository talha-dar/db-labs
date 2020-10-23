#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

int main() {
	char reg[15]{ '\0' };
	Student temp;
	cout << "\nEnter reg#: ";
	cin >> reg;

	ifstream fin("data.csv");
	ofstream fout("task4.csv");

	while (!fin.eof()) {
		fin >> temp;
		if (isStrEqual(temp.getRegistration(), reg)) {
			continue;
		}
		fout << temp;
	}

	return 0;
}
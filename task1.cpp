#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

int main() {
	char reg[15]{ '\0' };
	char record[100]{ '\0' };
	Student temp;

	cout << "\nEnter reg#: ";
	cin >> reg;

	ifstream fin("data.csv");
	while (!fin.eof()) {
		fin >> temp;
		if (isStrEqual(temp.getRegistration(), reg)) {
			cout << temp;
			break;
		}
	}
	fin.eof();

	return 0;
}
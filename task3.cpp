#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

int main() {
	char reg[15]{ '\0' };
	char cgpa[5]{ '\0' };
	Student temp;

	cout << "\nEnter reg : ";
	cin >> reg;

	cout << "\nEnter cgpa: ";
	cin >> cgpa;

	ofstream fout("task3.csv");
	ifstream fin("data.csv");

	while (!fin.eof()) {
		fin >> temp;
		if (isStrEqual(temp.getRegistration(), reg)) {
			temp.setCGPA(atof(cgpa));
		}
		fout << temp;
	}

	fout.close();
	fin.close();
	return 0;
}
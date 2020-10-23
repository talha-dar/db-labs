#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;

int main() {
	char reg[15]{ '\0' };
	char name[50]{ '\0' };
	char progn[5]{ '\0' };
	char cgpa[5]{ '\0' };
	char num[20]{ '\0' };

	Student temp;
	cout << "\nEnter comma separated record. NO WHITESPACES: ";
	cin >> temp;
	
	// open or create file, cout data to it, then close.
	ofstream fout("data.csv", ios::out | ios::app);
	fout << temp;
	fout.close();

	return 0;
}
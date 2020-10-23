#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	char *registration;
	char* name;
	char *program;
	double CGPA;
	char *contact;

public:
	Student(const char *_registration = nullptr,const char *_name = nullptr, const char *_program = nullptr, const double _CGPA = 0, const char *_contact = nullptr);
	Student(const Student &);
	~Student();

	// setters
	void setRegistration(const char *);
	void setName(const char *);
	void setProgram(const char *);
	void setCGPA(const double);
	void setContact(const char *);

	//getters
	char *getRegistration() const;
	char *getName() const;
	char *getProgram() const;
	double getCGPA() const;
	char *getContact() const;

	// operators

	// assignment
	Student &operator=(const Student &src);

	// stream operators
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, const Student&);
};

int len(const char*);
void deepCopy(char*&, const char*);
bool isStrEqual(const char*, const char*);
void clearStr(char*);


#pragma once
#include <iostream>
#include "otherfunc.cpp"
using namespace std;

class Student
{
private:
    char *registration;
    char *firstName;
    char *lastName;
    char *program;
    double CGPA;
    char *contact;

public:
    Student(const char *_registration = nullptr, const char *_firstName = nullptr, const char *_lastName = nullptr, const char *_program=nullptr, const double _CGPA = 0, const char *_contact = nullptr);
    Student(const Student &);
    ~Student();

    // setters
    void setRegistration(const char *);
    void setFirstName(const char *);
    void setLastName(const char *);
    void setProgram(const char *);
    void setCGPA(const double);
    void setContact(const char *);

    //getters
    char *getRegistration() const;
    char *getFirstName() const;
    char *getLastName() const;
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
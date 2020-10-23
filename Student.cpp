#include "Student.h"

Student::Student(const char *_registration, const char *_firstName, const char *_lastName, const char *_program, const double _CGPA, const char *_contact)
{
    if (_registration && _firstName && _lastName && _program && _contact && _CGPA >= 0)
    {
        deepCopy(registration, _registration);
        deepCopy(lastName, _lastName);
        deepCopy(firstName, _firstName);
        deepCopy(program, _program);
        deepCopy(contact, _contact);
        CGPA = _CGPA;
    }
}

Student::~Student()
{
    // Since Student object is created will all attribute set at once, we need only check only attribute for memory to conclude all others have allocated memory as well.
    if (registration)
    {
        delete[] registration, firstName, lastName, program, contact;
        registration = nullptr, firstName = nullptr, lastName = nullptr, program = nullptr, contact = nullptr;
    }
}

Student::Student(const Student &src)
{
    if (src.registration)
    {
        deepCopy(registration, src.registration);
        deepCopy(lastName, src.lastName);
        deepCopy(firstName, src.firstName);
        deepCopy(program, src.program);
        deepCopy(contact, src.contact);
        CGPA = src.CGPA;
    }
    else
    {
        registration = nullptr, firstName = nullptr, lastName = nullptr, program = nullptr, contact = nullptr;
        CGPA = 0;
    }
}
void Student::setRegistration(const char *str)
{
    if (str)
    {
        if (registration)
        {
            delete[] registration;
            registration = nullptr;
        }
        deepCopy(registration, str);
    }
}

void Student::setFirstName(const char *str)
{
    if (str)
    {
        if (firstName)
        {
            delete[] firstName;
            firstName = nullptr;
        }
        deepCopy(firstName, str);
    }
}

void Student::setLastName(const char *str)
{
    if (str)
    {
        if (lastName)
        {
            delete[] lastName;
            lastName = nullptr;
        }
        deepCopy(lastName, str);
    }
}

void Student::setProgram(const char *str)
{
    if (str)
    {
        if (program)
        {
            delete[] program;
            program = nullptr;
        }
        deepCopy(program, str);
    }
}

void Student::setContact(const char *str)
{
    if (str)
    {
        if (contact)
        {
            delete[] contact;
            contact = nullptr;
        }
        deepCopy(contact, str);
    }
}

void Student::setCGPA(const double num)
{
    if (num >= 0)
    {
        CGPA = num;
    }
}

char *Student::getRegistration() const
{
    char *temp = nullptr;
    if (registration)
    {
        deepCopy(temp, registration);
    }
    return temp;
}

char *Student::getFirstName() const
{
    char *temp = nullptr;
    if (firstName)
    {
        deepCopy(temp, firstName);
    }
    return temp;
}

char *Student::getLastName() const
{
    char *temp = nullptr;
    if (lastName)
    {
        deepCopy(temp, lastName);
    }
    return temp;
}

char *Student::getProgram() const
{
    char *temp = nullptr;
    if (program)
    {
        deepCopy(temp, program);
    }
    return temp;
}

char *Student::getContact() const
{
    char *temp = nullptr;
    if (contact)
    {
        deepCopy(temp, contact);
    }
    return temp;
}

double Student::getCGPA() const
{
    return CGPA;
}

// assignment operator

Student &Student::operator=(const Student &src)
{
    // Since Student object is created will all attribute set altogether,
    // we need only check one attribute for memory to conclude that all other attributes have allocated memory as well.
    if (this != &src)
    {
        if (src.registration)
        {
            if (registration)
            {
                delete[] registration, firstName, lastName, program, contact;
                registration = nullptr, firstName = nullptr, lastName = nullptr, program = nullptr, contact = nullptr;
            }
            deepCopy(registration, src.registration);
            deepCopy(firstName, src.firstName);
            deepCopy(lastName, src.lastName);
            deepCopy(program, src.program);
            deepCopy(contact, src.contact);
            CGPA = src.CGPA;
        }
    }
    return *this;
}

ostream &operator<<(ostream &out, const Student &src)
{
    out << src.getRegistration() << ",";
    out << src.getFirstName() << ",";
    out << src.getLastName() << ",";
    out << src.getProgram() << ",";
    out << src.getCGPA() << ",";
    out << src.getContact() << '\n';
    return out;
}

istream &operator>>(istream &in, Student &dest)
{
    char record[200]{'\0'};
    char registration[14]{'\0'}; //L1S19BSCS0060
    char fName[26]{'\0'};
    char lName[26]{'\0'};
    char program[11]{'\0'};
    char contact[12]{'\0'}; //03330000000
    char CGPA[5]{'\0'};
    int i = 0, j = 0;

    //get input stream from user
    in.getline(record, 199);

    // separate each csv attribute from record into an array
    // i+=2 before each separation to skipover comma and whitespace
    //registration#
    while (record[i] != ',')
    {
        registration[j++] = record[i++];
    }

    //first name
    i += 1, j = 0;
    while (record[i] != ',')
    {
        fName[j++] = record[i++];
    }

    // last name
    i += 1, j = 0;
    while (record[i] != ',')
    {
        lName[j++] = record[i++];
    }

    // program
    i += 1, j = 0;
    while (record[i] != ',')
    {
        program[j++] = record[i++];
    }

    //CGPA
    i += 1, j = 0;
    while (record[i] != ',')
    {
        CGPA[j++] = record[i++];
    }

    //contact
    i += 1, j = 0;
    while (record[i] != '\0')
    {
        contact[j++] = record[i++];
    }

    // assign attributes to Student class
    dest.setRegistration(registration);
    dest.setFirstName(fName);
    dest.setLastName(lName);
    dest.setProgram(program);
    dest.setCGPA(atof(CGPA)); // std::atof() converts cstring to double
    dest.setContact(contact);

    //
    return in;
}
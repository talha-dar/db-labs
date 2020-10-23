#include "Student.h"

Student::Student(const char *_registration, const char *_name,const char *_program, const double _CGPA, const char *_contact)
{
	if (_registration && _name && _program && _contact && _CGPA >= 0)
	{
		deepCopy(registration, _registration);
		deepCopy(name, _name);
		deepCopy(program, _program);
		deepCopy(contact, _contact);
		CGPA = _CGPA;
	}
	else {
		registration = nullptr;
		name = nullptr;
		program = nullptr;
		CGPA = 0;
		contact = 0;
	}
}

Student::~Student()
{
	// Since Student object is created will all attribute set at once, we need only check only attribute for memory to conclude all others have allocated memory as well.
	if (registration)
	{
		delete[] registration, name, program, contact;
		registration = nullptr, name = nullptr, program = nullptr, contact = nullptr;
	}
}

Student::Student(const Student &src)
{
	if (src.registration)
	{
		deepCopy(registration, src.registration);
		deepCopy(name, src.name);
		deepCopy(program, src.program);
		deepCopy(contact, src.contact);
		CGPA = src.CGPA;
	}
	else
	{
		registration = nullptr, name = nullptr, program = nullptr, contact = nullptr;
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

void Student::setName(const char *str)
{
	if (str)
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
		deepCopy(name, str);
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

char *Student::getName() const
{
	char *temp = nullptr;
	if (name)
	{
		deepCopy(temp, name);
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
				delete[] registration, name, program, contact;
				registration = nullptr, name = nullptr, program = nullptr, contact = nullptr;
			}
			deepCopy(registration, src.registration);
			deepCopy(name, src.name);
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
	out << src.getName() << ",";
	out << src.getProgram() << ",";
	out << src.getCGPA() << ",";
	out << src.getContact() << '\n';
	return out;
}

istream &operator>>(istream &in, Student &dest)
{
	char record[200]{ '\0' };
	char registration[14]{ '\0' }; //L1S19BSCS0060
	char name[100]{ '\0' };
	char program[11]{ '\0' };
	char contact[12]{ '\0' }; //03330000000
	char CGPA[5]{ '\0' };
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
		name[j++] = record[i++];
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
	dest.setName(name);
	dest.setProgram(program);
	dest.setCGPA(atof(CGPA)); 
	dest.setContact(contact);

	//
	return in;
}


int len(const char *arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return i;
}

void deepCopy(char *&dest, const char *src)
{
	// create memory
	int l = 0;
	if (src)
	{
		l = len(src);
		dest = new char[l + 1]{ '\0' };
	}

	// copy memory
	for (int i = 0; i < l; i++)
	{
		dest[i] = src[i];
	}
}

bool isStrEqual(const char *str1, const char *str2)
{
	if (len(str1) != len(str2))
	{
		return false;
	}
	else
	{
		for (int i = 0; str1[i] != '\0'; i++)
		{
			if (str1[i] != str2[i])
			{
				return false;
			}
		}
		return true;
	}
}

// empties a string any string
void clearStr(char *str)
{
	if (str)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			str[i] = '\0';
		}
	}
}
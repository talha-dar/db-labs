#include<iostream>
#include"otherfunc.cpp"
using namespace std;


class Employee{
    private:
    int ID;
    char* name;
    char* joiningDate;
    int departmentID;
    char* contact;
    long salary;
    char maritalStatus;
    
    public:
    Employee(const int _ID=0, const char* _name=nullptr, const char* _joiningDate=nullptr, const int _departmentID=0, const char* _contact=nullptr, const long _salary=0, const char _maritalStatus='\0');
    Employee(const Employee&);
    ~Employee();
    //setters
    void setID(const int);
    void setDepartmentID(const int);
    void setSalary(const long);
    void setMaritalStatus(const char);
    void setName(const char*);
    void setJoiningDate(const char);
    void setContact(const char*);
    //getters
    int getID()const;
    char* getName()const;
    char* getJoiningDate()const;
    int getDepartmentID()const;
    char* getContact()const;
    long getSalary()const;
    char getMaritalStatus()const;

    //operators
    Employee& operator=(const Employee&);
    friend istream& operator>>(istream&, Employee&);
    friend ostream& operator<<(ostream&, const Employee&);
};
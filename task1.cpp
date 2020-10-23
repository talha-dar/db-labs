#include<iostream>
#include<fstream>
#include"otherfunc.cpp"
using namespace std;

int main(){
    char filename[]={"StudentInfo.csv"};
    char registration[14]={'\0'}; //L1S19BSCS0060
    char fName[26]={'\0'};
    char lName[26]={'\0'};
    char program[11]={'\0'};
    char contact[12]={'\0'};//03330000000
    double CGPA;
    CGPA = 0;
    char record[200]{'\0'};
    int listSize;
    listSize = 3;
    // create filestream
    fstream fout;
    fout.open(filename, ios::out | ios::app);//creates new file or opens to append

    // clear arrays for next input
    for(int i=0; i<listSize; i++){
        
        // get student info from user
        cout<<"\nReg#: ";
        cin>>registration;
        cout<<"\nFirst Name: ";
        cin>>fName;
        cout<<"\nLasr Name: ";
        cin>>lName;
        cout<<"\nProgram: ";
        cin>>program;
        cout<<"\nCGPA: ";
        cin>>CGPA;
        cout<<"\nContact: ";
        cin>>contact;

        // write stuff to file
        fout<<registration<<','<<fName<<','<<lName<<','<<program<<','<<CGPA<<','<<contact<<'\n';

        //clear arrays
        clearStr(registration);
        clearStr(fName);
        clearStr(lName);
        clearStr(program);
        clearStr(contact);
    }

    fout.close();
    cout<<"\nFile written.";
    return 0;
}
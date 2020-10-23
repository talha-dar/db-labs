#include <iostream>
#include <fstream>
#include"Student.h"
#include"Student.cpp"
using namespace std;

template<typename T>
void arrayGrow(T*& arr, int& size){
    if(size==0){
        size++;
        arr= new T[size]{};
    }
    else{
        //backup current contents of arr
        T* temp=new T[size*2]{};
        for(int i=0; i<size; i++){
            temp[i]=arr[i];
        }

        //delete contents of current array
        delete[] arr;
        
        //point arr to newly created memory
        size=size*2;
        arr=temp;
    }
}

int main()
{
    char filename[]={"StudentInfo.csv"};
    int count=6;
    Student* students=new Student[count]{};
    
    //opening file stream
    ifstream fin(filename);
    if(!fin.is_open()){
        cout<<"\nFile not found.";
        return 0;
    }

    //reading records onto students array
    fin.ignore(199,'\n');//ignore the title line
    for(int i=0; i<count;i++){
        fin>>students[i];
    }
    fin.close();

    //iterate array and print stuff
    for(int i=0; i<count;i++){
        if(students[i].getCGPA()>=3.5){
            cout<<"\n"<<students[i].getFirstName()<<' '<<students[i].getLastName();
        }
    }

    // delete memory
    delete[] students;
    students=nullptr;
    return 0;
}
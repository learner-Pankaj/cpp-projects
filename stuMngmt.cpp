//headers
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

void project();
void addData();
void displayData();
void deleteData();
void trashData();

class Student{
    int admissionNo;
    char sname[20];
    char sgender;
    int std;
    float smarks;
    double spercentage;

    public:
        void getData();
        void showData();
        int getAdmNo(){
            return admissionNo;
        }

}s;     //another way of creating obj of class

int main(){
    project();
    return 0;
}


void project(){
    int ch;
    do
    {
        system("cls");
        cout << "*****************STUDENT MANAGEMENT SYSTEM*****************\n";
        cout << "1. Write Student Record\n";
        cout << "2. Read Student Record\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Get Deleted Record\n";
        cout << "0. Exit\n";
        cout << "Enter your choice\n";
        cin >> ch;

        system("cls");
        switch (ch)
        {
        case 1:
            addData();
            break;
        case 2: 
            displayData();
            break;
        case 3:
            deleteData();
            break;
        case 4:
            trashData();
            break;
        default:
            cout << "Enter Valid number";
            break;
        }

        system("pause");

    } while (ch);
    
}

void addData(){
    ofstream fout;
    fout.open("Stu.txt", ios::out | ios::app | ios::binary);
    s.getData();
    fout.write((char*)&s, sizeof(s));   //write data in file
    fout.close();
    cout << "\n\n********Data Saved in flie Successfully*********\n";

}

void Student::getData(){
    cout << "\n\n***********Enter Student Details***********\n\n";
    cout << "Admission Number : "; cin >> admissionNo;
    cout << "\nFullName : ";
    cin.ignore(); cin.getline(sname, 20);
    cout << "Gender (M/F) : "; cin >> sgender;
    cout << "Class "; cin >> std;
    cout << "Total marks (\500) "; cin >> smarks;
    cout << endl;
    spercentage = (smarks*100.0)/500.00; 
}

void Student::showData(){
    cout << "\n\n**************Student Details**************\n\n";
    cout << "Admision Number : "<< admissionNo << endl;
    cout << "Student Name : "<<sname<<endl;
    cout << "Gender : " << sgender << endl;
    cout << "Class : " << std << endl;
    cout << "Total marks : " << smarks << endl;
    cout << "Percentage : " << spercentage << endl;
}

void displayData(){
    ifstream fin;
    fin.open("Stu.txt", ios::in | ios::binary);
    while(fin.read((char*)&s, sizeof(s)));{
        s.showData();
    }
    fin.close();
    cout << "\n\n******Data reading from file is successfully done******\n";
}

void deleteData(){
    int n, flag = 0;
    ifstream fin;
    ofstream fout, tout;
    fin.open("Stu.txt", ios::in | ios::binary);
    fout.open("Temp.txt", ios::out | ios::binary);
    tout.open("Trash.txt", ios::out | ios::binary);
    cout << "Enter Admission number";
    cin >> n;
    while(fin.read((char*)&s, sizeof(s))){
        if(n==s.getAdmNo()){
            cout << " This Record " << n << "has been sent to Trash.\n";
            s.showData();
            tout.write((char*)&s, sizeof(s));
            flag++;
        }else{
            fout.write((char*)&s, sizeof(s));
        }
    }
    fout.close();
    tout.close();
    fin.close();

    if(flag == 0){
        cout << " " << "No record found\n\n";
    }
    remove("Stu.txt");
    rename("Temp.txt", "Stu.txt");

}

void trashData(){
    ifstream fin ;
    fin.open("Trash.txt", ios::in | ios::binary);
    while(fin.read((char*)&s, sizeof(s))){
        s.showData();
    }
    fin.close();
    cout << "Reading data from trash file successfully\n";
}
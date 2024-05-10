
#include <iostream>
#include<string>
using namespace std;

struct Employee{
    int empId;
    string name;
    int age;
    double salary;
};

void displayEmployee(Employee& emp){
    cout << "Employee ID : " <<emp.empId << endl;
    cout << "Employee name : " <<emp.name << endl;
    cout << "Employee age : " <<emp.age << endl;
    cout << "Employee salary : " <<emp.salary << endl;
}

int main()
{
    int MAX_EMPLOYEE = 100;
    int numOfEmp = 0;
    struct Employee emp[MAX_EMPLOYEE];
    
    int choice;
    do{
        cout << "Menu" << endl;
        cout << "1. Add Employee\n";
        cout << "2. Display Employee\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice : ";
        cin >> choice;
        
        switch(choice){
            case 1:
                if(numOfEmp<MAX_EMPLOYEE){
                    cout << "Enter Employee Id ";
                    cin >> emp[numOfEmp].empId;
                    cout << "Enter Employee name ";
                    cin.ignore();
                    getline(cin, emp[numOfEmp].name);
                    // cin >> emp[numOfEmp].name;
                    cout << "Enter Employee age ";
                    cin >> emp[numOfEmp].age;
                    cout << "Enter Employee salary ";
                    cin >> emp[numOfEmp].salary;
                    numOfEmp++;
                }else{
                    cout << "cannot add more employee, Array is full.";
                }
                break;
            case 2:
                if(numOfEmp>0){
                    cout << "\nEmployee Details.\n";
                    for(int i=0; i<numOfEmp; i++){
                        displayEmployee(emp[i]);
                        cout << endl;
                    }
                }else{
                    cout << "No Employee to display\n";
                }
                break;
            case 3: 
                cout << "Exiting the program.\n";
                break;
            default: 
                cout << "Invalid choice.\n";
                break;
        }
    }while(choice != 3);
    return 0;
}


#include <iostream>
#include<string>
using namespace std;

struct Employee{
    int empId;
    string name;
    int age;
    double salary;
};

void addEmployee(Employee emp[], int numOfEmp){
    cout << "Enter Employee Id ";
    cin >> emp[numOfEmp].empId;
    cout << "Enter Employee name ";
    cin.ignore();
    getline(cin, emp[numOfEmp].name);
    cout << "Enter Employee age ";
    cin >> emp[numOfEmp].age;
    cout << "Enter Employee salary ";
    cin >> emp[numOfEmp].salary;
}

void displayEmployee(Employee& emp){
    cout << "Employee ID : " <<emp.empId << endl;
    cout << "Employee name : " <<emp.name << endl;
    cout << "Employee age : " <<emp.age << endl;
    cout << "Employee salary : " <<emp.salary << endl;
}

int searchById(Employee emp[], int numOfEmp, int id){
    for(int i=0; i<numOfEmp; i++){
        if(emp[i].empId==id){
            return i;
        }
    }
    return -1;
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
        cout << "3. Search Employee\n";
        cout << "4. Update Salary\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "\nEnter your choice : ";
        cin >> choice;
        
        switch(choice){
            case 1:  //ADD EMPLOYEE
                if(numOfEmp<MAX_EMPLOYEE){
                    addEmployee(emp, numOfEmp);
                    numOfEmp++;
                }else{
                    cout << "cannot add more employee, Array is full.";
                }
                break;
            case 2: // DISPLAY EMPLOYEE
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
            case 3: //SEARCH EMPLOYEE
                if(numOfEmp>0){
                    int id;
                    cout << "Enter the ID of the employee : ";
                    cin >> id;
                    int index = searchById(emp, numOfEmp, id);
                    if(index != -1){
                        displayEmployee(emp[index]);
                    }else{
                        cout << "No Emplodyee found. \n";
                    }
                }else{
                    cout << "No Employee found\n";
                }
                
                break;
            case 4: //UPDATE SALARY
                if(numOfEmp>0){
                    int id;
                    cout << "Enter the ID of the employee : ";
                    cin >> id;
                    int index = searchById(emp, numOfEmp, id);
                    if(index != -1){
                        cout << "Enter salary ";
                        cin >> emp[index].salary;
                        cout << "\n Salary updated \n";
                        displayEmployee(emp[index]);
                    }else{
                        cout << "No Emplodyee found. \n";
                    }
                }else{
                    cout << "No Employee found\n";
                }
                break;
            case 5: //DELETE EMPLOYEE
                if(numOfEmp>0){
                    int id;
                    cout << "Enter the ID of the employee you want to delete : ";
                    cin >> id;
                    int index = searchById(emp, numOfEmp, id);
                    if(index != -1){
                        for(int i=index; i<numOfEmp-1; i++){
                            emp[i]=emp[i+1];
                        }
                        numOfEmp--;
                        for(int i=0; i<numOfEmp; i++){
                            displayEmployee(emp[i]);
                            cout << endl;
                        }
                    }else{
                        cout << "No Emplodyee found. \n";
                    }
                }else{
                    cout << "No Employee found\n";
                }
                break;
            case 6: //EXIT PROGRAM
                cout << "Exiting the program.\n";
                break;
            default: //DEFAULT HANDLE
                cout << "Invalid choice.\n";
                break;
        }
    }while(choice != 6);
    return 0;
}

#include<conio.h>
#include<iostream>
#include<string>

using namespace std;

class atm{
    private:
        long int accountNo;
        string name;
        int PIN;
        double balance;
        string mobileNo;
    
    public:
        //set data
        void setData(long int accountNo_a, string name_a, int PIN_a, double balance_a, string mobileNo_a){
            accountNo = accountNo_a;
            name = name_a;
            PIN = PIN_a;
            balance = balance_a;
            mobileNo = mobileNo_a;
        }

        long int getAccountNo(){
            return accountNo;
        }
        string getName(){
            return name;
        }
        int getPIN(){
            return PIN;
        }
        double getBalance(){
            return balance;
        }
        string getMobileNo(){
            return mobileNo;
        }

        void setMobileNo(string mob_curr, string mob_new){
            if(mob_curr == mobileNo){
                mobileNo = mob_new;
                cout << "\nSuccessfully updated mobile number."<<endl;
                getch();
            }
            else{
                cout << "\nCurrent mobile number is not correct"<<endl;
                getch();
            }
        }

        //to Withdraw cash 
        void cashWithdraw(int amount_a){
            if(amount_a > 0 && amount_a < balance){
                balance = balance-amount_a;
                cout << "\nPlease collect you cash\n";
                cout << "\nAvailable balance : " << balance << endl;
                getch();
            }else{
                cout << "\nInsufficieant balance or Incorrect entry"<<endl;
                getch();
            }
        }
};

int main(){
    int feature = 0, enterPIN;
    long int enterAccountNo;

    system("cls");

    atm user1;
    //set data of user1 using atm object
    user1.setData(123456789, "Pankaj", 1234, 50000.12, "9876598765");

    do
    {
        system("cls");
        cout << endl << "*****Welcome to ATM*****" << endl;
        cout << endl << "Enter your Account No : ";    //asking user to authenticate with account no
        cin >> enterAccountNo;
        cout << endl << "Enter PIN : ";
        cin >> enterPIN;


        if((enterAccountNo==user1.getAccountNo()) && (enterPIN == user1.getPIN())){
            do{
               int amount = 0;
               string oldMobleNo, newMobileNo;
               system("cls");
               cout << endl << "*****Welcome "<< user1.getName() << "*****" << endl;
               cout << endl << "Select Options";
               cout << endl << "1. Check Balance";
               cout << endl << "2. Cash Withdraw";
               cout << endl << "3. Show UserDetails";
               cout << endl << "4. Update Mobile Number";
               cout << endl << "5. Exit" << endl;

               cin >> feature;

               switch (feature)
               {
               case 1:
                cout << endl << "Your bank balance is : "<< user1.getBalance() << endl;
                getch();
                break;
               case 2:
                cout << endl << "Enter Amount : ";
                cin >> amount;
                user1.cashWithdraw(amount);
                getch();
                break;
               case 3:
                cout << endl << "***Your Details***";
                cout << endl << "Account Number -> " << user1.getAccountNo();
                cout << endl << "Name -> " << user1.getName();
                cout << endl << "Balance -> " << user1.getBalance();
                cout << endl << "Mobile Number -> " << user1.getMobileNo() << endl;
                getch();
                break;
               case 4:
                cout << endl << "Enter Old Mobile number : ";
                cin >> oldMobleNo;
                cout << endl << "Enter New Mobile number : ";
                cin >> newMobileNo;
                user1.setMobileNo(oldMobleNo, newMobileNo);
                getch();
                break;
               case 5:
                exit(0); 
               
               default:
                cout << endl << "Provide Valid Entry!!!";
               }
            }while(1); 
        }
    } while (1);
    
}
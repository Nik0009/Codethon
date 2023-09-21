// header files
#include <iostream>
using namespace std;

// constants max accounts
const int MAX_ACCOUNTS = 100;

// declaring arrays and variables to store account information
string accountNumbers[MAX_ACCOUNTS];
string accountHolders[MAX_ACCOUNTS];
double accountBalances[MAX_ACCOUNTS];

int accountCounter = 0;
int loggedInAccountIndex = -1;

// class bank
class Bank
{
public:

    // login function
    int login()
    {
        string accNum;
        cout << "\n.............................................................................................\n";
        cout << "\t\t\t\tLogIn";
        cout << "\n.............................................................................................\n";
        cout << "\t\t\tEnter your account number: ";
        cin >> accNum;

        // checks if the entered account number exists in the system
        for (int i = 0; i < accountCounter; i++)
        {
            if (accountNumbers[i] == accNum)
            {
                cout << "\n.............................................................................................\n";
                cout << "\t\t\tLogin successful. \n\t\t\tWelcome, " << accountHolders[i] << "!";
                cout << "\n.............................................................................................\n\n\n";
                return i;
            }
        }
        cout << "\t\t\tAccount not found.\n";
        return -1;
    }

    // create account function
    void createAccount()
    {
        if (accountCounter >= MAX_ACCOUNTS)
        {
            cout << "\n.............................................................................................\n";
            cout << "\t\t\t\tSorry, we can't create more accounts.\n";
            cout << "\n.............................................................................................\n\n\n";
            return;
        }
       cout << "\n.............................................................................................\n";
        cout<< "\t\t\t\tCreating New Account ";
        cout << "\n.............................................................................................\n";
        cout << endl
             << "\t\t\tEnter your name: ";
        cin >> accountHolders[accountCounter];
        accountNumbers[accountCounter] = "ACC" + to_string(accountCounter + 1);
        cout << "\t\t\tYour account number is: " << accountNumbers[accountCounter] << "\n";
        cout << "\t\t\tEnter initial deposit: ";
        cin >> accountBalances[accountCounter];
        cout << "\n\t\t\tCongratulations !! \n\t\t\tYour Account Has Created Successfully!!\n"
             << endl;
        accountCounter++;
    }

    // deposit cash function
    void depositCash(int index)
    {
        double amount;
        cout << "\n.............................................................................................\n";
        cout << "\t\t\t\tCash Deposite";
        cout << "\n.............................................................................................\n";
        cout << "\t\t\tEnter the amount to deposit: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "\n.............................................................................................\n";
            cout << "\t\t\tInvalid deposit amount.\n";
            cout << "\n.............................................................................................\n";
            return;
        }

        accountBalances[index] += amount;
        cout << "\n.............................................................................................\n";
        cout << "\t\t\tDeposit successful. \n\t\t\tNew balance: " << accountBalances[index] << "";
        cout << "\n.............................................................................................\n\n\n";
    }

    // withdrawal cash function
    void withdrawCash(int index)
    {
        double amount;
        cout << "\n.............................................................................................\n";
        cout << "\t\t\t\tCash Withdrawal";
        cout << "\n.............................................................................................\n";
        cout << "\t\t\tEnter the amount to withdraw: ";
        cin >> amount;

        if (amount <= 0 || amount > accountBalances[index])
        {
            cout << "\n.............................................................................................\n";
            cout << "\t\t\tInvalid withdrawal amount or insufficient funds.\n";
            cout << "\n.............................................................................................\n\n\n";
            return;
        }

        accountBalances[index] -= amount;
        cout << "\n.............................................................................................\n";
        cout << "\t\t\tWithdrawal successful. \n\t\t\tNew balance: " << accountBalances[index] << "\n";
        cout << "\n.............................................................................................\n\n\n";
    }

    // Display Account Info function 
    void displayAccountInfo(int index)
    {
        cout << "\n.............................................................................................\n";
        cout << "\t\t\t\tDisplaying Account Information";
        cout << "\n.............................................................................................\n";
        cout << "\t\t\tAccount Number: " << accountNumbers[index] << "\n";
        cout << "\t\t\tAccount Holder Name: " << accountHolders[index] << "\n";
        cout << "\t\t\tCurrent Balance: " << accountBalances[index] << "\n\n\n";
    }
};

// main function
int main()
{
    int option;
    // creating class object
    Bank customer;

    do
    {
        cout << ".............................................................................................\n";
        cout << "....................................Simple Banking System...................................." << endl;
        cout << ".............................................................................................\n";
        cout << "\n\t1.Create New Account.\n\t2.LogIn\n\t3.Cash Deposite.\n\t4.Cash Withdrawal.\n\t5.Displaying Account Information.\n\t6.LogOut.\n\t";

        // if user != -1 login andlogin== -1-not login  and 
        if (loggedInAccountIndex != -1)
        {
            cout << "\n.............................................................................................\n";
            cout << "\t\t\t\tLogged in as: " << accountHolders[loggedInAccountIndex] << " (" << accountNumbers[loggedInAccountIndex] << ")\n";
            cout << ".............................................................................................\n";
        }

        cout << "Please Enter Any Option From Above:";
        cin >> option;

        switch (option)
        {
        case 1:
            
            customer.createAccount();

            break;

        case 2:
            
            loggedInAccountIndex = customer.login();
            break;

        case 3:
            
            if (loggedInAccountIndex != -1)
            {
                customer.depositCash(loggedInAccountIndex);
            }
            else
            {
                cout << ".............................................................................................\n";
                cout << "\t\t\t\tPlease log in first.\n";
                cout << ".............................................................................................\n";
            }
            break;

        case 4:
            
            if (loggedInAccountIndex != -1)
            {
                customer.withdrawCash(loggedInAccountIndex);
            }
            else
            {
                cout << "\n.............................................................................................\n";
                cout << "\t\t\t\tPlease log in first.\n";
                cout << "\n.............................................................................................\n";
            }
            break;

        case 5:
            
            if (loggedInAccountIndex != -1)
            {
                customer.displayAccountInfo(loggedInAccountIndex);
            }
            else
            {
                cout << "\n.............................................................................................\n";
                cout << "\t\t\t\tPlease log in first.\n";
                cout << "\n.............................................................................................\n";
            }
            break;
        case 6:
            loggedInAccountIndex = -1; // Logout
            cout << "\n.............................................................................................\n";
            cout << "\t\t\tLogged out. \n\t\t\tGoodbye! Thank You For Visiting !!";
            cout << "\n.............................................................................................\n";
            break;

        default:
        cout << "\n.............................................................................................\n";
            printf("\t\t\t\tPlease enter correct option from above.");
            cout << "\n.............................................................................................\n\n\n";
            break;
        }
    } while (option != 0);

    return 0;
}

// output :- 

// .............................................................................................
// ....................................Simple Banking System....................................
// .............................................................................................

//         1.Create New Account.
//         2.LogIn
//         3.Cash Deposite.
//         4.Cash Withdrawal.
//         5.Displaying Account Information.
//         6.LogOut.
//         Please Enter Any Option From Above:1

// .............................................................................................
//                                 Creating New Account 
// .............................................................................................

//                         Enter your name: abc
//                         Your account number is: ACC1
//                         Enter initial deposit: 1200 

//                         Congratulations !! 
//                         Your Account Has Created Successfully!!

// .............................................................................................
// ....................................Simple Banking System....................................
// .............................................................................................

//         1.Create New Account.
//         2.LogIn
//         3.Cash Deposite.
//         4.Cash Withdrawal.
//         5.Displaying Account Information.
//         6.LogOut.
//         Please Enter Any Option From Above:2

// .............................................................................................
//                                 LogIn
// .............................................................................................
//                         Enter your account number: ACC1

// .............................................................................................
//                         Login successful. 
//                         Welcome, abc!
// .............................................................................................


// .............................................................................................
// ....................................Simple Banking System....................................
// .............................................................................................

//         1.Create New Account.
//         2.LogIn
//         3.Cash Deposite.
//         4.Cash Withdrawal.
//         5.Displaying Account Information.
//         6.LogOut.

// .............................................................................................
//                                 Logged in as: abc (ACC1)
// .............................................................................................
// Please Enter Any Option From Above:3

// .............................................................................................
//                                 Cash Deposite
// .............................................................................................
//                         Enter the amount to deposit: 1200

// .............................................................................................
//                         Deposit successful.
//                         New balance: 2400
// .............................................................................................


// .............................................................................................
// ....................................Simple Banking System....................................
// .............................................................................................

//         1.Create New Account.
//         2.LogIn
//         3.Cash Deposite.
//         4.Cash Withdrawal.
//         5.Displaying Account Information.
//         6.LogOut.

// .............................................................................................
//                                 Logged in as: abc (ACC1)
// .............................................................................................
// Please Enter Any Option From Above:4

// .............................................................................................
//                                 Cash Withdrawal
// .............................................................................................
//                         Enter the amount to withdraw: 120

// .............................................................................................
//                         Withdrawal successful.
//                         New balance: 2280

// .............................................................................................


// .............................................................................................
// ....................................Simple Banking System....................................
// .............................................................................................

//         1.Create New Account.
//         2.LogIn
//         3.Cash Deposite.
//         4.Cash Withdrawal.
//         5.Displaying Account Information.
//         6.LogOut.

// .............................................................................................
//                                 Logged in as: abc (ACC1)
// .............................................................................................
// Please Enter Any Option From Above:5

// .............................................................................................
//                                 Displaying Account Information
// .............................................................................................
//                         Account Number: ACC1
//                         Account Holder Name: abc
//                         Current Balance: 2280


// .............................................................................................
// ....................................Simple Banking System....................................
// .............................................................................................

//         1.Create New Account.
//         2.LogIn
//         3.Cash Deposite.
//         4.Cash Withdrawal.
//         5.Displaying Account Information.
//         6.LogOut.

// .............................................................................................
//                                 Logged in as: abc (ACC1)
// .............................................................................................
// Please Enter Any Option From Above:6

// .............................................................................................
//                         Logged out.
//                         Goodbye! Thank You For Visiting !!
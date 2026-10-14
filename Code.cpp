#include <iostream>
using namespace std;

class Bank
{
    int accno;
    float balance;
    static int count;

public:
    Bank(int accno, float balance)
    {
        this->accno = accno;
        this->balance = balance;
        count++;
    }

    inline void display()
    {
        cout << "Account Number: " << accno << endl;
        cout << "Balance: " << balance << endl;
    }

    static void showCount()
    {
        cout << "Total Accounts: " << count << endl;
    }

    friend class Details;
};

int Bank::count = 0;

class Details
{
public:
    void show(Bank b)
    {
        cout << "Account Number: " << b.accno << endl;
        cout << "Balance using Friend Class: "
             << b.balance << endl;
    }
};

int main()
{
    Bank b1(101, 5000);
    Bank b2(102, 8000);

    cout << "Account 1 Details:" << endl;
    b1.display();

    cout << "\nAccount 2 Details:" << endl;
    b2.display();

    Bank::showCount();

    Details d;
    cout << "\nAccessing Private Data:" << endl;
    d.show(b1);

    return 0;
}

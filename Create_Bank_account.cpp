#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_holder,string address,int age,string password)
    {
        this->account_holder=account_holder;
        this->address=address;
        this->password=password;
        this->age=age;
        this->account_number=rand()%1000000000;
        this->balance=0;
        cout<<"Your account no is "<<account_number<<endl;
    }
    int show_balance(string password)
    {
        if(this->password==password)
        {
            return balance;
        }
        else
        {
            cout<<"password does not match"<<endl;
        }
    }
    void add_money(string password,int amount)
    {
        if(amount<0)
        {
            cout<<"invalid amount"<<endl;
            return ;
        }
        if(this->password==password)
        {
            this->balance+=amount;
            cout<<"Add money successfully"<<endl;
        }
        else
        {
            cout<<"password does not match"<<endl;
        }
    }
    void diposite_money(string password,int amount)
    {
        if(amount<0)
        {
            cout<<"invalid amount"<<endl;
            return ;
        }
        if(this->balance<amount)
        {
            cout<<"insufficient balance "<<endl;
            return ;
        }
        if(this->password==password)
        {
            this->balance-=amount;
            cout<<"diposite successfully"<<endl;
        }
        else
        {
            cout<<"password dose not match"<<endl;
        }
    }
    friend class MyCash;
};
class MyCash
{
protected:
    int balance;
public:
    MyCash()
    {
        this->balance=0;
    }
    void add_money_from_bank(BankAccount *myAccount,string password,int amount)
    {
        if(amount<0)
        {
            cout<<"invalid amount"<<endl;
            return ;
        }
        if(myAccount->balance<amount)
        {
            cout<<"insufficient balance"<<endl;
            return ;
        }
        if(myAccount->password==password)
        {
            this->balance+=amount;
            myAccount->balance-=amount;
            cout<<"money transfer successfully"<<endl;
        }
        else
        {
            cout<<"password does not match"<<endl;
        }
    }
    int show_balance()
    {
        return balance;
    }
};
BankAccount* create_account()
{
    string account_holder,password;
    string address;
    int age;
    cout<<"CREATE ACCOUNT "<<endl;
    cout<<"Enter name , address , age and password :";
    cin>>account_holder>>address>>age>>password;
    BankAccount *myAccount=new BankAccount(account_holder,address,age,password);
    return myAccount;
}
void add_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Enter password and amount :";
    cin>>password>>amount;
    myAccount->add_money(password,amount);
    cout<<"Your bank balance is : "<<myAccount->show_balance("abc")<<endl;
}
void diposite_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Enter password and amount :";
    cin>>password>>amount;
    myAccount->diposite_money(password,amount);
    cout<<"Your bank balance is : "<<myAccount->show_balance("abc")<<endl;
}
void add_money_from_bank(MyCash *myCash,BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add money from bank:"<<endl;
    cout<<"Enter password and amount :";
    cin>>password>>amount;
    myCash->add_money_from_bank(myAccount,password,amount);
    cout<<"Your bank balance is : "<<myAccount->show_balance("abc")<<endl;
    cout<<"Your bank balance is : ";
    cout<<myCash->show_balance()<<endl;
}
int main()
{
    BankAccount *myAccount=create_account();
     MyCash *myCash=new MyCash();

    int n=1;
    while(n)
    {
        cout<<"Select an option"<<endl;
        cout<<"1. Add money to bank"<<endl;
        cout<<"2. Diposite money form bank"<<endl;
        cout<<"3. Add money mycash form bank"<<endl;

        int option ;
        cout<<"Enter your option :";
        cin>>option;
        if(option==1)
        {
            add_money(myAccount);
        }
        else if(option==2)
        {
            diposite_money(myAccount);
        }
        else if(option==3)
        {
           add_money_from_bank(myCash,myAccount);
        }
        else
        {
            cout<<"invalid opiton"<<endl;
        }
        cout<<"do you want to continue (0,1) :";
        int a;
        cin>>a;
        n=a;
    }
    return 0;
}

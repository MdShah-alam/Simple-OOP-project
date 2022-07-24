#include<bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
private:
    int total_tax;
public:
    Restaurant()
    {
        total_tax=0;
    }
    void setter(double amount)
    {
        total_tax+=amount;
    }
    double getter()
    {
        return total_tax;
    }
};

int main()
{
    int n;
    cin>>n;
    Restaurant rt;
    int food_item[n];

    for(int i=0; i<n; i++)
    {
        cin>>rt.food_item_codes[i];
        getchar();
        getline(cin,rt.food_item_names[i]);
        cin>>rt.food_item_prices[i];
    }

    cout<<"\t\t\t\t\MAKE BILL"<<endl;
    cout<<"\t\t\t\t..............."<<endl;
    cout<<"Item codes\t\t Item name \t\t Item price"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<rt.food_item_codes[i]<<"\t\t";
        cout<<rt.food_item_names[i]<<"  \t\t  ";
        cout<<rt.food_item_prices[i]<<endl;
    }

    int a=1;
    while(a)
    {
        cout<<endl;
        int table,item;
        cout<<"Enter Table no : ";
        cin>>table;
        cout<<"Enter Numbers of Item : ";
        cin>>item;
        int code[item],quantity[item];
        for(int i=0; i<item; i++)
        {
Flag:
            bool found=true;
            cout<<"Enter Item "<<i+1<<" Code : ";
            cin>>code[i];
            for(int j=0; i<n; j++)
            {
                if(code[i]==rt.food_item_codes[j])
                {
                    cout<<"Enter Item "<<i+1<<" Quantity : ";
                    cin>>quantity[i];
                    found=false;
                    break;
                }
            }
            if(found==true)
            {
                cout<<"This code is not valid "<<endl;
                goto Flag;
            }
        }
        cout<<endl;
        cout<<"\t\t\t\t BILL SUMMARY"<<endl;
        cout<<"\t\t\t\t................"<<endl;
        cout<<"Table No : "<<table<<endl;
        cout<<"Item Code     ";
        cout<<"Item name       ";
        cout<<"Item price      ";
        cout<<"Item Quantity      ";
        cout<<"Total Price      "<<endl;
        int sum=0;
        for(int i=0; i<item; i++)
        {
            int a=0;
            cout<<code[i]<<"      ";
            for(int j=0; j<n; j++)
            {
                if(code[i]==rt.food_item_codes[j])
                {
                    cout<<rt.food_item_names[j]<<"      ";
                    cout<<rt.food_item_prices[j]<<"       \t ";
                    a=quantity[i]*rt.food_item_prices[j];
                }
            }
            cout<<quantity[i]<<"       \t ";
            cout<<a;
            sum+=a;
            cout<<endl;
        }
        cout<<"TAX";
        double tax=(double)(sum*5)/100;
        rt.setter(tax);
        cout<<"\t\t\t\t\t\t\t\t    "<<rt.getter()<<endl;
        cout<<"..........................................................................."<<endl;
        cout<<"NET TOTAL\t\t\t\t\t\t\t "<<tax+sum<<endl;
        cout<<endl<<"Are you go to other Table (1/0) ? : ";
        cin>>a;
    }
    return 0;
}

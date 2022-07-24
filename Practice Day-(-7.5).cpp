#include<bits/stdc++.h>
using namespace std;

class Shop
{
public:
    string product_name;
    int product_price;
    int product_quantity;
private:
    int total_income;
public:
    Shop()
    {
       total_income=0;
    }
    void setter(int amount)
    {
      total_income+=amount;
    }
    int  getter()
    {
        return total_income;
    }
};
Shop input(Shop sp[],int n)
{
    for(int i=0; i<n; i++)
    {
        string name;
        int price,quantity;
        cout<<"Product "<<i+1<<" name :";
        cin>>name;
        cout<<"Product "<<i+1<<" price :";
        cin>>price;
        cout<<"Product "<<i+1<<" quantity :";
        cin>>quantity;
        sp[i].product_name=name;
        sp[i].product_price=price;
        sp[i].product_quantity=quantity;
    }
    return *sp;
}
void output(Shop sp[],int n)
{
    cout<<"\t\t\t\t BUY PRODUCT"<<endl;
    cout<<"\t\t\t\t ..........."<<endl;
    cout<<"Product Index\t\t";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<i+1<<"\t\t";
    }
    cout<<endl;
    cout<<"Product name\t\t";
    for(int i=0; i<n; i++)
    {
        cout<<sp[i].product_name<<"\t\t";
    }
    cout<<endl;
    cout<<"Product price\t\t";
    for(int i=0; i<n; i++)
    {
        cout<<sp[i].product_price<<"\t\t";
    }
    cout<<endl;
    cout<<"Product quantity\t";
    for(int i=0; i<n; i++)
    {
        cout<<sp[i].product_quantity<<"\t\t";
    }
    cout<<endl;
}
Shop buy(Shop sp[],int n)
{
    int product;
    int a;
    cout<<"which product do you want buy from 1 to "<<n<<" : ";
    cin>>a;
    cout<<"How many quantity do you want buy ";
    cin>>product;
    int amount=0;
    if(product<=sp[a-1].product_quantity)
    {
        amount=product*sp[a-1].product_price;
        sp[a-1].setter(amount);
        cout<<sp[a-1].product_name<<" bought "<<product<<" pc successfully"<<endl;
        cout<<"Total income is : ";
        cout<<sp[a-1].getter();
        sp[a-1].product_quantity-=product;
    }
    else
    {
        cout<<"This quantity is not available"<<endl;
    }
    return *sp;
}
int main()
{
    int n;
    cout<<"Numbers of product :";
    cin>>n;
    Shop sp[n];

    input(sp,n);
    output(sp,n);
    int a=1;
    while(a)
    {
    buy(sp,n);
    output(sp,n);
    cout<<"Do you want to continue (0 , 1) ? : ";
    cin>>a;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    char section;
    int roll;
protected:
    int english_marks;
private:
    string password;
public:
    void str_password(string pass)
    {
        password=pass;
    }
    void set_marks(int marks)
    {
        english_marks=marks;
    }
    int  get_marks()
    {
        return english_marks;
    }
    void update_marks(string pass,int marks)
    {
        if(password==pass)
        {
            english_marks=marks;
        }
        else
        {
            cout<<"Incorrect password"<<endl;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    Student st[n];
    for(int i=0; i<n; i++)
    {
        string name,password;
        char section ;
        int roll,english_marks;
        cin>>name>>password;
        cin>>section;
        cin>>roll>>english_marks;
        st[i].name=name;
        st[i].section=section;
        st[i].roll=roll;
        st[i].str_password(password);
        st[i].set_marks(english_marks);
    }
    int roll,marks;
    string password;
    cin>>roll>>marks>>password;
    bool found =false;
    for(int i=0; i<n; i++)
    {
        if(st[i].roll==roll)
        {
            found=true;
            st[i].update_marks(password,marks);
        }
    }
    if(!found)
    {
        cout<<"Student not found!"<<endl;
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        cout<<st[i].name<<" "<<st[i].section<<" "<<st[i].roll<<" "<<st[i].get_marks()<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;
class stu
{
    int id;
    char name[20];
public:
    void getstu()
    {
        cout<<"enter id and name";
        cin>>id>>name;
    }
    void putstu()
    {
        cout<<"Name= "<<name<<endl;
        cout<<"ID "<<id<<endl;
    }
};
class marks:public stu
{
protected:
    int m1,m2,m3;
    public:
    void getmarks()
    {
        cout<<"enter 3 sub marks";
        cin>>m1>>m2>>m3;
    }
    void putmarks()
    {
        cout<<"marks are:\n";
        cout<<"m1= "<<m1<<"\t"<<"m2= "<<m2<<"\t"<<"m3= "<<m3<<endl;
    }
};
class result:public marks
{
    float tot,avg;
public:
    void show()
    {
        tot=m1+m2+m3;
        avg=tot/3.0;
        cout<<"total= "<<tot<<endl<<"average= "<<avg;
    }
};

int main()
{
   result r;
    r.getstu();
    r.getmarks();
    r.putstu();
    r.putmarks();
    r.show();
}

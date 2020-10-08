#include <iostream>

using namespace std;
template<class t>
t sum(t a,t b)
{
    return a+b;
}
template <class t>
t sum(t a,t b,t c)
{
    return a+b+c;
}
int main()
{
    cout<<"2 int sum= "<<sum(10,5)<<endl;
    cout<<"3 float sum= "<<sum((float)5.6,(float)4,(float)5);
}

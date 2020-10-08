#include <iostream>
#include<math.h>
using namespace std;
main()
{
    float x,n,i,j,t,c=0,flag,k;
    cout<<"enter the value of X";
    cin>>x;
    cout<<"enter the number of terms";
    cin>>n;
    x=x*3.14/180;
    for(i=2;i<=n;i++)
    {
        flag=1;
        for(j=(2*i)-1;j>=1;j--)
        {
            flag=flag*j;
        }

                t=pow((-1),i+1)*pow(x,(2*i)-1);
        c= t/flag +c;

    }
    k=x+c;
    cout<<"sine series is "<<k;
}

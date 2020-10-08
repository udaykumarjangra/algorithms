#include <iostream>

using namespace std;

int main()
{

    int a[100];
    int i,j,k,m,n,b;

    cout<<"Enter no. of elements in array\n\n";
    cin>>n;

    cout<<"\nEnter "<<n<<" elements of an array\n";

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }


    for(j=1;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            if(a[k]>a[k+1])
            {
                b=a[k];
                a[k]=a[k+1];
                a[k+1]=b;
            }
        }
    }

    cout<<"\n\nArray after bubble sort :  ";


    for(m=0;m<n;m++)
    {
        cout<<a[m]<<" ";
    }
    return 0;
}

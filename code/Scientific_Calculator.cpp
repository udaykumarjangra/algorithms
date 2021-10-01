#include<iostream>
#include<cmath>
using namespace std;
class cal
{
	public:
	double add(float,float);
	double subtract(float,float);
	double multiply(float,float);
	double divide(float,float *);
};
class scical
{
	public:
		double sinfun(double);
		double cosfun(double);
		double tanfun(double);
		double square(double);
		double sqrtfun(double);
		int fact(int);
		double powfun(double,double);
};
double cal::add(float x,float y)
{
	return(x+y);
}
double cal::subtract(float x,float y)
{
	return(x-y);
}
double cal::multiply(float x,float y)
{
	return(x*y);
}
double cal::divide(float x,float *y)
{
	if(*y==0)
	{
		cout<<"ERROR(Cannot divide by 0)";
		cout<<"\n"<<"Enter second number again(other than 0)";
		cin>>(*y);
		return(x/(*y));
	}
	else
	{
		return(x/(*y));
	}
}
double scical::sinfun(double x)
{
	return(sin(x));
}
double scical::cosfun(double x)
{
	return(cos(x));
}
double scical::tanfun(double x)
{
	return(tan(x));
}
double scical::square(double x)
{
	return(x*x);
}
double scical::sqrtfun(double x)
{
	return(sqrt(x));
}
int scical::fact(int x)
{
	if(x==1)
	return (1);
	else
	while(x!=1)
	return(x*fact(x-1));
}
double scical::powfun(double x,double y)
{
	return(pow(x,y));
}
int main()
{
	int choice,choicecal,choice1;
	cal p;
	scical q;
	float n1,n2,n3;
	do{
	cout<<"Which type of calculator do you want to use?\n"<<"1.Standard calculator\n"<<"2.Scientific calculator\n";
	cin>>choicecal;
	if(choicecal==1)
	{
		cout<<"\n------------------------------------STANDARD CALCULATOR-------------------------------------------------\n";
	cout<<"Select the operation:\n"<<"1.Add\n"<<"2.Subtract\n"<<"3.Multiply\n"<<"4.Divide\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				cout<<"\nEnter first number=";
				cin>>n1;
				cout<<"\nEnter second number=";
				cin>>n2;
				n3=p.add(n1,n2);
				cout<<"\n"<<n1<<"+"<<n2<<"="<<n3;			
			}
			break;
	    case 2:
	    	{
	    		cout<<"\nEnter first number=";
	    		cin>>n1;
	    		cout<<"\nEnter second number=";
	    		cin>>n2;
	    		n3=p.subtract(n1,n2);
	    		cout<<"\n"<<n1<<"-"<<n2<<"="<<n3;
			}
			break;
		case 3:
		{
			cout<<"\nEnter first number=";
			cin>>n1;
			cout<<"\nEnter second number=";
			cin>>n2;
			n3=p.multiply(n1,n2);
			cout<<"\n"<<n1<<"*"<<n2<<"="<<n3;
		}
		break;
		case 4:
		{
			cout<<"\nEnter first number=";
			cin>>n1;
			cout<<"\nEnter second number=";
			cin>>n2;
			n3=p.divide(n1,&n2);
			cout<<"\n"<<n1<<"/"<<n2<<"="<<n3;
		}
		break;
		 default:
			{
				cout<<"Invalid input";
			}
	}}
	if(choicecal==2)
	{
		cout<<"\n--------------------------------------SCIENTIFIC CALCULATOR-----------------------------------------\n";
		cout<<"Select the operation:\n1.sin\n2.cos\n3.tan\n4.square\n5.sqrt\n6.pow\n7.factorial\n";
		cin>>choice;
		cout<<"\nEnter value=";
		cin>>n1;
		switch(choice)
		{
			case 1:
			{
				n2=q.sinfun(n1);
				cout<<"\nsin of "<<n1<<"="<<n2;
			}
			break;
			case 2:
			{
				n2=q.cosfun(n1);
				cout<<"\ncos of "<<n1<<"="<<n2;
			}
			break;
			case 3:
			{
			n2=q.tanfun(n1);
			cout<<"\ntan of "<<n1<<"="<<n2;
			}
			break;
			case 4:
			{
				n2=q.square(n1);
				cout<<"\nsquare of "<<n1<<"="<<n2;
			}
			break;
			case 5:
				{
					n2=q.sqrtfun(n1);
					cout<<"\nsquare root of "<<n1<<"="<<n2;
				}
				break;
			case 6:
				{
					cout<<"\nEnter power=";
					cin>>n2;
					n3=q.powfun(n1,n2);
					cout<<n1<<" raised to power "<<n2<<"="<<n3;
				}
				break;
			case 7:
				{
					n2=q.fact(n1);
					cout<<"\nFactorial of "<<n1<<"="<<n2;
				}
			}}
			cout<<"\nDo you want to use again?\n1.Yes\n2.No\n";
			cin>>choice1;
		}while(choice1==1);}

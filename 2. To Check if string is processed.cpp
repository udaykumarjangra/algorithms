#include <bits/stdc++.h>
using namespace std;

void first()
{
	int transition[4][2] =
	{
		{ 1 , 0 },
		{ 1 , 2 },
		{ 1 , 3	},
		{ 1 , 0 }
	};
	int current = 0;
	int final = 3;
	string s;
	cout<<"Enter string to be processed: ";
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{
		cout<<current<<" -> ";
		current = transition[current][s[i] - 'a'];
	}
	cout<<current;
	if(current == final)
	{
		cout<<endl<<"Accepted";
	}
	else{
		cout<<endl<<"Rejected";
	}
}
void second()
{
	int transition[5][2] =
	{
		{ 1 , 3 },
		{ 3 , 2 },
		{ 3 , 4	},
		{ 3 , 3	},
		{ 4 , 4 }
	};
	int current = 0;
	int final = 4;
	string s;
	cout<<"Enter string to be processed: ";
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{
		cout<<current<<" -> ";
		current = transition[current][s[i] - 'a'];
	}
	cout<<current;
	if(current == final)
	{
		cout<<endl<<"Accepted";
	}
	else{
		cout<<endl<<"Rejected";
	}
}
void third()
{
	int transition[4][2] =
	{
		{ 1 , 0 },
		{ 1 , 2 },
		{ 1 , 3 },
		{ 3 , 3 }
	};
	int current = 0;
	int final = 3;
	string s;
	cout<<"Enter string to be processed: ";
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{
		cout<<current<<" -> ";
		current = transition[current][s[i] - 'a'];
	}
	cout<<current;
	if(current == final)
	{
		cout<<endl<<"Accepted";
	}
	else{
		cout<<endl<<"Rejected";
	}
}

int main()
{
	while(1){
		cout<<"\n1. To check string ending with abb \n2. To check string starting with abb\n3. To check string having sub string abb\n";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
				first();
				break;
			case 2:
				second();
				break;
			case 3:
				third();
				break;
		}
	}
}

#include<bits/stdc++.h>
using namespace std;



void display(stack<int> s){
	while(s.size()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
}

void insert(stack<int> &s, int ele){
	if(s.size()==0){
		s.push(ele);
		return;
	}
	int temp = s.top();
	s.pop();
	insert(s,ele);
	s.push(temp);
	return ;
}

void reverse(stack<int> &s){
	if(s.size()==1){
		return;
	}	
	int val = s.top();
	s.pop();
	reverse(s);
	insert(s, val);
	return;
}


int main(){
	
	cout<<"Enter size:\t";
	int size;
	cin>>size;
	stack<int> s;
	int val;
	for(int i=0;i<size;i++){
		cin>>val;
		s.push(val);
	}
	cout<<"\nBEFORE\n";
	display(s);
	reverse(s);
	cout<<"\nBEFORE\n";
	display(s);
	return 0;
}

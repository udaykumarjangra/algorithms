#include<bits/stdc++.h>
using namespace std;

//void sort();
void insert(stack<int> &s, int temp);


void display(stack<int> s){
	while(s.size()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
}

void sort(stack<int> &s){
	if(s.size()==1){
		return ;
	}
	int temp = s.top();
	s.pop();
	sort(s);
	insert(s, temp);	
}

void insert(stack<int> &s, int temp){
	if(s.size()==0 || temp>=s.top()){
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s,temp);
	s.push(val);
	return ;
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
	
	sort(s);
	display(s);
	return 0;
}

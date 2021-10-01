#include<bits/stdc++.h>
using namespace std;



void display(stack<int> s){
	while(s.size()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
}

void del_mid(stack<int> &s, int k){
	if(k==1){
		s.pop();
		return;
	}	
	int val = s.top();
	s.pop();
	del_mid(s, k-1);
	s.push(val);
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
	int k = (s.size() / 2) + 1;
	del_mid(s,k);
	display(s);
	return 0;
}

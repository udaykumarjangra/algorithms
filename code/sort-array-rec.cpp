#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> &v);
void insert(vector<int> &v, int);


void display(vector<int> &a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

void sort(vector<int> &v){
	if(v.size()==1)
	{
		return ;
	}
	int temp = v[v.size()-1];
	v.pop_back();
	sort(v);
	insert(v, temp);
}

void insert(vector<int> &v, int temp){
	if(v.size()==0 || temp>=v[v.size()-1]){
		v.push_back(temp);
		return ;
	}
	int val = v[v.size()-1];
	v.pop_back();
	insert(v, temp);
	v.push_back(val);
	return ;
}

int main(){
	
	cout<<"Enter size:\t";
	int size;
	cin>>size;
	vector<int>v;
	int val;
	for(int i=0;i<size;i++){
		cin>>val;
		v.push_back(val);
	}
	cout<<"Before Sorting:\n";
	display(v, size);
	cout<<"\nAfter Sorting, The number becomes\n";
	sort(v);
	display(v, size);
	
	return 0;
}

#include<iostream>
#include<climits>
using namespace std;

class stackUsingArray{
	private:
	    int *data;
	    int nextIndex;
	    int capacity=4;
	
	public:
		stackUsingArray()
		{
			data=new int[capacity];
			nextIndex=0;
		}
		
		//size of stack
		int size()
		{
			return nextIndex;
		}
		
		//check for empty stack
		bool isEmpty()
		{
			if(nextIndex==0)
			    return true;
			else
			    return false;
		}
		
		//insert element
		void push(int element)
		{
			if(nextIndex==capacity)
			{
				int *newData=new int[capacity*2];
				for(int i=0;i<capacity;i++)
				{
					newData[i]=data[i];
				}
				capacity=2*capacity;
				delete data;
			    data=newData;
			}
			data[nextIndex]=element;
			nextIndex++;
		}
		
		//top element of stack
		int top()
		{
			if(isEmpty()){
			    cout<<"Stack is empty\n";
			    return INT_MIN;
	    	}
			    
			return data[nextIndex-1];
		}
		
		//delete element
		int pop()
		{
			if(isEmpty()){
			    cout<<"Stack is empty\n";
			    return INT_MIN;
		    }
			nextIndex--;    
			return data[nextIndex];
		}		
};

int main()
{
	stackUsingArray s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	cout<<s.top()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
  
  return 0;
}

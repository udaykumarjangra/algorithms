//Mid Point Line Algorithm
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void solve(int x1, int y1, int x2, int y2){
	int dx = x2 - x1, dy = y2 - y1;
	int d = dy - (dx/2);
	int x = x1, y = y1;
	while(x < x2)
	{
		putpixel(x,y,WHITE);
		if(d < 0)
		{
			d = d + dy;
		}
		else{
			d = d + (dy - dx);
			y++;
		}
		x++;
	}
}

int main()
{
	int x1, x2, y1, y2;
	cout<<"Enter X1 Y1 (Starting Point)"<<endl;
	cin>>x1>>y1;
	cout<<"Enter X2 Y2 (Ending Point)"<<endl;
	cin>>x2>>y2;
	initwindow(500,500);
	solve(x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;
}

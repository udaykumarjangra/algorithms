//Bresenham's Line Drawing Algorithm
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void solve(int x1, int y1, int x2, int y2){
	int dx = x2 - x1;
	int dy = y2 - y1;
	int d = 2 * dy - dx;
	int x = x1, y = y1;
	while(x < x2)
	{
		putpixel(x,y,WHITE);
		x++;
		if(d >= 0)
		{
			d = d + 2 * (dy - dx);
			y++;
		}
		else{
			d = d + 2 * dy;
		}
	}
}

int main()
{
	int x1, x2, y1, y2, c1,c2,tmp;
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

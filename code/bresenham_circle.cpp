//Bresenham's Circle Drawing Algorithm
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void symPlot(int xc, int yc, int x, int y)
{
	putpixel(x+xc,y+yc,RED);  
    putpixel(x+xc,-y+yc,YELLOW);  
    putpixel(-x+xc,-y+yc,GREEN);  
    putpixel(-x+xc,y+yc,BLUE);  
    putpixel(y+xc,x+yc,BLUE);  
    putpixel(y+xc,-x+yc,GREEN);  
    putpixel(-y+xc,-x+yc,YELLOW);  
    putpixel(-y+xc,x+yc,RED);  
}
void solve(int x, int y, int r){
	int X=0, Y=r;
	int d = 3 - (2 * r);
	while(X <= Y)
	{
		
		symPlot(x,y,X,Y);
		if(d <= 0)
		{
			d = d + (4 * X) + 6;
		}
		else{
			d = d + (4 * X) - (4 * Y) + 10;
			Y--;
		}
		X++;
	}
}

int main()
{
	int x1, y1, radius;
	cout<<"Enter X Y (Center of Circle)"<<endl;
	cin>>x1>>y1;
	cout<<"Enter Radius of Circle"<<endl;
	cin>>radius;
	initwindow(500,500);
	solve(x1,y1,radius);
	getch();
	closegraph();
	return 0;
}

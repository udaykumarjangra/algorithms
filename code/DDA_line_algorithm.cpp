#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	
	// Input values for coordinates of the two end points.
	int x1, y1, x2, y2;
	cout<<"Enter the two points between which you want to draw the line";
	cout<<"\n ( x1,y1 )\n";
	cin>>x1>>y1;
	cout<<"\n ( x2,y2 )\n";
	cin>>x2>>y2;

	// Calculate dx and dy
	int dx = x2 - x1;
	int dy = y2 - y1;
	
	// Calculate the STEP Value.
	int step = ( abs(dx) > abs(dy) ) ? abs(dx) : abs(dy);
	
	// Calculate the values to be incremented in the x and y coordinates
	float x_inc = dx / step;
	float y_inc = dy / step;
	
	for( int i = 1 ; i <= step ; i++ )
	{
		putpixel( x1, y1, RED );
		x1 = x1 + round( x_inc );
		y1 = y1 + round( y_inc );
	}
	
	
    getch();
    closegraph();
}

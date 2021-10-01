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
	cout<<" Enter the two points between which you want to draw the line";
	cout<<"\n ( x1,y1 )\n";
	cin>>x1>>y1;
	cout<<"\n ( x2,y2 )\n";
	cin>>x2>>y2;

	int x = x1, y = y1; // Temp Variables for caluclations
	
	// Calculating values of dx, dy
	int dx = x2 - x1;
	int dy = y2 - y1;
	
	// Calculating Decision Parameter
	int P = 2 * dy - dx;
	
	// Drawing Line
	while( x <= x2 )
	{
		putpixel( x, y, RED);
		x++;
		if( P < 0 )
		{
			P = P + 2 * dy; 
		}	
		else 
		{
			P = P + 2 * dy - 2 * dx;
			y++;
		}
	}

    getch();
    closegraph();
}

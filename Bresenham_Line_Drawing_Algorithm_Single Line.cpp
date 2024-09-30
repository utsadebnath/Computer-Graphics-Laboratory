#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<iostream>
using namespace std;
void Bresenham_LineDrawing_Single(int x1,int y1,int x2,int y2)
{
	int d,dx,dy,dt,ds,x,y;
	d = 2*dy-dx;
	dx = x2-x1;
	dy = y2-y1;
	dt = 2*(dy-dx);
	ds = 2*dy;
	x=x1,y=y1;
	
	while(x<=x2)
	{
		if(d<=0)
		{
			x++;
			d=d+ds;
			putpixel(x, y, WHITE);
		}
		else
		{
			x++;
			y++;
			d=d+dt;
			putpixel(x, y, WHITE);
		}
		
	}
}
int main()
{
	int gd=DETECT,gm;
	int x1,x2,y1,y2;
	initgraph(&gd,&gm, "");
	//user input
	cout<<"Enter the value of (x1,y1): ";
	cin>>x1>>y1;
	cout<<"Enter the value of (x2,y2): ";
	cin>>x2>>y2;

	Bresenham_LineDrawing_Single(x1,y1,x2,y2);
	
	getch();
	closegraph();
}



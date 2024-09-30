#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<ctime>
using namespace std;
void Bresenham_LineDrawing_Multiple(int x1,int y1,int x2,int y2)
{
	int d,dx,dy,dt,ds,x,y;
	dx = x2-x1;
	dy = y2-y1;
	dt = 2*(dy-dx);
	ds = 2*dy;
	d = (2*dy)-dx;
	x=x1,y=y1;
	
	while(x<x2)
	{
		if(d<0)
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
	initgraph(&gd,&gm, "");;
	for(int i=0;i<1000;i++)
	{
		// for generating random input
		int x1 =rand() % getmaxx();
		int x2 =rand() % getmaxx();
		int y1 =rand() % getmaxy();
		int y2 =rand() % getmaxy();
		Bresenham_LineDrawing_Multiple(x1,y1,x2,y2);
	}
	getch();
	closegraph();
}



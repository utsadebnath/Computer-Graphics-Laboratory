#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<iostream>
#define round(val)(int)(val+0.5)
using namespace std;
void DDA_LineDrawing_Single(int x1,int y1,int x2,int y2)
{
	//slope calculation
	float dx,dy,m,x,y;
	dx= float(x2-x1);
	dy= float(y2-y1);
	m=dy/dx;
	
	if(m<=1)
	{
		x=x1;
		y=float(y1);
		for(x=x1;x<x2;x++)
		{
			putpixel(int(x),round(y),RED);
			y=y+m;
		}
	}
	else
	{
		y=y1;
		for(y=y1;y<=y1;y++)
		{
			putpixel(round(x),int(y),RED);
			x=x+(1/m);
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
	DDA_LineDrawing_Single(x1,y1,x2,y2);
	
	getch();
	closegraph();
}



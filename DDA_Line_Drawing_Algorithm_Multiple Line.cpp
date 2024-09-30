#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<ctime>
#define round(val)(int)(val+0.5)
using namespace std;
void DDA_LineDrawing_Multiple(int x1,int y1,int x2,int y2)
{
	//slope calculation
	float dx,dy,m,x,y;
	dx= float(x2-x1);
	dy= float(y2-y1);
	m=dy/dx;
	
	if(m<1)
	{
		x=x1;
		y=float(y1);
		for(x=x1;x<x2;x++)
		{
			putpixel(int(x),round(y),WHITE);
			y=y+m;
		}
	}
	else
	{
		y=y1;
		for(y=y1;y<=y1;y++)
		{
			putpixel(round(x),int(y),WHITE);
			x=x+(1/m);
		}
	}
}

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm, "");

for(int i=0;i<1000;i++)
{
	// for generating random input
	int x1 =rand() % getmaxx();
	int x2 =rand() % getmaxx();
	int y1 =rand() % getmaxy();
	int y2 =rand() % getmaxy();
	

	DDA_LineDrawing_Multiple( x1, y1, x2, y2);
}
getch();
closegraph();
}




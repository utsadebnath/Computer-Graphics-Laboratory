#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
using namespace std;
void Midpoint_CircleDrawing(int xc,int yc,int r)
{
	int x,y,p;
	x=0,y=r;
	p=1-r;
	while(x<=y)
	{
		if(p<=0)
		{
			p = p+(2*x)+3;
			
		}
		else
		{
			p = p+(2*(x-y))+5;
			y--;
		}
		x++;
		putpixel(x+xc,y+yc,WHITE);  
    	putpixel(x+xc,-y+yc,WHITE);  
    	putpixel(-x+xc,-y+yc,WHITE);  
    	putpixel(-x+xc,y+yc,WHITE);  
    	putpixel(y+xc,x+yc,WHITE);  
    	putpixel(y+xc,-x+yc,WHITE);  
    	putpixel(-y+xc,-x+yc,WHITE);  
   		putpixel(-y+xc,x+yc,WHITE);  
	}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm, "");
	//user input
	int xc,yc,r;
	cout<<"Enter the co-ordinates of the center(xc,yc) : ";
	cin>>xc>>yc;
	cout<<"Enter the value of radius(r) : ";
	cin>>r;
	Midpoint_CircleDrawing(xc,yc,r);
	getch();
	closegraph();
}


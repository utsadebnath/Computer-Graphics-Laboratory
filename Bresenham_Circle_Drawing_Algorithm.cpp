#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;
void Bresenham_CircleDrawing(int xc,int yc,int r)
{
	int x,y,d;
	x=0,y=r;
	// shift operation for 3-(2*r)
	int res = r << 1;
	d = 3 - res;
	
	while(x<=y)
	{
		if(d<=0)
		{
			d = d+(4*x)+6;
			
		}
		else
		{
			d = d+(4*(x-y))+10;
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
	Bresenham_CircleDrawing(xc,yc,r);
	getch();
	closegraph();

}

#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
using namespace std;
void Midpoint_EllipseDrawing(int xc,int yc,int a,int b)
{
	int x=0,y=b;
	int aa=a*a,bb=b*b,aa2=aa*2,bb2=bb*2;
	int fx=0,fy=aa2*b;
	int p=bb-aa*b+0.25*aa;
	while(fx<fy)
	{  
    	putpixel(xc+x,yc-y,WHITE);  
    	putpixel(xc-x,yc-y,WHITE);  
    	putpixel(xc+x,yc+y,WHITE);  
    	putpixel(xc-x,yc+y,WHITE); 
    	x++;
    	fx=fx+bb2;
    	if(p<0)
    	{
    		p=p+fx+bb;
		}
		else
		{
			y--;
			fy=fy-aa2;
			p=p+fx+bb-fy;
		}
	}
		
	p=bb*(x+0.5)*(x+0.5)+aa*(y-1)*(y-1)-aa*bb;
	while(y>0)
	{
		putpixel(xc+x,yc-y,WHITE);  
    	putpixel(xc-x,yc-y,WHITE);  
    	putpixel(xc+x,yc+y,WHITE);  
    	putpixel(xc-x,yc+y,WHITE);
		y--;
		fy=fy-aa2;
		if(p>=0)
		{
			p=p-fy+aa;	
		}
		else
		{
			x++;
			fx=fx+bb2;
			p=p+fx-fy+aa;	
		}
			
	}	
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm, "");
	initwindow(950,540);
//	int xc,yc,a,b;
//	cout<<"Enter the value for xc,yc,a,b : ";
//	cin>>xc>>yc>>a>>b;
	for(int i=0;i<100;i++)
	{
		int xc =rand() % 800;
		int yc =rand() % 400;
		int a =rand() % 150;
		int b =rand() % 100;
		Midpoint_EllipseDrawing(xc,yc,a,b);
	}

	
	getch();
	closegraph();
}

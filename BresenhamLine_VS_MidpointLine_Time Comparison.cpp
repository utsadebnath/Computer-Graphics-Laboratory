#include <iostream>
#include <graphics.h>
#include <conio.h>
#include<cmath>
#include <ctime>
using namespace std;
void DDA_linedrawing_Multiple(int x1, int x2, int y1, int y2)
{
	int dx, dy, xi, yi, steps, i;
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) >abs(dy))
	{
		steps =dx;
	}
	else
	{
		steps =dy;
	}
	xi = dx / steps;
	yi = dy / steps;
	for (i = 0; i < steps; i++)
	{
		putpixel(x1, y1, LIGHTBLUE);
		x1 = x1 + xi;
		y1 = y1 + yi;
	}
}
void Bresenham_LineDrawing_Multiple(int x1, int y1, int x2, int y2)
{
	int d, dx, dy, dt, ds, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	dt = 2 * (dy - dx);
	ds = 2 * dy;
	d = (2 * dy) - dx;
	x = x1; 
	y = y1;

	while (x < x2)
	{
		if (d < 0)
		{
			x++;
			d = d + ds;
			putpixel(x, y, WHITE);
		}
		else
		{
			x++;
			y++;
			d = d + dt;
			putpixel(x, y, WHITE);
		}
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	
	clock_t start_time_general,	end_time_general, 
		start_time_bresenham, end_time_bresenham,
	 	start_time_dda, end_time_dda;
				
	double time_taken_dda=0;
	double time_taken_bresenham=0;
	double time_taken_general=0;

	for (int i = 0; i < 1000; i++)
	{
		// for generating random input
		int x1 = rand() % getmaxy();
		int x2 = rand() % getmaxy();
		int y1 = rand() % getmaxy();
		int y2 = rand() % getmaxy();
        
        start_time_dda = clock();
		DDA_linedrawing_Multiple(x1, y1, x2, y2);
		end_time_dda = clock();
        time_taken_dda += double(end_time_dda - start_time_dda);
        
		start_time_bresenham = clock();
		Bresenham_LineDrawing_Multiple(x1, y1, x2, y2);
		end_time_bresenham = clock();
        time_taken_bresenham += double(end_time_bresenham - start_time_bresenham);
	}

	cout << "Bresenham  Line Time: " << time_taken_bresenham/CLOCKS_PER_SEC << " seconds" <<endl;
	cout << "DDA Line Time : " << time_taken_dda/CLOCKS_PER_SEC << " seconds" <<endl;
	
	getch();
	closegraph();
}

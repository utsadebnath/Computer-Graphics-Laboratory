#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <ctime>
using namespace std;

void General_CircleDrawing(int xc, int yc, int r)
{
	int x, y;
	for (x = 0; x <= r; x++)
	{
		y = sqrt(r * r - x * x);

		putpixel(x + xc, y + yc, RED);
		putpixel(x + xc, -y + yc, RED);
		putpixel(-x + xc, -y + yc, RED);
		putpixel(-x + xc, y + yc, RED);
		putpixel(y + xc, x + yc, RED);
		putpixel(y + xc, -x + yc, RED);
		putpixel(-y + xc, -x + yc, RED);
		putpixel(-y + xc, x + yc, RED);
	}
}
void Bresenham_CircleDrawing(int xc, int yc, int r)
{
	int x, y, d;
	x = 0, y = r;
	// shift operation for 3-(2*r)
	int res = r << 1;
	d = 3 - res;

	while (x <= y)
	{
		if (d <= 0)
		{
			d = d + (4 * x) + 6;
		}
		else
		{
			d = d + (4 * (x - y)) + 10;
			y--;
		}
		x++;
		putpixel(x + xc, y + yc, WHITE);
		putpixel(x + xc, -y + yc, WHITE);
		putpixel(-x + xc, -y + yc, WHITE);
		putpixel(-x + xc, y + yc, WHITE);
		putpixel(y + xc, x + yc, WHITE);
		putpixel(y + xc, -x + yc, WHITE);
		putpixel(-y + xc, -x + yc, WHITE);
		putpixel(-y + xc, x + yc, WHITE);
	}
}

void Midpoint_CircleDrawing(int xc, int yc, int r)
{
	int x, y, p;
	x = 0, y = r;
	p = 1 - r;
	while (x <= y)
	{
		if (p <= 0)
		{
			p = p + (2 * x) + 3;
		}
		else
		{
			p = p + (2 * (x - y)) + 5;
			y--;
		}
		x++;
		putpixel(x + xc, y + yc, GREEN);
		putpixel(x + xc, -y + yc, GREEN);
		putpixel(-x + xc, -y + yc, GREEN);
		putpixel(-x + xc, y + yc, GREEN);
		putpixel(y + xc, x + yc, GREEN);
		putpixel(y + xc, -x + yc, GREEN);
		putpixel(-y + xc, -x + yc, GREEN);
		putpixel(-y + xc, x + yc, GREEN);
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");

	clock_t  start_time_general, end_time_general, 
			 start_time_bresenham, end_time_bresenham,
			 start_time_midpoint, end_time_midpoint;

	double time_taken_midpoint = 0;
	double time_taken_bresenham = 0;
	double time_taken_general = 0;

	for (int i = 0; i < 1000; i++)
	{
		// for generating random input
		int xc = rand() % getmaxy();
		int yc = rand() % getmaxy();
		int r = rand() % 200;

		start_time_general = clock();
		General_CircleDrawing(xc, yc, r);
		end_time_general = clock();
		time_taken_general += double(end_time_general - start_time_general);

		start_time_bresenham = clock();
		Bresenham_CircleDrawing(xc, yc, r);
		end_time_bresenham = clock();
		time_taken_bresenham += double(end_time_bresenham - start_time_bresenham);

		start_time_midpoint = clock();
		Midpoint_CircleDrawing(xc, yc, r);
		end_time_midpoint = clock();
		time_taken_midpoint += double(end_time_midpoint - start_time_midpoint);
	}
	cout << "General Time : " << time_taken_general / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "Bresenham Time: " << time_taken_bresenham / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "Midpoint Time : " << time_taken_midpoint / CLOCKS_PER_SEC << " seconds" << endl;

	getch();
	closegraph();
}

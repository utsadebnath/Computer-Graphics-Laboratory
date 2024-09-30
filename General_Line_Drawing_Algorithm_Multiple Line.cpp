#include <graphics.h>
#include <iostream>
#include<math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;
    
    float x = x1;
    float y = y1;
    
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < 1000; i++) {
        int x1 = rand() % getmaxx();
        int y1 = rand() % getmaxy();
        int x2 = rand() % getmaxx();
        int y2 = rand() % getmaxy();
        
        drawLine(x1, y1, x2, y2);
    }

    getch();
    closegraph();
    return 0;
}


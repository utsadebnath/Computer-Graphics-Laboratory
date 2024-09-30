#include <graphics.h>
#include <iostream>
#include<math.h>
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

    int x1, y1, x2, y2;

    // User input for start point & end point
    cout << "Enter the value of (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the value of (x2, y2): ";
    cin >> x2 >> y2;

    // Draw the line using the custom function
    drawLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}


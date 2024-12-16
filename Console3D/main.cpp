#include <iostream>
#include "screenCtrl.h"
#include <windows.h>
#include <math.h>

# define M_PI           3.14159265358979323846 

void drawLine(float x1, float y1, float x2, float y2, char ch);

using namespace std;

class Line {
private:
	float pX1 = 0;
	float pX2 = 0;
	float pY1 = 0;
	float pY2 = 0;

public:
	float X1 = 0;
	float X2 = 0;
	float Y1 = 0;
	float Y2 = 0;

	void draw(char ch) {
		drawLine(pX1, pY1, pX2, pY2, ' ');
		drawLine(X1, Y1, X2, Y2, ch);
		pX1 = X1;
		pX2 = X2;
		pY1 = Y1;
		pY2 = Y2;
	}

	void erase() {
		drawLine(pX1, pY1, pX2, pY2, ' ');
	}

};

void drawLine(float x1, float y1, float x2, float y2, char ch) {
	int x;
	int y;
	if (x1 > x2) {
		for (x = x2; x <= x1; x++) {
			y = y1 + (((y1 - y2) / (x1 - x2)) * (x - x1));
			moveCsr(y + 1, x);
			cout << ch;
		}
	}
	else if (x1 < x2) {
		for (x = x1; x <= x2; x++) {
			y = y1 + (((y1 - y2) / (x1 - x2)) * (x - x1));
			moveCsr(y + 1, x);
			cout << ch;
		}
	}

	if (y1 > y2) {
		for (y = y2; y <= y1; y++) {
			x = (((y - y1) / (y1 - y2)) * (x1 - x2)) + x1;
			moveCsr(y + 1, x);
			cout << ch;
		}
	}
	else if (y1 < y2) {
		for (y = y1; y <= y2; y++) {
			x = (((y - y1) / (y1 - y2)) * (x1 - x2)) + x1;
			moveCsr(y + 1, x);
			cout << ch;
		}
	}
}

void drawLineA(float x, float y, float angle, float length, char ch) {
	drawLine(x, y, (cos(angle) * length * 2) + x, (sin(angle) * length) + y, ch);
	//cout << cos(angle) * length << '\t' << sin(angle) * length << endl;
	
}

double toRad(double angle) {
	return (angle * M_PI) / 180;
}

void drawRandomLine() {
	consoleColorSet(((rand() % 2) == 0) ? ((rand() % 8) + 40) : ((rand() % 8) + 100));
	drawLine((rand() % 80), (rand() % 25), (rand() % 80), (rand() % 25), ' ');
}

int main() {
	srand(time(0));
	Line line1;
	while (1) {
		
		line1.X1 = (rand() % 80);
		line1.X2 = (rand() % 80);

		line1.Y1 = (rand() % 25);
		line1.Y2 = (rand() % 25);
		line1.draw('H');
		Sleep(100);
	}
}


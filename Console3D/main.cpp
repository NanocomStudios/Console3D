#include <iostream>
#include "screenCtrl.h"
#include <windows.h>
#include <math.h>

# define M_PI           3.14159265358979323846 

using namespace std;

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
	drawLine(x, y, cos(angle) * length, sin(angle) * length, ch);
	
}

double toRad(double angle) {
	return (angle * M_PI) / 180;
}

int main() {
	int previousI = 0;
	while (1) {
		for (int i = 0; i < 360; i++) {
			drawLineA(40, 25, toRad(previousI), 5, ' ');
			drawLineA(40, 25, toRad(i), 5, '0');
			previousI = i;
			Sleep(50);
		}
	}
}


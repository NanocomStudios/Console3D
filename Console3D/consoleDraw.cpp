#include <iostream>
#include "screenCtrl.h"
#include "consoleDraw.h"
#include <math.h>

using namespace std;

void render() {

}

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


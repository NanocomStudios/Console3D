#include <iostream>
#include "screenCtrl.h"
#include <windows.h>
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


int main() {
	int previousI = 0;
	while (1) {
		for (int i = 0; i < 79; i++) {
			drawLine(40, 0, previousI, 20, ' ');
			drawLine(40, 0, i, 20, '0');
			previousI = i;
			Sleep(50);
		}
	}
}


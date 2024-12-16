#pragma once
#ifndef CONSOLE_DRAW
#define CONSOLE_DRAW

# define M_PI           3.14159265358979323846 

void drawLine(float x1, float y1, float x2, float y2, char ch);
void drawLineA(float x, float y, float angle, float length, char ch);
double toRad(double angle);
void drawRandomLine();

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

	void drawNew(float x1, float y1, float x2, float y2, char ch) {
		X1 = x1;
		X2 = x2;
		Y1 = y1;
		Y2 = y2;
		erase();
		draw(ch);
	}

	void drawOver(float x1, float y1, float x2, float y2, char ch) {
		X1 = x1;
		X2 = x2;
		Y1 = y1;
		Y2 = y2;
		draw(ch);
	}

	void draw(char ch) {
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

class Triangle {
	Line line1;
	Line line2;
	Line line3;

public:
	void drawNew(float x1, float y1, float x2, float y2, float x3, float y3, char ch) {
		erase();
		drawOver(x1, y1, x2, y2, x3, y3, ch);

	}

	void drawOver(float x1, float y1, float x2, float y2, float x3, float y3, char ch) {
		line1.drawOver(x1, y1, x2, y2, ch);
		line2.drawOver(x2, y2, x3, y3, ch);
		line3.drawOver(x3, y3, x1, y1, ch);
	}

	void erase() {
		line1.erase();
		line2.erase();
		line3.erase();
	}

};

#endif
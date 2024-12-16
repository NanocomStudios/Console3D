#include <iostream>
#include <Windows.h>
#include "consoleDraw.h"
using namespace std;

int main() {
	srand(time(0));
	Line line1;
	Triangle tri1;
	while (1) {
		
		tri1.drawNew((rand() % 80), (rand() % 25), (rand() % 80), (rand() % 25), (rand() % 80), (rand() % 25), 'H');
		//drawRandomLine();
		Sleep(100);
	}
}


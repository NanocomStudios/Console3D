#include <iostream>
#include "consoleDraw.h"
using namespace std;

int main() {
	srand(time(0));
	Line line1;
	while (1) {
		
		line1.drawL((rand() % 80), (rand() % 25), (rand() % 80), (rand() % 25), 'H');
		//drawRandomLine();
		//Sleep(100);
	}
}


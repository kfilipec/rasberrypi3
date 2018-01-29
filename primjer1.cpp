#include <wiringPi.h>
#include <iostream>
using namespace std;

#define LED  18

int main() {
	
	cout <<"Blinkanje\n" ;
	
	wiringPiSetupGpio();
	
	pinMode(LED, OUTPUT);

	while(1) {
		
		digitalWrite(LED, 1);
		delay(500);
		digitalWrite(LED, 0);
		delay(500);
	}
	return 0;
}



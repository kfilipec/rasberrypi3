#include <wiringPi.h>
#include <stdio.h>



int main() {
	
	wiringPiSetupGpio();

	while(1) {
		digitalWrite(18, HIGH);
		delay(500);
		digitalWrite(18, LOW);
		delay(500);
	}
	return 0;
}



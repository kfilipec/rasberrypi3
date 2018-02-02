#include <iostream>
#include <wiringPi.h>
using namespace std;

int switchState;

#define GREEN 18
#define RED 15
#define switchInput 14

int main(){
	
	wiringPiSetupGpio();
	pinMode(GREEN, OUTPUT);
	pinMode(RED, OUTPUT);
	pinMode(switchInput, INPUT);
	pullUpDnControl(switchInput, PUD_OFF);
	
	
	while(1){
		switchState= digitalRead(switchInput);
		if(switchState==0) {
			digitalWrite(GREEN, LOW);
			digitalWrite(RED, HIGH);
			delay(500);
			digitalWrite(RED, LOW);
			delay(500);
		}
		else if(switchState==1) {
			digitalWrite(RED, LOW);
			digitalWrite(GREEN, HIGH);
			delay(500);
			digitalWrite(GREEN, LOW);
			delay(500);
		}
		else {
			digitalWrite(RED, HIGH);
			digitalWrite(GREEN, HIGH);
		}
	}
}

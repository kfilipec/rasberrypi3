#include <iostream>
#include <wiringPi.h>
using namespace std;

int switchState;
int previousSwitchState;
int x;

#define GREEN 18
#define RED 15
#define switchInput 14



int main(){
	
	wiringPiSetupGpio();
	pinMode(GREEN, OUTPUT);
	pinMode(RED, OUTPUT);
	pinMode(switchInput, INPUT);
	digitalRead(switchInput);
	
	previousSwitchState= -1;
	x=0;
	
	
	while(1){
		
		switchState = digitalRead(switchInput);
		
		if (previousSwitchState ==-1)
			previousSwitchState = switchState;
		if (previousSwitchState != switchState)
			x++;
			
	if (x<5){
		digitalWrite(GREEN, HIGH);
		digitalWrite(RED, LOW);
	}
	else {
		digitalWrite(GREEN,LOW);
		digitalWrite(RED, HIGH);
		delay(1000);
		x=0;
	}
	previousSwitchState = switchState;
			
}
}

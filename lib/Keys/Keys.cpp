#include "Keys.h"
Keys::Keys(int onPress, int onRelease )
{
	OnPress = onPress;
	OnRelease = onRelease;
}

void Keys::process(int pin_num)
{
	if (digitalRead(pin_num) == LOW && isPressed == false)
	{
		isPressed = true;
		Serial1.write(OnPress);
		debug("sending:");
		debug(pin_num);
		debug(" ");
		debugln(OnPress);
	}
	else if (digitalRead(pin_num) == HIGH && isPressed == true)
	{
		isPressed = false;
		if (OnRelease)
		{
			Serial1.write(OnRelease);
			// debug("on relase:");
			// debugln(OnRelease);
		}
	}
}

Keys r1c1(1, 129); // [
Keys r1c2(2, 130); // p and 1
Keys r1c3(3, 131); // o and 2
Keys r1c4(4, 132); // i and 3
Keys r1c5(5, 133); // u and 4
Keys r1c6(6, 134); // y and 5

Keys r2c1(7, 135);	// '
Keys r2c2(8, 136);	// ; and
Keys r2c3(9, 137);	// l and |
Keys r2c4(10, 138); // k and (
Keys r2c5(11, 139); // j and )
Keys r2c6(12, 140); // h and &

Keys r3c1(13, 141); // ]
Keys r3c2(14, 142); // /
Keys r3c3(15, 143); // . and @
Keys r3c4(16, 144); // , and#
Keys r3c5(17, 145); // m and $
Keys r3c6(18, 146); // n and ^

Keys r4c3(19, 147); // right alt
Keys r4c4(20, 148); // shift
Keys r4c5(21, 149);
Keys r4c6(22, 150); // return
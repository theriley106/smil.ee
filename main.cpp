#include <string>
#include "upm/jhd1313m1.hpp"
#include <iostream>
#include <stdio.h>
#include <time.h>

#define I2C_BUS  0
#define RGB_WHT 0xff,0xff,0xff
#define RGB_RED 0xff,0x00,0x00
#define RGB_GRN 0x00,0xff,0x00
#define RGB_BLU 0x00,0x00,0xff
#define SLEEP_TIME 2

using namespace std;
upm::Jhd1313m1* lcd;

void display(string str1, string str2, int red, int green, int blue)
{
	lcd->clear();
	lcd->setColor(red, green, blue);
	lcd->setCursor(0,0); /* first row */
	lcd->write(str1);
	lcd->setCursor(1,0); 
	lcd->write(str2);
}

int main(int argc, char* argv[])
{
	string str1 = " ";
	string str2 = " ";

	lcd = new upm::Jhd1313m1(I2C_BUS, 0x3e, 0x62);


	str1 = argv[1];
	if ((argc >= 3) && (argv[2] != NULL))
		str2 = argv[2];
	display(str1, str2, RGB_GRN);
	return 0;
}

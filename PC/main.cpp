#include <iostream>
#include "SerialPort.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define SLEEP_TIME_TX 3

SerialPort *arduino;

char direction;

//Bluetooth portname
char *portName = "\\\\.\\COM53";

using namespace std;

char forward_dir[] = "F\n";
char left_dir[] = "L\n";
char right_dir[] = "R\n";
char stop_dir[] = "S\n";

void goForward(void)
{
	arduino->writeSerialPort(forward_dir, MAX_DATA_LENGTH);
}

void goLeft(void)
{
	arduino->writeSerialPort(left_dir, MAX_DATA_LENGTH);
}

void goRight(void)
{
	arduino->writeSerialPort(right_dir, MAX_DATA_LENGTH);
}

void goNowhere(void)
{
	arduino->writeSerialPort(stop_dir, MAX_DATA_LENGTH);
}

int main()
{
	arduino = new SerialPort(portName);

	if (arduino->isConnected()) cout << "Connection Established!" << endl;


	while (arduino->isConnected()) {
		cout << "Direction: " << endl;

		//Getting input without echoing
		//direction = _getch();

		cin >> direction;

		switch (direction)
		{
		case 'f':
			goForward();
			break;
		case 'l':
			goLeft();
			break;
		case 'r':
			goRight();
			break;
		default:
			goNowhere();
			break;
		}

		Sleep(SLEEP_TIME_TX);
	}

	delete arduino;
}

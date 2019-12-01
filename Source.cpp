#include <iostream>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include "Header.h"
using namespace std;
int back() {
	int code;
	cout << endl;
	cout << "������� ������, ���� ������ ��������� � ����";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}
struct vector
{
	double x;
	double y;
	double z;
};

vector sum(vector a, vector b)
{
	return { a.x + b.x,a.y + b.y,a.z + b.z };
}

double scalar(vector a, vector b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

double module(vector a)
{
	return sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

vector mul(double k, vector a)
{
	return { k * a.x,k * a.y,k * a.z };
}

void print_text(vector a, vector b, vector c, double k, double sum, double modul_a, vector ak)
{
	cout << "������ a(" << a.x << ";" << a.y << ";" << a.z << ") �� b(" << b.x << ";" << b.y << ";" << b.z << ")" << endl;
	cout << " a +  b = �(" << c.x << ";" << c.y << ";" << c.z << ")" << endl;
	cout << "��������� ������� a �� b = " << sum << endl;
	cout << "����� a = " << modul_a << endl;
	cout << "�������� a �� ������ k = (" << ak.x << ";" << ak.y << ";" << ak.z << ")" << endl;
}

void file(vector a, vector b, vector c, double k, double sum, double modul_a, vector ak)
{
	ofstream file("vector.txt");
	file << "������ a(" << a.x << ";" << a.y << ";" << a.z << ") �� b(" << b.x << ";" << b.y << ";" << b.z << ")" << endl;
	file << " a +  b = �(" << c.x << ";" << c.y << ";" << c.z << ")" << endl;
	file << "��������� ������� a �� b = " << sum << endl;
	file << "����� a = " << modul_a << endl;
	file << "�������� a �� ������ k = (" << ak.x << ";" << ak.y << ";" << ak.z << ")" << endl;
	file.close();

}

int m2()
{
	setlocale(LC_ALL, "Russian");
	vector a, b;
	double k;
	cout << "������� ���������� ������� �" << endl;
	cin >> a.x >> a.y >> a.z;
	cout << "������� ���������� ������� �" << endl;
	cin >> b.x >> b.y >> b.z;
	cout << "������� ������" << endl;
	cin >> k;
	vector c = sum(a, b);
	double sum = scalar(a, b);
	double modul_a = module(a);
	vector ak = mul(k, a);
	print_text(a, b, c, k, sum, modul_a, ak);
	file(a, b, c, k, sum, modul_a, ak);
	back();
	return 0;
}
int binom(int n, int k)
{
	if (n == k || k == 0)
		return 1;
	else
		return binom(n - 1, k - 1) + binom(n - 1, k);
}

int m4()
{
	setlocale(LC_ALL, "Russian");
	int n, k;
	cout << "������� n" << endl;
	cin >> n;
	while(n<0){
		cout << "������� n" << endl;
		cin >> n;
	}
	cout << "������� k" << endl;
	cin >> k;
	while (k>n &&k<0){
		cout << "������� k" << endl;
		cin >> k;
	}
	cout << binom(n, k);
	back();
	return 0;
}
int m1()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	char s[1000];
	ifstream file("text.txt");
	while (!file.eof()) {
		file.getline(s, 1000);
		n++;
	}
	file.seekg(0, ios::beg);
	char** mas = new char* [n];
	for (int i = 0; i < n; ++i)
	{
		mas[i] = new char[200];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			mas[i][j] = '\0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			file.read((char*)& mas[i][j], 1);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			if (mas[i][j] == '/' && mas[i][j + 1] == '/')
			{
				int c = j;
				while (mas[i][c] != '\n')
				{
					cout << mas[i][c];
					mas[i][c] = ' ';
					c++;
				}
				cout << endl;
			}
		}
	}
	file.close();
	ofstream file1("text.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			file1 << mas[i][j];
		}
	}
	file1.close();
	for (int i = 0; i < n; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
	back();
	return 0;
}
int m3() { back(); return 0;}
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include "Header.h"
using namespace std;
int back() {
	int code;
	cout << endl;
	cout << "Нажмите пробел, если хотите вернуться в меню";
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
	cout << "Вектор a(" << a.x << ";" << a.y << ";" << a.z << ") та b(" << b.x << ";" << b.y << ";" << b.z << ")" << endl;
	cout << " a +  b = с(" << c.x << ";" << c.y << ";" << c.z << ")" << endl;
	cout << "Скалярний добуток = " << sum << endl;
	cout << "Норма а = " << modul_a << endl;
	cout << "Множення а на скаляр = (" << ak.x << ";" << ak.y << ";" << ak.z << ")" << endl;
}

void file(vector a, vector b, vector c, double k, double sum, double modul_a, vector ak)
{
	ofstream file("vector.txt");
	file << "Вектор a(" << a.x << ";" << a.y << ";" << a.z << ") та b(" << b.x << ";" << b.y << ";" << b.z << ")" << endl;
	file << " a +  b = с(" << c.x << ";" << c.y << ";" << c.z << ")" << endl;
	file << "Скалярний добуток = " << sum << endl;
	file << "Норма a = " << modul_a << endl;
	file << "Множення a на скаляр = (" << ak.x << ";" << ak.y << ";" << ak.z << ")" << endl;
	file.close();

}

int m2()
{
	setlocale(LC_ALL, "Russian");
	vector a, b;
	double k;
	cout << "Введите координаты вектора а" << endl;
	cin >> a.x >> a.y >> a.z;
	cout << "Введите координаты вектора в" << endl;
	cin >> b.x >> b.y >> b.z;
	cout << "Введите скаляр" << endl;
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
	cout << "Введите n" << endl;
	cin >> n;
	while(n<0){
		cout << "Введите n" << endl;
		cin >> n;
	}
	cout << "Введите k" << endl;
	cin >> k;
	while (k>n &&k<0){
		cout << "Введите k" << endl;
		cin >> k;
	}
	cout << binom(n, k);
	back();
	return 0;
}
int m1()
{
	setlocale(LC_ALL, "Russian");
	char s[100] = { '\0' };
	ifstream file("1.txt");
	ofstream file1("2.txt");
	while (!file.eof())
	{
		file.read(s, sizeof(s));
		for (int i = 0; i < 100; i++)
		{
			if (s[i] == '/' && s[i + 1] == '/')
			{
				int j = i;
				while (s[j] != '\n') 
				{
					cout << s[j];
					s[j] = ' ';
					j++;
				}
				cout << endl;
			}
		}
		file1.write(s, sizeof(s));
	}
	file.close();
	file1.close();
	/*int n = 0;
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
	delete[] mas;*/
	back();
	return 0;
}
int m3()
{
	setlocale(LC_ALL, "Russian");
	ifstream file("matrix.txt");
	cout << "Основная диагональ" << endl;
	int n;
	file >> n;
	int** mas1 = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		mas1[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			file >> mas1[i][j];
			cout << mas1[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas1[i][j] == mas1[j][i] && i != j)
			{
				mas1[i][j] = 0;
				mas1[j][i] = 0;
			}
		}
	}
	cout << "Отакой она стала" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mas1[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (mas1[i][j] == 0) { count++; }
		}
		if (count == n) { cout << i + 1 << " строка-нулевая" << endl; }
	}
	for (int j = 0; j < n; j++)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (mas1[i][j] == 0) { count++; }
		}
		if (count == n) { cout << j + 1 << " столбец-нулевой" << endl; }
	}
	file.seekg(1, ios::beg);
	cout << "````````````````````````````````````````````````````````````" << endl;
	cout << "Побочная диагональ" << endl;
	int** mas2 = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		mas2[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			file >> mas2[i][j];
			cout << mas2[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (mas2[i][j] == mas1[n - j - 1][n - i - 1] && i != n - j - 1 && j != n - i - 1)
			{
				mas2[i][j] = 0;
				mas2[n - j - 1][n - i - 1] = 0;
			}
		}
	}
	cout << "Отакой она стала" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mas2[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (mas2[i][j] == 0) { count++; }
		}
		if (count == n) { cout << i + 1 << " строка-нулевая" << endl; }
	}
	for (int j = 0; j < n; j++)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (mas2[i][j] == 0) { count++; }
		}
		if (count == n) { cout << j + 1 << " столбец-нулевой" << endl; }
	}
	back();
	return 0;
}
#include <stdlib.h>
#include <iostream>   // для организации потокового ввода-вывода
#include <math.h>     // подключает математические функции
#include <locale>     // для использования символов на кириллице
#include <conio.h>    //для использования getch()
#include <string>

using namespace std;  // использовать пространство стандартных имен

int main()
{
	setlocale(LC_ALL, "rus");   // усановление локализации(рус)

	int k, n;

	bool isNormValue = false,
		firstIteration = true;

	cout << "Составить программу для вычисления числа перестановок используя только операторы цикла и условия.На вход подаются числа k и n. \n";

	while (!isNormValue)
	{
		if (!firstIteration) cout << "Данные введены некорректно, вводите целые числа!\n";
		else firstIteration = false;

		string str;
		bool isDigit = true;

		cout << "Введите число k: ";
		cin >> str;
		for (char s : str) {
			if (!isdigit(s))isDigit = false;
		}
		if (!isDigit) continue;
		k = atoi(str.c_str());

		cout << "Введите число n: ";
		cin >> str;
		for (char s : str) {
			if (!isdigit(s))isDigit = false;
		}
		if (!isDigit) continue;
		n = atoi(str.c_str());

		isNormValue = true;

		if (k > n) {
			cout << "Данные введены некорректно, k должно быть меньше n!\n";
			isNormValue = false;
			firstIteration = true;
		}
	}

	/* n! / (k!(n-k)!) */

	// отдельно вычислим факториалы

	int nF = 1, kF = 1, nkF = 1;
	int nkf = n - k;

	while (n != 1) {
		nF *= n--;
	}
	while (k != 1) {
		kF *= k--;
	}
	while (nkf != 1) {
		nkF *= nkf--;
	}


	double C = (nF / (kF * nkF));
	cout << C;
	
	return 0;
}

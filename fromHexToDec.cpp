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

	int x1, x2;
	bool isDigit = true,
		isNegative = false,
		isDouble = false,
		isHex = false;

	string str;

	while (!isHex)
	{
		cout << "Введите число в восьмеричной системе счисления (цифры от 0 до 7 включительно): ";
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (isalpha(str[i])) isDigit = false;
			if (isdigit(str[i]) > 7) isDigit = false;
		}

		if (str.find(".") != string::npos) isDouble = true;
		if (str.find("-") != string::npos) isNegative = true;

		if (isDigit) isHex = true;           //Условие выхода из цикла
	}

	string str1, str2;
	double res = 0;

	if (isNegative) str.erase(0, 1);
	if (isDouble) {
		int posPoint = str.find(".");

		str1 = str.substr(0, posPoint);
		str2 = str.substr(posPoint + 1, str.size() - posPoint);
		
		reverse(begin(str2), end(str2));

		x1 = atoi(str1.c_str());
		x2 = atoi(str2.c_str());

		for (int i = 0; i < str1.length(); i++) {
			res += (x1 % 10) * pow(8, i);
			x1 /= 10;
		}

		for (int i = 0; i < str2.length(); i++) {
			res += (x2 % 10) * pow(8, -i - 1);;
			x2 /= 10;
		}
	}
	else {
		x1 = atoi(str.c_str());
		for (int i = 0; i < str1.length(); i++) {
			res += (x1 % 10) * pow(8, i);;
			x1 /= 10;
		}
	}

	if (isNegative) res *= -1;

	cout << "Число в десятичной системе: " << res;
	return 0;
}

#include <stdlib.h>
#include <iostream>   // для организации потокового ввода-вывода
#include <math.h>     // подключает математические функции
#include <locale>     // для использования символов на кириллице
#include <conio.h>    //для использования getch()

using namespace std;  // использовать пространство стандартных имен

int main()
{
    float x, z;       // определение переменных
    setlocale(LC_ALL, "rus");   // усановление локализации(рус)
    
    cout << "\n x=";  // Вывод сообщения х=
    cin >> x;         // Ввод значеия в переменную х с клавиатуры
    
    z = x - (pow(x, 3) / 3) + (pow(x, 5) / 5);    // высчитываем значение выражения
    cout << "Результат=" << z;    // Вывод результата вычисления на экран
    
    _getch();         // приостановка выполнения программы до нажатия любой клавиши
    return 0;
}

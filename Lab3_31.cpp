#include <iostream>
#include <fstream>

using namespace std;

void WriteFile(const char*, string);
string ReadFile(const char*);
void Transformation(string&);

int main()
{
	setlocale(LC_ALL, "Russian");
	const char* pathToOldFile = "old_file.txt";
	const char* pathToNewFile = "new_file.txt";

	string myStr = ReadFile(pathToOldFile);
	cout << "Считанный из файла текст: " << myStr << endl;
	Transformation(myStr);
	cout << "Записываемый в файл текст: " << myStr << endl;
	WriteFile(pathToNewFile, myStr);

	return 0;
}

void WriteFile(const char* writeFile, string str) {
	ofstream F(writeFile);
	if (!F)
	{
		cout << "Невозможно открыть файл! \n";
	}

	F << str << endl; // записать в файл строку str

	F.close();
}

/*bool ReadFile(const char* filename) {
	// создать экземпляр класса
	ifstream inStream(filename); // открыть файл в конструкторе

	// если файл не открыт, то выход с кодом false
	if (!inStream)
		return false;

	// чтение строк в цикле while
	char str[100]; // буфер для чтения одной строки

	while (inStream) // если is ненулевое, то еще не конец файла
	{
		inStream.getline(str, '\n'); // прочитать строку из файла в буфер str
		cout << str << endl; // вывести на екран
	}

	inStream.close(); // закрыть файл
	return true;
}
*/

string ReadFile(const char* readFile) {

	// создать экземпляры классов ifstream
	ifstream rf(readFile, ios::in | ios::binary); // файл-источник (чтение)

	// проверка, открыт ли файл-источник
	if (!rf)
	{
		cout << "Невозможно открыть файл." << endl;
		return "";
	}

	char sym;
	string str = "";

	// цикл посимвольного чтения
	rf.get(sym); // считать из rf => sym
	if (sym)
	{
		do
		{
			str += sym;
			rf.get(sym); // считать из rf => sym
		} while (rf);
	};

	//cout << "Read result: " << str << endl;

	rf.close(); // закрыть оба файла
	return str;
}

void Transformation(string& str) {
	for (char& ch : str) {
		switch (ch) {
		case 'z': ch = 'a'; break;
		case 'я': ch = 'а'; break;
		case ' ': ch = ' '; break;
		default: ch++; break;
		}
	}
}
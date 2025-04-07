#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;
//глобальные переменные - стороны прямоугольника 
int ch1, ch2;

//проверка корректности вводимых данных 
bool UserInput(string input) {
	//если строка пустая - ввод некорректен
	if (input.empty()) return false;
	//попытаться
	try {
		//преобразование введенного значения в тип int
		int number = stoi(input);
		if (number < 0) return false;
	}
		catch (...) //если возникла ошибка в блоке try
		{
			return false;
		}
		return true;
}


//функция ввода данных
void enterNumber(int& varLink, string label)
{
	string str_input;
	cout << label << " - ";
	//ввод значения в текстовом виде
	getline(cin, str_input);
	//пока ввод некорректен
	while (!UserInput(str_input)) {
		cout << label << " = ";
		//ввод значения в текстовом виде
		getline(cin, str_input);
	}
	//присвоение переменной varLink преобразованного 
	// в тип int 
	//правильно введенного текстового значения 
	varLink = stoi(str_input);
}

char inputFirstChar() {
    char ch;
    cout << "Введите первый символ: ";
    cin >> ch;
    return ch;//branch_fun_1
}

// Функция для ввода второго символа
char inputSecondChar() {

}


// Функция для вывода символа и его кода ASCII
void printCharAndAscii() {

}

// Функция для вывода суммы кодов ASCII
void printAsciiSum() {

}

struct MenuItem {
	string title;
	function<void()> action;
};
	
int main() {
	map<int, MenuItem> menu = {
	//cout << "Пожалуйста, введите номер действия или 0, если вы хотите закрыть программу:" << endl;
	{ 1,{"1. Ввести первый символ", inputFirstChar } },
	{2, {"2. Ввести второй символ", inputSecondChar}},
	{3, {"3. Вывести каждый символ и код ASCII", printCharAndAscii}},
	{4, {"4. Вывести сумму кодов ASCII символов ch1 и ch2", printAsciiSum}},
	};
	int choice = 0;

	while (true) {
		cout << "Меню:" << endl;
		for (const auto& item : menu) {
			cout << "Task " << item.first << ". " << item.second.title << endl;
		}
		cout << "0. Выход" << std::endl;
		enterNumber(choice, "Input number of menu: ");
		if (choice == 0) {
			cout << "© 2025 FirstName LastName" << endl;
			break;
		}
		cout << endl;
		if (menu.find(choice) != menu.end()) {
			menu[choice].action();
		}
		else {
			cout << "Некорректный ввод.";
		}
		cout << endl;
	}
	return 0;
}
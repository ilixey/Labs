#include <iomanip>
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <string>

using namespace std;

void showMenu();
int number();
string Word();

class Products
{
protected:
	int NDS;
	string origin;
public:
	Products(int NDS, string origin)
	{
		this->NDS = NDS;
		this->origin = origin;
	};
	virtual void show() = 0;
};

int Menu(Products** mass);

class Fruits :public Products
{
private:
	int price;
	int amount;
public:
	Fruits(int NDS, string origin, int price, int amount):Products(NDS, origin)
	{
		this->price = price;
		this->amount = amount;
	};
	void show() override
	{
	
		cout << "Страна-производитель: " << this->origin << endl << "НДС: " << this->NDS << "%" << endl;
		cout << "Цена: " << this->price << "$" << endl << "Количество: " << this->amount << "кг" << endl;
	};
};

class Vegetables :public Products
{
private:
	int price;
	string kind;
public:
	Vegetables(int NDS, string origin, int price, string kind):Products(NDS, origin)
	{
		this->price = price;
		this->kind = kind;
	};
	void show() override
	{

		cout << "Страна-производитель: " << this->origin << endl << "НДС: " << this->NDS << "%" << endl;
		cout << "Цена: " << this->price << "$" << endl << "Вид: " << this->kind << endl;
	};
};

class Alcohol :public Products
{
private:
	int strength;
	string type;
public:
	Alcohol(int NDS, string origin, int strength, string type):Products(NDS, origin)
	{
		this->strength = strength;
		this->type = type;
	};
	void show() override
	{

		cout << "Страна-производитель: " << this->origin << endl << "НДС: " << this->NDS << "%" << endl;
		cout << "Крепость: " << this->strength << "%" << endl << "Тип: " << this->type << endl;
	}
	;
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	cout << endl;
	Products* mass[3];
	Fruits fruits(20, "Poland", 500, 500);
	Vegetables vegetables(20, "Belarus", 825, "tomato");
	Alcohol alcohol(20, "USA", 40, "GIN");
	mass[0] = &fruits;
	mass[1] = &vegetables;
	mass[2] = &alcohol;
	Menu(mass);
	return 0;
}

void showMenu()
{
	cout << "\tНажмите 1 - Фрукты \n\tНажмите 2 - Овощи \n\tНажмите 3 - Алкоголь\n\tНажмите 4 - выход\n\tВаш выбор:> ";
}

int Menu(Products** mass)
{

	cout << endl;
	system("cls");

	string origin;
	int NDS;
	cout << "Введите страну-производитель:" << endl;
	origin = Word();
	cout << "\nВведите НДС:" << endl;
	NDS = number();

	int amount, price;
	cout << "\nВведите цену:" << endl;
	price = number();
	cout << "\nВведите количество: " << endl;
	amount = number();

	string kind;
	cout << "\nВведите вид" << endl;
	kind = Word();

	string type;
	int strength;
	cout << "\nВведите Крепость:" << endl;
	strength = number();
	cout << "\nВведите тип" << endl;
	type = Word();
	system("cls");

	mass[0] = new Fruits(NDS, origin, price, amount);
	mass[0]->show();
	mass[1] = new Vegetables(NDS, origin, price, kind);
	mass[1]->show();
	mass[2] = new Alcohol(NDS, origin, strength, type);
	mass[2]->show();

	if (mass[0] != NULL) delete mass[0];
	if (mass[1] != NULL) delete mass[1];
	if (mass[2] != NULL) delete mass[2];

	return 0;
}

int number()
{
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224)
		{
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

string Word()
{
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

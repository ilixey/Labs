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
	void show()
	{
		system("cls");
		cout << "Страна-производитель: " << this->origin << endl << "НДС: " << this->NDS << "%" << endl;
	};
};

int Menu(Products** mass);

class Fruits :virtual public Products
{
private:
	int price;
	int amount;
public:
	Fruits(int NDS, string origin, int price, int amount):Products(NDS, origin)
	{
		this->Products::Products(NDS, origin);
		this->price = price;
		this->amount = amount;
	};
	void show()
	{
		Products::show();
		cout << "Цена: " << this->price << "$" << endl << "Количество: " << this->amount << "кг" << endl;
	};
};

class Vegetables :virtual public Products
{
private:
	int price;
	string kind;
public:
	Vegetables(int NDS, string origin, int price, string kind):Products(NDS, origin)
	{
		this->Products::Products(NDS, origin);
		this->price = price;
		this->kind = kind;
	};
	void show()
	{
		Products::show();
		cout << "Цена: " << this->price << "$" << endl << "Дата производства: " << this->kind << endl;
	};
};

class Alcohol :virtual public Products
{
private:
	int strength;
	string type;
public:
	Alcohol(int NDS, string origin, int strength, string type):Products(NDS, origin)
	{
		this->Products::Products(NDS, origin);
		this->strength = strength;
		this->type = type;
	};
	void show()
	{
		Products::show();
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
	int choice;
	while (true)
	{
		showMenu();
		choice = number();
		cout << endl;
		system("cls");
		switch (choice)
		{
		case 1://Fruits
		{
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
			mass[0] = new Fruits(NDS, origin, price, amount);
			mass[0]->show();
			break;
		}
		case 2://Vegetables
		{
			string origin;
			int NDS;
			cout << "\nВведите страну-производитель:" << endl;
			origin = Word();
			cout << "Введите НДС:" << endl;
			NDS = number();

			int price;
			string kind;
			cout << "\nВведите цену:" << endl;
			price = number();
			cout << "\nВведите вид" << endl;
			kind = Word();
			mass[1] = new Vegetables(NDS, origin, price, kind);
			mass[1]->show();
			break;
		}
		case 3://alcohol
		{
			string origin;
			int NDS;
			cout << "Введите страну-производитель:" << endl;
			origin = Word();
			cout << "\nВведите НДС:" << endl;
			NDS = number();

			string type;
			int strength;
			cout << "\nВведите Крепость:" << endl;
			strength = number();
			cout << "\nВведите тип" << endl;
			type = Word();
			mass[2] = new Alcohol(NDS, origin, strength, type);
			mass[2]->show();
			break;
		}
		case 4:
			return 0;
		default:
			cout << endl << "Ошибка! Неверное действие" << endl;
		}
	}
	if (mass[0] != NULL) delete mass[0];
	if (mass[1] != NULL) delete mass[1];
	if (mass[2] != NULL) delete mass[2];
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

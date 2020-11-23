#include <iomanip>
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <string>

using namespace std;

void showMenu();
int menu();
int number();
string word();

class Products
{
private:
	int NDS;
	string origin;
public:
	Products(int NDS, string origin)
	{
		this->NDS = NDS;
		this->origin = origin;
	};
	void showProducts();
};

class Fruits :public Products
{
private:
	int price;
	int amount;
public:
	Fruits(int NDS, string origin, int price, int amount) :Products(NDS, origin)
	{
		this->price = price;
		this->amount = amount;
	};
	void showFruits();
};

class Vegetables :public Products
{
private:
	int price;
	string kind;
public:
	Vegetables(int NDS, string origin, int price, string kind) :Products(NDS, origin)
	{
		this->price = price;
		this->kind = kind;
	};
	void showVegetables();
};

class Alcohol :public Products
{
private:
	int strength;
	string type;
public:
	Alcohol(int NDS, string origin, int strength, string type) :Products(NDS, origin)
	{
		this->strength = strength;
		this->type = type;
	};
	void showAlcohol();
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	cout << endl;
	menu();
	return 0;
}

void showMenu()
{
	cout << "\tНажмите 1 - Фрукты \n\tНажмите 2 - Овощи \n\tНажмите 3 - Алкоголь\n\tНажмите 4 - выход\n\tВаш выбор:> ";
}

int menu()
{
	Fruits* fruits = NULL;
	Vegetables* vegetables = NULL;
	Alcohol* alcohol = NULL;

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
			origin = word();
			cout << "\nВведите НДС:" << endl;
			NDS = number();

			int amount, price;
			cout << "\nВведите цену:" << endl;
			price = number();
			cout << "\nВведите количество: " << endl;
			amount = number();
			fruits = new Fruits(NDS, origin, price, amount);
			fruits->showFruits();
			break;
		}
		case 2://Vegetables
		{
			string origin;
			int NDS;
			cout << "\nВведите страну-производитель:" << endl;
			origin = word();
			cout << "Введите НДС:" << endl;
			NDS = number();

			int price;
			string kind;
			cout << "\nВведите цену:" << endl;
			price = number();
			cout << "\nВведите вид" << endl;
			kind = word();
			vegetables = new Vegetables(NDS, origin, price, kind);
			vegetables->showVegetables();
			break;
		}
		case 3://alcohol
		{
			string origin;
			int NDS;
			cout << "Введите страну-производитель:" << endl;
			origin = word();
			cout << "\nВведите НДС:" << endl;
			NDS = number();

			string type;
			int strength;
			cout << "\nВведите Крепость:" << endl;
			strength = number();
			cout << "\nВведите тип" << endl;
			type = word();
			alcohol = new Alcohol(NDS, origin, strength, type);
			alcohol->showAlcohol();
			break;
		}
		case 4:
			return 0;
		default:
			cout << endl << "Ошибка! Неверное действие" << endl;
		}
	}
	if (fruits != NULL) delete fruits;
	if (vegetables != NULL) delete vegetables;
	if (alcohol != NULL) delete alcohol;
}

void Products::showProducts()
{
	system("cls");
	cout << "Страна-производитель: " << this->origin << endl << "НДС: " << this->NDS << "%" << endl;
}

void Fruits::showFruits()
{
	system("cls");
	Products::showProducts();
	cout << "Цена: " << this->price << "$" << endl << "Количество: " << this->amount << "кг" << endl;
}

void Vegetables::showVegetables()
{
	system("cls");
	Products::showProducts();
	cout << "Цена: " << this->price << "$" << endl << "Дата производства: " << this->kind << endl;
}

void Alcohol::showAlcohol()
{
	system("cls");
	Products::showProducts();
	cout << "Крепость: " << this->strength << "%" << endl << "Тип: " << this->type << endl;
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

string word()
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

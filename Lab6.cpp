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
public:
	Products() {};
	Products(int NDS)
	{
		this->NDS = NDS;
	};
	virtual void show() = 0;
};

int Menu();

class Fruits :virtual public Products
{
protected:
	int price;
	int amount;
public:
	Fruits() {};
	Fruits(int NDS, int price, int amount) :Products(NDS)
	{
		this->price = price;
		this->amount = amount;
	};
	void show() override
	{
		system("cls");
		cout << "НДС: " << this->NDS << "%" << endl;
		cout << "Цена: " << this->price << "$" << endl << "Количество: " << this->amount << "кг" << endl;
	};
};

class Vegetables :virtual public Products
{
protected:
	int price;
	string kind;
public:
	Vegetables() {};
	Vegetables(int NDS, int price, string kind) :Products(NDS)
	{
		this->price = price;
		this->kind = kind;
	};
	void show() override
	{
		system("cls");
		cout << endl << "НДС: " << this->NDS << "%" << endl;
		cout << "Цена: " << this->price << "$" << endl << "Вид: " << this->kind << endl;
	};
};

class Provider :public Fruits, public Vegetables
{
private:
	string company;
	string country;
	int rate;
public:
	Provider() {};
	Provider(int NDS, int price, int amount, string company,string country, int rate) : Fruits(NDS, price, amount), Products(NDS)
	{
		this->company = company;
		this->country = country;
		this->rate = rate;
	};

	Provider(int NDS, int price, string kind, string company, string country, int rate) : Vegetables(NDS, price, kind), Products(NDS)
	{
		this->company = company;
		this->country = country;
		this->rate = rate;
	};
	void show_provider1()
	{
		Fruits:: show();
		system("cls");
		cout << "Компания-поставщик: " << this->company<< endl << "Страна-поставщик: " << this->country<< endl << "Рейтинг поставщика: " << this->rate << endl;
	};

	void show_provider2()
	{
		Vegetables::show();
		system("cls");
		cout << "Компания-поставщик: " << this->company << endl << "Страна-поставщик: " << this->country << endl << "Рейтинг поставщика: " << this->rate << endl;
	}
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	cout << endl;
	Menu();
	return 0;
}

void showMenu()
{
	cout << "\tНажмите 1 - Фрукты \n\tНажмите 2 - Овощи \n\tНажмите 4 - выход\n\tВаш выбор:> ";
}

int Menu()
{
	Provider* provider = NULL;

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
			int NDS;
			cout << "\nВведите НДС:" << endl;
			NDS = number();

			int amount, price;
			cout << "\nВведите цену:" << endl;
			price = number();
			cout << "\nВведите количество: " << endl;
			amount = number();

			string country, company;
			int rate;
			cout << "\nВведите компанию-поставщика: " << endl;
			company = Word();
			cout << "\nВведите страну-производитель: " << endl;
			country = Word();
			cout << "\nВведите рейтинг поставщика: " << endl;
			rate = number();
			provider = new Provider(NDS, price, amount, country, company, rate);
			provider->show_provider1();
			break;
		}

		case 2://Vegetables
		{
			string origin;
			int NDS;
			cout << "\nВведите страну-производитель:" << endl;
			origin = Word();
			cout << "\nВведите НДС:" << endl;
			NDS = number();

			int price;
			string kind;
			cout << "\nВведите цену:" << endl;
			price = number();
			cout << "\nВведите вид" << endl;
			kind = Word();

			string country, company;
			int rate;
			cout << "\nВведите компанию-поставщика: " << endl;
			company = Word();
			cout << "\nВведите страну-производитель: " << endl;
			country = Word();
			cout << "\nВведите рейтинг поставщика: " << endl;
			rate = number();
			provider = new Provider(NDS, price, kind, country, company, rate);
			provider->show_provider2();
			break;
		}

		case 4:
			return 0;
		default:
			cout << endl << "Ошибка! Неверное действие" << endl;
		}
	}
	if (provider != NULL) delete provider;
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

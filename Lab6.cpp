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
	void show() 
	{
		cout << "НДС: " << this->NDS << "%" << endl;
	};
};

int Menu();


class Provider : virtual public Products
{
protected:
	string company;
	string country;
	int rate;
public:
	Provider() {};
	Provider(int NDS, string company,string country, int rate) : Products(NDS)
	{
		this->company = company;
		this->country = country;
		this->rate = rate;
	};

	void show()
	{
		cout << "Компания-поставщик: " << this->company<< endl << "Страна-поставщик: " << this->country<< endl << "Рейтинг поставщика: " << this->rate << endl;
	};
};

class Section :virtual public Products
{
protected:
	string name;
public:
	Section() {};
	Section(int NDS, string name) :Products(NDS)
	{
		this->name = name;
	};
	void show()
	{
		cout << "Отдел: " << this->name << endl;
	};
};

class Unit : public Provider, public Section
{
protected:
	int price;
	string kind;
	int code;
public:
	Unit() {};
	Unit(int NDS, string company, string country, int rate, string name, int price, string kind, int code) :Products(NDS), Section(NDS, name), Provider(NDS, company, country, rate)
	{
		this->price = price;
		this->kind = kind;
		this->code = code;
	};
	void show_unit() 
	{
		system("cls");
		Products::show();
		Provider::show();
		Section::show();
		cout << "Код товара: " << this->code << endl;
		cout << "Товар: " << this->kind << endl << "Цена: " << this->price << "$" << endl;
	};
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

int Menu()
{
	Unit* unit = NULL;
	system("cls");

	int NDS;
	cout << "\nВведите НДС:" << endl;
	NDS = number();

	string country, company;
	int rate;
	cout << "\nВведите компанию-поставщика: " << endl;
	company = Word();
	cout << "\nВведите страну-производитель: " << endl;
	country = Word();
	cout << "\nВведите рейтинг поставщика: " << endl;
	rate = number();

	string name;
	cout << "\nВведите отдел:" << endl;
	name = Word();

	int price, code;
	string kind;
	cout << "\nВведите код товара: " << endl;
	code = number();
	cout << "\nВведите товар:" << endl;
	kind = Word();
	cout << "\nВведите цену" << endl;
	price = number();

	unit = new Unit(NDS, company, country, rate, name, price, kind, code);
	unit->show_unit();
	if (unit != NULL) delete unit;
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

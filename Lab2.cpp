#include <iostream>
#include <string>

using namespace std;

class Square{

private:

	double length;

public:

	Square(int valueA){
		length = getValue(valueA);
	}

	double GetLength() {
		return length;
	}

	void PrintLength() {
		cout << "Длина ребра: " << length << endl;
	}

	void FindArea() {
		cout << "Площадь квадрата равна " << length * length << endl;
	}

	void FindPerimeter() {
		cout << "Периметр квадрата равен " << 4 * length << endl;
	}

	double getValue(int value)
	{
		while (true) {
			cout << "Введите длину ребра квадрата: ";
			double value;
			cin >> value;
			if (cin.fail() || value<0)
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Некорректное значение, повторите попытку\n";
			}
			else
			{
				cin.ignore(256, '\n');
				return value;
			}
			
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	int a = 0;
	Square square(a);

	system("cls");

	cout << "Выбранная длина ребра: " << square.GetLength() << endl;
	square.FindPerimeter();
	square.FindArea();
}

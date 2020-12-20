#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int writeNumbers();

template <class T> class Matrix
{
private:
	T** a;
	T n;	
	T m;
public: 
	Matrix()
	{
		n = 0;
		m = 0;
		a = NULL;
	};
	Matrix(T n1, T m1)
	{
		n = n1; m = m1;
		a = new T* [m];
		for (int i = 0; i < m; i++)
			a[i] = new T[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = 0;

	}
	Matrix(const Matrix<T>& object)
	{
		n = object.n;
		m = object.m; if (object.a == NULL)
		{
			a = NULL;
			return;
		}
		a = new T* [m];
		for (int i = 0; i < m; i++)
			a[i] = new T[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = object.a[i][j];

	}

	void operator + (Matrix<T>& object)
	{
		if (n == object.n && m == object.m)
		{
			Matrix<T> temp(n, m);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					temp.a[i][j] = a[i][j] + object.a[i][j];

			temp.show();

		}
		else
			return;

		system("pause");
	}

	void operator < (Matrix<T>& object)
	{
		if (n == object.n && m == object.m)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					if (a[i][j] > object.a[i][j])
					{
						infNET();
						return;
					}

				}
			infDA();
		}


		else
			return;

		system("pause");
	}

	void show()
	{

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		system("pause");

	}

	void max_el()
	{
		int max = a[0][0];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (max < a[i][j]) {
					max = a[i][j];
				}
			}
		}

		cout << "\nМаксимальный элемент матрицы равен " << max << endl;
		system("pause");
	}

	void sredn()
	{
		double sr = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				sum += a[i][j];

			}
		}
		sr = sum / (n * m);
		cout << "\nСреднее значение элемнтов матрицы равно " << sr << endl;
		system("pause");
	}

	void fillArray() {
		cout << "\n1 - Ввести матрицу рандомно \n2 - Ввести матрицу вручную\n";
		int choice;
		cin >> choice;
			switch (choice)
			{
				case 1: {
					cout << "\nВведите левую границу диапазона: ";
					int l = 0, r = 0;
					cin >> l;
					cout << "\nВведите правую границу диапазона: ";
					cin >> r;
					srand(time(NULL));
					for (int i = 0; i < n; i++)
						for (int j = 0; j < m; j++)
							a[i][j] = rand() % (r - l + 1) + l;
					break;
				}
				case 2:
				{
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++)
							cin >> a[i][j];
					}
					break;
				}
			}
	}
	void infDA()
	{
		cout << "\nДА" << endl;
	}
	void infNET()
	{
		cout << "\nНЕТ" << endl;
	}
};

int main()
{
	setlocale(0, "rus");
	int n, m, k, p;
	cout << "Выберите количество столбцов: ";
	cin >> n;
	cout << "\nВыберите количество строк: ";;
	cin >> m;
	k = n;
	p = m;
	Matrix<double> object(n, m);
	while (true) {
		int choice = 0;
		system("cls");
		cout << "1 - Заполнить матрицу\n2 - Показать матрицу\n3 - Найти среднее значение элементов\n4 - Найти максимальный элемент\n5 - Сложить матрицы\n6 - Сравнить матрицы\n7 - Выйти\n";
		cin >> choice;
		switch (choice) {
				case 1:
			{
				object.fillArray();
				break;
			}

			case 2:
			{
				object.show();
				break;
			}

			case 3:
			{
				object.sredn();
				break;
			}

			case 4:
			{
				object.max_el();
				break;
			}

			case 5:
			{

				Matrix<double> object1(k, p);
				object1.fillArray();
				object.show();
				object1.show();
				system("pause");
				object + object1;
				break;
			}

			case 6:
			{
				Matrix<double> object1(k, p);
				object1.fillArray();
				object.show();
				object1.show();
				object < object1;
				system("pause");
				break;
			}

			case 7: return false;
			
		}
	}
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
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
				if (key == 13 && numbers.length() != 0 && numbers != "-") break;
				else
					if ((key >= '0' && key <= '9') || (key == '-' && numbers.length() == 0)) {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

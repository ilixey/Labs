#include<iostream>
#include<iomanip>

using namespace std;

class Class {

private:

	int value;

public:

	Class(int value) {

		this->value = value;

	}

	void Set() {

		int a;
		cin >> a;
		cout << endl;
		this->value = a;

	}

	int Get() {

		return value;

	}


	friend Class& operator++(Class& d);
	friend ostream& operator<<(ostream &out, Class& d);


};

Class& operator++(Class& d) {

	++d.value;
	return d;
};

ostream& operator<<(ostream &out, Class& d) {

	out << d.value;
	return out;

}


int main() {

	setlocale(LC_ALL, "rus");

	Class value(0);

	bool flag = false;
	while (!flag) {
		system("cls");
		cout << "Введите значение: ";
		value.Set();
		++value;
		cout << "Значение после операции:" << value << endl;
		cout << "Введить 0, чтобы выйти ";
		int a;
		cin >> a;
		cout << endl;
		if (a == 0) flag = true;
	}
}

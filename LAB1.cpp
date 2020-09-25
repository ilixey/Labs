#include<iomanip>
#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	double a, b, c, x;

	cout << "Уравнение вида: a*x+b=c\nВведите коофиценты\n";

	cout << "а=";
	cin >> a;
	cout << "\nb=";
	cin >> b;
	cout << "\nc=";
	cin >> c;

	cout << a << "*x + " << b << "=" << c;
	x = (c - b) / a;

	cout << "\nОтвет:\n";

	cout << setw(10) << setfill('%') << setprecision(4) << x;
}

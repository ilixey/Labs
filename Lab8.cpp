#include <iostream> 
#include <locale.h> 
#include <string>

using namespace std;

class BankAccount {
private:
	double balance;
public:
	BankAccount() {
		balance = 0;
	}

	BankAccount(double balance) {
		this->balance = balance;
	}

	void show();
	void withdraw(double sum); //снять
	void replenish(double sum); //пополнить
	double get();
	void set(double balance);
};
void  BankAccount::show() {
	cout << "Настоящий баланс: " << this->balance << endl;
}

double  BankAccount::get()
{
	return this->balance;
}

void  BankAccount::set(double balance) {
	this->balance = balance;
}

void   BankAccount::withdraw(double sum) {
	balance -= sum;
}

void  BankAccount::replenish(double sum) {
	balance += sum;
}

template <class T>
class Tran
{
	T* that;
	T* prev;
public:
	Tran() :prev(NULL), that(new T) {}
	Tran(const Tran& obj) :
		that(new T(*(obj.that))), prev(NULL) {}
	~Tran() { delete that;  delete prev; }

	Tran& operator=(const Tran& obj)
	{
		if (this != &obj)
		{
			delete that;
			that = new T(*(obj.that));
		}
		return *this;
	};

	void Show(int fl)
	{
		cout << "\t\tБанковский счёт ";
		if (!fl)
			cout << "до начала транзакции " << endl;
		else
			cout << "после выполнения транзакции: " << endl;

		if (prev)
			cout << "\t\tДо операции: " << prev->get() << endl;
		else
			cout << "\t\tДо операции: данные отсутсвуют" << endl;
		cout << "\t\tВ данный момент " << that->get() << endl;
	};

	bool Begin()
	{
		delete prev;
		prev = that;
		that = new T(*prev);
		if (!that)
			return false;
		return true;
	};

	void Commit()
	{
		delete prev;
		prev = NULL;
	};

	void Back()
	{
		if (prev != NULL)
		{
			delete that;
			that = prev;
			prev = NULL;
		}
	};

	T* operator->()
	{
		return that;
	};
};

void showMenu() {
	cout << "\t\t\t\t1 - Пополнить баланс" << endl;
	cout << "\t\t\t\t2 - Снять со счёта" << endl;
	cout << "\t\t\t\t3 - Показать баланс" << endl;
	cout << "\t\t\t\t4 - Откатить последнюю операцию" << endl;
	cout << "\t\t\t\t5 - История операций" << endl;
	cout << "\t\t\t\t6 - Посмотреть механизм транзакций" << endl;
	cout << "\t\t\t\t7 - Закрепить счёт" << endl;
	cout << "\t\t\t\t0 - Выйти" << endl;
	cout << "\t\t\t>> ";
}

int main()
{
	string log = "";
	Tran<BankAccount> tr;
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	double sum;
	tr.Show(false);
	do {
		showMenu();
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "\tВведите сумму для пополнения: ";
			cin >> sum;
			if (tr.Begin()) {
				tr->replenish(sum);
				log += "\nПополнение: " + to_string(sum);
			}
			else {
				cout << "Ошибка в создании транзакции!";
				log += "\nПополнение: Ошибка в создании транзакции!";
			}
			break;
		case 2:
			cout << "\tВведите сумму для снятия: ";
			cin >> sum;
			if (tr.Begin()) {
				tr->withdraw(sum);
				log += "\nСнятие: " + to_string(sum);
			}
			else {
				cout << "Ошибка в создании транзакции!";
				log += "\nCнятие: Ошибка в создании транзакции!";
			}

			if (tr->get() < 0) {
				cout << "\tОбнаружен отрицательный баланс(недостаточно средств для снятия), проводится откат операци..." << endl;
				log += "\nCнятие: отрицательный баланс - откат назад";
				tr.Back();
			}

			break;
		case 3:
			cout << "\t\t";
			tr->show();
			break;
		case 4:
			tr.Back();
			log += " - откат назад";
			break;
		case 5:
			cout << endl << log << endl << endl;
			break;
		case 6:
			tr.Show(true);
			break;
		case 7:
			tr.Commit();
			log += "\nСчет закреплен";
			break;
		default:
			break;
		}
	} while (choice != 0);

	tr.Show(true);
	return 0;
}


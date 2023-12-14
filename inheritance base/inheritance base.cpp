#include <iostream>

using namespace std;
const int LEN = 80; // максимальная длина имени
///////////////////////////////////////////////////////////
class employee // некий сотрудник
{
private:
	char name[LEN]; // имя сотрудника
	unsigned long number; // номер сотрудника
public:
	void getdata()
	{
		cout << "\n Введите фамилию: "; cin >> name;
		cout << " Введите номер: "; cin >> number;
	}
	void putdata()
	{
		cout << "\n Фамилия: " << name;
		cout << "\n Номер: " << number;
	}
};
//////////////////////////////////
class compensation : public employee// зарплата
{
private:
	double comp;
	enum per { hour, week, mon };
	per per2;
public:
	void getdata1()
	{
		cout << " Введите сумму компенсации ";
		cin >> comp;
		char a = 'a';
		cout << " Введите период (h/w/m): ";
		cin >> a;
		switch (a)
		{
		case 'h': per2 = hour; break;
		case 'w': per2 = week; break;
		case 'm': per2 = mon; break;
		}
		cout << endl;
	}
	void putdata1()
	{
		cout << " Сумма компенсации: " << comp << endl;
		cout << " Период: ";
		switch (per2)
		{
		case hour: cout << "в час" << endl; break;
		case week: cout << "в неделю" << endl; break;
		case mon: cout << "в месяц" << endl; break;
		}
	}
};
///////////////////////////////////////////////////////////
class manager : public compensation // менеджер
{
private:
	char title[LEN]; // должность, например вице-президент
	double dues; // сумма взносов в гольф-клуб
public:
	void getdata()
	{
		employee::getdata();
		cout << " Введите должность: "; cin >> title;
		cout << " Введите сумму взносов в гольф-клуб: "; cin >> dues;
		compensation::getdata1();
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n Должность: " << title;
		cout << "\n Сумма взносов в гольф-клуб: " << dues << endl;
		compensation::putdata1();
	}
};
///////////////////////////////////////////////////////////
class scientist : public compensation// ученый
{
private:
	int pubs; // количество публикаций
public:
	void getdata()
	{
		employee::getdata();
		cout << " Введите количество публикаций: "; cin >> pubs;
		compensation::getdata1();
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n Количество публикаций: " << pubs << endl;
		compensation::putdata1();
	}
};
///////////////////////////////////////////////////////////
class laborer : public compensation // рабочий
{
};
///////////////////////////////////////////////////////////


int main()
{
	setlocale(LC_ALL, "Russian");
	manager m1, m2;
	scientist s1;
	laborer l1;
	// введем информацию о нескольких сотрудниках
	cout << endl;
	cout << "\nВвод информации о первом менеджере";
	m1.getdata();
	cout << "\nВвод информации о втором менеджере";
	m2.getdata();
	cout << "\nВвод информации о первом ученом";
	s1.getdata();

	cout << "\nВвод информации о первом рабочем";
	l1.getdata();

	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	m1.putdata();

	cout << "\nИнформация о втором менеджере";
	m2.putdata();

	cout << "\nИнформация о первом ученом";
	s1.putdata();

	cout << "\nИнформация о первом рабочем";
	l1.putdata();

	cout << endl;
	return 0;
}
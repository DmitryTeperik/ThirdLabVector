


/*11. Реализовать шаблон класса динамический массив (Vector<X>), хранящий элементы
произвольного типа. Класс должен содержать:
Инициализация массива; +
Добавление элемента в начало массива;+
Добавление элемента в конец массива;+
Показ всех элементов массива.+
a)
Удаление всех элементов массива;+
Определение количества элементов массива;+
Проверка массива на пустоту;+
Удаление первого элемента;+
Удаление последнего элемента; +
Теперик Д. В. ,9 группа */

#include "stdafx.h"
#include <iostream>
#include "Windows.h"
#include "Money.h"
using namespace std;

template <typename TYPE>
class Vector
{
private:
	int size;
	TYPE *data;
	void Create(int n);
public:
	int Length();
	Vector(int n);
	Vector();
	~Vector();
	Vector& Clear();
	Vector& Init(int n);
	Vector& PushFront(TYPE a);
	Vector& PushBack(TYPE a);
	TYPE PopFront();
	TYPE PopBack();
	void Print();
	bool IsEmpty();
	TYPE& operator [] (int i);
};

//Определение длины массива
template <typename TYPE>
int Vector<TYPE>::Length()
{
	return size;
}

template <typename TYPE>
void Vector<TYPE>::Create(int n)
{
	if (n <= 0)
	{
		size = 0;
	}
	else
	{
		size = n;
	}
	if (n < 1)
	{
		n = 0;
	}
	data = new TYPE[n];
}

//Конструктор
template <typename TYPE>
Vector<TYPE>::Vector(int n)
{
	Create(n);
}

//Конструктор
template <typename TYPE>
Vector<TYPE>::Vector()
{
	Create(0);
}

//Деструктор
template <typename TYPE>
Vector<TYPE>::~Vector()
{
	delete[]data;
}

//Очистка массива
template <typename TYPE>
Vector<TYPE>& Vector<TYPE>::Clear()
{
	delete[]data;
	Create(0);
	return *this;
}

//Инициализация массива
template <typename TYPE>
Vector<TYPE>& Vector<TYPE>::Init(int n)
{
	delete[]data;
	Create(n);
	return *this;
}

//Добавление в начало
template <typename TYPE>
Vector<TYPE>& Vector<TYPE>::PushFront(TYPE a)
{
	TYPE *res = new TYPE[size + 1];
	res[0] = a;
	for (int i = 0; i < size; ++i)
	{
		res[i + 1] = data[i];
	}
	delete[]data;
	data = res;
	++size;
	return *this;
}

//Добавление в конец
template <typename TYPE>
Vector<TYPE>& Vector<TYPE>::PushBack(TYPE a)
{
	TYPE *res = new TYPE[size + 1];
	res[size] = a;
	for (int i = 0; i < size; ++i)
	{
		res[i] = data[i];
	}
	delete[]data;
	data = res;
	++size;
	return *this;
}

//Удаление из начала
template <typename TYPE>
TYPE Vector<TYPE>::PopFront()
{
	TYPE a = data[0];
	if (size < 2)
	{
		Create(0);
	}
	else
	{
		--size;
		TYPE *res = new TYPE[size];
		for (int i = 0; i < size; ++i)
		{
			res[i] = data[i + 1];
		}
		delete[]data;
		data = res;
	}
	return a;
}

//Удаление из конца
template <typename TYPE>
TYPE Vector<TYPE>::PopBack()
{
	TYPE a;
	if (size < 2)
	{
		a = data[0];
		Create(0);
	}
	else
	{
		--size;
		a = data[size];
		TYPE *res = new TYPE[size];
		for (int i = 0; i < size; ++i)
		{
			res[i] = data[i];
		}
		delete[]data;
		data = res;
	}
	return a;
}

//Проверка на пустоту
template <typename TYPE>
bool Vector<TYPE>::IsEmpty()
{
	if (size == 0)
		return 1;
	return 0;
}

//Вывод всех элементов на экран
template <typename TYPE>
void Vector<TYPE>::Print()
{

	for (int i = 0; i < Length(); ++i)
	{
		cout << data[i] << " ";
	}

}

//Переопределение квадратных скобок
template <typename TYPE>
TYPE& Vector<TYPE>::operator [] (int i)
{
	if (i < 0)
	{
		i = 0;
	}
	else if (i > size)
	{
		i = size - 1;
	}
	return data[i];
}

int Menu()
{
	cout << "------------------------------------------------------\n";
	cout << "                         МЕНЮ                         \n";
	cout << "------------------------------------------------------\n";
	cout << "1 - Инициализация массива.\n";
	cout << "2 - Добавление элемента в начало массива.\n";
	cout << "3 - Добавление элемента в конец массива; .\n";
	cout << "4 - Показ всех элементов массива.\n";
	cout << "5 - Удаление всех элементов массива.\n";
	cout << "6 - Проверка массива на пустоту.\n";
	cout << "7 - Удаление первого элемента.\n";
	cout << "8 - Удаление последнего элемента.\n";
	cout << "9 - Определение длины массива.\n";
	cout << "0 - Выход.\n";
	cout << "------------------------------------------------------\n";
	int p;
	do {
		cout << ">> ";
		cin >> p;
		if ((p < 0) || (p > 9))
			cout << "Введеное значение неверно. Повторите ввод.\n";
	} while ((p < 0) || (p > 9));
	getchar();
	cout << "\n";
	return p;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector<int> VecInt;
	Vector<string> VecStr;
	Vector<Money> VecMon;

	int n;
	int a;
	string str;
	Money b;


	do
	{
		n = Menu();
		switch (n)
		{
		case 1:
		{
			VecInt.Init(0);
			cout << "VecInt инициализирован" << endl;
			VecStr.Init(0);
			cout << "VecStr инициализирован" << endl;
			VecMon.Init(0);
			cout << "VecMon инициализирован" << endl;
		}
		break;
		case 2:
		{
			a = 5;
			str = "ежик";
			b = (34.11);
			VecInt.PushFront(a);
			VecStr.PushFront(str);
			VecMon.PushFront(b);
		}
		break;
		case 3:
		{
			a = 1;
			str = "картошка";
			b = (50.20);
			VecInt.PushBack(a);
			VecStr.PushBack(str);
			VecMon.PushBack(b);
		}
		break;
		case 4:
		{
			VecInt.Print();
			cout << endl;
			VecStr.Print();
			cout << endl;
			VecMon.Print();
			cout << endl;
		}
		break;
		case 5:
		{
			VecInt.Clear();
			cout << "VecInt очищен" << endl;
			VecStr.Clear();
			cout << "VecStr очищен" << endl;
			VecMon.Clear();
			cout << "VecMon очищен" << endl;
		}
		break;
		case 6:
		{
			if (VecInt.IsEmpty())
				cout << "VecInt пуст" << endl;
			else
				cout << "VecInt непуст" << endl;

			if (VecStr.IsEmpty())
				cout << "VecStr пуст" << endl;
			else
				cout << "VecStr непуст" << endl;

			if (VecMon.IsEmpty())
				cout << "VecMon пуст" << endl;
			else
				cout << "VecMon непуст" << endl;

		}
		break;
		case 7:
		{
			if (VecInt.IsEmpty())
			{
			
				cout << "VecInt пуст. Удаление невозможно" << endl;
			}
				
			else
			{ 
				VecInt.PopFront();
			}
				
			if (VecStr.IsEmpty())
			{
				cout << "VecStr пуст. Удаление невозможно" << endl;
			}
				
			else
			{
				VecStr.PopFront();
			}
				
			if (VecMon.IsEmpty())
			{
				cout << "VecMon пуст. Удаление невозможно" << endl;
			}	
			else
			{
				VecMon.PopFront();
			}
				
		}
		break;
		case 8:
		{
			if (VecInt.IsEmpty())
			{

				cout << "VecInt пуст. Удаление невозможно" << endl;
			}

			else
			{
				VecInt.PopBack();
			}

			if (VecStr.IsEmpty())
			{
				cout << "VecStr пуст. Удаление невозможно" << endl;
			}

			else
			{
				VecStr.PopBack();
			}

			if (VecMon.IsEmpty())
			{
				cout << "VecMon пуст. Удаление невозможно" << endl;
			}
			else
			{
				VecMon.PopBack();
			}
		}
		break;
		case 9:
		{
			cout << "Длина VecInt: " << VecInt.Length() << endl;
			cout << "Длина VecStr: " << VecStr.Length() << endl;
			cout << "Длина VecMon: " << VecMon.Length() << endl;
		}
		break;
		}
	} while (n != 0);
	return 0;
}




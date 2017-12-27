


/*11. ����������� ������ ������ ������������ ������ (Vector<X>), �������� ��������
������������� ����. ����� ������ ���������:
������������� �������; +
���������� �������� � ������ �������;+
���������� �������� � ����� �������;+
����� ���� ��������� �������.+
a)
�������� ���� ��������� �������;+
����������� ���������� ��������� �������;+
�������� ������� �� �������;+
�������� ������� ��������;+
�������� ���������� ��������; +
������� �. �. ,9 ������ */

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

//����������� ����� �������
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

//�����������
template <typename TYPE>
Vector<TYPE>::Vector(int n)
{
	Create(n);
}

//�����������
template <typename TYPE>
Vector<TYPE>::Vector()
{
	Create(0);
}

//����������
template <typename TYPE>
Vector<TYPE>::~Vector()
{
	delete[]data;
}

//������� �������
template <typename TYPE>
Vector<TYPE>& Vector<TYPE>::Clear()
{
	delete[]data;
	Create(0);
	return *this;
}

//������������� �������
template <typename TYPE>
Vector<TYPE>& Vector<TYPE>::Init(int n)
{
	delete[]data;
	Create(n);
	return *this;
}

//���������� � ������
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

//���������� � �����
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

//�������� �� ������
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

//�������� �� �����
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

//�������� �� �������
template <typename TYPE>
bool Vector<TYPE>::IsEmpty()
{
	if (size == 0)
		return 1;
	return 0;
}

//����� ���� ��������� �� �����
template <typename TYPE>
void Vector<TYPE>::Print()
{

	for (int i = 0; i < Length(); ++i)
	{
		cout << data[i] << " ";
	}

}

//��������������� ���������� ������
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
	cout << "                         ����                         \n";
	cout << "------------------------------------------------------\n";
	cout << "1 - ������������� �������.\n";
	cout << "2 - ���������� �������� � ������ �������.\n";
	cout << "3 - ���������� �������� � ����� �������; .\n";
	cout << "4 - ����� ���� ��������� �������.\n";
	cout << "5 - �������� ���� ��������� �������.\n";
	cout << "6 - �������� ������� �� �������.\n";
	cout << "7 - �������� ������� ��������.\n";
	cout << "8 - �������� ���������� ��������.\n";
	cout << "9 - ����������� ����� �������.\n";
	cout << "0 - �����.\n";
	cout << "------------------------------------------------------\n";
	int p;
	do {
		cout << ">> ";
		cin >> p;
		if ((p < 0) || (p > 9))
			cout << "�������� �������� �������. ��������� ����.\n";
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
			cout << "VecInt ���������������" << endl;
			VecStr.Init(0);
			cout << "VecStr ���������������" << endl;
			VecMon.Init(0);
			cout << "VecMon ���������������" << endl;
		}
		break;
		case 2:
		{
			a = 5;
			str = "����";
			b = (34.11);
			VecInt.PushFront(a);
			VecStr.PushFront(str);
			VecMon.PushFront(b);
		}
		break;
		case 3:
		{
			a = 1;
			str = "��������";
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
			cout << "VecInt ������" << endl;
			VecStr.Clear();
			cout << "VecStr ������" << endl;
			VecMon.Clear();
			cout << "VecMon ������" << endl;
		}
		break;
		case 6:
		{
			if (VecInt.IsEmpty())
				cout << "VecInt ����" << endl;
			else
				cout << "VecInt ������" << endl;

			if (VecStr.IsEmpty())
				cout << "VecStr ����" << endl;
			else
				cout << "VecStr ������" << endl;

			if (VecMon.IsEmpty())
				cout << "VecMon ����" << endl;
			else
				cout << "VecMon ������" << endl;

		}
		break;
		case 7:
		{
			if (VecInt.IsEmpty())
			{
			
				cout << "VecInt ����. �������� ����������" << endl;
			}
				
			else
			{ 
				VecInt.PopFront();
			}
				
			if (VecStr.IsEmpty())
			{
				cout << "VecStr ����. �������� ����������" << endl;
			}
				
			else
			{
				VecStr.PopFront();
			}
				
			if (VecMon.IsEmpty())
			{
				cout << "VecMon ����. �������� ����������" << endl;
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

				cout << "VecInt ����. �������� ����������" << endl;
			}

			else
			{
				VecInt.PopBack();
			}

			if (VecStr.IsEmpty())
			{
				cout << "VecStr ����. �������� ����������" << endl;
			}

			else
			{
				VecStr.PopBack();
			}

			if (VecMon.IsEmpty())
			{
				cout << "VecMon ����. �������� ����������" << endl;
			}
			else
			{
				VecMon.PopBack();
			}
		}
		break;
		case 9:
		{
			cout << "����� VecInt: " << VecInt.Length() << endl;
			cout << "����� VecStr: " << VecStr.Length() << endl;
			cout << "����� VecMon: " << VecMon.Length() << endl;
		}
		break;
		}
	} while (n != 0);
	return 0;
}




#pragma once
#include <iostream>
using namespace std;
struct fine
{
	char comment[100];
	int sumfine;
	char date[20];
};
struct car
{
	char name[20];
	float engine;
	short power;
	char color[50];
	char transm[50];
	char number[20];
	fine fines;
};
template<typename T>
void addElement(T*& arr, int& old_size) {
	if (arr == nullptr && old_size != 0)//�������� �� �� ��� ������ ����
		// � ������ �� 0
		return;
	T* nArr = new T[old_size + 1];//��������� ������ �������� �������
	if (!nArr)//���� ������ �� �������� , �� ��������� �������
		return;
	for (int i = 0; i < old_size; ++i)//����������� ��������� �� 
		//������ ������ � �����
		nArr[i] = arr[i];
	old_size++;
	delete[] arr;//���� ������ ������ ����,�� �� �������
	arr = nArr;
}
template<typename T>
void deleteElement(T*& array,int& oldsize ,int poz)
{
	if (array == nullptr && oldsize != 0)
		return;
	T* newarray = new T[oldsize - 1]{};
	if (!newarray)//���� ������ �� �������� , �� ��������� �������
		return;
	for (int i = 0; i < poz; i++)
	{
		newarray[i] = array[i];
	}
	for (int i = poz + 1; i < oldsize; i++)
	{
		newarray[i - 1] = array[i];
	}
	delete array;
	array = newarray;
	--oldsize;
}
void create(car*& Car, int size)
{
	cout << "������� ��� ������ ";
	cin >> Car[size].name;
	cout << "������� ����� ��������� ";
	cin >> Car[size].engine;
	cout << "������� �������� ";
	cin >> Car[size].power;
	cout << "������� ���� ";
	cin >> Car[size].color;
	cout << "������� ��� ������� ";
	cin >> Car[size].transm;
	cout << "������� �������� ";
	cin >> Car[size].number;
	cout << "������� �������� ������ ";
	cin >> Car[size].fines.comment;
	cout << "������� ����� ������ ";
	cin >> Car[size].fines.sumfine;
	cout << "������� ���� ";
	cin >> Car[size].fines.date;
}
/*-------------������ �� �����-------------------*/
void printrange(car*& test, int size)
{
	for (int i = 0; i < size; i++)
		cout << i + 1 << ")" << "���: " << test[i].name << " " << "��������: " << test[i].number << " " << "����: " << test[i].color << " " << "����� �������: " << test[i].fines.sumfine << endl;
}
void printall(car*& test, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "��� " << test[i].name << "\n����� " << test[i].number << "\n����� " << test[i].engine << "\n�������� " << test[i].power << "\n���� " << test[i].color << "\n��� ������� "
			<< test[i].transm << "\n����� ������� " << test[i].fines.sumfine << endl;
	}
}
void printspecific(car*& test, int element)
{
	cout << "��� " << test[element].name << "\n����� " << test[element].number << "\n����� " << test[element].engine << "\n�������� " << test[element].power << "\n���� " << test[element].color << "\n��� ������� "
		<< test[element].transm << "\n����� ������� " << test[element].fines.sumfine << endl;
}
/*-------------�����-------------------*/
void findnumber(car*& test, char find[20], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(test[i].number, find))
		{
			cout << "���� ����� ����������� ������ " << test[i].name << "\n����� ������� ������ " << test[i].fines.sumfine << endl;
		}
	}
}
void findcolor(car*& test, char find[20], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(test[i].color, find))
		{
			cout << "����� ���� � ������ " << test[i].name << "\n����� ������� ������ " << test[i].fines.sumfine << endl;
		}
	}
}
void findfine(car*& test, int fine, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (test[i].fines.sumfine == fine)
		{
			printspecific(test, i);
		}
	}
}
void findcar(car*& test, char find[20], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(test[i].name, find))
		{
			printspecific(test, i);
		}
	}
}
/*-------------����������-------------------*/
void sortname(car* test)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - 1; j++)
		{
			if (strcmp(test[j].name, test[j + 1].name) < 0)
				swap(test[j].name, test[j + 1].name);
		}
	}
}
void sortengine(car* test)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - 1; j++)
		{
			if (test[j].engine < test[j + 1].engine)
				swap(test[j].engine, test[j + 1].engine);
		}
	}
}
void sortpower(car* test)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - 1; j++)
		{
			if (test[j].power < test[j + 1].power)
				swap(test[j].power, test[j + 1].power);
		}
	}
}
void sortcolor(car* test)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - 1; j++)
		{
			if (test[j].color < test[j + 1].color)
				swap(test[j].color, test[j + 1].color);
		}
	}
}
/*-------------������-------------------*/
void addfine(car*& test,int size ,char find[20])
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(test[i].number, find))
		{
			int fine;
			cout << "������� ����� ������ ������� �� ������ �������� ";
			cin >> fine;
			test[i].fines.sumfine += fine;
		}
	}
}
void deletefine(car*& test,int size ,char find[20])
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(test[i].number, find))
		{
			int fine;
			cout << "������� ����� ������ ������� �� ������ ������� ";
			cin >> fine;
			test[i].fines.sumfine += fine;
		}
	}
}


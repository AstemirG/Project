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
	if (arr == nullptr && old_size != 0)//проверка на то что массив есть
		// и размер не 0
		return;
	T* nArr = new T[old_size + 1];//выделение памяти большего размера
	if (!nArr)//если память не выделена , то завершаем функцию
		return;
	for (int i = 0; i < old_size; ++i)//копирование элементов из 
		//старой памяти в новую
		nArr[i] = arr[i];
	old_size++;
	delete[] arr;//если старая память есть,то ее удаляем
	arr = nArr;
}
template<typename T>
void deleteElement(T*& array,int& oldsize ,int poz)
{
	if (array == nullptr && oldsize != 0)
		return;
	T* newarray = new T[oldsize - 1]{};
	if (!newarray)//если память не выделена , то завершаем функцию
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
	cout << "Введите имя машины ";
	cin >> Car[size].name;
	cout << "Введите объем двигателя ";
	cin >> Car[size].engine;
	cout << "введите мощность ";
	cin >> Car[size].power;
	cout << "Введите цвет ";
	cin >> Car[size].color;
	cout << "Введите тип коробки ";
	cin >> Car[size].transm;
	cout << "Введите госномер ";
	cin >> Car[size].number;
	cout << "Введите описание штрафа ";
	cin >> Car[size].fines.comment;
	cout << "Введите сумму штрафа ";
	cin >> Car[size].fines.sumfine;
	cout << "Введите дату ";
	cin >> Car[size].fines.date;
}
/*-------------ВЫВОДЫ НА ЭКРАН-------------------*/
void printrange(car*& test, int size)
{
	for (int i = 0; i < size; i++)
		cout << i + 1 << ")" << "Имя: " << test[i].name << " " << "Госномер: " << test[i].number << " " << "Цвет: " << test[i].color << " " << "Сумма штрафов: " << test[i].fines.sumfine << endl;
}
void printall(car*& test, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Имя " << test[i].name << "\nНомер " << test[i].number << "\nОбъем " << test[i].engine << "\nМощность " << test[i].power << "\nЦвет " << test[i].color << "\nТип коробки "
			<< test[i].transm << "\nСумма штрафов " << test[i].fines.sumfine << endl;
	}
}
void printspecific(car*& test, int element)
{
	cout << "Имя " << test[element].name << "\nНомер " << test[element].number << "\nОбъем " << test[element].engine << "\nМощность " << test[element].power << "\nЦвет " << test[element].color << "\nТип коробки "
		<< test[element].transm << "\nСумма штрафов " << test[element].fines.sumfine << endl;
}
/*-------------ПОИСК-------------------*/
void findnumber(car*& test, char find[20], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(test[i].number, find))
		{
			cout << "Этот номер принадлежит машине " << test[i].name << "\nСумма штрафов машины " << test[i].fines.sumfine << endl;
		}
	}
}
void findcolor(car*& test, char find[20], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(test[i].color, find))
		{
			cout << "Такой цвет у машины " << test[i].name << "\nСумма штрафов машины " << test[i].fines.sumfine << endl;
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
/*-------------СОРТИРОВКИ-------------------*/
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
/*-------------ШТРАФЫ-------------------*/
void addfine(car*& test,int size ,char find[20])
{
	for (int i = 0; i < size; i++)
	{
		if (strstr(test[i].number, find))
		{
			int fine;
			cout << "Введите сумму штрафа которую вы хотите добавить ";
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
			cout << "Введите сумму штрафа которую вы хотите удалить ";
			cin >> fine;
			test[i].fines.sumfine += fine;
		}
	}
}


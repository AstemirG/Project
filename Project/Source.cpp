#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;
random_device ran;
int main()
{
	setlocale(LC_ALL, "rus");
	short count;
	short countsort=0, countfind=0;//countы для свичей 
	char find[20], test[256];//Для поисков 
	int i = 0, Find, size = 0, numdelete;
	char FileName [] {"Project.txt"};
	ifstream inf;
	inf.open(FileName);
	while (inf.getline(test, 256))
		size++;
	car* Car = new car[size];
	inf.clear();
	inf.seekg(0,ios::beg);
	//inf.close();
	//inf.open(FileName);
	int x = 0;
	while (!inf.eof())
	{
		inf >> Car[x].name >> Car[x].engine >> Car[x].power >> Car[x].color >> Car[x].transm >> Car[x].number >> Car[x].fines.comment >> Car[x].fines.sumfine >> Car[x].fines.date;
		x++;
	}
	inf.close();
	do
	{
		cout << "1)Добавить машину \n"
			"2)Удалить машину \n"
			"3)Отсортировать \n"
			"4)Поиск \n"
			"5)Показать все машины \n"
			"6)Добавить штраф \n"
			"7)Удалить штраф \n"
			"8)Вывести информацию о конкретной машине \n"
			"9)Вывести все машины с заданой суммой штрафов \n"
			"0)Выход \n";
		cin >> count;
		switch (count)
		{
		case 1:
			addElement(Car, size);
			create(Car, size-1);
			break;
		case 2:
			printrange(Car, size);
			cout << "Введите номер под которым стоит машина, которую вы хотите удалить ";
			cin >> numdelete;
			numdelete--;
			deleteElement(Car, size, numdelete);
			break;
		case 3:
			do
			{
				cout << "1)Отсортировать по имени \n"
					"2)Отсортировать по цене \n"
					"3)Отсортировать по объему двигателя \n"
					"4)Отсортировать по мощности \n"
					"5)Отсортировать по цвету \n"
					"0)Назад \n";
				cin >> countsort;
				switch (countsort)
				{
				case 1:
					sortname(Car);
					printall(Car, size);
					break;
				case 2:
					sortengine(Car);
					printall(Car, size);
					break;
				case 3:
					sortpower(Car);
					printall(Car, size);
					break;
				case 4:
					sortcolor(Car);
					printall(Car, size);
					break;
				}
			}
			while (countsort);
			break;
		case 4:
			cout << "1)Поиск по госномеру \n"
				"2)Поиск по цвету \n"
				"0)Назад \n";
			cin >> countfind;
			switch (countfind)
			{
			case 1:
				cout << "Введите номер который вы хотите найти ";
				cin >> find;
				findnumber(Car, find, size);
				break;
			case 2:
				cout << "Введите цвет машины который вы хотите найти ";
				cin >> find;
				findcolor(Car, find, size);
				break;
			}
			break;
		case 5:
			printrange(Car, size);
			break;
		case 6:
			cout << "Введите госномер машины которому нужно добавить штраф ";
			cin >> find;
			addfine(Car, size, find);
			break;
		case 7:
			cout << "Введите госномер машины которому нужно удалить штраф ";
			cin >> find;
			deletefine(Car, size, find);
			break;
		case 8:
			cout << "Введите имя машины которую надо найти ";
			cin >> find;
			findcar(Car, find, size);
			break;
		case 9:
			cout << "Введите сумму штрафов ";
			cin >> Find;
			findfine(Car, Find, size);
			break;
		}
	} while (count);
	ofstream ouf;
	ouf.open(FileName);
	inf.clear();
	inf.seekg(0, ios::beg);
	for (int x = 0; x < size; x++)
	{
		ouf << Car[x].name << " " << Car[x].engine << " " << Car[x].power << " " << Car[x].color << " " << Car[x].transm << " " << Car[x].number << " " << Car[x].fines.comment << " "
			<< Car[x].fines.sumfine << " " << Car[x].fines.date;
		if (x <= size - 2)
			ouf << "\n";
	}
	ouf.close();
}
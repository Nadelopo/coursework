#include <iostream>
#include <list>
#include "Rectangle.h"
#include "Quadrangle.h"
#include "Menu.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	Menu menu;
	menu.Start();

	string value;
	do {
		cout << "0 - создать объект\n";
		cout << "1 - удалить объект\n";
		cout << "2 - получить данные о фигуре объект\n";
		cout << "3 - проверка существования фигуры\n";
		cout << "4 - определить факт пересечения объектов\n";
		cout << "5 - переместить объект на плоскости\n";
		cout << "9 - очистить консоль\n";
		cin >> value;
		cout << endl;

		if (value == "0")
			menu.Create();

		if (value == "1")
			menu.Delete();

		if (value == "2")
			menu.Show();

		if (value == "3")
			menu.Verification();

		if (value == "4")
			menu.Intersect();

		if (value == "5")
			menu.Move();

		if (value == "9")
			system("CLS");

	} while (true);
}
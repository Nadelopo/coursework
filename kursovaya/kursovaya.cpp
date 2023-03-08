

#include <iostream>
#include "Rectangle.h"
#include <list>
using namespace std;

list <Rectangle> listRectangle;


bool onlyDigits(const string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}


void createRectangle() {
	int id = size(listRectangle);
	string x, y, width, height;
	do {
		cout << "укажите координату x\n"; cin >> x;
		cout << "укажите координату y\n"; cin >> y;
		cout << "укажите ширину\n"; cin >> width;
		cout << "укажите высоту\n"; cin >> height;
		system("CLS");
	} while (!onlyDigits(x) || !onlyDigits(y) || !onlyDigits(width) || !onlyDigits(height));
	Rectangle rect(id, stoi(x), stoi(y), stoi(width), stoi(height));
	listRectangle.push_back(rect);
}


void Create() {
	//system("cls");
	string value;
	do {
		cout << "0 - создать прямоугольник\n";
		cout << "1 - создать четырехугольник\n";
		cin >> value;
	} while (value != "0" && value != "1");
	cout << endl;
	if (value == "0") {
		createRectangle();
	}
}

void getRectangleById(int id) {
	if (id < size(listRectangle)) {
		for (Rectangle v : listRectangle) {
			if (id == v.getId()) {
				v.getData();
			}
		}
	}
	else {
		cout << "элемента с таким id не существует\n";
	}
}

void Show() {
	string id, choiceValue;
	do {
		cout << "0 - данные о прямоугольнике\n";
		cout << "1 - данные о четырехугольнике\n";
		cin >> choiceValue;
	} while (choiceValue != "0" && choiceValue != "1");
	cout << endl;

	do {
		cout << "укажите id элемента\n"; cin >> id;
	} while (!onlyDigits(id));
	cout << endl;

	if (choiceValue == "0") {
		getRectangleById(stoi(id));
	}
	cout << endl;
}

void coutR() {
	for (Rectangle l : listRectangle) {
		cout << l.getId() << " ";
	}
}

bool rectangleExists(int id) {
	bool value;
	for (auto r : listRectangle) {
		if (r.getId() == id) {
			value = true;
			break;
		}
		else {
			value = false;
		}
	}
	return value;
}

void Verification() {
	string id, choiceValue;
	do {
		cout << "0 - проверить существование прямоугольника\n";
		cout << "1 - проверить существование четырехугольнике\n";
		cin >> choiceValue;
	} while (choiceValue != "0" && choiceValue != "1");
	cout << endl;

	do {
		cout << "укажите id элемента\n"; cin >> id;
	} while (!onlyDigits(id));
	cout << endl;

	if (choiceValue == "0") {
		if (rectangleExists(stoi(id))) {
			cout << "элемент существует\n";
		}
		else {
			cout << "такого элемента не существует\n";
		}
	}
	cout << endl;
}


void deleteRectangle(int id) {
	for (Rectangle& rect : listRectangle) {
		listRectangle.remove_if([id](Rectangle rect) {
			if (rect.getId() == id) {
				return true;
			}
			else {
				return false;
			}
			});
	}
}

void Delete() {
	string id, choiceValue;
	do {
		cout << "0 - удалить прямоугольник\n";
		cout << "1 - удалить четырехугольник\n";
		cin >> choiceValue;
	} while (choiceValue != "0" && choiceValue != "1");
	cout << endl;

	do {
		cout << "укажите id элемента\n"; cin >> id;
	} while (!onlyDigits(id));
	cout << endl;

	if (choiceValue == "0") {
		if (rectangleExists(stoi(id))) {
			deleteRectangle(stoi(id));
		}
		else {
			cout << "такого элемента не существует\n";
		}
	}
	cout << endl;
}

bool intersectRectangles(int id1, int id2) {
	Rectangle rect1, rect2;
	for (Rectangle r : listRectangle) {
		if (r.getId() == id1) {
			rect1 = r;
		}
		if (r.getId() == id2) {
			rect2 = r;
		}
	}
	int r1 = rect1.getX() + rect1.getWidth();
	int b1 = rect1.getY() + rect1.getHeight();
	int r2 = rect2.getX() + rect2.getWidth();
	int b2 = rect2.getY() + rect2.getHeight();
	return (rect1.getX() < r2) && (rect2.getX() < r1) && (rect1.getY() < b2) && (rect2.getY() < b1);
}

void Intersect() {
	string value, obj1, obj2;
	do {
		cout << "0 - прямоугольники\n";
		cout << "1 - четырехугольники\n";
		cin >> value;
	} while (value != "0" && value != "1");
	cout << endl;

	if (value == "0") {
		do {
			cout << "укажите id объекта 1\n"; cin >> obj1;
			cout << "укажите id объекта 2\n"; cin >> obj2;
		} while (!onlyDigits(obj1) || !onlyDigits(obj2));
		if (obj1 != obj2) {

			if (rectangleExists(stoi(obj1)) && rectangleExists(stoi(obj2))) {
				cout << intersectRectangles(stoi(obj1), stoi(obj2));
			}
			else {
				cout << "вы указали несуществующие объекты\n";
			}
		}
		else {
			cout << "вы указали один и тот же объект\n";
		}
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int id;
	string value;

	// для пересечения прямоугольников
	listRectangle.push_back(Rectangle (0,2, 1,5,3));
	listRectangle.push_back(Rectangle (1,1,0,2,2));
	listRectangle.push_back(Rectangle (2,6,2,3,1));

	do {
		do {
			cout << "0 - создать объект\n";
			cout << "1 - удалить объект\n";
			cout << "2 - получить данные о фигуре объект\n";
			cout << "3 - проверка существования фигуры\n";
			cout << "4 - определить факт пересечения объектов\n";
			cin >> value;
		} while (value != "0" && value != "1" && value != "2" && value != "3" && value != "4");
		cout << endl;

		if (value == "0") {
			Create();
		}
		if (value == "1") {
			Delete();
		}
		if (value == "2") {
			Show();
		}
		if (value == "3") {
			Verification();
		}
		if (value == "4") {
			Intersect();
		}

	} while (true);
}


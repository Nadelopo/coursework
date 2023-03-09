#include <iostream>
#include "Rectangle.h"
#include "Quadrangle.h"
#include <list>
using namespace std;

list <Rectangle> listRectangle;
list <Quadrangle> listQuadrangle;


bool onlyDigits(const string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

template<typename T>
int getNewId(list<T> list) {
	int maxId = 0;
	for (T elem : list) {
		if (elem.getId() > maxId) {
			maxId = elem.getId();
		}
	}
	return maxId + 1;
}

void createRectangle() {
	int id = getNewId(listRectangle);
	string x, y, width, height;
	do {
		cout << "укажите координату x\n"; cin >> x;
		cout << "укажите координату y\n"; cin >> y;
		cout << "укажите ширину\n"; cin >> width;
		cout << "укажите высоту\n"; cin >> height;
	} while (!onlyDigits(x) || !onlyDigits(y) || !onlyDigits(width) || !onlyDigits(height));
	Rectangle rect(id, stoi(x), stoi(y), stoi(width), stoi(height));
	listRectangle.push_back(rect);
}

void createQuadrangle() {
	int id = getNewId(listQuadrangle);
	string x1, x2, x3, x4, y1, y2, y3, y4;
	do {
		cout << "укажите координату x1\n"; cin >> x1;
	} while (!onlyDigits(x1));
	do {
		cout << "укажите координату y1\n"; cin >> y1;
	} while (!onlyDigits(y1));

	do {
		cout << "укажите координату x2\n"; cin >> x2;
	} while (!onlyDigits(x2));
	do {
		cout << "укажите координату y2\n"; cin >> y2;
	} while (!onlyDigits(y2));

	do {
		cout << "укажите координату x3\n"; cin >> x3;
	} while (!onlyDigits(x3));
	do {
		cout << "укажите координату y3\n"; cin >> y3;
	} while (!onlyDigits(y3));

	do {
		cout << "укажите координату x4\n"; cin >> x4;
	} while (!onlyDigits(x4));
	do {
		cout << "укажите координату y4\n"; cin >> y4;
	} while (!onlyDigits(y4));

	Quadrangle Q(id, stoi(x1), stoi(y1), stoi(x2), stoi(y2), stoi(x3), stoi(y3), stoi(x4), stoi(y4));
	listQuadrangle.push_back(Q);
}

void Create() {
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
	if (value == "1") {
		createQuadrangle();
	}
	cout << endl;
}

template<typename T>
bool elementExists(int id, list<T> list) {
	for (auto r : list) {
		if (r.getId() == id) {
			return true;
		}
	}
	return false;
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
	bool check = choiceValue == "0" ? elementExists(stoi(id), listRectangle) : elementExists(stoi(id), listQuadrangle);

	if (check) {
		cout << "элемент существует\n";
	}
	else {
		cout << "такого элемента не существует\n";
	}
	cout << endl;
}


template<typename T>
void getElementById(int id, list<T> list) {
	if (elementExists(id, list)) {
		for (T v : list) {
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
		getElementById(stoi(id), listRectangle);
	}
	if (choiceValue == "1") {
		getElementById(stoi(id), listQuadrangle);
	}

	cout << endl;
}

template<typename T>
void deleteElement(int id, list<T>& list) {
	list.remove_if([id](T& elem) {
		return elem.getId() == id;
		});
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

	bool check = choiceValue == "0" ? elementExists(stoi(id), listRectangle) : elementExists(stoi(id), listQuadrangle);
	if (check) {
		if (choiceValue == "0") {
			deleteElement(stoi(id), listRectangle);
		}
		if (choiceValue == "1") {
			deleteElement(stoi(id), listQuadrangle);
		}
	}
	else {
		cout << "такого элемента не существует\n";
	}
	//for (auto q : listRectangle) {
	//	cout << q.getId();
	//}
	//cout << endl;
	//for (auto q : listQuadrangle) {
	//	cout << q.getId();
	//}
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

// для четырехугольников
int direction(int x1, int y1, int x2, int y2, int x3, int y3) {
	int dir = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	return (dir > 0) ? 1 : ((dir < 0) ? -1 : 0);
}

bool doIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int d1 = direction(x1, y1, x2, y2, x3, y3);
	int d2 = direction(x1, y1, x2, y2, x4, y4);
	int d3 = direction(x3, y3, x4, y4, x1, y1);
	int d4 = direction(x3, y3, x4, y4, x2, y2);

	if (d1 != d2 && d3 != d4) {
		return true;
	}

	//if (d1 == 0 && direction(x3, y3, x4, y4, x1, y1) == 0 && ((x3 <= x1 && x1 <= x4) || (x4 <= x1 && x1 <= x3))) {
	//	return true;
	//}
	//if (d2 == 0 && direction(x3, y3, x4, y4, x2, y2) == 0 && ((x3 <= x2 && x2 <= x4) || (x4 <= x2 && x2 <= x3))) {
	//	return true;
	//}
	//if (d3 == 0 && direction(x1, y1, x2, y2, x3, y3) == 0 && ((x1 <= x3 && x3 <= x2) || (x2 <= x3 && x3 <= x1))) {
	//	return true;
	//}
	//if (d4 == 0 && direction(x1, y1, x2, y2, x4, y4) == 0 && ((x1 <= x4 && x4 <= x2) || (x2 <= x4 && x4 <= x1))) {
	//	return true;
	//}
	return false;
}

bool intersectQuadrangles(int id1, int id2) {
	Quadrangle qadr1, qadr2;
	for (Quadrangle r : listQuadrangle) {
		if (r.getId() == id1) {
			qadr1 = r;
		}
		if (r.getId() == id2) {
			qadr2 = r;
		}
	}
	QuadrangleCoordinates q1 = qadr1.getQuadrangle();
	QuadrangleCoordinates q2 = qadr2.getQuadrangle();

	if (doIntersect(q1.x1, q1.y1, q1.x2, q1.y2, q2.x1, q2.y1, q2.x2, q2.y2)) {
		return true;
	}
	if (doIntersect(q1.x1, q1.y1, q1.x2, q1.y2, q2.x2, q2.y2, q2.x3, q2.y3)) {
		return true;
	}
	if (doIntersect(q1.x1, q1.y1, q1.x2, q1.y2, q2.x3, q2.y3, q2.x4, q2.y4)) {
		return true;
	}
	if (doIntersect(q1.x1, q1.y1, q1.x2, q1.y2, q2.x1, q2.y1, q2.x4, q2.y4)) {
		return true;
	}

	if (doIntersect(q1.x2, q1.y2, q1.x3, q1.y3, q2.x1, q2.y1, q2.x2, q2.y2)) {
		return true;
	}
	if (doIntersect(q1.x2, q1.y2, q1.x3, q1.y3, q2.x2, q2.y2, q2.x3, q2.y3)) {
		return true;
	}
	if (doIntersect(q1.x2, q1.y2, q1.x3, q1.y3, q2.x3, q2.y3, q2.x4, q2.y4)) {
		return true;
	}
	if (doIntersect(q1.x2, q1.y2, q1.x3, q1.y3, q2.x1, q2.y1, q2.x4, q2.y4)) {
		return true;
	}

	if (doIntersect(q1.x3, q1.y3, q1.x4, q1.y4, q2.x1, q2.y1, q2.x2, q2.y2)) {
		return true;
	}
	if (doIntersect(q1.x3, q1.y3, q1.x4, q1.y4, q2.x2, q2.y2, q2.x3, q2.y3)) {
		return true;
	}
	if (doIntersect(q1.x3, q1.y3, q1.x4, q1.y4, q2.x3, q2.y3, q2.x4, q2.y4)) {
		return true;
	}
	if (doIntersect(q1.x3, q1.y3, q1.x4, q1.y4, q2.x1, q2.y1, q2.x4, q2.y4)) {
		return true;
	}

	if (doIntersect(q1.x1, q1.y1, q1.x4, q1.y4, q2.x1, q2.y1, q2.x2, q2.y2)) {
		return true;
	}
	if (doIntersect(q1.x1, q1.y1, q1.x4, q1.y4, q2.x2, q2.y2, q2.x3, q2.y3)) {
		return true;
	}
	if (doIntersect(q1.x1, q1.y1, q1.x4, q1.y4, q2.x3, q2.y3, q2.x4, q2.y4)) {
		return true;
	}
	if (doIntersect(q1.x1, q1.y1, q1.x4, q1.y4, q2.x1, q2.y1, q2.x4, q2.y4)) {
		return true;
	}
	return false;
}

void Intersect() {
	string value, obj1, obj2;
	do {
		cout << "0 - прямоугольники\n";
		cout << "1 - четырехугольники\n";
		cin >> value;
	} while (value != "0" && value != "1");
	cout << endl;

	do {
		cout << "укажите id объекта 1\n"; cin >> obj1;
		cout << "укажите id объекта 2\n"; cin >> obj2;
	} while (!onlyDigits(obj1) || !onlyDigits(obj2));

	bool intersectValue = false;
	if (obj1 != obj2) {
		if (value == "0") {
			if (elementExists(stoi(obj1), listRectangle) && elementExists(stoi(obj2), listRectangle)) {
				intersectValue = intersectRectangles(stoi(obj1), stoi(obj2));
			}
			else {
				cout << "вы указали несуществующие объекты\n";
			}
		}
		if (value == "1") {
			if (elementExists(stoi(obj1), listQuadrangle) && elementExists(stoi(obj2), listQuadrangle)) {
				intersectValue = intersectQuadrangles(stoi(obj1), stoi(obj2));
			}
			else {
				cout << "вы указали несуществующие объекты\n";
			}
		}
		if (intersectValue) {
			cout << "объекты пересекаются\n";
		}
		else {
			cout << "объекты не пересекаются\n";
		}
	}
	else {
		cout << "вы указали один и тот же объект\n";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	string value;

	listRectangle.push_back(Rectangle(0, 2, 1, 5, 3));
	listRectangle.push_back(Rectangle(1, 1, 0, 2, 2));
	listRectangle.push_back(Rectangle(2, 6, 2, 3, 1));

	listQuadrangle.push_back(Quadrangle(0, 3, 2, 4, 4, 8, 5, 7, 2));
	listQuadrangle.push_back(Quadrangle(1, 7, 4, 7, 7, 10, 9, 12, 4));
	listQuadrangle.push_back(Quadrangle(2, 5, 6, 5, 11, 7, 11, 7, 7));

	do {
		do {
			cout << "0 - создать объект\n";
			cout << "1 - удалить объект\n";
			cout << "2 - получить данные о фигуре объект\n";
			cout << "3 - проверка существования фигуры\n";
			cout << "4 - определить факт пересечения объектов\n";
			cout << "9 - очистить консоль\n";
			cin >> value;
		} while (value != "0" && value != "1" && value != "2" && value != "3" && value != "4" && value != "9");
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
		if (value == "9") {
			system("CLS");
		}

	} while (true);
}
#include "Rectangle.h"

Rectangle::Rectangle() {}
Rectangle::Rectangle(int _id, int _x1, int _y1, int _width, int _height) {
	width = _width;
	height = _height;
	id = _id;
	x1 = _x1;
	y1 = _y1;
	x2 = x1;
	y2 = _y1 + _height;
	x3 = _x1 + _width;
	y3 = y2;
	x4 = x3;
	y4 = _y1;
}
void Rectangle::getData() {
	cout << "координаты: (" + to_string(x1) + "," + to_string(y1) + ") (" + to_string(x2) + "," + to_string(y2) + ") (" + to_string(x3) + "," + to_string(y3) + ") (" + to_string(x4) + "," + to_string(y4) + ")\n";
	cout << "ширина: " + to_string(width) << endl;
	cout << "длина: " + to_string(height) << endl;
}
void Rectangle::MoveO(int _x, int _y) {
	x1 += _x;
	x2 += _x;
	x3 += _x;
	x4 += _x;
	y1 += _y;
	y2 += _y;
	y3 += _y;
	y4 += _y;
}
int Rectangle::getId() {
	return id;
}
int Rectangle::getX() {
	return x1;
}
int Rectangle::getY() {
	return y1;
}
int Rectangle::getWidth() {
	return width;
}
int Rectangle::getHeight() {
	return height;
}


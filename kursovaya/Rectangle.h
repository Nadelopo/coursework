#pragma once
#include "Figure.h"
#include <iostream>
#include <string>
using namespace std;


class Rectangle : public Figure
{
private:
	int x1, y1, x2, y2, x3, y3, x4, y4, id, width, height;
public:
	Rectangle(){}
	Rectangle(int _id, int _x1, int _y1, int _width, int _height)  {
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
	void getData()  {
		cout << "координаты: (" + to_string(x1) + "," + to_string(y1) + ") (" + to_string(x2) + "," + to_string(y2) + ") (" + to_string(x3) + "," + to_string(y3) + ") (" + to_string(x4) + "," + to_string(y4) + ")\n";
		cout << "ширина: " + to_string(width) << endl;
		cout << "длина: " + to_string(height) << endl;
	}
	void MoveO(int _x, int _y) override {
		x1 += _x;
		x2 += _x;
		x3 += _x;
		x4 += _x;
		y1 += _y;
		y2 += _y;
		y3 += _y;
		y4 += _y;
	}
	int getId() {
		return id;
	}
	int getX() {
		return x1;
	}
	int getY() {
		return y1;
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}

};


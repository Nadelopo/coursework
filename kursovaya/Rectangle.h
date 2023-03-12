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
	Rectangle();
	Rectangle(int _id, int _x1, int _y1, int _width, int _height);
	void getData();
	void MoveO(int _x, int _y) override;
	int getId();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
};


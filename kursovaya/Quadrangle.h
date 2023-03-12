#pragma once
#include "Figure.h"
#include <iostream>
#include <string>
using namespace std;

struct QuadrangleCoordinates {
	int id, x1,x2,x3,x4,y1,y2,y3,y4;
};

class Quadrangle : public Figure
{
private:
	int x1, y1, x2, y2, x3, y3, x4, y4, id;
public:
	Quadrangle();
	Quadrangle(int _id, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);
	void getData();
	void MoveO(int _x, int _y) override;
	int getId();
	QuadrangleCoordinates getQuadrangle();
};


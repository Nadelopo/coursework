#include "Quadrangle.h"

Quadrangle::Quadrangle() {}

Quadrangle::Quadrangle(int _id, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) {
	id = _id;
	x1 = _x1;
	x2 = _x2;
	x3 = _x3;
	x4 = _x4;
	y1 = _y1;
	y2 = _y2;
	y3 = _y3;
	y4 = _y4;
}

void Quadrangle::getData() {
	cout << "координаты: (" + to_string(x1) + "," + to_string(y1) + ") (" + to_string(x2) + "," + to_string(y2) + ") (" + to_string(x3) + "," + to_string(y3) + ") (" + to_string(x4) + "," + to_string(y4) + ")\n";
}

void Quadrangle::MoveO(int _x, int _y) {
	x1 += _x;
	x2 += _x;
	x3 += _x;
	x4 += _x;
	y1 += _y;
	y2 += _y;
	y3 += _y;
	y4 += _y;
}

int Quadrangle::getId() {
	return id;
}

QuadrangleCoordinates Quadrangle::getQuadrangle() {
	QuadrangleCoordinates result;
	result.x1 = x1;
	result.x2 = x2;
	result.x3 = x3;
	result.x4 = x4;
	result.y1 = y1;
	result.y2 = y2;
	result.y3 = y3;
	result.y4 = y4;
	return result;
}

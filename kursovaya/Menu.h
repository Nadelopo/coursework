#pragma once
#include <iostream>
#include <list>
#include "Rectangle.h"
#include "Quadrangle.h"
using namespace std;
class Menu
{
private:
	string value;
	list <Rectangle> listRectangle;
	list <Quadrangle> listQuadrangle;
	template<typename T>
	int getNewId(list<T> list);
	bool onlyDigits(const string s);
	void createRectangle();
	void createQuadrangle();
	template<typename T>
	bool elementExists(int id, list<T> list);
	template<typename T>
	void getElementById(int id, list<T> list);
	template<typename T>
	void deleteElement(int id, list<T>& list);
	bool intersectRectangles(int id1, int id2);
	int direction(int x1, int y1, int x2, int y2, int x3, int y3);
	bool doIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	bool intersectQuadrangles(int id1, int id2);
	template<typename T>
	void moveElement(int id, list<T>& list, int x, int y);
public:
	void Create();
	void Verification();
	void Show();
	void Delete();
	void Intersect();
	void Move();
	void Start();
};

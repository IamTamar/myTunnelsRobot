#pragma once
#include "Point.h"	
#include "Colors.cpp"	
#include <list>
#include "Stops.cpp"

class Vertex
{
private:
 	Point p;
	Colors c;
	list<Vertex*> next;
	Stops s;
public:
	Vertex(double x, double y, double z, Colors c) {
		this->p = Point(x,y,z);
		this->c = c;
		this->s = Stops::DEFAULT;
		//האם לאתחל את הרשימה?
	}
	Point getPoint() {
		return p;
	}
	Colors getColor() {
		return c;
	}
	Stops getStop() {
		return s;
	}

	void setColor(Colors c) {
		this->c = c;
	}
	void setStop(Stops s) {
		this->s = s;
	}

	void setPoint(double x, double y, double z) {
		this->p.changeX(x);
		this->p.changeY(y);
		this->p.changeZ(z);
	}
	void setPointByPoint(Point point) {
		this->p.changeX(point.getX());
		this->p.changeY(point.getY());
		this->p.changeZ(point.getZ());
	}
	void addVertixToList(Vertex* v) {
		next.push_back(v);
	}	
	bool isSimilliar(Vertex v);
	double distance(Vertex v);
	//Stops direction();
	double vertexDirection(Vertex r_v, Vertex p_v, Vertex o_v);
};


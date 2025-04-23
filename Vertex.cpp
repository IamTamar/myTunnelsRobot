#include "Vertex.h"
#include <iostream>
#include <cmath>
#include <vector>

Vertex initialVertex(double x, double y, double z) {
	return Vertex(x, y, z, Colors::WHITE);
}

// a distance between 2 vertice
double Vertex::distance(Vertex v) {
	//calculate the distance between this vertex and the vertex v
	//d =  sqrt of[(x2 � x1)v2 + (y2 � y1)v2 + (z2 � z1)v2]
	double x = this->getPoint().getX() - v.getPoint().getX();
	double y = this->getPoint().getY() - v.getPoint().getY();
	double z = this->getPoint().getZ() - v.getPoint().getZ();
	//std::cout << sqrt(x * x + y * y + z * z);
	return sqrt(x * x + y * y + z * z);
}
//Stops Vertex::direction(Vertex v) {
//
//	if (x < 0) return Stops::RIGHT;//If 1'st vertice is smaller than 2nd, solution will be smaller than 0
//	if (x > 0) return Stops::LEFT;//If 1'st vertice is bigger than 2nd, solution will be greater than 0
//	if (z < 0) return Stops::UP;
//	if (z > 0) return Stops::DOWN;
//}



bool Vertex::isSimilliar(Vertex v) {
	//check if the vertex v is similliar to this vertex
	if (this->distance(v) <= 10) // 10 is only an example!
		return true;
	return false;
}


//v1 and v2: vector v- robot direction from previous position
//u1 and u2: vector u- vertex direction from robot path: right/left/on-path
//determinant between 2 vectors causes to 3 results: 0- on path, <0- right, >0- left
double Vertex::vertexDirection( Vertex p_v, Vertex o_v) {
	//this - robot, p_v- previous, o_v - other vertex from lidar
	double v1, v2, u1, u2, res;
	v1 = this->getPoint().getX() - p_v.getPoint().getX();
	v2= this->getPoint().getY() - p_v.getPoint().getY();
	u1 = o_v.getPoint().getX() - this->getPoint().getX();
	u2 = o_v.getPoint().getY() - this->getPoint().getY();
	res = (v1 * u2) - (v2 * u1);
	return res;
}
//lidarDirections- check the direction of each vertex from the robot path
//����� �� ����� �� ���� ��� ��, ���� ����� �� ������. ���� �� �������� ��� ��? ������ �� �� ���� ��������� ��� ��?
//������ �� �� ����� ������� ������ ��������� ����?
//������ �� �� ����� ������� ������ ��������� ����?
void lidarDirections(vector<Vertex*> v, Vertex prevOnPath) {
	foreach(Vertex* vert in v)
	{
		int rightCount = 0, leftCount = 0;
		double res = this.vertexDirection(prevOnPath, *vert);
		if (res == 0)
		{
			vert->setStop(Stops::ON_PATH);
		}
		else if (res < 0)
		{
			//vert->setStop(Stops::RIGHT);
			rightCount++;
		}
		else
		{
			//vert->setStop(Stops::LEFT);
			leftCount++;
		}	
	}
}






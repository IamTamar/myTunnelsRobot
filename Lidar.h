#include "Vertex.h"
class Lidar
{
public:
	double rightDist;
	double leftDist;
	Vertex current;
public:
	 Lidar(double right, double left, Point p) {
		this->rightDist = right;
		this->leftDist = left;
		this->current.Vertex(p);
	}
	void distances(double right, double left) {
		this->rightDist = right;
		this->leftDist = left;
	}
};


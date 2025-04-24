#include "Vertex.h"
class Lidar
{
public:
	vector<Point> UpTDownLidar;//����� ������ ��� ���� ������ ���, ����� ������ ��� ���� ����� �����
	vector<Point> RightToLeftLidar;//��� ���� ����, ����� ���� - ���� ������� �� ������ ��� ����� ����� ������
	vector <Point> ceilingLidar;//����� ����� ������, ����� �������

public:
	vector<Point> UpTDownLidar();
	vector<Point> RightToLeftLidar();
	vector <Point> ceilingLidar();

	vector<Point*> wallsFilterUTD(vector<Point> v, double rightDist, double leftDist);
	vector<double> avgs(vector<Point*> vects);
	vector<double> wallsFilterRTL(vector<Point> v, double rightDist, double leftDist);
	bool wallInFront(vector<Point> v);
};


#include "Lidar.h"
#include "Vertex.cpp"
#include "algorithm"
#include <vector>
#include <math.h>

using namespace std;

vector<Point> UpTDownLidar() {
	//lidar performance:
	// up to down on right, and keeps going to buttom and down to up in left
	// writing into file
    //reading and moving into vector<vertex>
}
vector<Point> RightToLeftLidar() {
	//lidar performance:
	//  right near robot, and keeps going in front and left until near robot
	// writing into file
	//reading and moving into vector<vertex>
}
vector <Point> ceilingLidar() {
	//looks up to detect obstacles
}

//function that filters only walls points and then sorts up to down(y axe),
// and returns differences between up-down on right & left
//�� ���� ���� �� ����� ������� �2 ������ ��� ��!!! ���� ����� ��� ��
vector<Point*> wallsFilterUTD(vector<Point> v, double rightDist, double leftDist) {
	vector<Point> right = {}, left = {};
	for (Point p : v)
	{
		if (p.getX()  > 0 && p.getX() >= rightDist - 2)
			right.push_back(p);
		if ( p.getX() < 0 && p.getX() >= (leftDist - 2)*(-1))
			left.push_back(p);
	}

	sort(right.begin(), right.end(), []( Point a,  Point b) {
		return a.getY() > b.getY();
    });

	sort(left.begin(), left.end(), []( Point a,  Point b) {
		return a.getY() > b.getY();
	});
	 
	vector<Point*> vects = {right, left};
	//vector<double> avgs = { abs(avgRightUp - avgRightDown), abs(avgLeftUp - avgLeftDown) };
	return vects;
	//������ �� �������� ��� ����� ��� �� ��� ������� ���� ������, �� �� - ����� �����
}

vector<double> wallsFilterRTL(vector<Point> v, double rightDist, double leftDist) {
	vector<Point> right = {}, left = {};
	for (Point p : v)
	{
		if (p.getX() > 0 && p.getX() >= rightDist - 2)
			right.push_back(p);
		if (p.getX() < 0 && p.getX() >= (leftDist - 2) * (-1))
			left.push_back(p);
	}

	sort(right.begin(), right.end(), [](Point a, Point b) {
		return a.getY() > b.getY();
		});

	sort(left.begin(), left.end(), [](Point a, Point b) {
		return a.getY() > b.getY();
		});

	double avgRightUp, avgLeftUp, sumRightUp = 0, sumLeftUp = 0, avgRightDown, avgLeftDown, sumRightDown = 0, sumLeftDown = 0;
	for (int i = 0; i < 10; i++)
	{
		sumRightUp += right[i].getX();
		sumLeftUp += left[i].getX();
	}
	for (int i = 0; i < 10; i++)
	{
		sumRightDown += right[right.size() - 1 - i].getX();
		sumLeftDown += left[left.size() - 1 - i].getX();
	}
	avgRightUp = sumRightUp / 10;
	avgLeftUp = sumLeftUp / 10;
	avgRightDown = sumLeftUp / 10;
	avgLeftDown = sumLeftDown / 10;
	vector<double> avgs = { abs(avgRightUp - avgRightDown), abs(avgLeftUp - avgLeftDown) };
	return avgs;
}

vector<double> avgs(vector<Point*> vects) {
	double avgRightUp, avgLeftUp, sumRightUp = 0, sumLeftUp = 0, avgRightDown, avgLeftDown, sumRightDown = 0, sumLeftDown = 0;
	vector <Point> right = vects[0], left = vects[1];
	for (int i = 0; i < 10; i++)
	{
		sumRightUp += right[i].getX();
		sumLeftUp += left[i].getX();
	}
	for (int i = 0; i < 10; i++)
	{
		sumRightDown += right[right.size() - 1 - i].getX();
		sumLeftDown += left[left.size() - 1 - i].getX();
	}
	avgRightUp = sumRightUp / 10;
	avgLeftUp = sumLeftUp / 10;
	avgRightDown = sumLeftUp / 10;
	avgLeftDown = sumLeftDown / 10;

	vector<double> avgs = { abs(avgRightUp - avgRightDown), abs(avgLeftUp - avgLeftDown) };

	return avgs;
} 

bool wallInFront(vector<Point> v) {
	vector<Point> front = {};
	for (Point p : v)
	{
		if (p.getX() >= -20 && p.getX() <=20 )
			front.push_back(p);
	}

	sort(front.begin(), front.end(), [](Point a, Point b) {
		return a.getZ() > b.getZ();
	});

	//���� ����� �� ����� ����� ���???
	//������� ����� ���� ��� �����!
	double sum = 0, avg, median;
	for (Point p : front) {
		sum += p.getZ();
	}
	avg = sum / front.size();
	median = front[front.size() / 2];
	//���� ����� �� ������ �������?
	if (avg <= 40)
		return true;
	return false;
}

//using the ransac algorithm to filter outliers(i don't know if these are match for me)
// ����� ����� ����� ���� �� ����� ������ 
// ����� ����� �� �� ������� ���� ��� ������ ������� ����� �����. 
//https://pcl.readthedocs.io/projects/tutorials/en/latest/planar_segmentation.html#planar-segmentation
//#include <iostream>
//#include <pcl/ModelCoefficients.h>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//#include <pcl/sample_consensus/method_types.h>
//#include <pcl/sample_consensus/model_types.h>
//#include <pcl/segmentation/sac_segmentation.h>
//
//int
//main()
//{
//	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//
//	// Fill in the cloud data
//	cloud->width = 15;
//	cloud->height = 1;
//	cloud->points.resize(cloud->width * cloud->height);
//
//	// Generate the data
//	for (auto& point : *cloud)
//	{
//		point.x = 1024 * rand() / (RAND_MAX + 1.0f);
//		point.y = 1024 * rand() / (RAND_MAX + 1.0f);
//		point.z = 1.0;
//	}
//
//	// Set a few outliers
//	(*cloud)[0].z = 2.0;
//	(*cloud)[3].z = -2.0;
//	(*cloud)[6].z = 4.0;
//
//	std::cerr << "Point cloud data: " << cloud->size() << " points" << std::endl;
//	for (const auto& point : *cloud)
//		std::cerr << "    " << point.x << " "
//		<< point.y << " "
//		<< point.z << std::endl;
//
//	pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
//	pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
//	// Create the segmentation object
//	pcl::SACSegmentation<pcl::PointXYZ> seg;
//	// Optional
//	seg.setOptimizeCoefficients(true);
//	// Mandatory
//	seg.setModelType(pcl::SACMODEL_PLANE);
//	seg.setMethodType(pcl::SAC_RANSAC);
//	seg.setDistanceThreshold(0.01);
//
//	seg.setInputCloud(cloud);
//	seg.segment(*inliers, *coefficients);
//
//	if (inliers->indices.size() == 0)
//	{
//		PCL_ERROR("Could not estimate a planar model for the given dataset.\n");
//		return (-1);
//	}
//
//	std::cerr << "Model coefficients: " << coefficients->values[0] << " "
//		<< coefficients->values[1] << " "
//		<< coefficients->values[2] << " "
//		<< coefficients->values[3] << std::endl;
//
//	std::cerr << "Model inliers: " << inliers->indices.size() << std::endl;
//	for (const auto& idx : inliers->indices)
//		std::cerr << idx << "    " << cloud->points[idx].x << " "
//		<< cloud->points[idx].y << " "
//		<< cloud->points[idx].z << std::endl;
//
// // **����� ����� ���� (���� �� ���)**
//if (std::abs(coefficients->values[2]) > 0.9) {
//	std::cout << "Detected Ground Plane (����)!" << std::endl;
//}
//else if (std::abs(coefficients->values[2]) < 0.1) {
//	std::cout << "Detected Vertical Wall (���)!" << std::endl;
//}
//else {
//	std::cout << "Unknown plane orientation." << std::endl;
//}
//	return (0);
//}

// Compiling and running the program

//Add the following lines to your CMakeLists.txt file :
//
//cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
//
//project(planar_segmentation)
//
//find_package(PCL 1.2 REQUIRED)
//
//include_directories(${ PCL_INCLUDE_DIRS })
//link_directories(${ PCL_LIBRARY_DIRS })
//add_definitions(${ PCL_DEFINITIONS })
//
//add_executable(planar_segmentation planar_segmentation.cpp)
//target_link_libraries(planar_segmentation ${ PCL_LIBRARIES })


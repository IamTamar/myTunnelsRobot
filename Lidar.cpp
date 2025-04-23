#include "Lidar.h"
#include "Vertex.cpp"
#include "algorithm"
#include <vector>
#include <math.h>

using namespace std;
// לקרוא מקובץ נתוני לידאר
//בכל איטרציה, נשלח פס לידאר לכל גובה הקיר (מלמעלה למטה) כדי לבדוק:
//האם העומק של הנקודות העליונות דומה לעומק של הנקודות התחתונות
//אם כן- אין פתח כנראה ולא מופעלת מצלמה
//אם לא- יש פתח ומצלמה מופעלת, וכנראה שצריך לפנות לשם

vector<Vertex> rightLidar() {
	//switch on right lidar and writing to file
    //reading and moving into vector<vertex>
}
vector<Vertex> leftLidar() {
	//switch on left lidar and writing to file
	//reading and moving into vector<vertex>
}

//function that filters only walls points and then sorts up to down(y axe),
// and returns differences between up-down on right & left
//יש צורך לדעת מה המרחק מהקירות ב2 הצדדים לשם כך!!! חשוב לוודא שיש לי
vector<double> wallsFilter(vector<Point> v, double rightDist, double leftDist) {
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
	 
	double avgRightUp, avgLeftUp, sumRightUp=0, sumLeftUp=0, avgRightDown, avgLeftDown, sumRightDown = 0, sumLeftDown = 0;
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
	//כשנזמן את הפונקציה הזו נבדוק בכל צד האם ההפרשים מידי גדולים, אם כן - הפעלת מצלמה
	//  לא להשתמש בפונקציית הצדדים!!!!!
}




//using the ransac algorithm to filter outliers(i don't know if these are match for me)
// ביצוע פילוח מישור פשוט של קבוצת נקודות 
// כלומר למצוא את כל הנקודות בתוך ענן נקודות התומכות במודל מישור. 
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
// // **הוספת זיהוי משטח (רצפה או קיר)**
//if (std::abs(coefficients->values[2]) > 0.9) {
//	std::cout << "Detected Ground Plane (רצפה)!" << std::endl;
//}
//else if (std::abs(coefficients->values[2]) < 0.1) {
//	std::cout << "Detected Vertical Wall (קיר)!" << std::endl;
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


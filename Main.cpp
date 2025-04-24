#include "Main.h"
#include "Vertex.cpp"
#include "Lidar.cpp"
#include <stack>
#include <vector>


using namespace std;

void move() {
	
	
// קבלת נתוני הלידאר והמרה

	//define the first vertex
	Vertex first = initialVertex(0, 0, 0);
	first.setColor(Colors::GRAY);
	Main::verticeList.push_back(&first);
	//......
	// חישוב לאיפה ללכת, לאיפה לסטות, מסנן קלמן- בדיקה אם זה במקום הנכון
	Point kalmanPoint = kalmanFilter();
	first.setPoint(kalmanPoint);

	while(1){
		
		Vertex nextVertex = initialVertex(0,0,0);//עפ"י ההחלטה מי יהיה הקודקוד הבא
		first.setColor(Colors::BLACK);//exited from it
		first.addVertixToList(&nextVertex);//add to the prev list
		nextVertex.setColor(Colors::GRAY);
		Main::verticeList.push_back(&nextVertex);//add to main list

		//lidar data up to down..
		double rightDist, leftDist;
		//converting data from file to vector<point>
		vector<Point> lidarPointC;
		vector <double> avgs = wallsFilterUTD(lidarPointC, rightDist, leftDist);

		//lidar data robot right to left..





		//define a vertix direction
		
		nextVertex.setStop(s);
		if (s == Stops::LEFT)//if i turned left, flag is false, and keeping the prev vertix into turns stack
		{
			Main::flag = false;
			Main::turnsStack.push(first);
			Main::counter++;
		}

		//if the round was closed- it came to the first vertex of this round, when we turned oposite
		if (nextVertex.isSimilliar(Main.turnsStack.top()))
		{
			Main::flag = true;
			Main::turnsStack.pop();
			Main::counter--;
		}






  	}
	


}
	
#include "Vertex.h"
class Lidar
{
public:
	vector<Point> UpTDownLidar;//לידאר מלמעלה בצד ימין לכיוון מטה, ממשיך בסיבוב לצד שמאל מלמטה למעלה
	vector<Point> RightToLeftLidar;//בצד ימין לידו, ממשיך הלאה - מולו ולשמאלו עד שמשלים חצי סיבוב סביבו מקדימה
	vector <Point> ceilingLidar;//לידאר לתקרה מלפניו, בדיקת מכשולים

public:
	vector<Point> UpTDownLidar();
	vector<Point> RightToLeftLidar();
	vector <Point> ceilingLidar();

	vector<Point*> wallsFilterUTD(vector<Point> v, double rightDist, double leftDist);
	vector<double> avgs(vector<Point*> vects);
	vector<double> wallsFilterRTL(vector<Point> v, double rightDist, double leftDist);
	bool wallInFront(vector<Point> v);
};


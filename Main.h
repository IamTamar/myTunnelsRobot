#include <list>
#include <stack>
#include "Vertex.h"	
using namespace std;
class Main
{
public:
	std::list<Vertex*> verticeList;
	std::stack <Vertex> turnsStack;
	bool flag= true;//true- right side, false - left side
	int counter;//num of turns that i changed directions


	list<Vertex*> getVerticeList() {
		return verticeList;
	}
};
#pragma once
class Main
{
public:
	list<Vertex*> verticeList;
	stack <Vertex> turnsStack;
	bool flag= true;//true- right side, false - left side
	int counter;//num of turns that i changed directions

	list<Vertex*> getVerticeList() {
		return verticeList;
	}
};
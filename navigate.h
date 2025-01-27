#pragma once
class navigate
{
	enum Colors
	{
		 gray, //start but didnt finish
		 black //finish all 
	};
	//a position point contains 3 coordinates values
	struct Point
	{
		int x;
		int y;
		int z;
	};

	struct Vertice
	{
		Point p;
		Colors c;

	};
};


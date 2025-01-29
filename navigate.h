#pragma once
class navigate
{
	enum Colors
	{
		 GRAY, //start but didnt finish
		 BLACK //finish all 
	};
	//causes for stops
	enum Stops
	{
      RIGHT,
	  LEFT,
	  KIDNAPPED,
	  TERRORIST,
	  EXPLOSIVES,
	  //מכשול
	  OBSTACLE
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
		Colors c;//finish all directions or not 
	};
};


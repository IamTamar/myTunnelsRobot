//#include "Main.h"
#include "Vertex.h"
#include <stack>
#include <vector>
#include "Colors.cpp"

using namespace std;
//vvv!!
 int main() {
	std::cout << "Hello, World!" << std::endl;
	Vertex v1 = Vertex(1, 1, 1, Colors::WHITE);
	Vertex v2 = Vertex(-2, -2, 1, Colors::WHITE);
	Vertex v3 = Vertex(2, 1, 1, Colors::WHITE);
	Vertex v4 = Vertex(4, 2, 1, Colors::WHITE);
	Vertex v5= Vertex(-1, 1, 1, Colors::WHITE);
	Vertex v6 = Vertex(0, 0, 0, Colors::BLACK);


	std::cout << v1.vertexDirection(v2, v3) << std::endl;
	std::cout << v1.vertexDirection(v2, v4) << std::endl;
	std::cout << v1.vertexDirection(v2, v5) << std::endl;
	std::cout << v1.vertexDirection(v2, v6) << std::endl;
	std::cout << " " << std::endl;
	std::cout << v2.vertexDirection(v1, v3) << std::endl;
	std::cout << v2.vertexDirection(v1, v4) << std::endl;
	std::cout << v2.vertexDirection(v1, v5) << std::endl;
	std::cout << v2.vertexDirection(v1, v6) << std::endl;

	Vertex v7 = Vertex(-4, 3, 1, Colors::WHITE);
	Vertex v8 = Vertex(2, -2, 1, Colors::WHITE);
	Vertex v9 = Vertex(1, 1, 1, Colors::WHITE);
	Vertex v10 = Vertex(-2, 2, 1, Colors::WHITE);
	Vertex v11= Vertex(1, -2, 1, Colors::WHITE);
	Vertex v12= Vertex(0, -0.33333,0, Colors::BLACK);

	std::cout << v7.vertexDirection(v8, v9) << std::endl;
	std::cout << v7.vertexDirection(v8, v10) << std::endl;
	std::cout << v7.vertexDirection(v8, v11) << std::endl;
	std::cout << v7.vertexDirection(v8, v12) << std::endl;
	std::cout << " " << std::endl;
	std::cout << v8.vertexDirection(v7, v9) << std::endl;
	std::cout << v8.vertexDirection(v7, v10) << std::endl;
	std::cout << v8.vertexDirection(v7, v11) << std::endl;
	std::cout << v8.vertexDirection(v7, v12) << std::endl;
}
 
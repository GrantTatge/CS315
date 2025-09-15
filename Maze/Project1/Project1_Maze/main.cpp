#include <iostream>
#include "Maze.h"

int main(int argc, char *argv[]) {
	//for (int i = 1; i < argc; i++) {
	//	Maze maze = Maze(argv[i]);
	//	maze.solve();
	//	maze.printOutput();
	//}
	Maze testMaze = Maze("input2.txt");
	testMaze.solve();
	testMaze.printOutput();
}
#pragma once
#ifndef MAZE
#define MAZE

#include <vector>
#include<iostream>

typedef std::pair<int, int> cell;
const cell nullCell = { -1, -1 };
enum { PATH, WALL, SEEN, SOLVED, ENDPOINT};

class Maze {
public:
	Maze(std::string inFileName);
	void printBoard();
	void printOutput();
	void solve();

private:

	// Variables
	std::vector<std::vector<int>> board;
	cell startCell = nullCell;
	cell targetCell = nullCell;
	int yBound = 0;
	int xBound = 0;
	const std::vector<cell> adjacentMoves = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	bool solvable = false;

	// Find and set start/endpoint
	void setEndpoints();
	void identifyEndpoint(cell input);

	// Cell checking
	bool checkAdjacentCells(cell currPosition);
	cell chooseAdjacentCell(cell currPosition);

	// Various helper methods
	int getValueAt(cell coordinates);
	cell getAdjacentCell(cell currPosition, cell move);
	bool isInBounds(cell potentialCell);

	// Helper method for printOutput
	std::string outputHelper(cell currPosition);
	
};

#endif /* MAZE */
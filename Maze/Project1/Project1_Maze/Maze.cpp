// Grant Tatge

#include "Maze.h"
#include <string>
#include <fstream>
#include <stack>

Maze::Maze(std::string inFileName) {

    std::ifstream inFile(inFileName);

    std::string inLine;
    std::vector<int> inVec;

    if (inFile.is_open()) {
        while (getline(inFile, inLine)) {
            for (char n : inLine) {
                inVec.push_back((n - '0'));
            }
            board.push_back(inVec);
            inVec.clear();
        }
    }
    yBound = board.size();
    xBound = board.at(0).size();
    setEndpoints();
}


void Maze::setEndpoints() {
    for (int y = 0; y < yBound; y++) {
        identifyEndpoint({ y, 0 });
        identifyEndpoint({ y, xBound - 1 });
    }
    for (int x = 0; x < xBound - 1; x++) {
        identifyEndpoint({ 0, x });
        identifyEndpoint({ yBound - 1, x });
    }
}

void Maze::identifyEndpoint(cell input) {
    int currPoint = getValueAt(input);
    if (currPoint != WALL) {
        if (startCell == nullCell) {
            startCell = input;
            board.at(startCell.first).at(startCell.second) = SEEN;
        }
        else {
            targetCell = input;
            board.at(targetCell.first).at(targetCell.second) = ENDPOINT;
        }
    }
}

void Maze::printBoard() {
    for (auto i : board) {
        for (auto j : i) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

void Maze::printOutput() {
    if (solvable != true) {
        std::cout << "The maze is unsolvable. \n";
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.at(0).size(); j++) {
            std::cout << outputHelper({ i, j }) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n \n";
}


std::string Maze::outputHelper(cell currPosition) {
    switch (getValueAt(currPosition)) {
    case 0:
        return "\033[32m+\033[0m";
    case 1:
        return "#";
    case 2:
        return "\033[36m*\033[0m";
    case 3:
        return "\033[35m*\033[0m";
    case 4:
        return "\033[33mX\033[0m";
    }
    return " ";
}

void Maze::solve() {
    std::stack<cell> solveStack;
    solveStack.push(startCell);
    while (solveStack.empty() == false) {
        if (checkAdjacentCells(solveStack.top()) == false
            && solveStack.top() != targetCell) {
            // no adjacent cell is a potential path
            solveStack.pop();
        }
        else {
            solveStack.push(chooseAdjacentCell(solveStack.top()));
            if (board.at(solveStack.top().first).at(solveStack.top().second) == ENDPOINT) {
                break;
            }
            board.at(solveStack.top().first).at(solveStack.top().second) = SEEN;
        }
    }

    if (solveStack.empty()) {
        std::cout << "No solution exists \n";
        return;
    }

    solveStack.pop(); // the endpoint should stay labelled as the endpoint
    while (solveStack.empty() == false) {
        board.at(solveStack.top().first).at(solveStack.top().second) = SOLVED;
        solveStack.pop();
    }
    solvable = true;
}

bool Maze::checkAdjacentCells(cell currPosition) {
    for (auto potentialCell : adjacentMoves) {
        auto curr = getAdjacentCell(currPosition, potentialCell);
        if (isInBounds(curr)
            && (getValueAt(curr) == PATH
            || getValueAt(curr) == ENDPOINT)) {
            return true;
        }
    }
    return false;
}

cell Maze::chooseAdjacentCell(cell currPosition) {
    for (auto potentialCell : adjacentMoves) {
        auto curr = getAdjacentCell(currPosition, potentialCell);
        if (isInBounds(curr)
            && (getValueAt(curr) == PATH
            || getValueAt(curr) == ENDPOINT)) {
            return curr;
        }
    }
}

int Maze::getValueAt(cell coordinates) {
    return board.at(coordinates.first).at(coordinates.second);
}

cell Maze::getAdjacentCell(cell currPosition, cell move) {
    return { currPosition.first + move.first, currPosition.second + move.second };;
}

bool Maze::isInBounds(cell potentialCell) {
    if (potentialCell.first >= 0 && potentialCell.first < yBound
        && potentialCell.second >= 0 && potentialCell.second < xBound) {
        return true;
    }
    else 
        return false;
}
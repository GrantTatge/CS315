#include <iostream>
#include <fstream>

#include "BinSearchTree.hpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main( int argc, char *argv[] ) {
    // Use this as a starting point to test the functions
    // that you add to BinSearchTree.


    if( argc != 2 ) {
        std::cout << "usage: executable name-of-input-file\n";
        exit(1);
    }
    std::fstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if(!inputStream.is_open()) {
        std::cout << "Unable to open the input file " <<
                  argv[1] << std::endl;
        std::cout << "Terminating...\n";
        exit(2);
    }


    BinSearchTree *tree = new BinSearchTree();
    int aValue;
    while( inputStream >> aValue )
        tree->insert( aValue );

    // The size() function has not been implemented yet. It currently returns 0
    // so the program can compile and run. Your first task is to write a proper
    // recursive implementation of find(). Once that is done, move on to writing
    // the recursive version of size().

    std::cout << "The size of the tree is " << tree->size() << "." << std::endl;
    std::cout << "The max depth of the tree is : " << tree->maxDepth() << std::endl;
    std::cout << "In order listing of the tree structure: " << std::endl;
    tree->inorderListing();
    std::cout << std::endl;
    std::cout << "Testing iterInsert: " << std::endl;
    tree->iterInsert(1000);
    std::cout << std::endl;
    std::cout << "testing iterFind" << std::endl;
    tree->iterFind(1000);
    std::cout << std::endl;
    delete tree;
    return 0;
}

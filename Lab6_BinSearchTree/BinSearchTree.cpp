//
// Created by Ali Kooshesh on 10/1/25.
//

// Grant Tatge
// Danny Meza
// Daniel Padilla

#include "BinSearchTree.hpp"

#include <iostream>
#include <ostream>

BinSearchTree::BinSearchTree(): root{nullptr} {}

TreeNode *BinSearchTree::insert( TreeNode *root, int v ) {
    if( root == nullptr )
        return new TreeNode( v );
    if( root->value() < v )
        root->rightSubtree( insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( insert( root->leftSubtree(), v ) );
    return root;
}

bool BinSearchTree::insert(int v) {
    // Insert v in the tree if it is not already a member.
    // Return true if the value was indeed inserted into the tree.
    // Otherwise, return false.

    if( ! find(v) ) {
        root = insert(root, v);
        return true;
    }
    return false;
}

int BinSearchTree::size(TreeNode* currNode) {
    if( currNode == nullptr ) {
        return 0;
    }
    return 1 + size(currNode->leftSubtree()) + size(currNode->rightSubtree());
}

int BinSearchTree::size() {
    // Perform a traversal, adding + 1 for each node
    return size(root);
}

bool BinSearchTree::find(TreeNode* currNode, int v) {
    if (currNode == nullptr) {
        return false;
    }
    if (currNode->value() == v) {
        return true;
    }
    if (v < currNode->value()) {
        return find(currNode->leftSubtree(), v);
    }
    return find(currNode->rightSubtree(), v);
}

bool BinSearchTree::find(int v) {
    if (find(root, v)) {
        return true;
    }
    return false;
}

bool BinSearchTree::iterFind(int v) {
    TreeNode* currNode = root;
    if (currNode == nullptr) {
        return false;
    }
    while (currNode->value() != v) {
        if (currNode->value() == v) {
            return true;
        }
        if (currNode->leftSubtree() != nullptr && currNode->value() > v) {
            currNode = currNode->leftSubtree();
        }
        else if (currNode->rightSubtree() != nullptr && currNode->value() < v) {
            currNode = currNode->rightSubtree();
        }
        else {
            return false;
        }
    }
}

void BinSearchTree::inorderListing(TreeNode * currNode) {
    if (currNode == nullptr) {
        return;
    }
    inorderListing(currNode->leftSubtree());
    std::cout << currNode->value() << std::endl;
    inorderListing(currNode->rightSubtree());
}


void BinSearchTree::inorderListing() {
    inorderListing(root);
}

int BinSearchTree::maxDepth(TreeNode * currNode) {
    if( currNode == nullptr ) {
        return 0;
    }
    return 1 + std::max(size(currNode->leftSubtree()),
                        size(currNode->rightSubtree()));
}

int BinSearchTree::maxDepth() {
    return maxDepth(root);
}

void BinSearchTree::iterInsert(int v) {
    if (!find(v)) {
        auto* newNode = new TreeNode(v);
        if (root == nullptr) {
            root = newNode;
        }
        TreeNode *currNode = root;
        TreeNode *prevNode = currNode;
        while (currNode != nullptr) {
            prevNode = currNode;
            if (v < currNode->value()) {
                currNode = currNode->leftSubtree();
            }
            else {
                currNode = currNode->rightSubtree();
            }
        }
        if (prevNode->leftSubtree() == nullptr) {
            prevNode->leftSubtree(newNode);
        }
        else {
            prevNode->rightSubtree(newNode);
        }
    }
}

BinSearchTree::~BinSearchTree() {
    // This function should delete every node in the tree.
    // To do that, you will have to recursively traverse the tree, using
    // a post-order traversal.
    if (root->leftSubtree() != nullptr) {
        delete root->leftSubtree();
    }
    if (root->rightSubtree() != nullptr) {
        delete root->rightSubtree();
    }
    delete root;
}

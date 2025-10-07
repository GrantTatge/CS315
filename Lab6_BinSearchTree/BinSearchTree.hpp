//
// Created by Ali Kooshesh on 10/1/25.
//

#ifndef BINSEARCHTREESTUDENTFILES_ADT_BINSEARCHTREE_HPP
#define BINSEARCHTREESTUDENTFILES_ADT_BINSEARCHTREE_HPP


#include "TreeNode.hpp"

class BinSearchTree {
public:
    BinSearchTree();
    bool insert( int v );
    bool find( int v );
    bool iterFind( int v );
    int size();
    void inorderListing();
    int maxDepth();
    void iterInsert( int v );

    ~BinSearchTree();

private:
    TreeNode *insert( TreeNode *, int );
    bool find(TreeNode*, int v);
    int size(TreeNode*);
    void inorderListing(TreeNode*);
    int maxDepth(TreeNode*);
    TreeNode *root;
};


#endif //BINSEARCHTREESTUDENTFILES_ADT_BINSEARCHTREE_HPP
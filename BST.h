//===========================================
// Andrew Byerly & Colin Nguyen
// October 2025
// BST.h
// This file contains all the method 
// declarations of the BST class
//===========================================

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string> 
#include <vector>

#ifndef BST_H
#define BST_H

using namespace std;

template <typename D, typename K>
class BST {

    private:

    struct Node {
        D data;
        K key;

        Node* parent;
        Node* left;
        Node* right;
    };

    int size;
    Node* root;

    public:

    BST(void);
    BST(const D& data, const K& key);
    ~BST(void);

    bool empty (void);
    void insert (const D& data, const K& key);
    D get (const K& key);
    // void remove (const K& key);
    D max_data (void);
    K max_key (void);
    D min_data (void);
    K min_key (void);
    K successor (const K& key);
    std::string in_order(void);
    // void trim(K low, K high);
    void inorder_walk_destructor(Node* x); // we might not need this
    void transplant(Node* u, Node* v);


    std::string to_string (void) const;

    // use a queue to keep track of the parents and children that you saw
    // when we saw all children of the first item in the queue, remove it and then check the children of the other children in the queue
    // if a node has no kids then remove from the queue
};

#include "BST.cpp"

#endif
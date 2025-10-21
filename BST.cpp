//===========================================
// Andrew Byerly & Colin Nguyen
// October 2025
// BST.cpp
// This file contains all the method 
// definitions of the BST class
//===========================================

#include "BST.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//===========================================
// Constructor 
//===========================================
template <typename D, typename K> 
BST<D, K>::BST() {

    root = nullptr;

}

//===========================================
// Constructor
//===========================================
template <typename D, typename K>
BST<D, K>::BST(const D& data, const K& key) {

    Node instance = new Node;
    instance->data = data;
    instance->key = key;
    root = instance;

}

//===========================================
// Destructor
//===========================================
template <typename D, typename K>
BST<D, K>::~BST() {
    
}

//===========================================
// empty
//===========================================
template <typename D, typename K>
bool BST<D, K>::empty(void) {

    return root == nullptr;

}

//===========================================
// insert
//===========================================
template <typename D, typename K>
void BST<D, K>::insert(const D& data, const K& key) {
    
    Node* z = new Node;
    z->data = data;
    z->key = key; // create node to be inserted

    Node* y = nullptr;
    Node* x = root; // initialize tracking nodes

    while (x != nullptr) { // while not at a leaf position
        y = x;
        if (key < x->key) { x = x->left; }
        else { x = x->right; } // traverse tree left or right (based on key)
    }

    z->parent = y; // node trailing x is parent of z
    if (y == nullptr) { root = z; } // if tree is empty, make it the root
    else if (z->key < y->key) { y->left = z; } // insert z in left subtree of y
    else { y->right = z; } // insert z in right subtree of y
}

//===========================================
// get
//===========================================
template <typename D, typename K>
D BST<D, K>::get(const K& key) {

}

//===========================================
// remove
//===========================================
template <typename D, typename K>
void BST<D, K>::remove(const K& key) {
    
}

//===========================================
// max_data
//===========================================
template <typename D, typename K>
D BST<D, K>::max_data(void) {

}

//===========================================
// max_key
//===========================================
template <typename D, typename K> 
K BST<D, K>::max_key(void) {

}

//===========================================
// min_data
//===========================================
template <typename D, typename K>
D BST<D, K>::min_data(void) {

}

//===========================================
// min_key
//===========================================
template <typename D, typename K>
K BST<D, K>::min_key(void) {

}

//===========================================
// successor
//===========================================
template <typename D, typename K>
K BST<D, K>::successor(const K& key) {

}

//===========================================
// trim
//===========================================
template <typename D, typename K> 
void BST<D, K>::trim(K low, K high) {

}
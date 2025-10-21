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
    parent = nullptr;
	root = nullptr;
    right = nullptr;
    left = nullptr;
}

//===========================================
// Constructor
//===========================================
template <typename D, typename K>
BST<D, K>::BST(const D& data, const K& key) {

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

    return true;
}

//===========================================
// insert
//===========================================
template <typename D, typename K>
void BST<D, K>::insert(const D& data, const K& key) {

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
//===========================================
// Element.cpp
// Andrew Byerly & Colin Nguyen
// October 2025
// This file contains all the definitions of 
// the element class
//===========================================

#include "Element.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//============================================
// Empty Constructor
// Initiliazes an empty element constructor
// PARAMETERS:
// none
// RETURN VALUE:
// none
//============================================
template <typename D, typename K> Element<D, K>::Element(void) {

    instance = new item;
    instance->data;
    instance->key = -1;
    instance->left = nullptr;
    instance->right = nullptr;
    instance->parent = nullptr;
}

//============================================
// Element Constructor
// Initiliazes an empty element constructor
// PARAMETERS:
// D data, K key
// RETURN VALUE:
// none
//============================================
template <typename D, typename K> Element<D, K>::Element(D data, K key) {

    instance = new item;
    instance->data = data;
    instance->key = key;
    instance->left = nullptr;
    instance->right = nullptr;
    instance->parent = nullptr;
}

//============================================
// get_key
// This returns the element's numeric key 
// value
// PARAMETERS:
// none
// RETURN VALUE:
// int key
//============================================
template <typename D, typename K> K Element<D, K>::get_key(void) {

    return instance->key;
}

//============================================
// get_data
// This returns the element's data
// PARAMETERS:
// none
// RETURN VALUE:
// the T data of an element
//============================================
template <typename D, typename K> D Element<D, K>::get_data(void) {

    return instance->data;
}

//============================================
// to_string
// converts an element to a string
// PARAMETERS:
// none
// RETURN VALUE:
// a string of an element
//============================================
template <typename D, typename K> std::string Element<D, K>::to_string(void) const {
    std::stringstream s;

    s << "(" << instance->data << "," << instance->key << ")";

    return s.str();
}
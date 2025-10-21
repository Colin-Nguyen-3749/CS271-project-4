//===========================================
// Element.h
// Andrew Byerly & Colin Nguyen
// October 2025
// This file contains all the declarations of 
// the element class
//===========================================

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

#ifndef Element_H
#define Element_H

using namespace std;

template <typename D, typename K> class Element {

struct item {
    D data;
    K key;

    Element* parent;
    Element* left;
    Element* right;
};

public:
    Element();
    Element(D data, K key);
    K get_key();
    D get_data();
    std::string to_str() const;
    

private:
    item* instance;

};

#include "Element.cpp"

#endif
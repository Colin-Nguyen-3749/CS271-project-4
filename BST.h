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

#ifndef BST_H
#define BST_H

using namespace std;

template <typename D, typename K>
class BST {

    D data;
    K key;

    public:

    BST(void);
    BST(const D& data, const K& key);
    ~BST(void);

    bool empty (void);
    void insert (const D& data, const K& key);
    D get (const K& key);
    void remove (const K& key);
    D max_data (void);
    K max_key (void);
    D min_data (void);
    K min_key (void);
    K successor (const K& key);
    void trim(K low, K high);

    std::string to_string (void) const {
        std::stringstream s;

        for (int i = 0; i < size - 1; i++) {
            s << list[i] << " ";
        }
        if (size != 0) {
            s << list[size - 1];
        }
        return s.str();
    }



    private:

};

#include "BST.cpp"

#endif
//===========================================
// Andrew Byerly & Colin Nguyen
// October 2025
// bst_test.cpp
// This file contains our usecase implementation
// of the BST class
//===========================================

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include "BST.h"

using namespace std;

template <typename D, typename K>
BST<D, K>* create_bst (string fname) {

    BST<D, K> bst;

    ifstream file(fname);
    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string hexStr;
        string binary;

        getline(ss, hexStr, ',');
        getline(ss, binary, '\n');

        // Insert the values into the BST
        bst.insert(hexStr, binary);

    }

    file.close();

    BST<D, K>* treePtr = &bst;

    return treePtr;

}

template <typename D, typename K>
string convert(BST<D,K>* bst, string bin) {

    while (bin.length() % 4 != 0) {
        bin = "0" + bin;
    } // ensure that bin length is a multiple of 4 by padding the front with 0's.

    string hexConversion;

    for (int i = 0; i < bin.length(); i += 4) {
        string fourbit = bin.substr(i, i+3);
        hexConversion += bst->get(fourbit);
    } // gather every 4-bit denomination using it as the key, add its data to the conversion

    return hexConversion; // return the conversion

}

int main () {

    BST<string, string>* conversionTable = create_bst<string, string> ("binhex.txt");

    cout << conversionTable->to_string();

    cout << "Enter binary representation for conversion: ";

    string binary;
    cin >> binary;

    cout << "Hexadecimal representation of " << binary << " is " << convert<string, string> (conversionTable, binary) << endl;

    return 0;
}
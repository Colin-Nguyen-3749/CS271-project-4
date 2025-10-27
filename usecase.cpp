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

    BST<D, K> BST;

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
        BST.insert(hexStr[0], binary);

    }

    file.close();

    return BST;

}

template <typename D, typename K>
string convert(BST<D,K>* bst, string bin) {

    while (bin.length() % 4 != 0) {
        bin = "0" + bin;
    } // ensure that bin length is a multiple of 4 by padding the front with 0's.

    string hexConversion;

    for (int i = 0; i < bin.length(); i += 4) {
        string 4bit = bin.substr(i, i+3);
        hexConversion += bst.get(4bit);
    } // gather every 4-bit denomination using it as the key, add its data to the conversion

    return hexConversion; // return the conversion

}

int main () {

    BST<char, string> conversionTable; // BST to hold binary to hex conversion

    conversionTable = create_bst<char, string> ("binhex.txt");

    cout << "Enter binary representation for conversion: ";

    string binary;
    cin >> binary;

    cout << "Hexadecimal representation of " << binary << " is " << convert<char, string> (conversionTable, binary) << endl;

    return 0;
}
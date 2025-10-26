//===========================================
// Andrew Byerly & Colin Nguyen
// October 2025
// bst_test.cpp
// This file contains our own test cases
// for the BST class
//===========================================

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "usecase.cpp"
#include "BST.h"

using namespace std;

void test_insert1()
{
    try
    {
        BST<string, int> bst;
        bst.insert("CS", 271);
        string bst_str = bst.to_string();
        if (bst_str != "271")
        {
            cout << "Incorrect result of inserting (\"CS\", 271). Expected 271 but got : " << bst_str << endl;
        }
        bst.insert("CS", 109);
        bst.insert("CS", 111);
        bst.insert("CS", 112);
        bst.insert("CS", 113);
        bst.insert("CS", 114);
        bst.insert("CS", 173);
        bst.insert("CS", 181);
        bst.insert("CS", 234);
        bst.insert("CS", 395);
        bst.insert("CS", 371);
        bst_str = bst.to_string();
        if (bst_str != "271 109 395 111 371 112 113 114 173 181 234")
        {
            cout << "Incorrect result of inserting keys in order. Expected 109 111 112 113 114 173 181 234 395 371 but got : " << bst_str << endl;
        }
        int vals[10] = {3, 7, 4, 5, 6, 9, 0, 23, 12, 18};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if (bst_str != "3 0 7 4 9 5 23 6 12 18")
        {
            cout << "Incorrect result of inserting keys {3, 7, 4, 5, 6, 9, 0, 23, 12, 18}. Expected 3 0 7 4 9 5 23 6 12 18 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

int main()
{

    string file_name = "usecase.cpp";
    cout << endl
         << "Running tests for " << file_name << endl
         << endl;

    // test_empty();
    test_insert1();
    // test_get();
    // test_remove();
    // test_max_data();
    // test_max_key();
    // test_min_data();
    // test_min_key();
    // test_successor();
    // test_in_order();
    // test_trim();
    // // test_binhex();

    cout << "Testing completed" << endl;

    return 0;
}
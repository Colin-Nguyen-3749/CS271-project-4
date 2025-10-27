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
#include "BST.h"

using namespace std;

void test_insert_CS_classes()
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

        bst.insert("CS", 113);
        bst.insert("CS", 371);
        bst.insert("CS", 112);
        bst.insert("CS", 395);
        bst.insert("CS", 111);
        bst.insert("CS", 114);
        bst.insert("CS", 234);
        bst.insert("CS", 181);
        bst.insert("CS", 173);
        bst.insert("CS", 109);
       
        bst_str = bst.to_string();

        if (bst_str != "271 113 371 112 114 395 111 234 109 181 173")
        {
            cout << "Incorrect result of inserting keys in order. Expected 109 111 112 113 114 173 181 234 395 371 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_insert_long()
{
    try
    {
        BST<string, int> bst;
        bst.insert("Alfa", 1583124523);
        string bst_str = bst.to_string();
        if (bst_str != "1583124523")
        {
            cout << "Incorrect result of inserting (\"Alfa\", 1583124523). Expected 1583124523 but got : " << bst_str << endl;
        }

        bst.insert("Bravo", 13479128);
        bst.insert("Charlie", 17429);
        bst.insert("Delta", 8901726);
        bst.insert("Echo", 1063801);
        bst.insert("Foxtrot", 1098173849);
        bst.insert("Golf", 14307);
        bst.insert("Hotel", 983147);
        bst.insert("India", 134563647);
        bst.insert("Juliett", 54876);
        bst.insert("Kilo", 314987);
        bst.insert("Lima", 909735);
        bst.insert("Mike", 1349807);
        bst.insert("November", 23487);
        bst.insert("Oscar", 3291);
        bst.insert("Papa", 23491235);
        bst.insert("Quebec", 92379852);


        bst_str = bst.to_string();

        if (bst_str != "1583124523 13479128 17429 1098173849 14307 8901726 134563647 3291 1063801 23491235 983147 1349807 92379852 54876 23487 314987 909735")
        {
            cout << "Incorrect result of inserting keys in order. Expected 1583124523 13479128 17429 1098173849 14307 8901726 134563647 1063801 983147 1349807 54876 23487 314987 909735 but got : " << bst_str << endl;
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
    test_insert_CS_classes();
    test_insert_long();
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
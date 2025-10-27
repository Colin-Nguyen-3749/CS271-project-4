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

        if (bst.empty())
        {
            cout << "bst_string is incorrectly identified as non-empty." << endl;
        }

  }

    catch (exception &e)
    {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_get()
{
    try {
    BST<string, int> bst;
    bst.insert("Alfa", 13);
    bst.insert("Bravo", 1);
    bst.insert("Charlie", 7);
    bst.insert("Delta", 2);
    bst.insert("Echo", 19);
    bst.insert("Foxtrot", 21);
    bst.insert("Golf", 9);
    bst.insert("Hotel", 12);
    bst.insert("India", 14);
    bst.insert("Juliett", 18);
    bst.insert("Kilo", 3);
    bst.insert("Lima", 13);
    bst.insert("Mike", 17);
    bst.insert("November", 5);
    bst.insert("Oscar", 16);
    bst.insert("Papa", 15);
    bst.insert("Quebec", 10);
    bst.insert("Romeo", 128);
    bst.insert("Sierra", 192);
    bst.insert("Tango", 1238);
    bst.insert("Uniform", 127);
    bst.insert("Victor", 97);
    bst.insert("Whiskey", 0);
    bst.insert("XRay", 24);
    bst.insert("Yankee", 8);
    bst.insert("Zulu", 158);

    string val0 = bst.get(1);
    string val1 = bst.get(192);
    string val2 = bst.get(1238);
    string val3 = bst.get(10);
    string val4 = bst.get(97);
    string val5 = bst.get(127);
    string val6 = bst.get(0);
    string val7 = bst.get(16);
    string val8 = bst.get(158);
    string val9 = bst.get(12);
    string val10 = bst.get(124);

    if (val0 != "Bravo")
        {
            cout << "Incorrect get result. Expected \"Bravo\" but got : " << val0 << endl;
        }

    if (val1 != "Sierra")
    {
        cout << "Incorrect get result. Expected \"Sierra\" but got : " << val1 << endl;
    }

    if (val2 != "Tango")
    {
        cout << "Incorrect get result. Expected \"Tango\" but got : " << val2 << endl;
    }

    if (val3 != "Quebec")
    {
        cout << "Incorrect get result. Expected \"Quebec\" but got : " << val3 << endl;
    }

    if (val4 != "Victor")
    {
        cout << "Incorrect get result. Expected \"Victor\" but got : " << val4 << endl;
    }

    if (val5 != "Uniform")
    {
        cout << "Incorrect get result. Expected \"Uniform\" but got : " << val5 << endl;
    }

    if (val6 != "Whiskey")
    {
        cout << "Incorrect get result. Expected \"Whiskey\" but got : " << val6 << endl;
    }

    if (val7 != "Oscar")
    {
        cout << "Incorrect get result. Expected \"Oscar\" but got : " << val7 << endl;
    }

    if (val8 != "Zulu")
    {
        cout << "Incorrect get result. Expected \"Zulu\" but got : " << val8 << endl;
    }

    if (val9 != "Hotel")
    {
        cout << "Incorrect get result. Expected \"Hotel\" but got : " << val9 << endl;
    }
    }

    catch (exception &e) {
    cout << "Correctly caught error trying to get key 124 from bst: "
         << e.what() << endl;
    }
}

void test_remove()
{
    try
    {
        int vals[15] = {4, 9, 0, 2, 3, 53, 73, 1, 34, 5, 19, 34, 91, 102, 23};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 15; i++)
        {
            balanced_bst.insert("foobar", vals[i]);
        }

        balanced_bst.remove(34);
        balanced_bst.remove(9);
        balanced_bst.remove(4);
        balanced_bst.remove(2);
        balanced_bst.remove(3);
        balanced_bst.remove(5);
        string bst_str = balanced_bst.to_string();
        if (bst_str != "19 0 53 1 34 73 23 91 102")
        {
            cout << "Incorrect result of removing 34, 9, 4, 2, 3, and 5. Expected 19 0 53 1 34 73 23 91 102 but got : " << bst_str << endl;
        }

        balanced_bst.remove(0);
        balanced_bst.remove(34);
        balanced_bst.remove(1);
        balanced_bst.remove(23);
        balanced_bst.remove(102);
        balanced_bst.remove(19);
        balanced_bst.remove(53);
        balanced_bst.remove(91);
        balanced_bst.remove(73);

        bst_str = balanced_bst.to_string();

        if (bst_str != "") 
        {
            cout << "Incorrect result of removing 0, 34, 1, 23, 102, 19, 53, 91, and 73. Expected an empty list but got : " << bst_str << endl;
        }

        if (!balanced_bst.empty())
        {
            cout << "balanced_bst is incorrectly identified as non-empty." << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Correctly identified error; can't remove key from an empty tree." << e.what() << endl;
    }
}

void test_max_data()
{
    try
    {
        int vals[10] = {1203, 1267, 13459, 2496, 28456, 325864, 926, 2450, 6769, 2456};
        BST<string, int> balanced_bst;

        balanced_bst.insert("Alfa", vals[0]);
        balanced_bst.insert("Bravo", vals[1]);
        balanced_bst.insert("Charlie", vals[2]);
        balanced_bst.insert("Delta", vals[3]);
        balanced_bst.insert("Echo", vals[4]);
        balanced_bst.insert("Foxtrot", vals[5]);
        balanced_bst.insert("Golf", vals[6]);
        balanced_bst.insert("Hotel", vals[7]);
        balanced_bst.insert("India", vals[8]);
        balanced_bst.insert("Juliett", vals[9]);

        
        string max_str = balanced_bst.max_data();
        if (max_str != "Foxtrot")
        {
            cout << "Incorrect result of max_data. Expected \"Foxtrot\" but got : " << max_str << endl;
        }

        balanced_bst.remove(325864);

        string max_str2 = balanced_bst.max_data();
        if (max_str2 != "Echo")
        {
            cout << "Incorrect result of max_data. Expected \"Echo\" but got : " << max_str2 << endl;
        }

        balanced_bst.remove(28456);
        string max_str3 = balanced_bst.max_data();
        if (max_str3 != "Charlie")
        {
            cout << "Incorrect result of max_data. Expected \"Charlie\" but got : " << max_str3 << endl;
        }

        balanced_bst.remove(13459);
        string max_str4 = balanced_bst.max_data();
        if (max_str4 != "India")
        {
            cout << "Incorrect result of max_data. Expected \"India\" but got : " << max_str4 << endl;
        }

        balanced_bst.remove(6769);
        string max_str5 = balanced_bst.max_data();
        if (max_str5 != "Delta")
        {
            cout << "Incorrect result of max_data. Expected \"Delta\" but got : " << max_str5 << endl;
        }

        string min_str = balanced_bst.min_data();
        if (min_str != "Golf")
        {
            cout << "Incorrect result of min_data. Expected \"Golf\" but got : " << min_str << endl;
        }

        balanced_bst.remove(926);
        string min_str2 = balanced_bst.min_data();
        if (min_str2 != "Alfa")
        {
            cout << "Incorrect result of min_data. Expected \"Alfa\" but got : " << min_str2 << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

int main()
{

    string file_name = "usecase.cpp";
    cout << endl
         << "Running tests for " << file_name << endl
         << endl;

    test_insert_CS_classes();
    test_insert_long();
    test_get();
    test_remove();
    test_max_data();
    // test_max_key();
    // test_min_key();
    // test_successor();
    // test_in_order();
    // test_trim();
    // // test_binhex();

    cout << "Testing completed" << endl;

    return 0;
}
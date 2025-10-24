//===========================================
// Andrew Byerly & Colin Nguyen
// October 2025
// BST.cpp
// This file contains all the method 
// definitions of the BST class
//===========================================

#include "BST.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <sstream>
#include <queue>

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

    Node* instance = new Node;
    instance->data = data;
    instance->key = key;
    instance->left = nullptr;
    instance->right = nullptr;
    instance->parent = nullptr;
    root = instance;

}

//===========================================
// Destructor
//===========================================
// template <typename D, typename K>
// BST<D, K>::~BST() {
    
// }

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
    z->key = key;
    z->left = nullptr;
    z->right = nullptr;
    z->parent = nullptr; // initialize new node z to be inserted

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
    
    // initialize Node pointer x for BST traversal
    Node* x = root;

    while (x != nullptr && x->key != key) { // while we haven't found our key or reached a leaf node
        if (key < x->key) { x = x->left; } // left subtree traversal
        else { x = x->right; } // right subtree traversal
    }

    if (x == nullptr || x->key != key) { // if the key wasn't found in the BST, throw an error
        throw std::runtime_error("key doesn't exist within BST.");
    }

    // return data associated with key
    return x->data;

}

//===========================================
// remove
//===========================================
// template <typename D, typename K>
// void BST<D, K>::remove(const K& key) {

    
    // Node* x = root;

    // while (x != nullptr && x->key != key) {
    //     if (key < x->key) { x = x->left; }
    //     else { x = x->right; }
    // }

    // if (x->key != key) {
    //     throw std::runtime_error("Key doesn't exist within BST.")
    // }

    // if (x->parent->left->key == key) { x->parent->left = x->; }
    // else { x->parent->right = x->; }

    // ~x;
    

// }

//===========================================
// max_data
//===========================================
template <typename D, typename K>
D BST<D, K>::max_data(void) {
    Node* x = root;
    if (x != nullptr) { // if we're not working with an empty tree
        while (x->right != nullptr) {
            x = x->right; 
        } // go to the right most leaf node
    }
    return x->data;
}

//===========================================
// max_key
//===========================================
template <typename D, typename K> 
K BST<D, K>::max_key(void) {
    Node* x = root;
    if (x != nullptr) { // if we're not working with an empty tree
        while (x->right != nullptr) {
            x = x->right; 
        } // go to the right most leaf node
    }
    return x->key;
}

//===========================================
// min_data
//===========================================
template <typename D, typename K>
D BST<D, K>::min_data(void) {
    Node* x = root;
    if (x != nullptr) { // if we're not working with an empty tree
        while (x->left != nullptr) {
            x = x->left; 
        } // go to the leftmost leafnode
    }
    return x->data;
}

//===========================================
// min_key
//===========================================
template <typename D, typename K>
K BST<D, K>::min_key(void) {
    Node* x = root;
    if (x != nullptr) { // if we're not working with an empty tree
        while (x->left != nullptr) {
            x = x->left; 
        } // go to the leftmost leaf node
    }
    return x->key;
}

//===========================================
// successor
//===========================================
// template <typename D, typename K>
// K BST<D, K>::successor(const K& key) {

// }

//===========================================
// trim
//===========================================
// template <typename D, typename K> 
// void BST<D, K>::trim(K low, K high) {

// }

//===========================================
// inorder_tree_walk
//===========================================
// template <typename D, typename K>
// void BST<D, K>::inorder_tree_walk(std::stringstream result, Node* x) {
//     if (x != nullptr) {
//         inorder_tree_walk(result, x->left);
//         s << " " << x->key;
//         inorder_tree_walk(result, x->right);
//     }

// }

//===========================================
// to_string
//===========================================
template <typename D, typename K> 
std::string BST<D, K>::to_string(void) const {

    if (root == nullptr) { return ""; } // empty tree case

    std::stringstream s;

    std::queue<Node*> myQueue;
    myQueue.push(root); // start with the root node

    int checkKeys = 1;
    int toRemove = 0; // initialize our tracking variables

    while(checkKeys != 0) { // while there are still nodes to process
         
        toRemove = checkKeys; // number of nodes to remove at this level
        checkKeys = 0; // reset checkKeys for the next level
        
        while (toRemove !=0) { // process all nodes at this level
            Node* x = myQueue.front(); // get the front node
            s << x->key << " "; // add its key to the stringstream
            if (x->left != nullptr) {
                checkKeys++;
                myQueue.push(x->left);
            } // if left child exists, add to queue
            if (x->right != nullptr) {
                checkKeys++;
                myQueue.push(x->right);
            } // if right child exists, add to queue
            myQueue.pop(); // remove the processed node from the queue
            toRemove--; // decrement the count of nodes to remove at this level
        } 
    }

    string result = s.str();
    result.pop_back();  // Remove the trailing space

    return result;
}
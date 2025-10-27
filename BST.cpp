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
template <typename D, typename K>
BST<D, K>::~BST() {

    inorder_walk_destructor(root);

}

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
template <typename D, typename K>
void BST<D, K>::remove(const K& key) {

    if (root == nullptr) {
        throw std::runtime_error("BST is empty.");
    } // Handle empty tree case

    // Find node z with this key
    Node* z = root;
    while (z != nullptr && z->key != key) {
        if (key < z->key) z = z->left;
        else z = z->right;
    }
    if (z == nullptr) {
        throw std::runtime_error("key doesn't exist within BST.");
    } // Handle key not found case

    // Removal Cases
    if (z->left == nullptr) {
        // Case 1: no left child
        transplant(z, z->right);
    }
    else if (z->right == nullptr) {
        // Case 2: no right child
        transplant(z, z->left);
    }
    else {
        // Case 3: two children
        // Find inorder successor y = minimum(z->right)
        Node* y = z->right;
        while (y->left != nullptr) {
            y = y->left;
        }

        if (y->parent != z) {
            // Move y's right child up into y's place
            transplant(y, y->right);

            // Put z->right under y
            y->right = z->right;
            y->right->parent = y;
        }

        // Replace z with y
        transplant(z, y);

        // Put z->left under y
        y->left = z->left;
        y->left->parent = y;
    }

    // Free the removed node
    delete z;
}

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
template <typename D, typename K>
K BST<D, K>::successor(const K& key) {

    Node* x = root; 

    // Find node containing key
    while (x != nullptr && x->key != key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    if (x == nullptr) {
        throw std::runtime_error("Key not found in BST");
    } // handle key not found case

    // Case 1: Right subtree exists -> successor is its min
    if (x->right != nullptr) {
        Node* temp = x->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp->key; // return the key of the successor node
    }

    // Case 2: No right subtree -> go up to first left-ancestor
    Node* successor = x->parent;
    while (successor != nullptr && x == successor->right) {
        x = successor;
        successor = successor->parent;
    }

    if (successor == nullptr) {
        // no successor (ptr was the max element)
        throw std::runtime_error("No successor exists for this key");
    } // handle no left ancestor case

    return successor->key;

}

//===========================================
// in_order
//===========================================
template <typename D, typename K>
std::string BST<D, K>::in_order(void) {

    return inorder_tree_walk(root);

}

//===========================================
// trim
//===========================================
template <typename D, typename K> 
void BST<D, K>::trim(K low, K high) {

    vector<Node*> nodes;
    nodes = arrayify(root, nodes); // get all nodes in vector (in-order traversal)

    for (Node* node : nodes) { // for each node pointer in the vector
        if (node->key < low || node->key > high) { 
            remove(node->key); // remove nodes with keys outside [low, high]
        }
    }

}

//===========================================
// inorder_traversal_destructor
//===========================================
template <typename D, typename K>
void BST<D, K>::inorder_walk_destructor(Node* x) {

    if (x != nullptr) {
        inorder_walk_destructor(x->left);
        delete x;
        inorder_walk_destructor(x->right);
    }

}

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

//===========================================
// transplant
//===========================================
template <typename D, typename K>
void BST<D, K>::transplant(Node* u, Node* v) {
    // Replace subtree rooted at u with subtree rooted at v
    if (u->parent == nullptr) { // u is the root
        root = v;
    }
    else if (u == u->parent->left) { // u is a left child
        u->parent->left = v;
    }
    else { // u is a right child
        u->parent->right = v;
    }

    if (v != nullptr) { // update v's parent if v is not null (prevent dereferencing null pointer)
        v->parent = u->parent;
    }
}

//===========================================
// inorder_tree_walk
//===========================================
template <typename D, typename K>
string BST<D, K>::inorder_tree_walk(Node* x) {

    if (x == nullptr) return ""; // base case

    string left  = inorder_tree_walk(x->left); // traverse left subtree
    string mid   = std::to_string(x->key) + " "; // add current node's key
    string right = inorder_tree_walk(x->right); // traverse right subtree

    return left + mid + right; // concatenate results

}

//===========================================
// arrayify
//===========================================
template <typename D, typename K>
vector<typename BST<D, K>::Node*> BST<D, K>::arrayify(Node* x, vector<Node*>& nodes) {

    if (x != nullptr) {
        arrayify(x->left, nodes);
        nodes.push_back(x); // add the current node to the vector, passing vector by reference
        arrayify(x->right, nodes);
    } // in-order traversal to populate the vector

    return nodes; // return the populated vector
}
#ifndef BST_H
#define BST_H


#define TEMP template <class T>

#include <iostream>
#include <exception>
#include <string>
#include "Compare.h"
#include <vector>

using namespace std;

// Because we're working with templates and templates are 
// translated before compile time, we implement their code here 
// in the header file  

TEMP
class BSTNode {
    private:
        T data;
        BSTNode<T>* left;
        BSTNode<T>* right;

    public:
        BSTNode(T data_in){
            data = data_in;
            left = NULL;
            right = NULL;
        }
        BSTNode(BSTNode &other){
            data = other.data;
            left = other.left;
            right = other.right;
        }
        T getData(){
            return data;
        }
        void displayNode();

    template <class U> friend class BinarySearchTree;
};

TEMP
void BSTNode<T>::displayNode(){
    cout << data <<endl;
}

TEMP
class BinarySearchTree {
    private:
        // Functions
        bool insertIntoTree(T, BSTNode<T>*);
        bool removeRoot();
        void clear(BSTNode<T>*);
        void displayTreeIncOrder(BSTNode<T>*);
        void displayTreeDecOrder(BSTNode<T>*);
        void displayTreeTraversOrder(BSTNode<T>*);
        void getTreeInc(vector<T>&, BSTNode<T>*);
        void getTreeDec(vector<T>&, BSTNode<T>*);
        void getTreeTrav(vector<T>&, BSTNode<T>*);
        BSTNode<T>* find(T, BSTNode<T>*);
        BSTNode<T>* findMin(BSTNode<T>*);
        BSTNode<T>* findMax(BSTNode<T>*);
        BSTNode<T>* deleteNode(T, BSTNode<T>*);
        
        // Variables
        int size;
        BSTNode<T>* root;

    public:
        // Constructors
        BinarySearchTree(){
            size = 0;
            root = NULL;
        }         
        BinarySearchTree(vector<T> in){
            size = 0;
            root = NULL;

            for (T i : in){
                insert(i);
            }
        }
        BinarySearchTree(const BinarySearchTree<T> &);

        // Destructor
        ~BinarySearchTree(){
            clear();
            
        }
        
        // Functions
        int getSize(){
            return size;
        }
        bool insert(T);
        bool balance();
        void remove(T);
        void display(int);
        void clear();
        BSTNode<T>* getRoot(){
            return root;
        }
        vector<T> getTreeInc();
        vector<T> getTreeDec();
        vector<T> getTreeTrav();
       
        
};
// Shallow copy of other tree (only copies the root node)
TEMP
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &other){
    root = new BSTNode<T>(*other.root);
    size = other.size;
}

TEMP
bool BinarySearchTree<T>:: insert(T data_in){
    if (root == NULL){
        root = new BSTNode<T>(data_in);
        size ++;
        return true;
    }
    return insertIntoTree(data_in,root);
}

TEMP 
bool BinarySearchTree<T>::insertIntoTree(T data_in, BSTNode<T>* parent){

    if (Compare<T>::compare(data_in,parent->data) <= 0){
        if (parent->left == NULL){
            parent->left = new BSTNode<T>(data_in);
            size ++;
            return true;
        }
        return insertIntoTree(data_in, parent->left);
    }
    else {
        if (parent->right == NULL){
            parent->right = new BSTNode<T>(data_in);
            size ++;
            return true;
        }
        return insertIntoTree(data_in, parent->right);
    }
}


// Doesn't create the shortest tree possible,

TEMP 
bool BinarySearchTree<T>::balance(){
    vector<T> set = getTreeInc();
    int setSize,
        mid;

    clear();

    while (set.empty() == false){
        setSize = set.size();
        mid = setSize / 2;

        insert(set[mid]);
        
        set.erase(set.begin() + mid ); // removes element of set[mid]
    }

    return true;
}

TEMP
void BinarySearchTree<T>::clear(){
    clear(root);
}

TEMP
void BinarySearchTree<T>::clear(BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    clear(node->left);
    clear(node->right);

    delete node;
    root = NULL;
}

// mode 0   ==> display tree in increasing order
// mode 1   ==> display tree in decreasing order
// mode 2   ==> display tree in traversal order
TEMP
void BinarySearchTree<T>::display(int mode){
    if (root != NULL){
        if (mode == 0){
            displayTreeIncOrder(root);
        }
        else if (mode == 1){
            displayTreeDecOrder(root);
        }
        else if (mode == 2){
            displayTreeTraversOrder(root);
        }
        else
        {
            cout << "Invalid Mode\n";
        }

        cout << endl << endl;
        
    }
    else{
        cout << "EMPTY\n";
    }
    
}

TEMP
void BinarySearchTree<T>::displayTreeIncOrder(BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    displayTreeIncOrder(node->left);
    node->displayNode();
    displayTreeIncOrder(node->right);
}

TEMP
void BinarySearchTree<T>::displayTreeDecOrder(BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    displayTreeDecOrder(node->right);
    node->displayNode();
    displayTreeDecOrder(node->left);
}

TEMP
void BinarySearchTree<T>::displayTreeTraversOrder(BSTNode<T>* node){
    if (node == NULL){
        return;
    }

    displayTreeDecOrder(node->left);
    displayTreeDecOrder(node->right);
    node->displayNode();
}


// returns a vector of the tree in increasing order
TEMP
vector<T> BinarySearchTree<T>::getTreeInc(){
    vector<T> set;
    getTreeInc(set,root);
    return set;
}

TEMP 
void BinarySearchTree<T>::getTreeInc(vector<T> &set, BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    getTreeInc(set,node->left);
    set.push_back(node->data);
    getTreeInc(set,node->right);
}

// returns a vector of the tree in decreasing order
TEMP
vector<T> BinarySearchTree<T>::getTreeDec(){
    vector<T> set;
    getTreeDec(set,root);
    return set;
}

TEMP 
void BinarySearchTree<T>::getTreeDec(vector<T> &set, BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    getTreeInc(set,node->right);
    set.push_back(node->data);
    getTreeInc(set,node->left);
}

TEMP
vector<T> BinarySearchTree<T>::getTreeTrav(){
    vector<T> set;
    getTreeTrav(set,root);
    return set;
}

TEMP 
void BinarySearchTree<T>::getTreeTrav(vector<T> &set, BSTNode<T>* node){
    if (node == NULL){
        return;
    }
    
    getTreeInc(set,node->left);
    getTreeInc(set,node->right);
    set.push_back(node->data);
}


TEMP
BSTNode<T>* BinarySearchTree<T>::find(T data_in, BSTNode<T>* node){
    //Compare<T> comp;

    if (node == NULL){
        return NULL;
    }

    if (Compare<T>::compare(data_in, node ->data) == 0){
        return node;
    }
    else if (Compare<T>::compare(data_in, node->data) < 0){
        return find(data_in, node->left);
    }
    else {
        return find(data_in, node->right);
    }
}


TEMP 
bool BinarySearchTree<T>:: removeRoot(){
    if (root == NULL){
        return false;
    }
    if (root->left != NULL && root->right != NULL){
        BSTNode<T>* largestNode = findMax(root->left);
        T max = largestNode->data;
        root->data = max;
        deleteNode(max, root->left);
    } 
    else if (root->right != NULL){
        root = root->right;
    }  
    else if (root->left != NULL){
        root = root->left;
    }
    else {
        root = NULL;
    }
    size --;
    return true;
}

//  To implement,
//      destructor
TEMP
void BinarySearchTree<T>::remove(T data_in){
    if (Compare<T>::compare(data_in,root->data) == 0){
        removeRoot();
    }
    else {
        deleteNode(data_in, root);
    }
}

TEMP
BSTNode<T>* BinarySearchTree<T>::deleteNode(T data_in, BSTNode<T>* node){
   //BSTNode<T>* temp;

   if (node == NULL){
       return NULL;
   }
   
   if (Compare<T>::compare(data_in, node->data) < 0){
       node->left = deleteNode(data_in,node->left);
   }
   else if (Compare<T>::compare(data_in, node->data) > 0){
       node->right = deleteNode (data_in, node->right);
   }
   else {
       if (node->left == NULL){
           BSTNode<T>* temp = node->right;
           size --;
           free (node);
           return temp;    
       }
       else if (node->right == NULL){
           BSTNode<T>* temp = node->left;
           size --;
           free (node);
           return temp;
       }
        BSTNode<T>* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->data, node->right);
   }

   return node;
}


// Returns the smallest child of node 
TEMP
BSTNode<T>* BinarySearchTree<T>:: findMin(BSTNode<T>* node){
    BSTNode<T>* curr = node;

    while (curr != NULL && curr->left != NULL){
        curr = curr->left;
    }

    return curr;
}

// Returns the largest child of node
TEMP 
BSTNode<T>* BinarySearchTree<T>::findMax(BSTNode<T>* node){
    BSTNode<T>* curr = node;

    while (curr != NULL && curr->left != NULL){
        curr = curr->right;
    }

    return curr;
}


#endif
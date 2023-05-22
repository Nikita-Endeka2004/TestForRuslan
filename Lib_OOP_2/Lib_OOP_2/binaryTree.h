#ifndef _BINARYTREE_
#define _BINARYTREE_
#include "classLib.h"

class BinaryTree : public MyClass {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    BinaryTree();
    ~BinaryTree();
    BinaryTree(const BinaryTree& BinaryTree);
    BinaryTree(int* arr, int size);
    Node* root;
    void constructBST(int* arr, int start, int end);
    void printBT();
    void in_order_traversal(Node* node, int* arr, int& index, bool isLeft);
    void insertArray(Node*& node, int i, int j, Node*& newRoot);
    Node* contains(int value);
    int countNodes(Node* node);
private:
    Node*& lookup(Node* node, int index);
    void bubbleSort(int* arr, int n);
    Node* constructBST(int* arr, int start, int end, Node* node);
    void printBT(const char* prefix, const Node* node, bool isLeft);
    void deleteTree(Node* node);
};
#endif

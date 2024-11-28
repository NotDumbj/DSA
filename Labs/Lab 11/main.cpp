#include<iostream>
#include "BST.h"

using namespace std;

int main()
{
    BinarySearchTree<int> bst;
    bst.InsertItem(50);
    bst.InsertItem(30);
    bst.InsertItem(20);
    bst.InsertItem(40);
    bst.InsertItem(70);

    cout << "Inorder traversal: ";
    cout << bst.PrintTree();

    return 0;
}
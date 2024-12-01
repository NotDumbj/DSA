#include<iostream>
#include "BST.h"

using namespace std;


int main()
{
    BinarySearchTree<int> tree;
    cout << "Simple binary insertion" << endl;
    for(int i = 0; i < 10; i++)
    {
        int a = rand() % 10;
        tree.InsertItem(a);
        cout << a << " ";
    }
    cout << "\n\nEnter the number to find: ";
    int b;
    cin >> b;
    if (tree.RetrieveItem(b))
    {
        cout << "\nNumber found" << endl;
    }
    else
    {
        cout << "\nNumber not found" << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}
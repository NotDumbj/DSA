#include <fstream>

template <class ItemType>
struct TreeNode {
    ItemType info;             // Data stored in the node
    TreeNode<ItemType>* left;  // Pointer to left child
    TreeNode<ItemType>* right; // Pointer to right child
};

template <class ItemType>
class BinarySearchTree {
public:
    BinarySearchTree();                // Constructor to initialize the tree
    bool IsEmpty() const;      // Returns true if the tree is empty
    void InsertItem(ItemType item);  // Insert an item into the tree
    void RetrieveItem(ItemType& item, bool& found);  // Retrieve an item
    void PrintTree(std::ofstream& outFile); // Print the tree contents
    ~BinarySearchTree();  
private:
    TreeNode<ItemType>* root; // Pointer to the root of the tree
    void PrintHelper(TreeNode<ItemType>* ptr, std::ofstream& outFile);
    void RetrieveHelper(TreeNode<ItemType>* ptr, ItemType& item, bool& found); // Helper function for retrieving
    void MakeEmpty();         // Remove all items from the tree
    void MakeEmptyHelper(TreeNode<ItemType>* ptr); // Remove all items from the tree
};

// Constructor to initialize the tree

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() {
    root = nullptr;
}

// Destructor to free memory allocated for the tree

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    MakeEmpty();
}

// Function to check if the tree is empty

template <class ItemType>
bool BinarySearchTree<ItemType>::IsEmpty() const {
    return root == nullptr;
}

// Function to insert an item into the tree

template <class ItemType>
void BinarySearchTree<ItemType>::InsertItem(ItemType item) {
    TreeNode<ItemType>* newNode = new TreeNode<ItemType>;
    newNode->info = item;
    newNode->left = newNode->right = nullptr;
    if (root == nullptr) {
        root = newNode;
    } else {
        TreeNode<ItemType>* current = root;
        TreeNode<ItemType>* parent;
        while (true) {
            parent = current;
            if (item < current->info) {
                current = current->left;
                if (current == nullptr) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;
                if (current == nullptr) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

// Function to retrieve an item from the tree

template <class ItemType>
void BinarySearchTree<ItemType>::RetrieveItem(ItemType& item, bool& found) {
    found = false;
    RetrieveHelper(root, item, found);
}

// Helper function for retrieving

template <class ItemType>
void BinarySearchTree<ItemType>::RetrieveHelper(TreeNode<ItemType>* ptr, ItemType& item, bool& found) {
    if (ptr != nullptr) {
        RetrieveHelper(ptr->left, item, found);
        if (!found) {
            if (ptr->info == item) {
                item = ptr->info;
                found = true;
            }
            RetrieveHelper(ptr->right, item, found);
        }
    }
}

// Function to print the tree contents

template <class ItemType>
void BinarySearchTree<ItemType>::PrintTree(std::ofstream& outFile) {
    PrintHelper(root, outFile);
}

// Helper function for printing

template <class ItemType>
void BinarySearchTree<ItemType>::PrintHelper(TreeNode<ItemType>* ptr, std::ofstream& outFile) {
    if (ptr != nullptr) {
        PrintHelper(ptr->left, outFile);
        outFile << ptr->info << " ";
        PrintHelper(ptr->right, outFile);
    }
}

// Function to remove all items from the tree

template <class ItemType>
void BinarySearchTree<ItemType>::MakeEmpty() {
    MakeEmptyHelper(root);
}


// Helper function for removing

template <class ItemType>
void BinarySearchTree<ItemType>::MakeEmptyHelper(TreeNode<ItemType>* ptr) {
    if (ptr != nullptr) {
        MakeEmptyHelper(ptr->left);
        MakeEmptyHelper(ptr->right);
        delete ptr;
    }
}

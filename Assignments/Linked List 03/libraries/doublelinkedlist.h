typedef struct Node* Nodeptr;

struct Node{
    int data;
    Nodeptr next;
    Nodeptr prev;
};

class DoubleLinkedList{
    private:
        Nodeptr list;
    public:
        int length;
        DoubleLinkedList();
        void traverse();
	    Nodeptr find(int);
        void iAS(int x);
        int dAS();
        void iAE(int x);
        int dAE();
        int iAM(int x, int index);
        int dAM(int index);
        void saveList();
        void loadList();
        void clear();
};
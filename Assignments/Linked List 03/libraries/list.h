typedef struct Node* Nodeptr;

struct Node{
    int data;
    Nodeptr next;
};

class LinkedList{
    private:
        Nodeptr head;
    public:
        int length;
        LinkedList();
        void traverse();
	    Nodeptr find(int);
        void iAS(int x);
        int dAS();
        void iAE(int x);
        int dAE();
        int iAM(int x, int index);
        int dAM(int index);
};
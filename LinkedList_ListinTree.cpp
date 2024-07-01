#include <iostream>
using namespace std;

// Structure for storing data
struct Da {
    string name;
    int weight;
};

// Node of the linked list
struct NODE {
    Da info;
    NODE* pnext;
};

// Linked list structure
struct LIST {
    NODE* phead;
    NODE* ptail;
};

// Initialize an empty linked list
void CreateEmptyList(LIST& l) {
    l.phead = NULL;
    l.ptail = NULL;
}

// Create a new node in the linked list
NODE* CreateNode(Da x) {
    NODE* p;
    p = new NODE;
    if (p == NULL) exit(1);
    p->info = x;
    p->pnext = NULL;
    return p;
}

// Add a new node to the end of the linked list
void AddTail(LIST& L, Da x) {
    NODE* p = CreateNode(x);
    if (L.phead == NULL) {
        L.phead = p;
        L.ptail = L.phead;
    }
    else {
        L.ptail->pnext = p;
        L.ptail = p;
    }
}

// Node of the binary search tree
struct TNODE {
    string name;
    LIST weights;
    TNODE* pLeft;
    TNODE* pRight;
};

typedef TNODE* TREE;

// Create a new tree node
TREE CreateTNode(Da x) {
    TNODE* p = new TNODE;
    if (p == NULL) exit(1);
    p->name = x.name;
    CreateEmptyList(p->weights);
    AddTail(p->weights, x);
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Insert a new node into the binary search tree
void Insert(TREE& T, Da x) {
    if (T == NULL) {
        T = CreateTNode(x);
    }
    else if (x.name < T->name) {
        Insert(T->pLeft, x);
    }
    else if (x.name > T->name) {
        Insert(T->pRight, x);
    }
    else if (x.name == T->name) {
        AddTail(T->weights, x);
    }
}

// Create a binary search tree
void CreateTree(TREE& T) {
    Da x;
    while (true) {
        cin >> x.name;
        if (x.name == "-1") break;
        cin >> x.weight;
        Insert(T, x);
    }
}

// Find the level of a node in the tree
int FindLevel(TREE T, Da y, int level) {
    if (T == NULL) return -1;

    if (T->name == y.name) {
        NODE* p = T->weights.phead;
        while (p != NULL) {
            if (p->info.weight == y.weight) return level;
            p = p->pnext;
        }
    }

    if (y.name < T->name) {
        return FindLevel(T->pLeft, y, level + 1);
    }
    else {
        return FindLevel(T->pRight, y, level + 1);
    }
}

// Print the level and count of nodes in the tree
void PrintLevel(TREE T, Da y) {
    int level = FindLevel(T, y, 1);
    int count = 0;
    bool firstcnt=false;
    while (T != NULL) {
        if (T->name == y.name) {
            NODE* p = T->weights.phead;
            while (p != NULL) {
                count++;
                if (p->info.weight == y.weight) break;
                p = p->pnext;
            }
        }

        if (y.name < T->name) {
            T = T->pLeft;
        } else {
            T = T->pRight;
        }
    }

    cout << level << " " << count-1<< endl;
}

// Main function
int main() {
    TREE T = NULL;
    CreateTree(T);

    Da y;
    cin >> y.name >> y.weight;
    PrintLevel(T, y);
    return 0;
}

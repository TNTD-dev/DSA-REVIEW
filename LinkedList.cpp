#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Create node
struct NODE {
    int info;
    NODE* pnext;
};
// Create single liked list
struct LIST {
    NODE* phead;
    NODE* ptail;
};

// Create empty linked list

void CreateEmptyList(LIST& l) {
    l.phead = NULL;
    l.ptail = NULL;
};

// Create node

NODE* CreateNode(int x) {
    NODE* p;
    p = new NODE;
    if (p == NULL) exit(1);
    p->info = x;
    p->pnext = NULL;
    return p;
}

// Insert at the begining

void AddHead(LIST& L, NODE* p) {
    if (L.phead == NULL) {
        L.phead = p;
        L.ptail = L.phead;
    }
    else {
        p->pnext = L.phead;
        L.phead = p;
    }
}

// Insert at the end 

void AddTail(LIST& L, NODE* p) {
    if (L.phead == NULL) {
        L.phead = p;
        L.ptail = L.phead;
    }
    else {
        L.ptail->pnext = p;
        L.ptail = p;
    }
}

// Insert at a specific position after Q

void AddAfterQ(LIST& L, NODE* p, NODE* Q) {
    if (Q != NULL) {
        p->pnext = Q->pnext;
        Q->pnext = p;
        if (L.ptail == Q) L.ptail = p;
    }
}


// Delete at the begining 

bool RemoveHead(LIST& L, int& x) {
    NODE* p;
    if (L.phead != NULL) {
        x = L.phead->info;
        p = L.phead;
        L.phead = L.phead->pnext;
        if (L.phead == NULL) L.ptail = NULL;
        delete p;
        return 1; // deleted
    }
    return 0;
}

// Delete at a specific position after Q

bool RemoveAfterQ(LIST& L, NODE* Q, int& x) {
    NODE* p;
    if (Q != NULL) {
        p = Q->pnext;
        if (p != NULL) {
            if (p == L.ptail) L.ptail = Q;
            Q->pnext = p->pnext;
            x = p->info;
            delete p;
        }
        return 1;
    }

    return 0;
}

// Delete at key x

bool RemoveX(LIST& L, int x) {
    NODE* Q, * p;
    Q = NULL;
    p = L.phead;
    while (p != NULL && p->info != x) {
        Q = p;
        p = p->pnext;
    }
    if (p == NULL) return 0 // Not search x;
        if (Q != NULL) RemoveAfterQ(L, Q, x);
        else RemoveHead(L, x);
    return 1;
}

// Searching
// return not NULL is searched
// return NULL is not search
NODE* SearchNode(LIST L, int x) {
    NODE* p = L.phead;
    while (p != NULL && p->info != x) p = p->pnext;
    return p;
}

// Delete all list
void RemoveList(LIST& L) {
    NODE* p;
    while (L.phead != NULL) {
        p = L.phead;
        L.phead = p->pnext;
        delete p;
    }
    L.ptail = NULL;
}


// Traversal

void PrintList(LIST L) {
    NODE* p;
    if (L.phead ==NULL) cout << "DSLK rong." << endl;
    else {
        p = L.phead;
        while (p) {
            cout << p->info << " ";
            p = p->pnext;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


    return 0;
}
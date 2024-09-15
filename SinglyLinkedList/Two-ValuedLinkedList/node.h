#ifndef NODE_H
#define NODE_H

struct Node {
    int a;
    int b;
    struct Node* next;
};

struct Node* createPairNode(int a, int b);
void printList(struct Node* node);
void addFront(struct Node* head, struct Node* node);

#endif

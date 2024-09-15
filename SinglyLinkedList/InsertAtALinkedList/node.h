#ifndef NODE_H
#define NODE_H

struct Node {
    int value;
    struct Node* next;
};

Node* createNode(int value);
void insertAtPos(Node* linkedList, int newValue, int pos);
void printList(Node* head);

#endif

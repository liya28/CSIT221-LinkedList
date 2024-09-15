#ifndef NODE_H
#define NODE_H

struct Node {
    int value;
    Node* next;
};

Node* addNode(Node* head, int value);
void printList(Node* head);

#endif

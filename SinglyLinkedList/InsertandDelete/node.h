#ifndef NODE_H
#define NODE_H

struct Node {
    int value;
    struct Node* next;
};

void printList(struct Node* node);
struct Node* addNode(struct Node* node, int value);
void insertAtPos(struct Node* head, int newValue, int pos);
void deleteAtPos(struct Node* linkedList, int pos);

#endif

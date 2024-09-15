#include "node.h"
#include <iostream>

using namespace std;

struct Node *createPairNode (int a, int b)
{
    if (a > b)
        swap(a, b);
    
    Node *newNode = new Node;
    newNode->a = a;
    newNode->b = b;
    newNode->next = nullptr;
    
    return newNode;
}

void printList(struct Node *node)
{
    while (node != nullptr)
    {
        cout << "(" << node->a << ", " << node->b << ")";
        if (node->next != nullptr)
        {
            cout << " -> ";
        }
        node = node->next;
    }
    
    cout << endl;
}

void addFront(struct Node *head, struct Node *node)
{
    node->next = head->next;
    head->next = node;
}

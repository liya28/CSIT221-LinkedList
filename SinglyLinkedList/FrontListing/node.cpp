#include "node.h"
#include <iostream>

using namespace std;

Node* addNode(Node* head, int value) 
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    
    return head;
}

void printList(Node* head) 
{
    Node *current = head;
    bool first = true;
    
    while (current != nullptr)
    {
        if (current->value != 0)
        {
            if (!first)
                cout << " -> ";
            cout << current->value;
            first = false;
        }
        current = current->next;
    }
}

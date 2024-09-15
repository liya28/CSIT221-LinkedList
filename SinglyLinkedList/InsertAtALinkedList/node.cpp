#include "node.h"
#include <iostream>

using namespace std;

void insertAtPos(Node*& linkedList, int newValue, int pos) 
{
    Node *newNode = createNode(newValue);
    
    if (pos == 0)
    {
        newNode->next = linkedList->next;
        linkedList->next = newNode;
        return;
    }
    
    Node *current = linkedList->next;
    int current_pos = 0;
    
    while (current != nullptr && current_pos < pos - 1)
    {
        current = current->next;
        current_pos++;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

void printList(Node* head) 
{
    Node *current = head->next;
    bool first = true;
    while (current != nullptr)
    {
        if (!first)
        {
            cout << " -> ";
        }
        cout << current->value;
        first = false;
        current = current->next;
    }
}

// Do not modify
Node* createNode(int value) {
    Node* newNode = new Node;
    if (newNode == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        exit(1);
    }
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

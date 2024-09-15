#include "node.h"
#include <iostream>

using namespace std;

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->value;
        node = node->next;
        if (node != nullptr)
        {
            cout << " -> ";
        }
    }
}

Node *addNode(Node *node, int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    
    if (node == nullptr)
        return newNode;
        
    Node *current = node;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    
    return newNode;
}

void insertAtPos(Node *head, int newValue, int pos)
{
    Node *newNode = new Node;
    newNode->value = newValue;
    
    if (pos == 0)
    {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }
    
    Node *current = head->next;
    Node *prev = head;
    int curr_pos = 0;
    
    while (current != nullptr && curr_pos < pos)
    {
        prev = current;
        current = current->next;
        curr_pos++;
    }
    
    if (curr_pos != pos)
    {
        cout << "Out of bounds.";
        return;
    }
    
    newNode->next = prev->next;
    prev->next = newNode;
    
    return;
}

void deleteAtPos(Node *linkedList, int pos)
{
    if (linkedList == nullptr || linkedList->next == nullptr)
    {
        cout << "List empty.";
        return;
    }
    
    Node *current = linkedList->next;
    Node *prev = linkedList;
    
    if (pos == 0)
    {
        linkedList->next = current->next;
        delete current;
        return;
    }
    
    int curr_pos = 0;
    
    while (current != nullptr && curr_pos < pos)
    {
        prev = current;
        current = current->next;
        curr_pos++;
    }
    
    if (current == nullptr)
    {
        cout << "Out of bounds.";
        return;
    }
    
    prev->next = current->next;
    delete current;
    
    return;
}

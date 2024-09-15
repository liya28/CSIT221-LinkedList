#include <iostream>
#include "node.h"

void freeLinkedList(Node* head);

int main() {
    // Create the head node
    Node* linkedList = createNode(0);

    // Manually connect the linked lists
    Node* node1 = createNode(5);
    linkedList->next = node1;

    Node* node2 = createNode(3);
    node1->next = node2;

    Node* node3 = createNode(22);
    node2->next = node3;

    Node* node4 = createNode(100);
    node3->next = node4;

    Node* node5 = createNode(-10);
    node4->next = node5;

    Node* node6 = createNode(55);
    node5->next = node6;

    Node* node7 = createNode(-7);
    node6->next = node7;

    std::cout << "Original linked list:" << std::endl;
    printList(linkedList);
    std::cout << std::endl;

    int num1, num2, pos;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter position: ";
    std::cin >> pos;

    // Insert num1 and num2 in ascending order at the specified position
    Node* current = linkedList;
    int i = 0;
    while (i < pos && current != nullptr) {
        current = current->next;
        i++;
    }

    if (current != nullptr) {
        Node* newNode1 = createNode(num1);
        newNode1->next = current->next;
        current->next = newNode1;

        Node* newNode2 = createNode(num2);
        newNode2->next = newNode1->next;
        newNode1->next = newNode2;
    }

    // Display all the values of the linked list
    printList(linkedList);

    // Delete the linked list from memory
    freeLinkedList(linkedList);

    return 0;
}

void freeLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

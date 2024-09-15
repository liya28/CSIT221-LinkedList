#include <iostream>
#include "node.h"

int main() {
    // Create the head node
    Node* linkedList = new Node;
    linkedList->value = 0;
    linkedList->next = nullptr;

    int newValue;

    do {
        std::cout << "Enter an integer: ";
        std::cin >> newValue;

        if (newValue != 0) {
            linkedList = addNode(linkedList, newValue);
        }
    } while (newValue != 0);

    // Display the values of the linked list
    printList(linkedList);

    // Delete the linked list from memory
    Node* nextNode = linkedList->next;

    while (linkedList != nullptr) {
        delete linkedList;
        linkedList = nextNode;

        if (nextNode != nullptr) {
            nextNode = nextNode->next;
        }
    }

    return 0;
}

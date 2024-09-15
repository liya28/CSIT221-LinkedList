#include <iostream>
#include "node.h"

int main() {
    Node* linkedList = new Node;

    Node* node1 = addNode(linkedList, 5);
    Node* node2 = addNode(node1, 3);
    Node* node3 = addNode(node2, 22);
    Node* node4 = addNode(node3, 100);
    Node* node5 = addNode(node4, -10);
    Node* node6 = addNode(node5, 55);
    Node* node7 = addNode(node6, -7);

    std::cout << "Original linked list:" << std::endl;
    printList(linkedList->next);
    std::cout << std::endl;

    int num1, num2, pos, posToDelete;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter position: ";
    std::cin >> pos;

    std::cout << "Enter position to delete: ";
    std::cin >> posToDelete;

    deleteAtPos(linkedList, posToDelete);

    insertAtPos(linkedList, num1, pos);
    insertAtPos(linkedList, num2, pos);

    // Display all the values of the linked list
    printList(linkedList->next);

    return 0;
}

#include <iostream>
#include "node.h"

int main() {
    // Create the head node
    Node* linkedList = new Node;

    int n, a, b;

    std::cout << "Enter number of pairs: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Enter pair " << i + 1 << ":\n";
        std::cin >> a >> b;
        std::cout << "\n";

        addFront(linkedList, createPairNode(a, b));
    }

    printList(linkedList->next);
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

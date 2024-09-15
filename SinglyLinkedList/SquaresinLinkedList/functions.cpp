#include <iostream>
#include "functions.h"

using namespace std;

void printSquaredValues(Node* node) {
    node = node->next;
    
    cout << node->value * node->value;
    node = node->next;
    
    while (node != nullptr)
    {
        cout << " -> " << node->value * node->value;
        node = node->next;
    }
    return;
}

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    
    Node (int value) : data(value), next(nullptr) {}
};

class LinkedList
{
    private:
        Node *head;
    public:
        LinkedList() : head(nullptr) {}
        
        void addNode(int newData, bool addToEnd)
        {
            Node *newNode = new Node(newData);
            
            if (addToEnd)
            {
                if (head == nullptr)
                {
                    head = newNode;
                }
                else
                {
                    Node *current = head;
                    while (current != nullptr && current->next != nullptr)
                    {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        
        int countNodes()
        {
            int count = 0;
            Node *current = head;
            while (current != nullptr && current->next != nullptr)
            {
                count++;
                current = current->next;
            }
            return count;
        }
        
        void swapNodes()
        {
            Node *dummyNode = new Node(0);
            dummyNode->next = head;
            
            Node *prevNode = dummyNode;
            Node *currentNode = head;
            
            while (currentNode != nullptr && currentNode->next != nullptr)
            {
                Node *nextNode = currentNode->next;
                currentNode->next = nextNode->next;
                nextNode->next = currentNode;
                prevNode->next = nextNode;
                
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            
            head = dummyNode->next;
            delete dummyNode;
        }
        
        void printList()
        {
            Node *current = head;
            while (current != nullptr && current->next != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
        }
};




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
                    head = newNode;
                else
                {
                    Node *current = head;
                    while (current->next != nullptr)
                    {
                        current = current->next;
                    }
                    current->next = newNode;
                    newNode->next = nullptr;
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
            while (current != nullptr)
            {
                count++;
                current = current->next;
            }
            return count;
        }
        
        void printList()
        {
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
        }
};

int main()
{
    LinkedList myList;

    int choice = 1;

    while (choice)
    {
        cout << "Enter data for the node: ";
        int data;
        cin >> data;
        
        cout << "Add to end (1) or start (0)? ";
        bool addToEnd;
        cin >> addToEnd;
        
        myList.addNode(data, addToEnd);   

        cout << "Do you want to add more? ";
        cin >> choice;

        cout << endl;
    }
    
    int totalNodes = myList.countNodes();
    cout << "Total number of nodes: " << totalNodes << endl;
    
    cout << "Data:" << endl;
    
    myList.printList();
    
    return 0;
}


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
        Node *head1;
        Node *head2;
    public:
        LinkedList() : head1(nullptr), head2(nullptr) {}
        
        ~LinkedList()
        {
            clearList(head1);
            clearList(head2);
        }

        void clearList(Node *&head)
        {
            Node *current = head;
            while (current != NULL)
            {
                Node *nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
        }
        
        void addNode(int data, bool listNum)
        {
            Node *&head = (listNum) ? head1 : head2;
            Node *newNode = new Node(data);
            
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                Node *currentNode = head;
                while (currentNode->next != nullptr)
                {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
        }
        
        void printList(bool listNum)
        {
            Node *head = (listNum) ? head1 : head2;
            Node *currentNode = head;
            while (currentNode != nullptr)
            {
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
        
        bool isNodeThere(int value)
        {    
            if (head1 == nullptr) return false;
            if (head1->data == value || head1->next->data == value) return true;
        
            Node *current = head1;
            
            while (current != nullptr)
            {
                if (current->data == value)
                    return true;
                current = current->next;
            }
            return false;
        }
};

int main()
{
    LinkedList myList;
    
    int size;
    cout << "Enter elements of the list: ";
    cin >> size;
    
    int data;
    cout << "List:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element: ";
        cin >> data;
        myList.addNode(data, 1);
    }
    
    cout << "Enter value to find: ";
    cin >> data;

    int res = myList.isNodeThere(data);

    (res) ? cout << "Found" : cout << "Not Found";
    
    return 0;
}

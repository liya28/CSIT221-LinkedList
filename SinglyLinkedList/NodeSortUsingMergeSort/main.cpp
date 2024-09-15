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
        
        void addNode(int data)
        {
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
        
        void printList()
        {
            Node *currentNode = head;
            while (currentNode != nullptr)
            {
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
        
        void split_list(Node *source, Node *&a, Node *&b)
        {
            if (source == nullptr || source->next == nullptr)
            {
                a = source;
                b = nullptr;
                return;
            }
            
            Node *slow = source;
            Node *fast = source->next;
            
            while (fast != nullptr)
            {
                fast = fast->next;
                if (fast != nullptr)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            
            a = source;
            b = slow->next;
            slow->next = nullptr;
        }
        
        Node *sorted_list(Node *a, Node *b)
        {
            Node *result = nullptr;
            
            if (a == nullptr)
                return b;
            if (b == nullptr)
                return a;
                
            if (a->data <= b->data)
            {
                result = a;
                result->next = sorted_list(a->next, b);
            }
            else
            {
                result = b;
                result->next = sorted_list(a, b->next);
            }
            return result;
        }
        
        void merge_sort_helper(Node *&head)
        {
            if (head == nullptr || head->next == nullptr) return;
            
            Node *a;
            Node *b;
            
            split_list(head, a, b);
            
            merge_sort_helper(a);
            merge_sort_helper(b);
            
            head = sorted_list(a, b);
        }
        
        void merge_sort()
        {
            merge_sort_helper(head);
        }
};

int main()
{
    LinkedList myList;
    
    int size;
    cout << "Enter elements of the list: ";
    cin >> size;
    
    int data;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element: ";
        cin >> data;
        myList.addNode(data);
    }
    
    cout << "Original list: ";
    myList.printList();
    
    myList.merge_sort();
    
    cout << "Sorted list: ";
    myList.printList();
    
    return 0;
}

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
        
        bool isPalindrome()
        {
            if (head1 == nullptr || head1->next == nullptr) return true;

            Node *slow = head1;
            Node *fast = slow->next;

            while (fast != nullptr)
            {
                fast = fast->next;
                if (fast != nullptr)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            
            Node *current = slow;
            Node *previous = nullptr;
            while (current != nullptr)
            {
                Node *next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            Node *firstHalf = head1;
            Node *secondHalf = previous;

            while (secondHalf != nullptr)
            {
                if (firstHalf->data != secondHalf->data)
                    return false;
                firstHalf = firstHalf->next;
                secondHalf = secondHalf->next;
            }

            return true;
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
    
    int res = myList.isPalindrome();

    (res) ? cout << "It is a palindrome" : cout << "It is not a palindrome";    
    
    return 0;
}

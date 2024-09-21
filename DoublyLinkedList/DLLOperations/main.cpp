#include "dlinkedlist.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
	DList *list = new DLinkedList();
	
	int op;
	int num;
	int pos;
	
	do
	{
		cout << "\nCHOOSE\n";
		cout << "1. Add at First\n";
		cout << "2. Add at End\n";
		cout << "3. Remove First\n";
		cout << "4. Remove Last\n";
		cout << "5. Insert at Pos\n";
		cout << "6. Remove at Pos\n";
		cout << "7. Remove All\n";
		cout << "8. Reverse List\n";
		cout << "9. Get Size\n";
		cout << "10. Print List\n";
		cout << "11. Exit\n";
		cout << "Enter your choice: ";
		cin >> op;
		
		switch(op)
		{
			case 1:
				cout << "Enter a number: ";
				cin >> num;
				list->addNodeAtBeg(num);
				break;
			case 2:
				cout << "Enter a number: ";
				cin >> num;
				list->addNodeAtEnd(num);
				break;
			case 3:
				cout << "Removing...";
				cout << "Removed First: " << list->removeFirst() << endl;
				break;
			case 4:
				cout << "Removing...";
				cout << "Removed Last: " << list->removeLast() << endl;
				break;
			case 5:
				cout << "Enter pos to insert: ";
				cin >> pos;
				cout << "Enter num: ";
				cin >> num;
				cout << "Inserting...\n";
				list->insertAtPos(num, pos);
				break;
			case 6:
				cout << "Enter pos to remove: ";
				cin >> pos;
				cout << "Removed " << list->removeAtPos(pos) << endl;
				break;
			case 7:
				cout << "Enter num to remove all its instances: ";
				cin >> num; 
				cout << "Instances of " << num << ": " << list->removeAll(num) << endl;
				break;
			case 8:
				cout << "Reversing... ";
				list->reverse();
				break;
			case 9:
				cout << "Getting the size...\n";
				cout << "Current size: " << list->getSize() << endl;
				break;
			case 10:
				cout << "Printing...\n";
				list->print();
				break;
			case 11:
				cout << "Exiting...\n";
				return 0;
			default:
				cout << "INVALID\n";
				break;
		}
	} while (op != 11);
	return 0;
}

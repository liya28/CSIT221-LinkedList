#include "node.h"

class DList
{
	public:
		virtual void addNodeAtBeg(int num) = 0;
		virtual void addNodeAtEnd(int num) = 0;
		virtual int removeFirst() = 0;
		virtual int removeLast() = 0;
		virtual void insertAtPos(int num, int pos) = 0; 
		virtual int removeAtPos(int pos) = 0;
		virtual int removeAll(int num) = 0;
		virtual void reverse() = 0;
		virtual int getSize() = 0;		
		virtual void print() = 0;
};

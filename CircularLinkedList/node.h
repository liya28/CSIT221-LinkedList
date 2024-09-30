#include <iostream>
#include "person.h"

struct node
{
	Person* person;
	node *prev;
	node *next;
};

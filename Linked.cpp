#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;						// Every node contains a pointer of its 'datatype'.
};									// So every node can be linked with another node by pointing at the succeeding node, hence forming linked list.
void add(node*&, int);
int main()
{
	node* head = NULL;				// This means an empty list. This pointer does not point towards any node
	for (int i = 0; i < 10; i++)    // A loop to generate a linked list.
	{
		add(head, i);				// The function adds nodes to the list
	}
	return 0;
}

void add(node*& h, int data1)
{
	if (h == NULL)					// Firstly checks if head is not pointing towards a node.
	{
		h = new node;				// In that case, a new node is generated using dynamic allocation
		h->data = data1;			// Placing data in the new node
		h->next = NULL;				// As it is then the only node on the list, it should not point to any node. Hence its pointer
									//is set to NULL.
	}
	else                            //If it is pointing towards a node, then
	{
		node *curr = new node;		//We make an isolated node
		curr->data = data1;			//Add its data
		curr->next = NULL;			//Set its pointer to NULL, as it is the node to be added to the list
		node* h_reset = h;			
		while (h->next != NULL)		//In order to link the new node to the list, head should point towards the last node on the list.
			h = h->next;			//This loop is used to reach there
		h->next = curr;				//Here, the new node is linked with the previously last node in the list
		h = h_reset;				//Finally, head is reassigned its initial value. 
}
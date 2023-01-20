#include <iostream>
using namespace std;

/**
 * struct node - doubly linked list representation.
 * @data: the integer stored at the node.
 * @prev: a pointer to the previous element of the list.
 * @next: a pointer to the next element of the list.
 *
 * Description: doubly linked list node structure for our assignment.
 */
struct node
{
	int data;
	node *prev;
	node *next;
};

struct node *head = NULL;

/**
 * insert_at_start - a function that inserts new node (new member) at the start of doubly linked list.
 * @value: a data value that a new node holds.
 *
 * Return: nothing.
 */
void insert_at_start(int value)
{
	struct node *new_node = new node();

	new_node->data = value;

	if (!head)
	{
		new_node->prev = new_node->next = new_node;
		head = new_node;
	}
	else
	{
		struct node *last_node = head->prev;

		new_node->prev = last_node;
		new_node->next = head;
		last_node->next = new_node;
		head->prev = new_node;
		head = new_node;
	}
}
/**
 * insert_at_end - a function that inserts new node(new member) at the end of doubly linked list.
 * @value: a data value that a new node holds.
 *
 * Return: nothing.
 */
void insert_at_end(int value)
{
	node *new_node = new node(); // create a node

	new_node->data = value; // allocate a dat for new node.

	if (!head) // if head pointer is null.
	{
		new_node->next = new_node->prev = new_node;
		head = new_node;
	}
	else // if head points to a linked list.
	{
		node *last_node = head->prev;
		new_node->next = head;
		head->prev = new_node;
		new_node->prev = last_node;
		last_node->next = new_node;
	}
}
/**
 * insert_at_index - a function that inserts new node(member) at specific index.
 * @value: a data value that a new node holds.
 * @index: an index position of linked list.(starting from 0 - n).
 *
 * Return: nothing.
 */
void insert_at_index(int value, int index)
{
	struct node *new_node;
	struct node *at_node;
	int i = 0;

	if (head)
	{
		at_node = head;
		while (at_node->next != head && i != index)
		{
			i++;
			at_node = at_node->next;
		}
		if (i == index)
		{
			new_node = new node();

			new_node->data = value;
			new_node->next = at_node;
			new_node->prev = at_node->prev;
			at_node->prev->next = new_node;
			at_node->prev = new_node;
			if (i == 0)
			{
				head = new_node;
			}
		}
	}
}
/**
 * delete_at_start - deletes first node of the doubly linked list.
 *
 * Return: nothing.
 *
 */
void delete_at_start()
{
	if (head)
	{
		struct node *to_be_deleted = head;

		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		free(to_be_deleted);
	}
}
/**
 * delete_at_end - deletes last node of the doubly linked list.
 *
 * Return: nothing.
 */
void delete_at_end()
{
	if (head)
	{
		struct node *to_be_deleted = head->prev;

		to_be_deleted->prev->next = to_be_deleted->next;
		to_be_deleted->next->prev = to_be_deleted->prev;
		free(to_be_deleted);
	}
}
/**
 * delete_at_index - deletes node at a specific position.
 * @index: position of the node(0 to n, just like array)
 *
 * Return: nothing.
 *
 */
void delete_at_index(int index)
{
	struct node *at_node = head;
	int i = 0;

	if (head)
	{
		if (index == 0)
		{
			head = at_node->next;
			at_node->next->prev = at_node->prev;
			at_node->prev->next = at_node->next;
			free(at_node);
			return;
		}
		while (at_node->next != head && i != index)
		{
			i++;
			at_node = at_node->next;
		}
		if (i == index)
		{
			at_node->prev->next = at_node->next;
			at_node->next->prev = at_node->prev;
			free(at_node);
		}
	}
}
/**
 * display - prints data values of doubly linked list.
 *
 * Return: nothing.
 */
void display()
{
	struct node *temp = head;

	while (temp->next != head)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}

/**
 * main - Entry point for our program.
 *
 * Return: 0 for success.
 */
int main(void)
{
	cout << "------------------------------------------------------------------------------------\n";
	cout << "************************DOUBLY CIRCULAR LINKED LIST*********************************\n\n";
	cout << "list values after inserting (1, 2, 3, 4) in our linked list:\n";

	for (int i = 1; i < 5; i++)
	{
		insert_at_end(i);
	}
	display();
	cout<<endl;
	cout<<"list values after inserting value (5) at the end of the list:\n";
	insert_at_end(5);
	display();
	cout<<endl;
	cout<<"list of values after inserting value (0) at the front of the list:\n";
	insert_at_start(0);
	display();
	cout<<endl;
	cout<<"lets insert value (9) at position 3(which array like) and display:\n";
	insert_at_index(9, 3);
	display();
	cout<<endl;
	cout<<"lets remove the first node and display:\n";
	delete_at_start();
	display();
	cout<<endl;
	cout<<"lets remove the last node and display:\n";
	delete_at_end();
	display();
	cout<<endl;
	cout<<"lets delete a value at a position 2 and display:\n";
	delete_at_index(2);
	display();
	cout<<endl;

	cout << "************************THE END*********************************\n";
	cout<<"------------------------------------------------------------------\n";
	return 0;
}

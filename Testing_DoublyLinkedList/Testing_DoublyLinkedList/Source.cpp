#include <iostream>
using namespace std;

struct node
{
	int data;
	node*next;
	node*prev;

	node()
	{
		next = NULL;
		data = 0;
	}
};
struct DoublyLinkedList
{
	node *head;
	node *tail;

	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}	
	~DoublyLinkedList()
	{
		node *t;
		while (head != NULL)
		{
			t = head;
			head = head->next;
			delete t;
		}
		tail = NULL;
	}

	void InsertAtStart(int num)
	{
		node *temp = new node;
		temp->data = num;

		if (head == NULL)
		{
			
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			tail = temp;
		}

		else
		{
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;
		}
	}
	void InsertAtEnd(int num)
	{

		node *temp = new node;
		temp->data = num;

		if (head == NULL)
		{
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			tail = temp;

			//or just call insAtStart(val);
			
		}

		else
		{
			temp->prev = tail;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}
	}
	void DeleteAtEnd()
	{

		if (head == NULL)
		{

			cout << "linklist empty" << endl;
		}

		else if (head->next == NULL)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}

		else
		{
			node *temp;
			temp = tail->prev;
			delete tail;
			tail = temp;
			temp->next = NULL;
		}
	}
	void DeleteAtStart()
	{
		if (head == NULL)
		{
			cout << "empty" << endl;
		}

		else if (head->next == NULL)
		{
			DeleteAtEnd();
		}
		else
		{
			node *temp = head;
			head = head->next;
			delete temp;
			head->prev = NULL;
		}
	}
	int TotalNodes()
	{
		int num=0;
		node *temp = head;
		while (temp != tail)
		{
			temp = temp->next;
			num++;
		}
		return num;
	}
	void InsertAtAnyPosition(int val, int position)
	{	

		if (position > TotalNodes())
		{
			cout << "position does not exist " << endl;
		}
		else if (position == TotalNodes() + 1)
		{
			InsertAtEnd(val);
		}
		else if (position == 1)
		{
			InsertAtStart(val);
		}
		else
		{
			node *temp;
			int count = 1;
			while (count < position - 1)
			{
				temp = temp->next;
			}

			node *n;

			n->next = temp->next;
			n->prev = temp;
			temp->next = n;
			n->next->prev = n;
		}
	}
	void DeleteAtAnyPosition(int position)
	{
		if (TotalNodes() < position)
		{
			cout<<"Enter another position\n";
		}
		else if (position == 1)
			DeleteAtStart();
		else if (position == TotalNodes())
			DeleteAtEnd();
		else
		{
			node *temp;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}

	}
	void DisplayDoublyLinkedList()
	{
	//Traversion
		node *temp = head;
		while (temp != NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	}
};
void main()
{
	DoublyLinkedList a;
	a.InsertAtStart(2);
	a.InsertAtStart(3);
	a.InsertAtEnd(1);
	a.InsertAtAnyPosition(4,2);
	a.DisplayDoublyLinkedList();
	a.DeleteAtAnyPosition(5);


}
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
struct Dlinkedlist
{
	node *head;
	node *tail;

	Dlinkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	void insAtStart(int val)
	{
		node *temp = new node;
		temp->data = val;
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
	void insAtEnd(int val)
	{
		node *temp = new node;
		temp->data = val;
		if (head == NULL)
		{
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			tail = temp;
		}
		else
		{
			temp->prev = tail;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}
	}
	void delAtEnd()
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

	void delAtStart()
	{
		if (head == NULL)
		{
			cout << "empty" << endl;
		}
		else if (head->next == NULL)
		{
			delAtEnd();
		}
		else
		{
			node *temp = head;
			head = head->next;
			delete temp;
			head->prev = NULL;
		}
	}

	int countNodes()
	{

	}

	void insAtAnyPos(int val, int pos)
	{

		if (pos > countNodes())
		{
			cout << "position does not exist " << endl;
		}
		else if (pos == countNodes() + 1)
		{
			insAtEnd(val);
		}
		else if (pos == 1)
		{
			insAtStart(val);
		}
		else
		{
			node *temp;
			int count = 1;
			while (count < pos - 1)
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
	void delAtAnyPos(int val, int pos)
	{
		if (pos == 1)
			delAtStart();
		if (pos == countNodes())
			delAtEnd();
		if (countNodes() < pos)
		{
			node *temp;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
	void display()
	{	
		node*temp=head;
		while (temp->next != NULL)
		{
			cout << temp->data;
			temp = temp->next;
		}
	}
	~Dlinkedlist()
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
};
void main()
{
	Dlinkedlist A;
	A.insAtStart(2);
	A.insAtStart(3);
	A.insAtStart(4);
	A.insAtStart(5);
	A.display();
	system("pause");
}
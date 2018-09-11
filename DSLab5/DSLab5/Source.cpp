#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *nextnodepointer;	
};

struct Queue
{
	Node* Headpointer;
	Node* Tailpointer;

	Queue()
	{
		Headpointer = NULL;
		Tailpointer = NULL;
	}

	bool IsEmpty()
	{
		if (Headpointer==NULL)
		{
			//cout<<"Queue is empty.\n";
			return 1;
		}
		else
		{
			//cout<<"Queue isn't empty.\n";
			return 0;
		}
	}

	void InsertAtEnd(int num)
	{
		Node*a= new Node;
		a->nextnodepointer= NULL;
		a->data=num;

		if (IsEmpty() == 1)
		{
			Headpointer=a;
			Tailpointer=a;
		}

		if (IsEmpty() == 0)
		{
		Tailpointer->nextnodepointer=a;
		Tailpointer=a;
		}
	}

	void DeleteAtStart()
	{
		Node *temp = Headpointer;
		Headpointer=temp->nextnodepointer;	
		delete temp;
		temp = NULL;
	}

	void DisplayAtTop()
	{
			Node *temp = Headpointer;
			cout<<temp->data<<endl;
	}

	/*~Queue()
	{
		Node *temp = Headpointer;
		while (Headpointer != NULL)
		{
			temp=Headpointer;
			Headpointer=temp->nextnodepointer;
			delete temp;
			temp=NULL;
			cout<<"Destructor called\n";
		}
	}
*/
};

void main()
{
	//Queue a;

	/*a.InsertAtEnd(5);
	a.InsertAtEnd(12);
	a.InsertAtEnd(72);
	a.DisplayAtTop();*/
	//cout<<a.IsEmpty();
	/*a.DeleteAtStart();*/
}
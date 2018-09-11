#include <iostream>
using namespace std;

//Linked List

struct Node									//For single node
{
	int data;								//For data's part of node
	Node *nextnodepointer;					//Pointer's part of node which points to next node; that's why it has 'node' datatype coz it points to next node.
};					

struct Stack
{
	Node *headpointer;						//Headpointer--which have location of first node

	Stack()
	{
		headpointer=NULL;							//Coz it's pointer					
	}
	void InsertAtStart(int num)						//Push or insert at start
	{
		Node*a = new Node;
		a->nextnodepointer=headpointer;				//New node's pointer is equal to headpointer
		a->data=num;								//Data entry to that new node
		headpointer=a;								//Making new node my head node
	}
	void DeleteAtStart()								//Delete headnode; pop from start
	{
		Node *temp = headpointer;
		headpointer=temp->nextnodepointer;			//or headpointer=headpointer->nextnodepointer;
		delete temp;
		temp = NULL;								//Optional here coz temp's scope is ending; it'll be Nullified anyway
	}
	void DisplayTopNode()
	{
		Node *temp = headpointer;
			cout<<temp->data<<endl;
	}
	~Stack()
	{
		Node *temp = headpointer;
		while (headpointer != NULL)
		{
			temp=headpointer;
			headpointer=temp->nextnodepointer;
			delete temp;
			temp=NULL;
			cout<<"Destructor called\n";
		}
		
	}
	Stack(Stack &a)
	{
		Stack TempStack;
		headpointer=NULL;
		Node*temp;
		temp=a.headpointer;

		while (temp != NULL)
		{
			TempStack.InsertAtStart(temp->data);
			temp=temp->nextnodepointer;
		}
		Node*temp1;
		temp1=TempStack.headpointer;

		while (temp1 != NULL)
		{
			InsertAtStart(temp1->data);
			temp1=temp1->nextnodepointer;
		}
	}
};

void main()
{
	Stack a;
	a.InsertAtStart(5);
	a.InsertAtStart(89);
	a.InsertAtStart(6);
	a.DeleteAtStart();
	a.DisplayTopNode();

	Stack b=a;

	b.DisplayTopNode();
}
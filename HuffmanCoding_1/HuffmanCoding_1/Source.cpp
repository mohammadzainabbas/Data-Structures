#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *nextnodepointer;	
};

struct FirstQueue
{
	Node* Headpointer;
	Node* Tailpointer;

	FirstQueue()
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
	void InsertAtEnd(int num)			//Enqueue
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
	void DeleteAtStart()				//Dequeue
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
	~FirstQueue()
	{
		Node *temp = Headpointer;
		while (temp != NULL)
		{
			delete temp->nextnodepointer;
			temp->nextnodepointer=NULL;
			cout<<"Destructor called\n";
			temp=temp->nextnodepointer;
		}
	}
	FirstQueue (const FirstQueue &OldQueue)
	{
	/*int TotalNodes=0;*/
		Headpointer=NULL;
		Tailpointer=NULL;
	
	Node* temp;
	temp=OldQueue.Headpointer;
	
	//Node* temp1=OldQueue.Headpointer;
	while (temp!=NULL)
	{
		/*TotalNodes+=1;*/
		InsertAtEnd(temp->data);
		temp=temp->nextnodepointer;
		cout<<"Aik aur node copy ho gahe ^_^ \n";
	}
	/*for (int Loop = 0; Loop <=TotalNodes; Loop++)
	{
		InsertAtEnd(temp1->data);
		temp1=temp1->nextnodepointer;
		
	}*/

	}

};

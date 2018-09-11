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
	~Queue()
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
	Queue (const Queue &OldQueue)
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

void main()
{
	Queue a;

	a.InsertAtEnd(5);
	a.InsertAtEnd(12);
	a.InsertAtEnd(72);
	a.InsertAtEnd(68);
	a.DisplayAtTop();
	a.DeleteAtStart();
	a.DisplayAtTop();
	cout<<a.IsEmpty()<<endl;

	Queue b=a;						//b.Queue(a);
	b.DisplayAtTop();
}

//cout<<"Aik aur node copy ho gahe ^_^ \n";
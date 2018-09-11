#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* nextnodepointer;	
	Node* previousnodepointer;
};

struct DoublyLinkedList
{
	Node* Headpointer;
	Node* Tailpointer;

	DoublyLinkedList()
	{
		Headpointer=NULL;
		Tailpointer=NULL;
	}
	bool IsEmpty()
	{
		if (Headpointer==NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void InsertAtStart(int num)
	{
		
		Node* a= new Node;
		
		if (IsEmpty() == 1)
		{
		a->nextnodepointer=NULL;
		a->previousnodepointer=NULL;
		a->data=num;
		Headpointer=Tailpointer=a;
		}
		else
		{
			a->nextnodepointer=Headpointer;
			a->previousnodepointer=NULL;
			Headpointer->previousnodepointer=a;
			Headpointer=a;
		}
		
	}
	void InsertAtEnd(int num)
	{
		
		Node* a= new Node;
		
		if (IsEmpty() == 1)
		{
		a->nextnodepointer=NULL;
		a->previousnodepointer=NULL;
		a->data=num;
		Headpointer=Tailpointer=a;
		}
		else
		{
			a->nextnodepointer=a;
			a->previousnodepointer=Tailpointer;
			Tailpointer->nextnodepointer=a;
			Tailpointer=a;
		}
		
	}
	void DeleteAtEnd()								//Delete headnode
	{
		if (IsEmpty() == 1)
		{
			cout<<"LinkedList is empty\n";
		}
		else
		
			if (Headpointer->nextnodepointer==NULL)
			{
				delete Headpointer;
				delete Tailpointer;
				Headpointer=Tailpointer=NULL;
			}
		
		else
		{
		Node *temp = Tailpointer->previousnodepointer;
		delete Tailpointer;
		Tailpointer=temp;
		temp->nextnodepointer=NULL;
		}
	}
	void DeleteAtStart()								//Delete headnode
	{
		Node *temp = Headpointer;
		temp=Headpointer;
		Headpointer=Headpointer->nextnodepointer;
		
		delete temp;
		temp = NULL;								//Optional here coz temp's scope is ending; it'll be Nullified anyway
	}
	void InsertAtAnyPosition(int num, int entryposition)
	{


		//else
		Node* a = new Node;
		int count=0;
		Node* temp=Headpointer ;
		while (count<entryposition-1)
		{
			count+=1;
			temp=temp->nextnodepointer;
		}
		a->nextnodepointer=temp->nextnodepointer;
		a->previousnodepointer= temp;
		temp->nextnodepointer=a;
		a->nextnodepointer->previousnodepointer=a;


	}
	void DeleteAtAnyPosition(int position)
	{


		//else
		
		int count=0;
		Node* temp=Headpointer ;
		while (count<position-1)
		{
			count+=1;
			temp=temp->nextnodepointer;
		}
		temp->previousnodepointer->nextnodepointer=temp->nextnodepointer;
		temp->nextnodepointer->previousnodepointer=temp->previousnodepointer;
		delete temp;
		temp = NULL;
	}

};
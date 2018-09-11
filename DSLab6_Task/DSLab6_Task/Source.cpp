#include <iostream>
#include <string>
using namespace std;

//Linked List

struct Node									//For single node
{
	char sign;
	Node *nextnodepointer;					//Pointer's part of node which points to next node; that's why it has 'node' datatype coz it points to next node.
};					

struct Stack
{
	Node *headpointer;						//Headpointer--which have location of first node

	Stack()
	{
		headpointer=NULL;							//Coz it's pointer					
	}
	
	void Push (char var)
	{
		Node*aa=new Node;
		aa->nextnodepointer=headpointer;
		aa->sign= var;
		headpointer=aa;
	}
	void Pop()								//Delete headnode; pop from start
	{
		Node *temp = headpointer;
		headpointer=temp->nextnodepointer;			//or headpointer=headpointer->nextnodepointer;
		delete temp;
		temp = NULL;								//Optional here coz temp's scope is ending; it'll be Nullified anyway
	}
	char DisplayTopNode()
	{
		Node *temp = headpointer;
		return temp->sign;
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
	
};

void main()
{
	Stack s1;
	int size=0;
	cout<<"Enter total length of your expression\n";
	cin>>size;

	char*InFix = new char [size];
	char*PostFix = new char [size];
	int num=0, num2=0;

	cout<<"Enter your In-fix expression\n";
	for (int i=0; i<size; i++)
	{
		cin>>InFix[i];
	}
	for (int j=0; j<size || num<size || num2<size ; j++,num++,num2++)
	{
		if (InFix[j] == '+' || InFix[j] == '-' || InFix [j] == '*' || InFix [j] == '/')
		{
			if (InFix [j] == '*' || InFix [j] == '/')
			{
				while (s1.DisplayTopNode() != '+' || s1.DisplayTopNode() != '-')
				{
					PostFix[num]=s1.DisplayTopNode(); 
					s1.Pop();
					num++;
				}
					s1.Push(InFix[j]);
			}
			else if (InFix[j] == '+' || InFix[j] == '-')
			{
				while (s1.DisplayTopNode() != '*' || s1.DisplayTopNode() != '/')
				{
					PostFix[num2]=s1.DisplayTopNode(); 
					s1.Pop();
					num2++;
				}
					s1.Push(InFix[j]);
			}
		}
		else
		{
			PostFix[j] = InFix[j];
		}
	}
	
	for (int num1 = 0; num1<size; num1++)
	{
		cout<<PostFix[num1];
	}

	

	
}
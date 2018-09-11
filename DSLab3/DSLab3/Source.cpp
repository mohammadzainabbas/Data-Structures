#include <iostream>

using namespace std;

//void function1 ()
//{
//int *ptr=new int;
//cin>>*ptr;
//cout<<ptr<<" "<<*ptr<<" "<<&ptr;
//delete ptr;
//ptr = NULL;
//}

//struct IntPointer
//{
//	int *ptr;
//
//	IntPointer()														//Default Constructor
//	{
//		ptr=NULL;														//Its a pointer so we've to initialize with NULL
//		cout<<"Default constructor loaded";
//	}
//	void SetValue(int a)												//Setter or for input
//	{
//		ptr = new int;													//For Dynamic memory allocation
//		*ptr=a;
//	}
//	void GetValue()														//Getter or for output		
//	{
//		cout<<*ptr<<endl;
//	}
//	//void Destructor()													//To deallocate dynamic memory
//	//{
//	//	delete ptr;
//	//	ptr = NULL;
//	//}
//	~IntPointer()										//Default Destructor-- calls whenever the attributes are destroyed; to delete dynamic memory automatically
//	{
//		delete ptr;
//		ptr =NULL;
//		cout<<"Destructor called\n";
//	}
//};

//Linked List

struct Node									//For single node
{
	int data;								//For data's part of node
	Node *nextnodepointer;					//Pointer's part of node which points to next node; that's why it has 'node' datatype coz it points to next node.

	//Node()										//Default Constructor for node
	//{
	//	data=0;
	//	nextnode=NULL;
	//}

};					

struct LinkedList
{
	Node *headpointer;								//Headpointer--which have location of first node

	LinkedList()
	{
		headpointer=NULL;							//Coz it's pointer					
	}
	void InsetAtStart(int num)
	{
		/*Node a;									//For just one node
		a.data =num;
		a.nextnodepointer=NULL;
		headpointer=&a;*/
		
		/*Node *a = new Node;						//For first node filling
		(*a).data=num;								//'(*a).data' and 'a->data' is same
		a->nextnodepointer=NULL;
		headpointer=a;*/
		
		Node*a = new Node;
		a->nextnodepointer=headpointer;				//New node's pointer is equal to headpointer
		a->data=num;								//Data entry to that new node
		headpointer=a;								//Making new node my head node
	}
	void InsertAtEnd (int num)
	{
		Node *temp=headpointer;
		while (temp->nextnodepointer != NULL)
			{
				temp=temp->nextnodepointer;
			}
				Node *a= new Node;
				a->nextnodepointer=NULL;
				a->data=num;
				temp->nextnodepointer=a;
			
	}
	void DeleteAtStart()								//Delete headnode
	{
		Node *temp = headpointer;
		headpointer=temp->nextnodepointer;			//or headpointer=headpointer->nextnodepointer;
		delete temp;
		temp = NULL;								//Optional here coz temp's scope is ending; it'll be Nullified anyway
	}
	void DeleteAtEnd()
	{
		Node *temp = headpointer;
		Node *NextTemp = temp->nextnodepointer;
		
		while (NextTemp->nextnodepointer != NULL)
		{
			temp=temp->nextnodepointer;
			NextTemp=NextTemp->nextnodepointer;
		}
		
		delete NextTemp;
		NextTemp = NULL; 
		temp->nextnodepointer=NULL;
	}
	void DisplayLinkedList()
	{
	//Traversion
		Node *temp = headpointer;
		while (temp != NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->nextnodepointer;
		}
	}
	~LinkedList()
	{
		Node *temp = headpointer;
		while (temp != NULL)
		{
			temp->data=0;
			delete temp->nextnodepointer;
			temp->nextnodepointer=NULL;

			temp=temp->nextnodepointer;
		}
		cout<<"Destructor called\n";
	}
	LinkedList(const LinkedList &a)					//Copy constructor
	{
		headpointer=NULL;
		Node* temp;
		temp=a.headpointer;

		while(temp != NULL)
		{
			InsertAtEnd(temp->data);
			temp=temp->nextnodepointer;
		}
	}
};

void main()
{
/*function1();*/

	/*IntPointer a;
	int num;
	cout<<"\nEnter any value \n";
	cin>>num;
	a.SetValue(num);
	a.GetValue();
	//a.Destructor();*/

	LinkedList a;
	a.InsetAtStart(5);
	a.InsetAtStart(89);
	a.InsertAtEnd(6);
	a.InsertAtEnd(55);
	a.DisplayLinkedList();
	a.DeleteAtEnd();
	a.DeleteAtEnd();
	a.DisplayLinkedList();

	LinkedList b=a;
	b.DisplayLinkedList();
}
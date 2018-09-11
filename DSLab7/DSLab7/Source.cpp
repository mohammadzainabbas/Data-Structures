#include <iostream>
using namespace std;

struct Node
{
	int Data;
	Node* RightPointer;
	Node* LeftPointer;
};
struct StackNode
{
	Node* TreeNode;
	StackNode* Next;
};
struct Stack
{
	StackNode* HeadPointer;
	Stack()
	{
		HeadPointer=NULL;
	}
	void Push(Node* temp)
	{
		StackNode* a= new StackNode;
		a->TreeNode=temp;
		a->Next=HeadPointer;
		HeadPointer=a;
	}
	Node* Pop ()
	{
		Node* Temp = HeadPointer->TreeNode;

		StackNode* temp = HeadPointer;
		HeadPointer=HeadPointer->Next;
		delete temp;
		temp=NULL;

		return Temp;
	}
	bool StackIsEmpty()
	{
		StackNode* temp = HeadPointer;

		if (temp==NULL)
		{
			return 0;
		}
		else 
		{
			return 1;
		}
	}
};
struct Tree
{
	Node* Root;
	Tree()
	{
		Root = NULL;
	}
	void Insert (int num, Node* temp)
	{

		if (Root == NULL)								//If Tree is empty
		{	
			Node* a = new Node;									
			a->Data= num;
			a->RightPointer=a->LeftPointer=NULL;
			Root = a;
			return;
		}

		if ( num < temp->Data)							//If coming data is less than root's data
		{
			if (temp->LeftPointer == NULL)				//Base Case
			{
				Node* a = new Node;									
				a->Data= num;
				a->RightPointer=a->LeftPointer=NULL;
				temp->LeftPointer=a;
				return;
			}
		else if (temp->LeftPointer != NULL)
			{
				temp=temp->LeftPointer;
				Insert(num, temp);
			}
		}
		
		if ( num > temp->Data)							//If coming data is more than root's data
		{
			if (temp->RightPointer == NULL)				//Base Case
			{
				Node* a = new Node;									
				a->Data= num;
				a->RightPointer=a->LeftPointer=NULL;
				temp->RightPointer=a;
				return;
			}
		else if (temp->RightPointer != NULL)
			{
				temp=temp->RightPointer;
				Insert(num, temp);
			}
		}
		 
	}
	void ImprovedInsert (int var)
	{
		Node* a = new Node;
		a->Data= var;
		a->RightPointer=a->LeftPointer=NULL;

		Node* Temp, *FatherTemp, *GrandFatherTemp, *FatherGrandFatherTemp;
		Temp=FatherTemp=GrandFatherTemp=FatherGrandFatherTemp=Root;

		if (Root == NULL)
		{
			Root=a;
		}
		else
		{
			Temp=Root;

			while (Temp!=NULL)
			{
				FatherGrandFatherTemp=GrandFatherTemp;
				GrandFatherTemp=FatherTemp;
				FatherTemp=Temp;

				if (var>Temp->Data)
				{
					Temp=Temp->RightPointer;
				}
				else
				{
					Temp=Temp->LeftPointer;
				}

			}

		

		if (var>FatherTemp->Data)
		{
			FatherTemp->RightPointer=a;
		}
		else
		{
			FatherTemp->LeftPointer=a;
		}


		//Improved Algorithm Starts


		if (FatherGrandFatherTemp!=GrandFatherTemp && FatherTemp->RightPointer == a && GrandFatherTemp->RightPointer == FatherTemp && GrandFatherTemp->LeftPointer==NULL)
		{
			if (FatherGrandFatherTemp->RightPointer == GrandFatherTemp)
			{
				FatherGrandFatherTemp->RightPointer=FatherTemp;
			}
			else
			{
				FatherGrandFatherTemp->LeftPointer=FatherTemp;
			}

			FatherTemp->LeftPointer=GrandFatherTemp;
			GrandFatherTemp->RightPointer=NULL;

		}
		else if (FatherGrandFatherTemp!=GrandFatherTemp && FatherTemp->LeftPointer == a && GrandFatherTemp->LeftPointer == FatherTemp && GrandFatherTemp->RightPointer==NULL)
		{
			if (FatherGrandFatherTemp->RightPointer == GrandFatherTemp)
			{
				FatherGrandFatherTemp->RightPointer=FatherTemp;
			}
			else
			{
				FatherGrandFatherTemp->LeftPointer=FatherTemp;
			}

			FatherTemp->RightPointer=GrandFatherTemp;
			GrandFatherTemp->LeftPointer=NULL;

		}
		else if (FatherGrandFatherTemp!=GrandFatherTemp && FatherTemp->RightPointer==a && GrandFatherTemp->LeftPointer == FatherTemp && GrandFatherTemp->RightPointer==NULL)
		{
			if (FatherGrandFatherTemp->RightPointer == GrandFatherTemp)
			{
				FatherGrandFatherTemp->RightPointer=a;
			}
			else
			{
				FatherGrandFatherTemp->LeftPointer=a;
			}

			a->LeftPointer=FatherTemp;
			a->RightPointer=GrandFatherTemp;
			GrandFatherTemp->RightPointer=GrandFatherTemp->LeftPointer=FatherTemp->RightPointer=FatherTemp->LeftPointer=NULL;

		}
		else if (FatherGrandFatherTemp!=GrandFatherTemp && FatherTemp->LeftPointer==a && GrandFatherTemp->RightPointer == FatherTemp && GrandFatherTemp->LeftPointer==NULL)
		{
			if (FatherGrandFatherTemp->RightPointer == GrandFatherTemp)
			{
				FatherGrandFatherTemp->RightPointer=a;
			}
			else
			{
				FatherGrandFatherTemp->LeftPointer=a;
			}

			a->RightPointer=FatherTemp;
			a->LeftPointer=GrandFatherTemp;
			GrandFatherTemp->RightPointer=GrandFatherTemp->LeftPointer=FatherTemp->RightPointer=FatherTemp->LeftPointer=NULL;

		}
		else
		{
			return;
		}
		}
	
	}
	//int Search(int var, Node* temp)
	//{
	//	static int num=0;
	//	num++;
	//	if (temp->Data==var)
	//	{
	//		//cout<<temp->Data<<endl;
	//		return num-1;
	//	}
	//	else if (var > temp->Data)
	//	{
	//		temp=temp->RightPointer;
	//		Search(var, temp);
	//	}
	//	else if (var < temp->Data)
	//	{
	//		temp=temp->LeftPointer;
	//		Search(var, temp);
	//	}
	//	else 
	//	{
	//	cout<<"Your node doesn't exist\n";
	//	}
	//}
	void InOrderTraversion (Node* c)								//Ma'am ka code
	{
		if (c!=NULL)
		{
			InOrderTraversion(c->LeftPointer);
			cout<<c->Data<<endl;
			InOrderTraversion(c->RightPointer);
		}
	}
	void PreOrderTraversion (Node* c)								//Ma'am ka code
	{
		if (c!=NULL)
		{
			cout<<c->Data<<endl;
			PreOrderTraversion(c->LeftPointer);
			PreOrderTraversion(c->RightPointer);
		}
	}
	void PostOrderTraversion (Node* c)								//Ma'am ka code
	{
		if (c!=NULL)
		{
			PostOrderTraversion(c->LeftPointer);
			PostOrderTraversion(c->RightPointer);
			cout<<c->Data<<endl;
		}
	}
	void Delete(int a)
	{
		if (Search(a) == NULL)
		{
			cout << "Tree is Empty!" << endl;
		}
		else
		{
			Node*temp = Root;
			Node*s = Search(a);
			Node*p = SearchParent(a);
			if (s->LeftPointer == NULL && s->RightPointer == NULL)
			{
				if (p == NULL)
				{
					delete Root;
					Root = NULL;
				}
				else if (s->Data > p->Data)
				{
					delete p->RightPointer;
					p->RightPointer = NULL;
				}
				else if (s->Data < p->Data)
				{
					delete p->LeftPointer;
					p->LeftPointer = NULL;
				}

			}
			else if ((s->LeftPointer == NULL) || (s->RightPointer == NULL))
			{
				if (s->LeftPointer == NULL)
				{
					p->LeftPointer = s->RightPointer;
					delete s;
				}
				else if (s->RightPointer == NULL)
				{
					p->LeftPointer = s->LeftPointer;
					delete s;
				}
			}
			else if ((s->LeftPointer != NULL) && (s->RightPointer != NULL))
			{
				if (s->LeftPointer->RightPointer == NULL)
				{
					if (s->Data > p->Data)
					{
						p->RightPointer = s->LeftPointer;
						p->RightPointer->RightPointer = s->RightPointer;
						delete s;
					}
					else if (s->Data < p->Data)
					{
						p->LeftPointer = s->LeftPointer;
						p->LeftPointer->RightPointer = s->RightPointer;
						delete s;
					}
				}
				else if (s->LeftPointer->RightPointer != NULL)
				{
					Node*temp = s->LeftPointer->RightPointer;
					while (temp->RightPointer != NULL)
					{
						temp = temp->RightPointer;
					}
					Node* tempfather = SearchParent(temp->Data);
					s->Data = temp->Data;
					tempfather->RightPointer = temp->LeftPointer;
				}
			}
		}
	}
	void DeleteAtAnyPosition (int var)
	{
	//In case of leaf node
		//search that node
		//Search it's parent
		//Delete the node
		//Parent's side (left/right) node = null
	//In case node has only one child
		//search parent node and node
		//Parent's side = child's side
		//Delete node
	//In case node has both child
		//search parent node and that node
		//Two ways
			//Pick right's most left node
			//Pick left's most right node
		//Replace that most left/right node with our delete-to-be node
		//Delete the node

	}
	Node* Search (int var)
	{
		Node* Temp = Root;
	
		while (Temp!=NULL)
		{
			if (Temp->Data==var)
			{
				return Temp;
				break;
			}
			else if (Temp->Data>var)
			{
				Temp=Temp->LeftPointer;
			}
			else if (Temp->Data<var)
			{
				Temp=Temp->RightPointer;
			}
		}
	}
	Node* SearchParent (int var)
	{
		Node* Temp = Root;
		Node* ParentTemp = NULL;
		while (Temp!=NULL)
		{
			
			if (Temp->Data==var)
			{
				return ParentTemp;
				break;
			}
			else if (Temp->Data>var)
			{
				ParentTemp=Temp;
				Temp=Temp->LeftPointer;
			}
			else if (Temp->Data<var)
			{
				ParentTemp=Temp;
				Temp=Temp->RightPointer;
			}
		}
	}
	void InOrderByStack (Node* temp)
	{
		Stack s;

		while (s.StackIsEmpty()!=0 || temp!= NULL)
		{
			if (temp!=NULL)
			{
				s.Push(temp);
					
				temp=temp->LeftPointer;
			}
			else
			{
				temp=s.Pop();
				cout<<temp->Data<<endl;
				temp=temp->RightPointer;
			}
		}
	}
	int TotalLeafNodes (Node* a)
	{
		if (a==NULL)
		{
			return 0;
		}
		else if (a->LeftPointer==NULL && a->RightPointer==NULL)
		{
			return 1;
		}
		else 
		{
			return TotalLeafNodes(a->LeftPointer)+TotalLeafNodes(a->RightPointer);
		}
	}
	/*Tree (const Tree&a)
	{
	cout<<"Copy Constructor Called\n";
	Root=NULL;

	Node* temp;
	temp=a.Root;

	while (temp!=NULL)
	{
		Insert(temp->Data,a.Root);
		InOrderTraversion(temp);
	}
	}*/
}; 

void main()
{
	Tree FirstTree;

	/*FirstTree.Insert(50,FirstTree.Root);
	FirstTree.Insert(45,FirstTree.Root);
	FirstTree.Insert(42,FirstTree.Root);
	FirstTree.Insert(43,FirstTree.Root);
	FirstTree.Insert(41,FirstTree.Root);
	FirstTree.Insert(48,FirstTree.Root);*/
	cout<<"Number of nodes : \t";
	int num=0;
	cin>>num;

	for (int i=0;i<num;i++)
	{
		int j=0;
		cin>>j;
		FirstTree.ImprovedInsert(j);
	}

	cout<<"Total no. of Leaf Nodes are : \t"<<FirstTree.TotalLeafNodes(FirstTree.Root)<<endl;

	/*FirstTree.InOrderTraversion(FirstTree.Root);
	FirstTree.Delete(48);
	FirstTree.InOrderTraversion(FirstTree.Root);
	FirstTree.InOrderByStack(FirstTree.Root);*/

	int num1=0, num2=0;
	cout<<"Enter value which you want to search\n";
	cin>>num1;
	cout<<"Your node is been found at position: "<<FirstTree.Search(num1)->Data<<endl;
	cout<<"It's parent node: "<<FirstTree.SearchParent(num1)->Data<<endl;
	//cout<<"Enter value whose parent you want to search\n";
	//cin>>num2;
	//cout<<"Parent of your node is: "<<FirstTree.SearchParent(num2)->Data<<endl;
	/*Tree secondtree=FirstTree;
	secondtree.InOrderTraversion(secondtree.Root);*/

}
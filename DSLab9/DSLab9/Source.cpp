#include <iostream>
#include <string>
using namespace std;

#define TableSize 100

struct HashArrayNode
{
	string FullName, Email, Username, Password;
	HashArrayNode* Nextpointer;

	HashArrayNode()
	{
		FullName=Email=Username=Password="";
		Nextpointer=NULL;
	}
};

struct HashTable
{
	HashArrayNode HashArray[TableSize];

	HashTable()
	{
		
	}
	int HashFunction (string a)
	{
		int Sum=0;
		
		for (int i=0; i<a.length(); i++)
		{
			Sum+=(a[i]*i);
		}
		return Sum%TableSize;
	}
	bool SearchUserName (string user_name)
	{
		int SearchPosition = HashFunction(user_name);

		if (HashArray[SearchPosition].Username == user_name)
		{
			return 1;
		}
		else
		{
			HashArrayNode* temp = HashArray[SearchPosition].Nextpointer;

			while (temp->Nextpointer!=NULL)
			{
				if (temp->Nextpointer->Username==user_name)
				{
					return 1;
				}
				else
				{
					temp=temp->Nextpointer;
				}
			}
			return 0;
		}
	}
	bool SearchPassword (string password)
	{
		int SearchPosition = HashFunction(password);

		if (HashArray[SearchPosition].Password == password)
		{
			return 1;
		}
		else
		{
			HashArrayNode* temp = HashArray[SearchPosition].Nextpointer;

			while (temp->Nextpointer!=NULL)
			{
				if (temp->Nextpointer->Password==password)
				{
					return 1;
				}
				else
				{
					temp=temp->Nextpointer;
				}
			}
			return 0;
		}
	}
	void Insert()
{
		HashArrayNode MyNode;

		cout<<"Enter your Details\n\n";
		cout<<"Full Name : \t";
		getline(cin,MyNode.FullName);

		cout<<"Email : \t";
		getline(cin,MyNode.Email);

		cout<<"Username : \t";
		getline(cin,MyNode.Username);

		cout<<"Password : \t";
		getline(cin,MyNode.Password);



		int InsertPosition = HashFunction(MyNode.Username);
		
	if (SearchUserName(MyNode.Username)==0)
	{
		if (HashArray[InsertPosition].FullName == "")
		{
			HashArrayNode* a = new HashArrayNode;
			a->FullName = MyNode.FullName;
			a->Email= MyNode.Email;
			a->Username=MyNode.Username;
			a->Password=MyNode.Password;
		}
		else
		{
			HashArrayNode* aa = new HashArrayNode;

			aa->FullName = MyNode.FullName;
			aa->Email= MyNode.Email;
			aa->Username=MyNode.Username;
			aa->Password=MyNode.Password;

			if (HashArray[InsertPosition].Nextpointer==NULL)
			{
				HashArray[InsertPosition].Nextpointer=aa;
			}
			else 
			{
				HashArrayNode* temp = HashArray[InsertPosition].Nextpointer;

				while (temp->Nextpointer!=NULL)
				{
					temp=temp->Nextpointer;
				}
				temp->Nextpointer=aa;
			}
		}
	}
	else
	{
		cout<<"Username already taken. Try again.\n";
	}
}
};


void main()
{
	HashTable FirstHashTable;

	FirstHashTable.Insert();
	FirstHashTable.Insert();
	FirstHashTable.Insert();
}
#include <list>
#include <iostream>
#include <string>
//STLs = standard template library
using namespace std;

struct Student
{
	string Name;
	int RollNo;
	string FatherName;
};

void Traverse(list<int> a)
{
	//Pointers in STLs are known as Iterators. They're like pointers but they're specifically used for STLs.

	list<int>::iterator temp;									//Pointer in STLs

	temp = a.begin();											//'begin()' returns the address of first node
	
	//We can't use inequality with iterators. We'll get compiler error;
	while (temp!= a.end())										//'end()' returns the address of last node
	{
		cout<<*temp<<"\t";										//'*temp' means value in temp
		temp++;													//temp=temp->next;
	}
	cout<<endl;
	//cout<<*a.end();

}
void BackTraverse (list <int> a)
{
	list <int>::iterator temp;

	temp=a.end();
	temp--;
	while (temp!=a.begin())
	{
		cout<<*temp<<"\t";
		temp--;
	}
	cout<<*a.begin()<<endl;
}
void MultiplyList (list <int> &a, int num)
{
	list<int>::iterator temp;
	temp=a.begin();
		
	while (temp!=a.end())
	{
		*temp= *temp*num;
		cout<<*temp<<"\t";
		temp++;
	}
	
	cout<<endl;
}
void DeleteAll (list <int> &a)
{
	list<int>::iterator temp;
	temp=a.begin();
	while (temp!=a.end())
	{
		 *temp =0;
		 a.pop_back();
	}
	
}
void DeleteRedundant (list <int> &a)
{
	list<int>::iterator temp1;
	list<int>::iterator temp2;
	
	temp1=a.begin();
	
	while (temp1!=a.end())
	{
		temp2=temp1;
		temp2++;
		while (temp2!=a.end())
		{
			if (*temp1==*temp2)
			{
				temp2=a.erase(temp2);
			}
			else
			{
				temp2++;
			}
		}
		temp1++;
	}

}
void DeleteMultiple (list <int> &a, int num)
{
	list<int>::iterator temp;
	temp=a.begin();

	while (temp!=a.end())
	{
		if (*temp%num ==0)
		{
			temp=a.erase(temp);
		}
		else
		{
			temp++;
		}
	}


}
list<int> AddThemUp (list<int> a, list<int> b)
{
	list<int>::iterator temp;
	
	list<int> List;

	temp=a.begin();

	while (temp!=a.end())
	{
		List.push_back(*temp);
		temp++;
	}
	temp=b.begin();
	while (temp!=b.end())
	{
		List.push_back(*temp);
		temp++;
	}
	return List;
}
list<int> ReverseOrder (list<int> a)
{
	list <int>::iterator temp;
	list<int> List;

	temp=a.begin();

	while (temp!=a.end())
	{
		List.push_front(*temp);
		temp++;
	}
	return List;
}
list<int> MergeThemAlternatively (list<int> a, list<int> b)
{
	list <int>::iterator temp1;
	list <int>::iterator temp2;
	list <int> List;

	int check=0;
	temp1=a.begin();
	temp2=b.begin();
	while (temp1!=a.end() && temp2!=b.end())
	{
		if (check%2==0)
		{
			List.push_back(*temp1);
			temp1++;
		}
		else
		{
			List.push_back(*temp2);
			temp2++;
		}
		check++;
	}
	//temp2=b.end();
	//List.push_back(*b.end());
	return List;
}
bool IsEqual (list<int> a, list<int> b)
{
	list<int>::iterator temp1;
	list<int>::iterator temp2;
	temp1=a.begin();
	temp2=b.begin();
	while (temp1!=a.end())
	{
		if (*temp1%*temp2 ==0)
		{
			temp1++;
			temp2++;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

void main ()
{
	list<int> a,b,c;												//LinkedList have int datatype.
	cout<<"Enter total numbers of nodes for 1st list.\n";
	int num=0;
	cin>>num;
	for (int i=0;i<num;i++)
	{
		int j=0;
		cin>>j;
		cout<<endl;
		a.push_back(j);
	}
	cout<<"Enter total numbers of nodes for 2nd list.\n";
	int num1=0,num2=0,num3=0;
	cin>>num1;
	for (int i=0;i<num1;i++)
	{
		int j=0;
		cin>>j;
		cout<<endl;
		b.push_back(j);
	}
	cout<<"First List is : \n";
	Traverse(a);
	cout<<"Second List is : \n";
	Traverse(b);
	cout<<"Multiply the first list with ? \n";
	cin>>num2;
	MultiplyList(a, num2);
	
	//BackTraverse(a);
	cout<<"Delete redundant from First List : \n";
	DeleteRedundant(a);
	Traverse(a);
	cout<<"Whose multiple do you wanna delete from First List ? \n";
	cin>>num3;
	DeleteMultiple(a,num3);
	Traverse(a);
	cout<<"Reverse the order of Second List : \n";
	c=ReverseOrder(b);
	Traverse(c);
	cout<<"Is First and Second Lists are equal ?? '1' for equal and '0' for non-equal. \n";
	cout<<IsEqual(a,b)<<endl;
	cout<<"Merge both lists Alternatively : \n";
	c=MergeThemAlternatively(a,b);
	Traverse(c);
	//a.push_back(5);											//Insert at end
	//a.push_front(12);											//Insert at start

	//list<Student> a;											
	//LinkedList have user-define datatype
}
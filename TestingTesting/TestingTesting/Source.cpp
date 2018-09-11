#include <iostream>
using namespace std;

struct OR
{
	bool a,b;

	OR()
	{
	a=b=0;
	}
	void InputOR()
	{
		cout<<"Enter your 1st pin.\n";
		cin>>a;
		cout<<"Enter your 2nd pin.\n";
		cin>>b;
	}
	bool OutputOR()
	{
		if ((a+b)>=1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void ChangeInputOR(int num)
	{
	
	switch (num)
	{
		case 1:
			{
				cout<<"Enter your 1st pin.\n";
				cin>>a;
			}
		break;
	
		case 2:
			{
				cout<<"Enter your 2nd pin.\n";
				cin>>b;
			}
		break;
	
	}
	}

};

struct NOT
{
	bool a;

	NOT()
	{
	a=0;
	}
	void InputNOT()
	{
	cin>>a;
	}
	void ToggleNOT()
	{
		if (a == true)
			a=false;
		else
		{
			a=true;
		}
	}
	void OutputNOT()
	{
		cout<<a<<endl;
	}

};

struct NOR
{
	OR num;
	NOR()
	{
		num.a=num.b=0;
	}
	void InputNOR()
	{
		num.InputOR();
	}
	void ChangeInputNOR(int var)
	{
		num.ChangeInputOR(var);
	}
	void OutputNOR()
	{
		NOT b;
		b.a=num.OutputOR();
		b.ToggleNOT();
		cout<<b.a<<endl;
	}

};

void main()
{
	NOR var;

	var.InputNOR();
	int num=0;
	cout<<"Do you want to make a change in your input??\n";
	cout<<"1) Yes \n2) No \n";
	cin>>num;
	if (num==1)
	{
	cout<<"Which input you wanna change ??\n";
	cin>>num;
	var.ChangeInputNOR(num);
	}
	cout<<"NOR of your inputs are : \n";
	var.OutputNOR();
	
}
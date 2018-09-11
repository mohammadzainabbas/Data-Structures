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
	bool OutputOR(bool num1,bool num2)
	{
		if (((num1*a)+(num2*b))>=1)
		{
			return true;
		}
		else
		{
			return false;
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
	bool OutputNOT()
	{
		return a;
	}

};

struct AND
{
	bool a,b;

	AND()
	{
	a=b=0;
	}
	void InputAND()
	{
		cout<<"Enter your 1st pin.\n";
		cin>>a;
		cout<<"Enter your 2nd pin.\n";
		cin>>b;
	}
	bool OutputAND()
	{
		return a*b;
	}
	void ChangeInputAND(int num)
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

struct XOR
{
	AND num1;

	XOR()
	{
		num1.a=num1.b=0;
	}
	void InputXOR()
	{
		num1.InputAND();
	}
	void ChangeInputXOR(int var1)
	{
		num1.ChangeInputAND(var1);
	}
	bool OutputXOR()
	{
		NOT n1;
			AND var1,var2;
			OR x;
		n1.a=num1.a;
		n1.ToggleNOT();
		var1.a=num1.a;
		var1.b=n1.OutputNOT();
		x.a=var1.OutputAND();
		n1.a=num1.b;
		n1.ToggleNOT();
		var2.a=n1.OutputNOT();
		var2.b=num1.b;
		x.b=var2.OutputAND();

		return x.OutputOR(var1.OutputAND(),var2.OutputAND());

		/*var.OutputOR(num1.a,num1.b);
		var.OutputOR(num2.a,num2.b);*/

		/*cout<<var.OutputOR(var.OutputOR(num1.a,num1.b),var.OutputOR(num2.a,num2.b))<<endl;
		*/
	}


};

void main()
{
	XOR var;

	var.InputXOR();
	int num=0;
	cout<<"Do you want to make a change in your input??\n";
	cout<<"1) Yes \n2) No \n";
	cin>>num;
	if (num==1)
	{
		int numm =0;
	cout<<"Which pin you wanna change from first input ??\n";
	cin>>num;
	cout<<"Which pin you wanna change from second input ??\n";
	cin>>numm;
	var.ChangeInputXOR(num,numm);
	}
	cout<<"XOR of your inputs are : \n";
	cout<<var.OutputXOR();
	
}
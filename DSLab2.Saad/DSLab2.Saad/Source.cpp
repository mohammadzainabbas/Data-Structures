#include <iostream>
#include <cmath>
using namespace std;

struct point

{
point ()
{x=0;
y=0;

}
	float x,y;

void input()
{
cout<<"Enter X co-ordinate: ";
cin>>x;

cout<<"\nEnter Y co-ordinate: ";
cin>>y;
cout<<endl;
}

void output()
{
cout<<" co-ordinates are "<<x<<","<<y<<endl;
cout<<"Y co-ordinate= "<<y<<endl;


}

float distance(point z)
{
	float dist;

	dist=pow((pow((z.x-x),2)+pow((z.y-y),2)),0.5);
	return dist;

}

void iszero()
{
if (x==0 & y==0)
	cout<<"It is the centre "<<endl;

}

point midpoint( point p3)
{
	point c;
	c.x=((x+p3.x)/2);
	c.y=((y+p3.y)/2);
return c;
}

 void isequal(point c)
 {
	 float mag1,mag2;
mag1=pow((pow((x-0),2)+pow((y-0),2)),0.5);
mag2=pow((pow((c.x-0),2)+pow((c.y-0),2)),0.5);
 
if (mag1>mag2)
	cout<<"Point 1 is further \n \n";
else
	cout<<"Point 2 is Further \n \n";
 }

};

struct Line
{
	
	point pp1,pp2;

	void input()
	{
		cout<<"Start point : \n";
		pp1.input();

		cout<<"End point : \n";
		pp2.input();
		cout<<" \n \n";
	}

	float length ()
	{
		float len=pp1.distance(pp2);
	return len;
	}

	void compare (Line x)
	{
		

		
		if (length()>x.length())
			cout<<"Line 1 is greater. ";
		else if (length()==x.length())
			cout<<"Lines are of same size. ";
		else
		cout<<"Line 2 is greater. \n ";
		
	}

		
	
};

void main()
{
	point p1,p2;
	Line l1,l2;

	int start=0;
	int choice=0,cont=1,choice2=0;

	cout<<"Do you want to: \n 1. Deal with Points \n 2. Deal with Lines \n";
	cin>>start;
	cout<<"\n \n";

	switch (start)
	{


	//Choice made: Point

	case 1:
	
	p1.input();
	p2.input();
	while (cont=1)
	{
	
	cout<<"1. Input \n 2. Output \n 3. Is Zero? \n 4. Distance \n 5. Midpoint \n 6. IsEqual \n";
	cin>>choice;
	cout<<"------------------------------------------ \n";
	switch (choice)
	{
	case 1:
	p1.input();
	p2.input();
	
	break;

	case 2:
	p1.output();
	p2.output();
	break;

	case 3:
	p1.iszero();
	p2.iszero();
	break; 

	case 4:
	cout<<"Distance is "<<p1.distance(p2)<<endl;
	break;
	
	case 5:
		
	cout<<"X co-ordinate of Mid Point is "<<p1.midpoint(p2).x<<" , "<<p1.midpoint(p2).y<<endl;
	break;

	case 6:
		p1.isequal(p2);
	}
	cout<<"Continue?";
	cin>>cont;
	}
	 //----------------------------------------------


	//Choice made: Line

	case 2:
	cout<<"Input Line 1 \n \n";
	l1.input();
	cout<<"Input Line 2 \n \n";
	l2.input();
	
	cout<<"------------------------------------------- \n";
	
	while (cont=1)
	{
	cout<<" Which Function do you want to apply? \n1. Input again \n 2. Length \n 3. Compare lines \n";
	cin>>choice2;
	switch (choice2)
	{
	

	
	case 1:
		cout<<"Input Line 1 \n";
	l1.input();
	cout<<"Input Line 2 \n";
	l2.input();
	break;

	case 2:
		cout<<"The length of line 1 is : "<<l1.length()<<endl;
		cout<<"The length of line 2 is : "<<l2.length()<<endl;
	break;

	case 3:
		l1.compare(l2);
	
	}
	cout<<"------------------------------------ \nContinue? \n";
	cin>>cont;

	
	
	}
	}
}
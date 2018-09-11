#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//struct Time
//{
//	int sec, min, hrs;
//
//	void SetSec ()
//	{
//		cin>>sec;
//	}
//	void SetMin()
//	{
//		cin>>min;
//	}
//	void SetHrs()
//	{
//		cin>>hrs;
//	}
//	Time()													//Default Constructor
//	{
//	sec=0; min=0; hrs=0;
//	cout<<"Default Constructor called";
//	}
//};

//struct Employee
//{
//	string Name, Designation;
//	Time Start,End;
//
//	void SetName()
//
//	{
//		/*cin>>Name;*/									//In case of string
//		getline(cin,Name);								//In case of string
//
//		//cin.getline(arrayname,100);						//In case of character array		'cin.getline(arrayname,arraysize);
//	
//	}
//
//	void SetStartTime()
//	{
//		Start.SetSec(); Start.SetMin();
//		Start.SetHrs();
//	}
//};

struct Point
{
	int x,y;

	Point()
	{
	x=0;	y=0;
	cout<<"Default Constructor called\n";
	}
	void inputPoint()
	{
		cout<<"Enter x-coordinate :\n";
		cin>>x;
		cout<<"Enter y-coordinate :\n";
		cin>>y;
	}
	/*void xpoint()
	{
	cin>>x;
	}
	void ypoint()
	{
		cin>>y;
	}*/
	void DistanceBetween (Point a)
	{
		int dist = sqrt(((x-a.x)*(x-a.x))+((y-a.y)*(y-a.y)));
		cout<<"Distance between two points are :"<<dist<<endl;
	}
	void Zeropoint()
	{
	if (x==0&&y==0)
	{
		cout<<"Point is at the centre i-e (0,0) \n";
	}
	else
	{
		cout<<"Point doesn't lie at the centre.\n";
	}
	}
	Point MiddlePoint (Point a)
	{
	Point var;
	var.x = ((x+a.x)/2);
	var.y = ((y+a.y)/2);
	cout<<var.x<<","<<var.y<<endl;
	return var;
	}
	void CompareEqual(Point a)
	{
		int num1=sqrt((x*x)+(y*y));
		int num2=sqrt((a.x*a.x)+(a.y*a.y));
		
		if (num1==num2)
		{
		cout<<"Two points are equal in magnitude.\n";
		}
		else
		{
			cout<<"Two points aren't equal in magnitude.\n";
		}
	}
	void CompareViaCentre (Point a)
	{
		int dist1 = sqrt(((x-0)*(x-0))+((y-0)*(y-0)));
		int dist2 = sqrt(((0-a.x)*(0-a.x))+((0-a.y)*(0-a.y)));

		if (dist1>dist2)
		{
				cout<<"First point is at greater distance from centre.\n";
		}
		else
		{
			cout<<"Second point is at greater distance from centre.\n";
		}
	}
	
};
struct Line
{
	Point StartPoint,EndPoint;
	void inputLine()
	{
		cout<<"Enter Starting point : \n";
		StartPoint.inputPoint();
		cout<<"Enter Ending point : \n";
		EndPoint.inputPoint();
	}
	void LineLength()
	{
		StartPoint.DistanceBetween(EndPoint);
	}
	void CompareLines(Line a)
	{
		if ((StartPoint.DistanceBetween(EndPoint))>(a.StartPoint.DistanceBetween(a.EndPoint)))
		{
		
		}
	}
};
void main()
{
/*Point p1,p2;

cout<<"First point : \n"<<"Enter x-coordinate : ";
p1.xpoint();
cout<<"\nEnter y-coordinate : ";
p1.ypoint();
cout<<"\nSecond point : \n"<<"Enter x-coordinate : ";
p2.xpoint();
cout<<"\nEnter y-coordinate : ";
p2.ypoint();

p1.DistanceBetween(p2);

cout<<"For first point.\n";
p1.Zeropoint();
cout<<"For second point.\n";
p2.Zeropoint();

cout<<"Their middle point is \n";
p1.MiddlePoint(p2);

cout<<"\nCompare two points by their magnitudes:\n";
p1.CompareEqual(p2);

cout<<"\nWhich one is at greater distance from the centre ??\n";
p1.CompareViaCentre(p2);
*/

}
#include <iostream>

using namespace std;

struct Rectangle
{

float length, width;

float Area(Rectangle a)
{
	float area1=a.length*a.width;
	return area1;
}

float Perimeter (Rectangle a)
{
	float perimete = 2*(a.length+a.width);
	return perimete;
}
void CompareArea (Rectangle a)
{
	if (Area>a.Area)
	cout<<"First rectangle is greater.\n";
	else
	cout<<"Second rectangle is greater.\n";
}
};
void main()
{
	Rectangle r1,r2;
	cout<<"Enter length of 1st rectangle.\n";
	cin>>r1.length;
	cout<<"Enter width of 1st rectangle.\n";
	cin>>r1.width;

	cout<<"Enter length of 2nd rectangle.\n";
	cin>>r2.length;
	cout<<"Enter width of 2nd rectangle.\n";
	cin>>r2.width;

	cout<<"Area and Perimeter of 1st rectangle is:\n";
	cout<<Area(r1)<<endl<<Perimeter(r1)<<endl;

	cout<<"Area and Perimeter of 2nd rectangle is:\n";
	cout<<Area(r2)<<endl<<Perimeter(r2)<<endl;

	r1.CompareArea(r2);
}
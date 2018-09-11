#include <iostream>
using namespace std;

struct Cylinder												//Structure for Cylinder					
{
float radius, height;										//Attributes		

float SurfaceArea ()										//Function 'SurfaceArea' inside structure 'Cylinder'
{
	return 2*3.1416*radius*(radius+height);
}
float Volume ()												//Function 'Volume' inside structure 'Cylinder'
{
	return 3.1416*radius*radius*height;
}
};
void main()													//Main function starts
{
	Cylinder c;												//Declaring variables for Cylinder data-type
	cout<<"Enter radius of Cylinder.\n";
	cin>>c.radius;
	cout<<"Enter height of Cylinder.\n";
	cin>>c.height;
	
	cout<<"Details of Cylinder.\n\n";
	
	cout<<"Surface Area is : ";
	cout<<c.SurfaceArea()<<endl;

	cout<<"Volume is : ";
	cout<<c.Volume()<<endl;

}


#include<iostream>
#include<string>
using namespace std;

struct Student
{
	string Name;
	string FathersName;
	int RegNo;
	int Degree;
	string Department;
};

void main()
{
	Student S1;
	cout<<"ENTER THE NAME OF THE STUDENT=";
	cin>>S1.Name;
	cout<<"THE FATHERS NAME=";
	cin>>S1.FathersName;
	cout<<"ENTER THE REG NO=";
	cin>>S1.RegNo;
	cout<<"ENTER THE DEGREE=";
	cin>>S1.Degree;
	cout<<"ENTER THE DEPARTMENT=";
	cin>>S1.Department;
}
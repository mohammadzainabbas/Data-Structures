#include <iostream>

using namespace std;

int Range[990];
int Fib(int a)
{
	if (Range[a]!=-1)
	{	return Range[a];
	}
	Range[a]=Fib(a-1)+Fib(a-2);
	return Range[a];
}
//int Fib(int a)
//{
//	if (a==1 || a==0)
//		return 1;
//	else 
//		return Fib(a-1)+Fib(a-2);
//}
void main()
{
for (int i=0;i<990;i++)
{
	Range[i]=-1;
}
Range[0]=0;
Range[1]=1;
int a[5];
cin>>a[2]>>a[3];
int *b;
b=&a[3];
cout<<*b;
//cout<<"nth term of fibanacci's series is :\t"<<Fib(a)<<endl;
}
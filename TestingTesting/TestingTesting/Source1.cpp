#include <iostream>

using namespace std;

int myfun (int arr[],int low,int high)
{
	if (low>high || (low==high&&arr[low]!=42))
		return 0;
	if (low==high && arr[low]==42)
		return 1;
	else return myfun(arr,low,(low+high)/2)+myfun(arr,1+(low+high)/2,high);
}
void main()
{
int arra[5];
arra[0]=9;
arra[1]=0;
arra[2]=42;
arra[3]=42;
arra[4]=5;
cout<<myfun(arra,0,4);
}
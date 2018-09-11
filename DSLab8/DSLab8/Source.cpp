#include <iostream>
using namespace std;

struct Sorting
{
	int Size;
	int *Array;
	
Sorting()
	{
		Array = NULL;
		Size=0;
	}
void Set(int a)
	{
		Size=a;
		Array = new int [Size];
	}
void Input()
	{
		for (int i=0; i<Size; i++)
		{
			cin>>Array[i];
		}
	}	
//void Swap (int a, int b)
// {
//	int temp=a;
//	b=a;
//	temp=b;
// }
void BubbleSortForAcending()
{
	cout<<"In Acending Order\n";
	for (int i =0; i<Size;i++)									//For Passes
	{
		for (int j=0; j<Size-1;j++)								//For Each Pass
		{
			if (Array[j+1]<Array[j])
			{
				swap(Array[j],Array[j+1]);						//Build-in Function for Swapping
			}
		}
	}
}
void BubbleSortForDecending()
{
	cout<<"In Decending Order\n";
	for (int i =0; i<Size;i++)									//For Passes
	{	
		for (int j=0; j<Size-1;j++)								//For Each Pass
		{
			if (Array[j+1]>Array[j])
			{
				swap(Array[j],Array[j+1]);						//Build-in Function for Swapping
			}
		}
	}
}
//void SelectionSortForDecending()					//Net
//{
//int First=0;
//for (int i=Size-1;i>0;i--)
//{
//	First=0;
//	for (int j=0;j<Size;j++)
//	{
//		if (Array[j]<Array[First])
//		{
//			First=j;
//		}
//		int temp = Array[First];
//		Array[First]=Array[i];
//		Array[i]=temp;
//	}
//}
//}
//void SelectionSort()
//{
//	for (int i=0; i<Size;i++)
//	{
//		for (int j=0; j<Size-1; j++)
//		{
//			
//		}
//	}
//}
void Selection_Sort()
{
int temp=0, Position=0;

for (int i =0; i<Size; i++)
{
	temp=Array[i];
	Position=i;

	for (int j=i;j<Size;j++)
	{
		if (temp>Array[j])
		{
			temp=Array[j];
			Position=j;
		}
	}
	swap(Array[Position],Array[i]);
}
}
void Insertion_Sort()
	{
		for(int i=0;i<Size;i++)
		{
			for(int j=i;j>0;j--)
			{
				if(Array[j-1]>Array[j])
				{
					swap(Array[j-1],Array[j]);
				}
			}

		}
	}
int MinimumValueOfArray (int a)
{
	int Minimum=Array[a];
	for (int i=a; i<Size; i++)
	{
		if (Array[i]<Minimum)
		{
			Minimum=Array[i];
		}
	}
	return Minimum;
}
int MaximumValueOfArray (int a)
{
	int Maximum=Array[a];
	for (int i=a; i<Size; i++)
	{
		if (Array[i]>Maximum)
		{
			Maximum=Array[i];
		}
	}
	return Maximum;
}
void Output()
	{
		cout<<"\nYour Array is : \n\n";
		for (int i=0; i<Size; i++)
		{
			cout<<Array[i]<<"\t";
		}
		cout<<"\n\n";
	}	
~Sorting()
{
	delete [] Array;
	Array = NULL;
}
Sorting (const Sorting &a)
	{
		Size=a.Size;
		cout<<"Copy Constructor Called\n";
		Array=new int [Size];

		for (int i=0;i<Size;i++)
		{
			Array[i]=a.Array[i];
		}
	}

};

void main()
{
	Sorting First;
	int size=0;
	cout<<"Enter the size of your Array:\t";
	cin>>size;
	First.Set(size);
	First.Input();
	First.Output();
	First.Insertion_Sort();
	First.Output();
	cout<<"Maximum \n"<<First.MaximumValueOfArray(0);
}
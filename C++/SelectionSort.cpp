#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void SelectionSort(int *a,int size)
{
    for(int i=0;i<size-1;i++)                                                //swapping array to give
    {                                                                        //minimum element in ith 
        for(int j=i+1;j<size;j++)                                            //position in each iteration
        {
            if(a[i]>a[j])
            {
                swap(&a[i],&a[j]);
            }
        }
    }
}

void printsortedarr(int *a,int size)                                          //printing array
{
    for(int i=0;i<size;i++)
    cout<<a[i]<<"  ";
}

int main() {
    
    
    int a[14]={25,23,11,-4,-10,-3,-9,-34,-56,-110,-111,-123,34,11};
    int size=14;
	
	printsortedarr(&a[0],size);
	cout<<endl;
	SelectionSort(&a[0],size);
	printsortedarr(&a[0],size);
	return 0;
}
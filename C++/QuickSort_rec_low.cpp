#include <iostream>
using namespace std;

void swap( int *l, int *h)
{
    int temp = *l;
    *l = *h;
    *h = temp;
}

int partition( int *a, int low, int high)
{
    int pivot = a[low];
    int i = high+1;
    
    for(int j = high; j >low; j--)
    {
        if( a[j] > pivot)
        {
           // i++; 
            swap(a[--i], a[j]);
        }
    }
    swap(a[--i],a[low]);
    return(i);                                                                                              //returning the correct position of pivot
}                                                                                                             //as per in sorted array

void QuickSort( int *a, int low, int high)
{
    if(low < high)
    {
        int pi = partition(a, low, high);
        
        QuickSort(a, low, pi-1);
        QuickSort(a, pi+1, high);
    }
}

void printsortedarr(int *a,int size)                                                                                                                                                                                            //printing array
{
    for(int i=0;i<size;i++)
      cout<<a[i]<<"  ";
    cout<<endl;
}

int main() {
    int a[14]={25,23,11,-4,-10,-3,-9,-34,-56,-110,-111,-123,34,11};
    int size=14;
	
	printsortedarr(&a[0],size);
	QuickSort(a,0,size-1);
	cout<<"The sorted array is "<<endl;
	printsortedarr(a,size);
	
	return 0;
}
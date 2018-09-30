#include <iostream>
using namespace std;


void InsertSort(int *a,int size)                                              //function to do sorting
{
    int key;
    int i,j;

    for(i=1;i<size;i++)
    {
        key=a[i];                                                             //initialising key to compare 
        j=i-1;                                                                
        while(j>=0 && a[j]>key)             
        {
            a[j+1] = a[j];                                                    //shifting entries greater than element to right
            j--;
        }
        
        a[j+1] = key;                                                         //putting key in the rightmost position  
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
	
	InsertSort(&a[0],size);
	printsortedarr(&a[0],size);
	return 0;
}
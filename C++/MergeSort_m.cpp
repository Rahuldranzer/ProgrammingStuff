#include <iostream>
using namespace std;

void Merge(int *a,int first, int mid_ind,int last)
{
    int * const T1 = new int[ last - first + 1];
    
    int i = first;
    int j = mid_ind + 1;
    int iter = 0;
    
    while(i <= mid_ind && j <= last)
        // if( a[i] < a[j])
        // {
        //     T1[iter] = a[i++];
        // }
        // else
        // {
        //     T1[iter] = a[j++];
        // }
        // iter++;
        
        T1[iter++] = (a[i] < a[j]) ? a[i++] : a[j++];
    
    while( i <= mid_ind) T1[iter++] = a[i++];
    
    while( j <= last) T1[ iter++] = a[j++];
    
    for(int i = 0; i < last - first + 1; i++)
        a[first + i] = T1[i];
        
    delete T1;
}

void MergeSort(int *a, int first, int last)
{
    cout<<"first and last in MergeSort "<<first<<" "<<last<<" "<<endl;
    if(first < last)
    {
        int m = (last+first)/2;
        
        MergeSort(a, first,m);
        MergeSort(a, m+1,last);
        
       cout<<"first,mid and last "<<first<<" "<<m<<" "<<last<<endl;
        
        Merge(a,first,m,last);
        cout<<"first,mid and last while merging"<<first<<" "<<m<<" "<<last<<endl;
    }
    //cout<<"Merged done correct"<<endl;
}

void printsortedarr(int *a,int size)                                          //printing array
{
    for(int i=0;i<size;i++)
    cout<<a[i]<<"  ";
    cout<<"did u get it"<<endl;
    cout<<endl;
}

int main() {
    int a[14]={25,23,11,-4,-10,-3,-9,-34,-56,-110,-111,-123,34,11};
    int size=14;
	
	printsortedarr(&a[0],size);
	MergeSort(&a[0],0,size-1);
	printsortedarr(&a[0],size);
	
	return 0;
}
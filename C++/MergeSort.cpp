#include <iostream>
using namespace std;

void Merge(int *a,int first, int mid_ind,int last)
{
    int n1 = mid_ind - first + 1;
    int n2 = last - mid_ind;
    cout<<"value of n1 and n2 "<<n1<<" "<<n2<<endl;
    int *T1,*T2;
    T1 = new int[n1];
    T2 = new int[n2];
    
    for(int i=0; i<n1; i++)
    {
        T1[i] = a[first+i];
        cout<<"first temp array index "<<first+i<<endl;
    }
    
    cout<<"first temp arr"<<endl;
    for(int i=0;i<n1;i++)
        cout<<T1[i]<<" ";
     cout<<endl;
    
    
    for(int i=0; i<n2; i++)
    {
        T2[i] = a[n1+i];
    }
    
    cout<<"second temp arr"<<endl;
    for(int i=0;i<n2;i++)
        cout<<T2[i]<<" ";
     cout<<endl;
  //  cout<<"engaged in merging"<<endl;
    int i=0;
    int j=0;
    int k=first;
    while(k<=last)
    {
        if(T1[i]<=T2[j])
        {
            a[k] = T1[i];
            i++;
        }
        else
        {
            a[k] = T2[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        a[++k] = T1[i];
        i++;
    }
    
    while(j<n2)
    {
        a[++k] = T2[j];
        j++;
    }
    
    delete[] T1;
    delete[] T2;
}

void MergeSort(int *a, int first, int last)
{
    if(first < last)
    {
        int m = (last+first)/2;
        
        MergeSort(&a[first],first,m);
        MergeSort(&a[m+1],m+1,last);
        
      //  cout<<"first,mid and last "<<first<<" "<<m<<" "<<last<<endl;
        
        Merge(&a[first],first,m,last);
      //  cout<<"first,mid and last after merging"<<first<<" "<<m<<" "<<last<<endl;
    }
    //cout<<"Merged done correct"<<endl;
}

void printsortedarr(int *a,int size)                                          //printing array
{
    for(int i=0;i<size;i++)
    cout<<a[i]<<"  ";
    cout<<"did u get it"<<endl;
}

int main() {
    int a[14]={25,23,11,-4,-10,-3,-9,-34,-56,-110,-111,-123,34,11};
    int size=14;
	
	printsortedarr(&a[0],size);
	cout<<endl;
	MergeSort(&a[0],0,size-1);
	cout<<"what are you doing "<<endl;
	printsortedarr(&a[0],size);
	
	return 0;
}
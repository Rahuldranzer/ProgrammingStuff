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
        cout<<"value of first "<<first<<endl;
        cout<<"a[first+i] value entered in temp "<<a[first+i]<<endl;
        T1[i] = a[first+i];
        cout<<"first temp array index "<<first+i<<endl;
    }
    
    cout<<"first temp arr"<<endl;                                                                            //printing 1st temp array
    for(int m=0;m<n1;m++)
        cout<<T1[m]<<" ";
     cout<<endl;
    
    
    for(int j=0; j<n2; j++)
    {
        T2[j] = a[mid_ind+1+j];
    }
    
    cout<<"second temp arr"<<endl;                                                                            //printing 2nd temp array
    for(int p=0;p<n2;p++)
        cout<<T2[p]<<" ";
     cout<<endl;
  
    int i=0;
    int j=0;
    int k=first;
   
    while(i<n1 && j<n2)
    {
        if(T1[i]<=T2[j])
        {
            cout<<"value of i in comparison "<<i<<endl;
            a[k] = T1[i];
            i++;
        }
        else
        {
            cout<<"value of j in comparison "<<j<<endl;
            
            a[k] = T2[j];
            j++;
        }
        k++;
        cout<<"value of i,n1,j and n2 and k in comparison "<<i<<" "<<n1<<" "<<j<<" "<<n2<<" "<<k<<endl;
    }
    
    while(i<n1)
    {
        cout<<"value of i,k going to be entered "<<i<<" "<<k<<endl;
        a[k] = T1[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        cout<<"value of j,k going to be entered "<<j<<" "<<k<<endl;
        a[k] = T2[j];
        j++;
        k++;
    }
    
    for(int p=0;p<k;p++)
      cout<<"value "<<a[p]<<" in "<<p<<" index "<<endl;                                                     //printing the temp merged array
    
    delete[] T1;
    delete[] T2;
}

void MergeSort(int *a, int first, int last)
{
    cout<<"first and last in MergeSort "<<first<<" "<<last<<" "<<endl;
    if(first < last)
    {
        int m = (last+first)/2;
        
        MergeSort(a,first,m);
        MergeSort(a,m+1,last);
        
       cout<<"first,mid and last "<<first<<" "<<m<<" "<<last<<endl;
        
        Merge(a,first,m,last);
        cout<<"first,mid and last thus merged "<<first<<" "<<m<<" "<<last<<endl;
    }
}

void printsortedarr(int *a,int size)                                                                          //printing array
{
    for(int i=0;i<size;i++)
      cout<<a[i]<<"  ";
    cout<<endl;
}

int main() {
    int a[14]={25,23,11,-4,-10,-3,-9,-34,-56,-110,-111,-123,34,11};
    int size=14;
	
	printsortedarr(&a[0],size);
	MergeSort(a,0,size-1);
	printsortedarr(a,size);
	
	return 0;
}
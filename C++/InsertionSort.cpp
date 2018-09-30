#include <iostream>
using namespace std;

int main() {
	int a[14]={25,23,11,-4,-10,-3,-9,-34,-56,-110,-111,-123,34,11};
	int i,j,key;
	int n=14;
	
	for(i=1;i<n;++i)
	{
	    key = a[i];
	    j=i-1;
	    while(j>=0 && a[j]>key)
	   {
	    a[j+1]=a[j];
	    
	    cout<<"swapped "<<a[j]<<" in "<<j+1<<endl;
	    j--;
	    
	   }
	   
	   a[j+1] = key;
	   
	   cout<<"value at "<<j+1<<"= "<<key<<endl;
	}
	
	cout<<"printing the sorted array"<<endl;
	for(i=0;i<n;i++)
	{
	    cout<<a[i]<<"\t";
	}
	return 0;
}
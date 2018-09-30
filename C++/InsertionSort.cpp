#include <iostream>
using namespace std;

int main() {
	int a[14]={25,23,11,-4,-10,-3,-9,-34,-56,-110,-111,-123,34,11};
	int i,j,key;
	int n=14;
	
	for(i=1;i<n; i++)
	{
	    key = a[i];                                  //key is being shifted to the right
	    j=i-1;                                       //to increase the sorted array length
	    while(j>=0 && a[j]>key)
	   {                                             //swapping the greater entries to the right side
	    a[j+1]=a[j];
	    
	    cout<<"swapped "<<a[j]<<" in "<<j+1<<endl;
	    j--;
	    
	   }
	   
	   a[j+1] = key;                                 //shifting lower value to its rightful position
	   
	   cout<<"value at "<<j+1<<"= "<<key<<endl;
	}
	
	cout<<"printing the sorted array"<<endl;
	for(i=0;i<n;i++)
	{
	    cout<<a[i]<<"\t";
	}
	return 0;
}
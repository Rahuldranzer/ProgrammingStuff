/* Minimum Swaps or Memory Writes solved using Cycle Sort */

#include <iostream>
using namespace std;


int main() {
    int a[4] = {4,3,2,1};
    int count = 0;
    int len = 4;
    
    for(int cycle_start = 0; cycle_start < len-1; cycle_start++ )
    {
       int item = a[cycle_start], pos = cycle_start;
       cout<<"value of item "<<a[cycle_start]<<endl;
       
       for(int i = cycle_start+1; i < len; i++)
	      //finding the right position
            if(a[i] < item) pos++;
			
        if(pos == cycle_start) continue ; //checking whether the element is already
                                              //in the right position
        while(item == a[pos]) pos++;      //ignoring the duplicates
            
            
        if(a[pos] != item)
           {    swap(a[pos], item);
                cout<<"value of pos for swapping "<<pos<<endl;
                cout<<"Value of item and arr[pos] being swapped "<<item<<" "<<a[pos]<<endl;
           }                 
                 
        while(pos != cycle_start)
           {
               pos = cycle_start;
                
               for(int i = cycle_start+1; i < len; i++)
                   if(a[i] < item) pos++;
                    
               while(item == a[pos]) pos++;
                
               if(item != a[pos])
                {
                    swap(a[pos], item);
                    cout<<"Value of item and arr[pos] being swapped "<<item<<" "<<a[pos]<<endl;
                    count++;
                }
            }	
	 cout<<"the min swaps are "<<count<<endl;
   }	
	for(int i = 0; i < len; i++)
	    cout<<a[i]<<" ";
	return 0;
}
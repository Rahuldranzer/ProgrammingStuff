/* Finding the X's */

#include <iostream>
using namespace std;

int main() {
	//code
	
	int test = 0;
	cin>>test;
	
	while(test--)
	{
	    int x = 0,l = 0,u = 0,count = 0;
	    cin>>x;
	    cin>>l>>u;
	    
	    for(int i = l+1; i < u; i++)
	    {
	        int y = i;
	        while(y > 0)
	        {
	            int z = y%10;
	            if(x == z) count++;
	            y = y/10;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
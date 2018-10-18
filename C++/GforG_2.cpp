/* Geek and his tricky Series */

#include <iostream>
using namespace std;

int main() {
	//code
	
	int test_case = 0;
	
	cin>>test_case;
	const unsigned int m = 1000000007;
	while(test_case--)
	{
	    int n = 0;
	    int term = 7;
	    cin>>n;
	    
	    for(int i = 1; i < n; i++)
	        term = (2*term)%m + i;
	        
	   cout<<term%m<<endl;
	    
	}
	return 0;
}
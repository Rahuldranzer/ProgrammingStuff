/* Finding Palindrome */

#include <iostream>
#include <string>

using namespace std;

bool valid_char(char ch)
{
    if(tolower(ch) >= 'a' && tolower(ch) <= 'z') return 1;
    if( ch >= '0' && ch <= '9') return 1;
    return 0;
}

int main() {
	//code
	
	int test = 0;
	cin>>test;
	
	cin.ignore();
	
	while(test--)
	{
	    string s;
	    getline(cin,s);
	    string res;
	    
	    bool matched = true;
	    
	    int len = s.size();
	    
	    for(int i = 0; i < len; i++)
	    {
	        if(valid_char(s[i]))
	            res += tolower(s[i]);
	    }
	    
	    len = res.size();
	    int i = 0, j = len - 1;
	    
	    while(i<j)
	    {
	        if(res[i] != res[j])
	            matched = false;
	       i++;
	       j--;
	    }
	    
	    cout<<(matched ? "YES\n" : "NO\n");
	}
	return 0;
}
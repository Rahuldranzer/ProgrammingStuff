/* Modifying 2 Strings to remove the common characters
and print the residue combined string */

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2,s3,s4;
    getline(cin, s1);
    getline(cin, s2);
    
    cout<<"The strings are "<<s1<<endl;
    cout<<s2<<endl;
    
  for(int i = 0; i < s2.size(); i++)
  {
    char c = s2[i];
    cout<<"the char is "<<c<<endl;
    
    int j = 0, k = 0;

    while(j < s1.size())
    {
    
     if(c == s1[j])
       s3.push_back(c);
    
     j++;
     cout<<"string common is "<<s3<<endl;
    
    }
 }

 int i = 0,j = 0;
      s4 = s1+s2;
 for(i = 0; i < s3.size(); i++)
 {
     j = 0;
     char c = s3[i];

     cout<<"value of char "<<s3[i]<<endl;
     while(j < s4.size())
     {
         if(c == s4[j]) s4.erase(s4.begin() + j);
         else
            j++;
            cout<<"the combined string is "<<s4<<endl;
     }
 }
 if(s4 == "") cout<<"-1"<<endl;

	return 0;
}
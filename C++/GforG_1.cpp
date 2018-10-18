using namespace std;

int main() {
	int test_case = 0;
	
	cin>>test_case;
	
	while(test_case != 0)
	{
	    int *arr;
	    long int size;
	    int k;
	    bool found = false;
	    cin>>size;
	    
	    arr = new int [size];
	    for(int i = 0; i < size; i++)
	        cin>> arr[i];
	        
	    cin>>k;
	    
	    int i = 0, j = size - 1;
	   
	   while(i < j)
	   {
	       if( k == arr[i] + arr[j])
	       {
	           found = true;
	           cout<<arr[i]<<" "<<arr[j]<<" "<<k<<endl;
	           i++;
	           j--;
	       }
	       else if( k < arr[i] + arr[j])
	            j--;
	            
	       else 
	            i++;
	   }
	   
	   if(found == false)
	    cout<<"-1"<<endl;
	   
	   test_case--; 
	}
	
	return 0;
}

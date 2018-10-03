#include <iostream>
using namespace std;

void populate(int *arr, int size)
{
    int coeff=1;
    //int k=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==0||j==0)
            {
                coeff=1;
                arr[i*(i+1)/2 +j]=coeff;                                    //populating array with Pascal values
            }
            else
            {
                coeff =(coeff*(i-j+1))/j;
                arr[i*(i+1)/2 +j]=coeff;
            }
        }
    }
}

void print(int *arr, int size)
{
    for(int i=0,k=0;(i*(i+1)/2 +k)<size;i++)                                //pyramidal print of Pascal Triangle
    {
        for(int j=size;j>i;j--)
        {
            cout<<" "; 
        } 
        for(k=0;k<=i;k++) 
        {
            cout<<arr[i*(i+1)/2 +k]<<" ";
        }
        cout<<endl;
    }
    
}
 
int main() {
    
    int num=0;
    int size=0;
    int *arr;
    
    cout<<"Enter the number of rows of Pascal Triangle: "<<endl;
    cin>>num;
    
    size= num*(num+1)/2;
    arr = new int[size];                                                 //dynamic memory allocation for array
    
    populate(&arr[0],size);
    print(&arr[0],size);
    
    delete[] arr;                                                        //freeing memory
    return 0;
}
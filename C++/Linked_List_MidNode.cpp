#include <iostream>
#include <cmath>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
    private:
    node *head, *tail;
    
    public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    
    void insert(int n)
    {
        node *temp = new node;
        temp -> data = n;
        temp -> next = NULL;
        
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail -> next = temp;
            tail = tail -> next;
        }
    }
    
    void del(int n)
    {
        node *temp = NULL;
        bool found = false;
        
        while(head != NULL && head -> data == n){
            temp = head;
            head = head -> next;
            delete temp;
            found = true;
        }

        if(head == NULL)
            return;
        
        temp = head;            
        
        while(temp -> next != NULL)
        {
            if ( temp -> next-> data == n )
            {
                node *succ = temp -> next -> next;

                delete temp -> next;
                temp -> next = succ;
                found = true;

            }
            else
            {
                temp = temp -> next;
            }
        }
        
        if(found)
            cout<<"Number deleted"<<endl;
        else
            cout<<"Number "<<n<<" not present "<<endl;
    }
    
    void mid_node()
    {
        node *temp = NULL;
        double counter =0;
        
        for(temp = head; temp != NULL; temp = temp -> next)
            counter++;
            
     cout<<"Number of entries in the list "<<counter<<endl;
     
     temp = head;
     if(counter == 0)
     {
         cout<<"The list is empty "<<endl;
         return;
     }
     else if (counter == 1)
     {
         cout<<"Only 1 entry in the list "<<temp ->data<<endl;
         return;
     }
     else if (counter > 1)
     {
         counter = round(counter/2);
         cout<<"counter value is "<<counter<<endl;                                                   //position of middle node
         
         while(counter >= 2)
         {
             temp = temp -> next;
             counter--;
         }
         
         cout<<"The middle node entry is "<<temp -> data<<endl;
     }
    }
    
    void display()
    {
        node *temp;
        temp = head;
        
        if( head == NULL)
        {
            cout<<"The list is empty "<<endl;
            return;
        }
        
        cout<<"The entries in linked list are "<<endl;
        
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next; 
        }
        
        cout<<endl;
    }
    
};


int main() {
	
	linked_list a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.mid_node();
	a.display();
	
	a.del(3);
	
	a.mid_node();
	a.display();
	return 0;
}
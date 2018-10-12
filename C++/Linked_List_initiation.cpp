#include <iostream>
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
	a.insert(23);
	a.insert(7);
	a.insert(71);
	a.insert(70);
	a.insert(-7);
	a.insert(8);
	a.insert(97);
	
	a.display();
	
	a.del(100);
	
	a.display();
	return 0;
}
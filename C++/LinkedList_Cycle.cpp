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
    
    void make_cycle()
    {
        node *fast = head, *slow = head;
        
        if(NULL == head)
        {
            cout<<"The List is empty "<<endl;
            return;
        }
        
        while((fast != NULL) && (fast -> next != NULL))
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        if(fast == NULL)
            slow -> next = head; 
        else
          fast -> next = slow; 
    }
    
    void detect_loop()
    {
        node *fast = head, *slow = head;
        
        if(NULL == head)
        {
            cout<<"List is empty "<<endl;
            return;
        }
        
        if( NULL == head -> next)
        {
            cout<<" Cycle does not exist "<<endl;                                            // Checking if the list 
            return;                                                                          // contains only 1 item
        }
        
        do{
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        while((fast != NULL) && (fast -> next != NULL) && (fast != slow));                   // (fast -> next) added to prevent
                                                                                             // segmentation fault
        if((fast == NULL) || (fast -> next == NULL))
                cout<<" Cycle does not exist "<<endl;
        else
        {
            cout<<"Cycle exists "<<endl;
            
            node *finder = head;                                                          //m = nodes outside the cycle, r = nodes in the cycle
                                                                                          //l = nodes between ith and the convergent node            
            while( finder != slow)                                                        //iterator 1 and iterator 2 running 
            {                                                                             //from head and ith node, converging to the node
                finder = finder -> next;                                                  //where the cycle starts : l + m = r
                slow = slow -> next;                                                                                                           
            }                                                                                                                                   
                                           
            if( finder == slow)
                cout<<"Cycle enters at "<<slow -> data <<" node"<<endl;                
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
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.detect_loop();
	a.display();

	
	a.make_cycle();
	a.detect_loop();
	
	return 0;
}
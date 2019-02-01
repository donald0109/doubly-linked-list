#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
class List
{
    private:
        struct node *head;
    public:
        List()
        {
            head=NULL;
        }
        node* c_node(int num)
        {
            struct node *temp;
            temp=new (struct node);
            temp->data=num;
            temp->next=NULL;
            temp->prev=NULL;
            return temp;
        }
        void insertAtfront(int num)
        {
            struct node *temp;
            temp=c_node(num);
            if(head==NULL)
            {
                head=temp;
                temp->next=NULL;
                temp->prev=NULL;
            }
            else
            {
                temp->next=head;
                head->prev=temp;
                head=temp;
            }
        }
        void insertAtend(int num)
        {
            struct node *temp,*monk;
            temp=c_node(num);
            monk=head;
            if(head==NULL)
            {
                head=temp;
                temp->next=NULL;
                temp->prev=NULL;
            }
            else
            {
                while(monk->next!=NULL)
                {
                    monk=monk->next;
                }
                monk->next=temp;
                temp->prev=monk;
                temp->next=NULL;
            }
        }
       void insertAtmid(int num,int pos)
        {
            struct node *temp, *monk, *b;
            temp=c_node(num);
            monk=head;
            int c=1;
            if (pos==1)
            {
                if(head==NULL)
                    head=temp;
                else
                {
                    temp->next=head;
                    head->prev=temp;
                    head=temp;
                }
            }
            else
            {
                while(c!=pos-1)
                {
                    monk=monk->next;
                    c++;
                }
                temp->next=monk->next;
                temp->prev=monk;
                monk->next=temp;
                temp=temp->next->prev;

            }
        }
        void Delete()
        {
            int num;
        	struct node *monk, *b;
  			monk=head;
  			if(head==NULL)
            {

                cout<<"The list is Empty\n";
            }
            else{
                    cout<<"Enter the element to delete\n";
            cin>>num;
                if(head->data==num)
  			{
  				head=head->next;
  				head->prev=NULL;
  			}
  			else
  			{
  				while(monk->next!=NULL && monk->data!=num)
  				{
  					b=monk;
  					monk=monk->next;
  				}
  				if(monk->data!=num)
                {

                    cout<<"no element";
                }
                else{
                    b->next=monk->next;
                    b=monk->next->prev;
                }

  			}
            }
        }
        void display()
        {
            struct node *temp;
            temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }

};
int main()
{
    List l;
    int ch,a,posi;
    while(1)
    {
    cout<<"Enter the choice \n 1. INSERT IN START\n 2. INSERT IN END\n 3. INSERT AT MID \n4. DISPLAY \n5. DELETE\n";
    cin>>ch;
    switch(ch)
    {
    	case 1:
    	cout<<"Enter the element to insert \n";
    	cin>>a;
    	l.insertAtfront(a);
    	break;
    	case 2:
    	cout<<"Enter the element to insert \n";
    	cin>>a;
    	l.insertAtend(a);
    	break;
        case 3:
            cout<<"Enter the element to insert \n";
    	cin>>a;
        cin>>posi;
    	l.insertAtmid(a,posi);
    	break;

    	case 4:
    	l.display();
    	break;
    	case 5:
            l.Delete();
            break;
    	default:
    	return 0;
    }
	}
}



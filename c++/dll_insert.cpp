#include <iostream>

using namespace std;

struct node1
{
    node1* prev;
    int data;
    node1* next;
};

class d_llt
{
    private:
        node1* start=NULL;

    public:
        void crt(int v)
        {
            node1* ptr;
            node1* newnode= new node1;
            newnode->data=v;

            if(start==NULL)
            {
                newnode->prev=newnode->next=NULL;
                start=newnode;
            }
            else
            {
                ptr=start;
                while(ptr->next!=NULL)
                    ptr=ptr->next;

                ptr->next=newnode;
                newnode->next=NULL;
                newnode->prev=ptr;
            }
        }

        void d_rev()  // Reverse Function
        {
            node1*ptr;
            ptr=start;

                while(ptr->next!=NULL)
                    ptr=ptr->next;

                while(ptr->prev!=NULL)
                {
                    cout<<ptr->data<<endl;
                    ptr=ptr->prev;
                }
                cout<<ptr->data<<endl;
        }

        void ins_first(int v)
        {
            node1*newnode = new node1;
            newnode->data=v;

            if(start==NULL)
            {
                newnode->next=newnode->prev=NULL;
                start=newnode;
            }
            else
            {
                newnode->prev=NULL;
                newnode->next=start;
                start=newnode;
            }
        }

        void ins_last(int v)
        {
            node1*ptr;
            node1*newnode = new node1;
            newnode->data=v;

            if(start==NULL)
            {
                newnode->next=newnode->prev=NULL;
                start=newnode;
            }
            else
            {
                ptr=start;
                while(ptr->next!=NULL)
                    ptr=ptr->next;

                ptr->next=newnode;
                newnode->prev=ptr;
                newnode->next=NULL;
            }
        }

        void ins_before_value(int v)
        {
            int p;
            node1*ptr;
            node1*pptr;
            node1*newnode = new node1;
            newnode->data=v;

            if(start==NULL)
            {
                newnode->next=newnode->prev=NULL;
                start=newnode;
            }
            else
            {
                cin>>p;
                pptr=ptr=start;
                if(ptr==start && ptr->data==p)
                {
                    newnode->prev=NULL;
                    newnode->next=ptr;
                    start=newnode;
                }
                else
                {
                    while(ptr->data!=p)
                    {
                        pptr=ptr;
                        ptr=ptr->next;
                    }

                    pptr->next=newnode;
                    newnode->prev=pptr;
                    newnode->next=ptr;
                    ptr->prev=newnode;
                }
            }
        }

        void ins_after_value(int v)
        {
            int p;
            node1*ptr;
            node1*pptr;
            node1*newnode = new node1;
            newnode->data=v;

            if(start==NULL)
            {
                newnode->next=newnode->prev=NULL;
                start=newnode;
            }

            else
            {
                cin>>p;
                pptr=ptr=start;
                while(pptr->data!=p)
                {
                    pptr=ptr;
                    ptr=ptr->next;
                }
                if(pptr->next==NULL)
                {
                    pptr->next=newnode;
                    newnode->prev=pptr;
                    newnode->next=NULL;
                }
                else
                {
                    pptr->next=newnode;
                    newnode->prev=pptr;
                    newnode->next=ptr;
                    ptr->prev=newnode;
                }
            }
        }

        void disp()
        {
            node1*ptr;
            ptr=start;
            if(start==NULL)
                cout<<"empty"<<endl;
            else
            {
                while(ptr!=NULL)
                {
                    cout<<ptr->data<<endl;
                    ptr=ptr->next;
                }
            }
        }
};
int main()
{
    d_llt l1;
    int n,val,v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        l1.crt(val);
    }
    cout<<"value to be inserted"<<endl;
    cin>>v;
    //l1.ins_first(v);
    //l1.ins_last(v);
    //l1.ins_before_value(v);

    l1.ins_after_value(v);
cout<<"Insert After Double Linked List"<<endl;
    l1.disp();
    return 0;
}

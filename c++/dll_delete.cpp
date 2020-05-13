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

        void del_first()
        {
            node1*ptr;

            if(start==NULL)
                cout<<"No element\n";
            else
            {
                ptr=start;
                start=ptr->next;
                ptr->next->prev=NULL;
                delete ptr;
            }
        }

        void del_last()
        {
            node1*ptr;
            if(start==NULL)
                cout<<"No element \n";
            else
            {
                while(ptr->next!=NULL)
                    ptr=ptr->next;

                ptr->prev->next=NULL;
                delete ptr;
            }
        }

        void del_after_value(int v)
        {
          int f=0;
            node1*ptr;
            node1*pptr;

            if(start==NULL)
                cout<"No element \n";
            else
            {
                pptr=ptr=start;
                while(ptr!=NULL)
                {
                  if(ptr->data==v)
                    f=1;
                  ptr=ptr->next;
                }
                if(f==1)
                {
                  pptr=ptr=start;
                  while(pptr->data!=v)
                  {
                    pptr=ptr;
                    ptr=ptr->next;
                  }

                  if(pptr->next==NULL)
                    cout<<"No element \n";
                  else if(pptr->next->next==NULL)
                    pptr->next=NULL;
                  else if(pptr==start)
                  {
                    ptr=ptr->next;
                    pptr->next=ptr->next;
                    ptr->next->prev=pptr;
                  }
                  else
                  {
                    pptr->next=ptr->next;
                    ptr->next->prev=pptr;
                  }
                }
                else
                {
                  cout<<"\nNo such element present";
                }
            }
        }

        void del_before_value(int v)
        {
            node1*ptr;
            node1*pptr;

            if(start==NULL)
                cout<"No element \n";
            else
            {
                pptr=ptr=start;
                if(ptr==start && ptr->data==v)
                    cout<<"no element \n";

                else
                {
                    pptr=ptr=start;
                    while(ptr->next->data!=v)
                    {
                        pptr=ptr;
                        ptr=ptr->next;
                    }

                    if(ptr==start)
                    {
                        start=ptr->next;
                        ptr->next->prev=NULL;
                        delete ptr;
                    }
                    else
                    {
                        pptr->next=ptr->next;
                        ptr->prev=pptr;
                        delete ptr;
                    }
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
    cout<<"Value to be deleted after : ";
    cin>>v;
    //l1.del_last();
    //l1.del_first();
    l1.del_after_value(v);
    //l1.del_before_value(v);
    cout<<"DOuble linked list Delete after value"<<endl;
    l1.disp();
    return 0;
}

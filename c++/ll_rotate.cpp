#include<iostream>
using namespace std;

struct node
{
  int data;
  node* next;
};

class ll_rotate
{
  private:
    node*start=NULL;

  public:

    void create_ll(int val)
    {
      node*ptr=start;
      node*newnode=new node;
      newnode->data=val;

      if(start==NULL)
        start=newnode;

      else
      {
        while(ptr->next!=NULL)
          ptr=ptr->next;

         ptr->next=newnode;
      }

      newnode->next=NULL;
    }

    void rot_ll(int k)
    {
      node*ptr=start;
      while(k!=0)
      {
        ptr=ptr->next;
        k--;
      }
      node*s1=start;
      start=ptr;

      while(ptr->next!=NULL){
        ptr=ptr->next;
      }

      ptr->next=s1;

      while(s1->next!=start){
        s1=s1->next;
      }

      s1->next=NULL;

    }

    void disp()
    {
        node*ptr;
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
  ll_rotate l1;

  for(int i=1;i<11;i++)
    l1.create_ll(i);
  l1.disp();

  l1.rot_ll(2);
  l1.disp();

}

#include<iostream>
using namespace std;

struct node1
{
  char val;
  node1 * next;
  node1 * adj;
};


class linked_graph
{
  private:
    node1 * head = NULL;

  public:

    void add_adj(char n1, char n2)
    {

      node1 * ptr1;
      node1 * newnode = new node1;
      newnode-> val = n2;
      newnode->next=newnode->adj=NULL;

      ptr1=head;

      while(ptr1->val!=n1)
        ptr1=ptr1->next;

      if(ptr1->adj == NULL)
        ptr1->adj=newnode;

      else
      {
        ptr1=ptr1->adj;
        while(ptr1->adj!=NULL)
          ptr1=ptr1->adj;

        ptr1->adj= newnode;
      }

    }


    void add_next( char v)
    {
      node1 * ptr;
      node1 * newnode = new node1;
      newnode-> val = v;

      ptr = head;

      if(head==NULL)
          head=newnode;

      else
      {
        while(ptr->next!=NULL)
          ptr=ptr->next;

        ptr->next=newnode;
      }

      newnode->next=newnode->adj=NULL;
    }

    void del_adj(char n1, char n2)
    {
      node1 * ptr1;
      node1 * ptr2;

      ptr1=head;

      while(ptr1->val!=n1)
        ptr1=ptr1->next;

      ptr2=ptr1->adj;

      if(ptr1->adj->val==n2)
      {
        if(ptr1->adj->adj==NULL)
          ptr1->adj=NULL;

        else
          ptr1->adj=ptr1->adj->adj;
      }

      else
      {
        while(ptr2->val!=n2)
          {
            ptr1=ptr2;
            ptr2=ptr2->adj;
          }

          if(ptr2->adj==NULL)
            ptr1->adj=NULL;

          else
            ptr1->adj=ptr2->adj;

          //cout<<"1 "<<ptr1->v<<" 2 "<<ptr2->v<<endl;
      }
    }

    void del_next(char n1)
    {
      node1 * ptr1;
      node1 * ptr2;
      ptr1=head;

      if( ptr1->val==n1)
        {
          cout<<endl<<"1st element"<<endl;
          if(ptr1->next == NULL)
              head=NULL;
          else
            head = ptr1->next;

          delete ptr1;
        }
      else
        {
          while(ptr1->next->val!=n1)
            ptr1=ptr1->next;

          ptr2= ptr1->next;

          if(ptr2->next == NULL)
              ptr1->next = NULL;

          else
            ptr1->next=ptr2->next;

        }
    }


    void disp()
    {
      node1* ptr;
      ptr=head;

      while(ptr!=NULL)
        {
          cout<<ptr->val<< "\t";
          ptr=ptr->next;
        }
      cout<<endl;
    }


    void disp_adj(char n1)
    {
      node1* ptr;
      ptr=head;

      while(ptr->val!=n1)
        ptr=ptr->next;

      cout<<"Adj list of "<<n1<<endl;
      while(ptr->adj!=NULL)
        {
          ptr=ptr->adj;
          cout<<ptr->val<< "\t";
        }
      cout<<endl;
    }
};

int main()
{

  linked_graph g1;
  g1.add_next('a');
  g1.add_next('b');
  g1.disp();

  g1.add_next('c');
  g1.add_next('d');
  g1.disp();

  g1.add_adj('b','c');
  g1.add_adj('b','d');
  g1.add_adj('b','a');

  g1.del_adj('b','a');

  g1.disp_adj('b');

}

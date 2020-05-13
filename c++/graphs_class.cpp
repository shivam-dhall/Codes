#include<iostream>
using namespace std;

// pass this class as a friend class if data needs to be a private one
class Node
{
    char v;
    Node * next;
    Node * adj;

  public:
    Node(char v = '\0')
    {
      this->v=v;
      this->next = NULL;
      this->adj = NULL;
    }

    friend class linked_graph;
};


class linked_graph
{
  private:
    Node * head ;

  public:
    linked_graph()
    {
      head = NULL;
    }

    Node * search_node(char n1)
    {
      Node * ptr1;
      ptr1=head;

      while(ptr1->v!=n1)
        ptr1=ptr1->next;

      return ptr1;
    }

    void addadj(char n1, char n2)
    {
      Node * ptr1;

      ptr1=search_node(n1);

      if(ptr1!=NULL)
      {
        Node * newnode = new Node(n2);

        if(ptr1->adj == NULL)
          ptr1->adj=newnode;

        else
        {
          ptr1=ptr1->adj;
          while(ptr1->next!=NULL)
            ptr1=ptr1->next;

          ptr1->next= newnode;
        }
      }
    }


    void addnode( Node * nw)
    {
      if(head==NULL)
        head=nw;

      else
      {
        Node * ptr;
        ptr=head;

        while(ptr->next!=NULL)
          ptr=ptr->next;

        ptr->next=nw;
      }
    }


    void del_adj(char n1, char n2)
    {
      Node * ptr1;
      Node * ptr2;

      ptr1=search_node(n1);
      ptr2=ptr1->adj;

      if(ptr1->adj->v==n2)
      {
        if(ptr1->adj->next==NULL)
          ptr1->adj=NULL;

        else
          ptr1->adj=ptr1->adj->next;
      }

      else
      {
        while(ptr2->v!=n2)
          {
            ptr1=ptr2;
            ptr2=ptr2->next;
          }

          if(ptr2->next==NULL)
            ptr1->next=NULL;

          else
            ptr1->next=ptr2->next;

          //cout<<"1 "<<ptr1->v<<" 2 "<<ptr2->v<<endl;
      }
    }

    void del_next(char n1)
    {
      Node * ptr1;
      Node * ptr2;
      ptr1=head;

      if( ptr1->v==n1)
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
          while(ptr1->next->v!=n1)
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
      Node* ptr;
      ptr=head;

      while(ptr!=NULL)
        {
          cout<<ptr->v<<"\t";
          ptr=ptr->next;
        }
      cout<<endl;
    }


    void disp_adj(char n1)
    {
      Node * ptr;
      ptr=head;

      while(ptr->v!=n1)
        ptr=ptr->next;

      ptr=ptr->adj;
      cout<<"Adj list of "<<n1<<endl;
      while(ptr!=NULL)
        {
          cout<<ptr->v<< "\t";
          ptr=ptr->next;
        }
      cout<<endl;
    }
};


int main()
{
  linked_graph g1;
  Node * n;

  n= new Node('A');
  g1.addnode(n);

  n= new Node('B');
  g1.addnode(n);

  n= new Node('C');
  g1.addnode(n);

  n= new Node('D');
  g1.addnode(n);

  g1.addadj('B','A');
  g1.addadj('B','C');
  g1.addadj('B','D');
  g1.disp_adj('B');

  g1.disp();

  g1.del_adj('B','D');
  g1.disp_adj('B');

}

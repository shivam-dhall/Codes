#include <iostream>
using namespace std;

struct node1
{
    int data;
    node1 *next;
};

class stack
{
  private:
    node1 *top;

  public:
    stack()
    {
        top = NULL;
    }
    void push(int val)
    {
      node1 *ptr;
      node1 *newnode = new node1;
      newnode->data = val;
      if (top == NULL)
      {
        newnode->next = NULL;
        top = newnode;
      }
      else
      {
        ptr = top;
        node1 *newnode = new node1;
        newnode->data = val;
        newnode->next = top;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
          top = newnode;
      }
    }
    void display()
    {
      node1 *ptr;
      ptr = top;
      while (ptr != NULL)
      {
          cout<< ptr->data<<endl;
          ptr = ptr->next;
      }
    }
    void pop()
    {
      node1 *ptr;
      ptr = top;
      top = ptr->next;
      delete ptr;
    }
};

//void dec_to_bin(stack*,int);
int main()
{
  stack s;
  //int num;
  s.push(5);
  s.push(2);
  s.push(4);
  s.push(9);
  // int inp, n;
  //cout << "Enter decimal No.: ";
  //cin>>num;
  //dec_to_bin(&s,num);
  //cout<<"\nBinary Number is: ";
  s.display();
  //cout<<"\n";
  return 0;
}

//void dec_to_bin(stack * s, int num)
//    {
//        // stack<int> stk;
//        while (num > 0)
//        {
//            int rem = num % 2;
//            num = num / 2;
//            s->push(rem);
//        }
//
//    }

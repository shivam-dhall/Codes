#include <iostream>
#include<stdlib.h>
using namespace std;

void push_stk(int *a,int &t,int n)
{
  int f;
  if(t>=(n-1))
      cout<<endl<<"full"<<endl;
  else
  {
      t++;
      cout<<"Enter Data : ";
      cin>>f;
      a[t]=f;
  }
}

void pop_stk(int &t)
{
  t--;
}

void disp_stk(int *a,int &t)
{
    //cout<<"sdf "<<t<<endl;
    for(int i=t;i>=0;i--)
      cout<<a[i]<<endl;
}
int main()
{
    int top=-1,n,op;
    cin>>n;
    int a[n];
    cout<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
    cin>>op;
    while(op!=4)
    {
        switch(op)
        {
            case 1:
                push_stk(a,top,n);
                break;
            case 2:
                pop_stk(top);
                break;
            case 3:
                disp_stk(a,top);
                break;
        }
        //system("cls");
        cout<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
        cin>>op;
    }
    return 0;
}

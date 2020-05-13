#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
using namespace std;

void enq(int *a,int n,int &f,int &r)
{
  int e;
  if(r==-1 && f==-1)
  {
    cout<<"Enter Data : ";
    cin>>e;
    r=f=0;
    a[f]=e;
  }
  else if(r<(n-1))
  {
    cout<<"Enter Data : ";
    cin>>e;
    a[++r]=e;
  }
  else
    cout<<"Overflow"<<endl;
}

void deq(int &f,int &r)
{
  if(f==-1)
    cout<<"Underflow"<<endl;

  else if(f==r)
    f=r=-1;

  else
    f++;
}

void disp(int *a,int r,int f)
{
  if(f==-1 && r==-1)
    cout<<"Empty";
  else
  {
    system("cls");
    cout<<"Queue\n";
    for(int i=f;i<=r;i++)
      cout<<a[i]<<endl;
  }
}

int main()
{
  int op,n,f=-1,r=-1;
  cout<<"Size : ";
  cin>>n;
  int a[n];
  system("cls");
  cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
  cin>>op;
  while(op!=4)
  {
    switch(op)
    {
      case 1:
        enq(a,n,f,r);
        break;

      case 2:
        deq(f,r);
        break;

      case 3:
        disp(a,r,f);
        Sleep(5000);
        break;
    }
    system("cls");
    cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
    cin>>op;
  }
}

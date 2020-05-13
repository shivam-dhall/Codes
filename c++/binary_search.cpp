#include <iostream>
using namespace std;

int main()
{
  int s,op,b,m,e;
  cout<<("\nEnter size :\n");
  cin>>s;
  int a[s];

  cout<<("Enter Data\n");
  for(int i=0;i<s;i++)
      cin>>a[i];

  cout<<("Enter op\n");
  cin>>op;

  b=0;
  e=s-1;
  while(b<=e)
  {
    m=(b+e)/2;
    if(a[m]==op)
    {
     cout<<("found\n");
     break;
    }
    else if(a[m]>op)
      e=m-1;
    else
      b=m+1;
  }
  return 0;
}

#include <iostream>
using namespace std;

void bs(int *a,int n)
{
  //cout<<(*a);
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        int t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
    }
  }
}
int main()
{
  int n;
  cin>>n;
  int a[n];

  for(int i=0;i<n;i++)
    cin>>a[i];

  bs(a,n);

  cout<<endl<<"Bubble Sorted"<<endl;
  for(int i=0;i<n;i++)
    cout<<a[i]<<endl;

  return 0;
}

#include<iostream>
using namespace std;

int sml(int *a,int j,int n)
{
  int m=a[j];
  int p=j;
  for(int i=j+1;i<n;i++)
  {
    if(m>a[i])
    {
      m=a[i];
      p=i;
    }
  }
  return p;
}

int main()
{
  int n,pos,tp;
  cout<<"Size : ";
  cin>>n;
  int a[n];
  cout<<"Array Elements"<<endl;
  for(int i=0; i<n; i++)
    cin>>a[i];


  for(int i=0;i<n;i++)
  {
    pos=sml(a,i,n);
    tp=a[i];
    a[i]=a[pos];
    a[pos]=tp;
  }

  for(int i=0;i<n;i++)
    cout<<a[i]<<endl;
}

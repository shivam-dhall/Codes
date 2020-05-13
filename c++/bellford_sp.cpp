#include<iostream>
using namespace std;


void bellman_ford(int **a, int *p, int n)
{
  int l;
  cout<<endl<<"Enter source vertex : ";
  cin>>l;
  for(int i=0;i<n;i++)
  {
    if(i==l)
      p[i]=0;
    else
      p[i]=99;
  }

  for(int i=0;i<n;i++)
  {
    if(a[l][i]!=0)
    {
      if(a[l][i]+p[l]<p[i])
        p[i]=a[l][i]+p[l];
    }
  }

  for(int k=0;k<n-1;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(a[i][j]!=0)
        {
          if(a[i][j]+p[i]<p[j])
            p[j]=a[i][j]+p[i];
        }
      }
    }
  }
}

void disp(int *p, int n)
{
  for(int i=0;i<n;i++)
    cout<<p[i]<<" ";
}

int main()
{
  int n;
  cout<<"No. of vertices : ";
  cin>>n;
  int **a;
  int p[n];

  a=new int*[n];
  for(int i=0;i<n;i++)
    a[i]=new int[n];

  for(int i=0 ; i<n ; i++)
  {
    for(int j=0 ; j<n ; j++)
    {
      if(i!=j)
      {
        cout<<"Enter A"<<i+1<<j+1<<" : ";
        cin>>a[i][j];
      }
      else
        a[i][j]=0;
    }
  }

  bellman_ford(a,p,n);
  disp(p,n);

}

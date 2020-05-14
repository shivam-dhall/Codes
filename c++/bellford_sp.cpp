#include<iostream>
using namespace std;


// replace int a[][] to int **a if using runtime size

void bellman_ford(int a[][4], int *p, int n)
{
  int l;
  cout<<endl<<"Enter source vertex [Starting from 0] : ";
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
  int p[n];

  //int a[4][4]={{0,6,0,0},{0,0,1,5},{2,0,0,2},{0,0,0,0}};

  int a[][9]={{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
              { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
              { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
              { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
              { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
              { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
              { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
              { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
              { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};
/*
  int **a;

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
  */

  bellman_ford(a,p,n);
  disp(p,n);

}

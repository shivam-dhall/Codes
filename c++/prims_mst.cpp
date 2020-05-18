#include<iostream>
using namespace std;

int min_edge( int a[][5], int *s, int n)
{
  int p=1000,min;

  for(int i=0;i<n;i++)
  {
    if(s[i]==1)
    {
      for(int j=0;j<n;j++)
      {
        if(a[i][j]!=0 && s[j]!=1 && p>a[i][j])
        {
          p=a[i][j];
          min=j;
        }
      }
    }
  }

  s[min]=1;
  return p;
}

void mst(int a[][5], int n)
{
  int s[n],t[n],u,t1,me,res,j;
  for(int i=0;i<n;i++)
    s[i]=0;

  res=0;
  cin>>u;
  s[u]=1;

  for(j=0;j<n-1;j++)
  {
    me=min_edge(a,s,n);
    res+=me;
  }

    cout<<res;
}

int main()
{
  int n;
  cin>>n;

  int a[5][5] = { {0,2,0,5,8 },
                  {2,0,6,0,0 },
                  { 0,6,0,9,0},
                  { 5,0,9,0,10},
                  { 8,0,0,10,0} };


  /*
  int **a;
  a= new int*[n];
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
  mst(a,n);

}

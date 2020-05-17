#include<iostream>
using namespace std;

int min_edge( int a[][5] ,int *t, int t1,int u, int *s, int n)
{
  int p=100,min;
  for(int j=0;j<n;j++)
  {
    for(int i=0;i<t1;i++)
    {
      if((p>a[u][t[i]]) && s[j]!=1)
      {
        p=a[u][t[i]];
        min=t[i];
      }
    }
  }
  return min;
}

void mst(int a[][5], int n)
{
  int s[n],t[n],u,t1,me,res[n],j;
  for(int i=0;i<n;i++)
    s[i]=0;

  cin>>u;
  s[u]=1;
  res[0]=u;

  for(j=1;j<=n;j++)
  {
    t1=0;
    s[u]=1;
    for(int i=0;i<n;i++)
    {
      if(a[u][i]!=0 && s[i]!=1)
         t[t1++]=i;
    }

    me=min_edge(a,t,t1,u,s,n);
    res[j]=u=me;
  }

  for(int i=0;i<n;i++)
    cout<<res[i];
}

int main()
{
  int n;
  cin>>n;

  int a[5][5] = { { 0, 2, 0, 6, 0 },
                  { 2, 0, 3, 8, 5 },
                  { 0, 3, 0, 0, 7 },
                  { 6, 8, 0, 0, 9 },
                  { 0, 5, 7, 9, 0 } };


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

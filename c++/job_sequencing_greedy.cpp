#include<iostream>
#include<algorithm>
using namespace std;

struct job {
  char a;
  int d,p;
};

void job_seq(job*a, int n, int *state, int *tslot, int tm,char *seq)
{
  int res=0, test=-1,si=0;

  for(int i=0;i<n;i++)
  {
    if(state[i]!=1 || state[i]!=-1)
    {
      if(tslot[a[i].d] !=1)
        {
          state[i]=1;
          tslot[a[i].d]=1;
          res+=a[i].p;
          seq[si++]=a[i].a;
        }
      else
      {
        for(int j= (a[i].d) ; j>0 ; j--)
          {
            test=-1;
            if(tslot[j]==0)
            {
              test=j;
              break;
            }
          }

        if(test!=-1)
        {
          state[i]=1;
          tslot[test]=1;
          seq[si++]=a[i].a;
          res+=a[i].p;
        }
        else
          state[i]=-1;
      }
    }
  }

  cout<<endl<<"Total Profit : "<<res<<endl;
}

int tmax(job * a, int n)
{
  int t=0;
  for(int i=0;i<n;i++)
    if(a[i].d>t)
      t=a[i].d;

  return t;
}

bool cmp(job a, job b)
{
  return(a.p>b.p);
}

int main()
{
  int n,tm;
  cin>>n;
  job a[n];
  int state[n];

  for(int i=0;i<n;i++)
    cin>>a[i].a>>a[i].d>>a[i].p, state[i]=0;

  sort(a,a+n,cmp);
  tm=tmax(a,n);

  int tslot[tm];
  char seq[tm];

  for(int i=1;i<=tm;i++)
    tslot[i]=0;

  job_seq(a,n,state,tslot,tm,seq);

  cout<<endl<<"Seq of tasks executed"<<endl;
  for(int i=0;i<tm;i++)
    cout<<seq[i]<<" ";

}

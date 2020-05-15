#include<iostream>
using namespace std;

void knapsack(int *w,int *p, float *r, int n, int c)
{
  int t=c,i1=0,t2;
  float x[n],t1,res=0;
  for(int i=0;i<n;i++)
    x[i]=0.0;

  while((i1<n) || (t-w[i1]>=0))
  {
    if(w[i1]>c)
      break;
    else if (t-w[i1]>=0)
    {
      x[i1]=1.0;
      res+=p[i1];
      t-=w[i1];
      //cout<<endl<<res<<" "<<t<<" ";
    }
    i1++;
  }

  i1=0;
  while(x[i1]!=0)
    i1++;

  if(t!=0)
    {
      t1=t/float(w[i1]);
      t2=t1*p[i1];
      //cout<<endl<<t2<<endl;
      res+=t2;
    }

  cout<<endl<<"Result : "<<res<<endl;
}


int main()
{
  int n,temp,c;
  cout<<"Enter no. of objects : ";
  cin>>n;
  cout<<"Enter bag capacity : ";
  cin>>c;
  int w[n],p[n];
  float r[n];

  for(int i=0;i<n;i++)
  {
    cin>>w[i]>>p[i];
    r[i]=p[i]/(float(w[i]));
  }

  for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         if (r[i] < r[j]) {
            temp = r[j];
            r[j] = r[i];
            r[i] = temp;

            temp = w[j];
            w[j] = w[i];
            w[i] = temp;

            temp = p[j];
            p[j] = p[i];
            p[i] = temp;
         }
      }
   }

  for(int i=0;i<n;i++)
    cout<<"Weight : "<<w[i]<<"  Profit : "<<p[i]<<"  Ratio : "<<r[i]<<endl;;

  knapsack(w,p,r,n,c);

}

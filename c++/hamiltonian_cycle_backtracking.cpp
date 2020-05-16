
#include<iostream>
using namespace std;

int pathcheck(int a[][5], int *ham_path, int v,int in)
{
    if (a[ham_path[in-1]][ v ] == 0)
      return 0;

    for (int i = 0; i < in; i++)
    {
        if (ham_path[i] == v)
         return 0;
    }
         return 1;
}

int hamiltoniancheck(int a[][5], int *ham_path, int index, int n)
{

    for (int i = 1; i < n; i++)
    {
     if(pathcheck(a , ham_path ,i ,index))
     {
        ham_path[index] = i;

        if(hamiltoniancheck (a, ham_path, index + 1, n)== 1)
            return 1;

        else
            ham_path[index] = -1;
     }
    }

    if (index == n)
    {
        if (a[ham_path[index - 1]][ham_path[0]] == 1)
    		return 1;
    	else
    		return 0;
    }

    return 0;
}

void hamiltonian(int a[][5],int n)
{
	int ham_path[n];
		ham_path[0] = 0;
	for (int i = 1; i < n; i++)
		ham_path[i] = -1;

	if (hamiltoniancheck(a, ham_path, 1, n) == true )
	{
    cout<<"Hamiltonian Cycle "<<endl;
    for (int i = 0; i < n; i++)
      cout << ham_path[i] << " ";

    cout <<ham_path[0]<<endl;
  }

  else
    cout<<endl<<"No Hamiltonian cycle exists"<<endl;

}

int main()
{
  int n;
  cin>>n;

  int a[5][5] = { {0, 1, 1, 0, 1},
                  {1, 0, 1, 1, 1},
                  {1, 1, 0, 1, 0},
                  {0, 1, 1, 0, 1},
                  {1, 1, 0 ,1, 0} };

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
  hamiltonian(a,n);

}

#include<iostream>
using namespace std;

void heapify(int *arr, int size, int i)
{
  if (size == 1)
    cout<<"Single element in the heap"<<endl;

  else
  {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if (l < size && arr[l] > arr[largest])
      largest = l;
    if (r < size && arr[r] > arr[largest])
      largest = r;
    if (largest != i)
    {
      int temp = arr[largest];
      arr[largest] = arr[i];
      arr[i] = temp;
      heapify(arr, size, largest);
    }
  }
}

void disp(int *arr, int n)
{
  for (int i = 0; i<n; i++)
    cout<<arr[i]<<" ";
}

int main()
{
  int n;
  cin>>n;
  int arr[n];

  for(int i=0;i<n;i++)
    cin>>arr[i];

  for (int i= n/2-1 ; i>=0 ; i--)
    heapify(arr, n, i);

  disp(arr,n);
}

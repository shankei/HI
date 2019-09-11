#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void swap(int A[],int i,int p)
{
  int temp=A[i];
  A[i]=A[p];
  A[p]=temp;
}
void partition(int A[],int i,int j,int &k)
{
  int pivot=A[j],l=i-1,r=i;
  while(r<=j-1)
  {
    if(A[r]<=pivot)
    {
      l++;
      swap(A,l,r);
    }
    r++;
  }
  k=l+1;
  swap(A,k,j);

}
int Randomized_FindRank(int A[],int i,int j,int r)
{
  int p;
  if(i<=j)
  {
     srand (time(0)); // it sets seed for random fn

  /* generate secret number between i and j: */
  p = rand() % (j-i+1) + i;
  swap(A,j,p);
  int k;
  partition(A,i,j,k);
  if(r==j-k+1)
  return k;
  else if (r<j-k+1)
  Randomized_FindRank(A,k+1,j,r);
  else
  Randomized_FindRank(A,i,k-1,r-(j-k+1));
  }
}

int main()
{
  int n,r;
  cout<<"enter length of array"<<endl;
	    cin>>n;
	    int arr[n],i;
      cout<<"enter array elements"<<endl;
	    for(i=0;i<n;i++)
	        cin>>arr[i];
          cout<<"enter rank for index"<<endl;
          cin>>r;
          int index=Randomized_FindRank(arr,0,n-1,r);
          cout<<"Element is  = "<<arr[index]<<endl;

	    cout<<endl;
}

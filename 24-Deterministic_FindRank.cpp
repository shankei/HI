#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int Deterministic_FindRank(int*,int,int,int);
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

int D_pivot(int A[],int i,int j)
{
  int t=j-i+1;
  int l=t%5;
  if(t>=5){

  for(int k=0;k<t-l;k+=5)
  {
    sort(A+k,A+k+5);
      swap(A,k/5,(k+5)/2);
  }
  return Deterministic_FindRank(A,i,i+t/5-1,t/10);
}
else
{
  sort(A,A+t);
  return (i+j)/2;
}
}

int Deterministic_FindRank(int A[],int i,int j,int r)
{
  int p;
  if(i<=j)
  {

  /* generate secret number between i and j: */
  p = D_pivot(A,i,j);
  cout<<"pivot="<<p<<endl;
  swap(A,j,p);
  int k;
  partition(A,i,j,k);
  if(r==j-k+1)
  return k;
  else if (r<j-k+1)
  Deterministic_FindRank(A,k+1,j,r);
  else
  Deterministic_FindRank(A,i,k-1,r-(j-k+1));
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
          int index=Deterministic_FindRank(arr,0,n-1,r);
          cout<<"Element is  = "<<arr[index]<<endl;

	    cout<<endl;
}

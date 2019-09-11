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
void RQS(int A[],int i,int j)
{
  int p;
  if(i<=j)
  {
     srand (time(NULL));

  /* generate secret number between 1 and 10: */
  p = rand() % (j-i+1) + i;
  cout<<"random pivot = "<<p<<endl;
  swap(A,j,p);
  int k;
  partition(A,i,j,k);
  RQS(A,i,k-1);
  RQS(A,k+1,j);
  }
}

int main()
{
  int n;
  cout<<"enter length of array"<<endl;
	    cin>>n;
	    int arr[n],i;
      cout<<"enter array elements"<<endl;
	    for(i=0;i<n;i++)
	        cin>>arr[i];
          RQS(arr,0,n-1);
          cout<<"sorted array is "<<endl;
	    for(i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	    cout<<endl;
}

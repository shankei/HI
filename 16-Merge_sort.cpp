#include<iostream>
#include<cstdlib>
using namespace std;
void Merge(int A[], int start, int end,int mid)
{
  int l=start,r=mid+1,k=0,B[end-start+1];
  while((l<=mid)&&(r<=end))
  {
    if(A[l]<=A[r])
    B[k++]=A[l++];
    else
    B[k++]=A[r++];
  }
  while(l<=mid)
  B[k++]=A[l++];
  while(r<=end)
  B[k++]=A[r++];
  l=start;
  k=0;
  while(l<=end)
  {
    A[l++]=B[k++];
  }
}
void Mergesort(int A[],int start,int end)
{
  if(start<end)
  {
    int mid=(start+end)/2;
    Mergesort(A,start,mid);
    Mergesort(A,mid+1,end);
    Merge(A,start,end,mid);
  }
}
int main()
{
  int n;
  cout<<"enter length"<<endl;
  cin>>n;
  int arr[n];

  if(n!=0){
    cout<<"enter array elemenst"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
  Mergesort(arr,0,n-1);
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
}
else
cout<<"wrong length";
cout<<endl;
  return 0;

}

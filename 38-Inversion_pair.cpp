// Find Number of inversion pair
// i<j  A[i]>A[j]
#include<iostream>
#include<cstdlib>
using namespace std;
int Merge(int A[], int start, int end,int mid)
{
  int l=start,r=mid+1,c=0,k=0,B[end-start+1];
  while((l<=mid)&&(r<=end))
  {
    if(A[l]<=A[r])
    {
    //l++;
    B[k++]=A[l++];
      }
    else
    {
    c=c+(mid-l+1);
    //r++;
    B[k++]=A[r++];
    }
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
  return c;
}
int Mergesort(int A[],int start,int end)
{
    int z=0;
  if(start<end)
  {
    int mid=(start+end)/2;
    z= Mergesort(A,start,mid);
    z+=Mergesort(A,mid+1,end);
    z+=Merge(A,start,end,mid);
  }
  return z;
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
int z=Mergesort(arr,0,n-1);
cout<<"inversion pairs = "<<z<<endl;
}
else
cout<<"wrong length";
cout<<endl;
  return 0;

}

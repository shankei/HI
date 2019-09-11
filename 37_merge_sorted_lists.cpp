#include<iostream>
#include<cstdlib>
#include<vector>
#include<iterator>
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

  int n,i,j,t;
  cout<<"enter number of lists to merge"<<endl;
  cin>>n;
  vector<int> v[n];// v is an array of vectors...
  for(i=0;i<n;i++)
  {
    cout<<"enter size of list"<<endl;
    cin>>l;
    cout<<"enter list elements"<<endl;
    for(j=0;j<l;j++)
      {
        cin>>t;
        v[i].push_back(t);
      }
  }
  Mergesort(v,0,n-1);
  return 0;
}

#include<iostream>
using namespace std;
int MaxSubArraysum(int a[],int n)
{
  int max_so_far=a[0];
  int curr_max=a[0];
  for(int i=1;i<n;i++)
  {
    curr_max=max(a[i],curr_max+a[i]);
    max_so_far=max(max_so_far,curr_max);
  }
  return max_so_far;
}
int main()
{
  int a[]={1,2,3,-8,4,-6,5,-7,-5,-4,3,-9};
  int n=sizeof(a)/sizeof(int);
  int max=MaxSubArraysum(a,n);
  cout<<" max sub array sum is= "<<max<<endl;
  return 0;
}

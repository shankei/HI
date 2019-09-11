// element occurs n/k+1 times in array
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
  int n,x,c,k,flag;
  cout<<"enter n and k"<<endl;
  cin>>n>>k;
  cout<<"enter array"<<endl;
  int arr[n],i;
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  sort(arr,arr+n);
  x=arr[0];
  c=1;
  flag=0;
  for(i=1;i<n;i++)
  {
    if(arr[i]==x)
    c++;
    else
    {
      if(c>=(n/k+1))
      {
      cout<<"Majority element is "<<x<<endl;
      flag=1;
       }
      x=arr[i];
      c=1;
    }
  }
  if(c>=(n/k+1))
  {
  flag=1;
cout<<"Majority element is "<<x<<endl;
 }
if(flag==0)
cout<<"No majority element"<<endl;
return 0;

}

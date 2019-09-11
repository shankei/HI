// given stock prices
// make max profit , you can buy once sell once
#include<iostream>
using namespace std;
int main()
{
  int n,k=0,t=0;
  cout<<"enter n"<<endl;
  cin>>n;
  cout<<"enter array"<<endl;
  int arr[n],i,max,j;
  for(i=0;i<n;i++)
    cin>>arr[i];
  max=0;
  i=0;
  for(j=1;j<n;j++)
  {
    if(arr[j]-arr[i]>max)
    {
      t=i;
      k=j;
    max=arr[j]-arr[i];
  }
    if(arr[i]>arr[j])
    i=j;
  }
if(max>0){
cout<<"max profit can be made is "<<max<<endl;
cout<<"buy at "<<t+1<<" sell at "<<k+1<<endl;
}
else
cout<<"No profit on this share kindly do not buy this one"<<endl;


  return 0;
}

// given stock prices
// make max profit , you can buy once sell once
// once you buy you can sell within L days
#include<iostream>
using namespace std;
int main()
{
  int n,k,t,l,r,a;
  cout<<"enter n and l"<<endl;
  cin>>n>>l;
  cout<<"enter array"<<endl;
  int arr[n],i,max,j;
  for(i=0;i<n;i++)
    cin>>arr[i];
  max=0;
  i=0;
  r=0;
  a=0;
  int S[n];
  for(j=1;j<n;j++)
  {
    if(j-i>l)
    {  a++;
      i=S[a];
    }
    if(arr[j]-arr[i]>max)
    max=arr[j]-arr[i];
   cout<<max<<endl;
    while(r>=i&&arr[S[r]]>arr[j])
    r--;

  r++;
  S[r]=j;
  }
if(max>0){
cout<<"max profit can be made is "<<max<<endl;
}
else
cout<<"No profit on this share kindly do not buy this one"<<endl;


  return 0;
}

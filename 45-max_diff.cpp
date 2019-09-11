#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int n,max,min,c;
  cout<<"enter n"<<endl;
  cin>>n;
  cout<<"enter array"<<endl;
  int arr[n],i;
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  max=arr[0];
  min=arr[0];
  for(i=1;i<n;i++)
  {
    if(arr[i]>max)max=arr[i];
    if(arr[i]<min)min=arr[i];
  }
  cout<<"Max diff is = "<<abs(max-min)<<endl;
  return 0;

  }

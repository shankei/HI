#include<iostream>
using namespace std;
int main()
{
  int n,x,c;
  cout<<"enter n"<<endl;
  cin>>n;
  cout<<"enter array"<<endl;
  int arr[n],i;
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  x=arr[0];
  c=1;
  for(i=1;i<n;i++)
  {
    if(x==arr[i])c++;
    else
    {
      if(c>0)c--;
      else
      {
        c=1;
        x=arr[i];
      }
    }
  }
  c=0;
  for(i=0;i<n;i++)
  {
    if(x==arr[i])c++;
  }
if(c>(n/2))
cout<<"Majority element is "<<x<<endl;
else
cout<<"No majority element"<<endl;
return 0;

}

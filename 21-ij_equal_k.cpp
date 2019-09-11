//sum of a[i] and a[j] == x
#include<iostream>
#include<algorithm>
using namespace std;

bool fun1(long long int n,long long int a[])
{
  long long int l=0,r=n-1,k,x,flag=0;
  for(k=0;k<n;k++)
  {
    x=a[k];
    l=0,r=n-1;
  while(l<r)
  {
    if(a[l]+a[r]==x){
      flag=1;
    cout<<a[l]<<" + "<<a[r]<<" = "<<x<<endl;
    }
    if(a[l]+a[r]<x)
    l++;
    else
    r--;
  }
}
  return flag==1;
}
/*bool fun2(long long int n,long long int x,long long int a[])
{
  long long int i;
  for(i=0;i<n;i++)
  {
    if(binary_search(a,a+n,x-a[i]))
    return true;
  }
    return false;
}


bool fun3(long long int n,long long int x,long long int a[])
{
  long long int i,arr[1000000]={0};
  for(i=0;i<n;i++)
  arr[a[i]]=1;
  for(i=0;i<n;i++)
  {
    if(arr[x-a[i]]==1)
    return true;
  }
    return false;
}
*/

int main()
 {

	    long long int n;
      cout<<"enter n"<<endl;
	    cin>>n;
	    long long int arr[n],i;
      cout<<"enter array"<<endl;
	    for(i=0;i<n;i++)
	        cin>>arr[i];
          sort(arr,arr+n);

          if(fun1(n,arr))
          cout<<"Yes sum exists"<<endl;
          else
          cout<<"sum do not exist"<<endl;

        /*
          if(fun2(n,x,arr))
          cout<<"Yes sum exists"<<endl;
          else
          cout<<"sum do not exist"<<endl;

          if(fun3(n,x,arr))
          cout<<"Yes sum exists"<<endl;
          else
          cout<<"sum do not exist"<<endl;
          */

	return 0;
}

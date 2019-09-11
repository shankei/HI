// element occurs n/k+1 times in array
#include<iostream>
using namespace std;
int ct(int k,int A[],int n)
{
  int count=0;
  for(int i=0;i<n;i++)
  if(A[i]==k)
  count++;
  return count;
}
int main()
{
  int n,k;
  cout<<"enter n and k"<<endl;
  cin>>n>>k;
  cout<<"enter array"<<endl;
  int arr[n],i,count[k][2]={0},flag=0;
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
  }
int z=0,j,q=0,nc=0,f=0,tp;
count[z][0]=arr[0];
count[z][1]++;
  for(i=1;i<n;i++)
  {
    nc=0;
    tp=0;
    for(j=0;j<=z;j++)
    {
    if(count[j][0]==arr[i])
    {
      nc=1;
    count[j][1]++;
    break;
    }
    }

   if(z<k-1&&nc==0)
    {
      z++;
      count[z][0]=arr[i];
      count[z][1]++;
    }
    else if(z==k-1&&nc==0)
        {
          for(j=0;j<=z;j++)
          {
            if(count[j][1]==0)
            {
            count[j][0]=arr[i];
            count[j][1]++;
            tp=1;
            break;
            }
          }
        }
     if(tp==0&&nc==0)
        {
        for(j=0;j<=z;j++)
        count[j][1]--;
        }
    }
for(i=0;i<k;i++)
{
  if(ct(count[i][0],arr,n)>=((n/k)+1))
  {
cout<<"Majority element is "<<count[i][0]<<endl;
f=1;
}
}
if(f==0)
{
cout<<"No majority element"<<endl;
}
return 0;

}



//min heap


#include<iostream>
using namespace std;
void Add(int H[],int n,int x)
{
  H[++n]=x;
}
void Bottom_up_heapify(int H[],int i)
{
  int p=(i-1)/2,t;
  while(p>=0)
  {
    if(H[p]>=H[i])
    {
      t=H[i],H[i]=H[p],H[p]=t;
      i=p;
      p=(i-1)/2;
    }
    else
    break;
  }
}
void Top_down_heapify(int H[],int i,int n)
{
  int l,r,j,t;
  l=2*i+1;
  r=2*i+2;
  while(r<n)
  {
    if(H[l]<H[r])
    j=l;
    else
    j=r;
    if(H[j]<H[i])
    {
        t=H[i];
        H[i]=H[j];
        H[j]=t;
        i=j;
        l=2*i+1;
        r=2*i+2;
    }
  }
  if((l==n-1)&&(H[l]<H[i]))
    {
      t=H[i],H[i]=H[l],H[l]=t;
    }
}

void Build_Heap(int H[],int n)
{
  int i;
  for(i=n-1/2;i>=0;i--)
  Top_down_heapify(H,i,n);
}
int min_Delete(int H[],int n)
{
  int t=H[n-1];
  H[n-1]=H[0];
  H[0]=t;
  n--;
  Top_down_heapify(H,0,n);
  return H[n];
}
int main()
{

  int n,i;
  cout<<"enter number of elements to be inserted heap"<<endl;
  cin>>n;
  cout<<"enter array"<<endl;
  int arr[n];
  for(i=0;i<n;i++)
    cin>>arr[i];
    Build_Heap(arr,n);
    int k=0,j=1;
    for(i=0;i<n;i++)
      {
        cout<<arr[i]<<" ";
        k++;
      if(k==j)
      {
      cout<<endl;
      j=j*2;
      k=0;
      }
    }
    cout<<endl;
  return 0;
}

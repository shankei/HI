#include<iostream>
#include<string>
#define mod 83
using namespace std;
int Rabin_karp(string txt,string pat,int base)
{
  int x=pat[0]-'0',y=txt[0]-'0',c=base;


  int p=pat.length();
  int t=txt.length();
  int arr[t],top=-1;
  for(int i=1;i<p;i++)
  {
    x=(x*base+pat[i]-'0')%mod;
    y=(y*base+txt[i]-'0')%mod;
    c=(c*base)%mod;
  }
  for(int i=p;i<=t;i++)
  {
    int check=1;
    if(x==y)
    {
      for(int j=0;j<p;j++)
      {
        if(pat[j]!=txt[i-p+j])
        {
          check=0;
          break;
        }
      }
      if(check==1)
      arr[++top]=i-p;
    }
    y=(y*base+txt[i]-'0')%mod;

    y=(y-(c)*(txt[i-p]-'0'))%mod;

  }
  for(int i=0;i<=top;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
    cout<<"The pattern occurs "<<top+1<<" times"<<endl;
return 1;
}
int main()
{
  int t=Rabin_karp("11010100110100","100",2);

  return 0;
}



#include<iostream>
#include<string>
#include<vector>
#define mod 83
using namespace std;
int RH(string txt1,string txt2,int base,int len)
{
  int x,y,counter=0;


  int t1=txt1.length();
  int t2=txt2.length();
  vector<int> v[mod];
  for(int i=0;i<=t1-len;i++)
  {
    x=txt1[i]-'0';
    for(int j=i+1;j<i+len;j++)
    x=(x*base+txt1[j]-'0')%mod;
    v[x].push_back(i);
  }

  for(int i=0;i<=t2-len;i++)
  {
    y=txt2[i]-'0';
    for(int j=i+1;j<i+len;j++)
    y=(y*base+txt2[j]-'0')%mod;

    for (auto k = v[y].begin(); k != v[y].end(); ++k)
        {
            if(v[y].size())
            {
            int check=1;
            for(int n=*k;n<=len+*k;n++)
            {

                  if(txt1[n]!=txt2[i+n-*k])
                  {
                    check=0;
                    break;
                  }
              }
              if(check==1)
              {
              counter++;
              cout<<"txt1="<<*k<<endl;
              cout<<"txt2="<<i<<endl;
            }
          }
        }
      }


  cout<<endl;
    cout<<"The pattern occurs "<<counter<<" times"<<endl;
return 1;
}
int main()
{
  int t=RH("1","1",2,1); // txt1 txt2 base length

  return 0;
}
//

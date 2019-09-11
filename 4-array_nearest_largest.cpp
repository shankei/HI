// given an array calculate array r such that r[i]=min j such that arr[j]>=arr[i];
// r= position of nearest greatest no.to right side.
#include<iostream>
using namespace std;

int main()
{
	int n,i;
cout<<"enter n"<<endl;
   cin >>n;

	int arr[n],s[n],R[n];
	cout <<"enter array"<<endl;

	for(i=0;i<n;i++)
	cin>>arr[i];

	int top=-1;
	for(i=0;i<n;i++)
	{
		while(top>-1&&arr[s[top]]<=arr[i])
		R[s[top--]]=i;

		s[++top]=i;

	}
	while(top>-1)
	R[s[top--]]=n;
	cout<<"\n";
	for(i=0;i<n;i++)
	cout<<R[i]<<" ";
	return 0;
}

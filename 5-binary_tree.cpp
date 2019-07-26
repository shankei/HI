//#include <bits/stdc++.h>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
	int info;
	struct node *lchild,*rchild;
}btree;
btree *find(btree *root,int p)
{
	btree *t=NULL;
	if(root==NULL||root->info==p)
		return root;
	 t=find(root->lchild,p);
	if(t==NULL)
		t=find(root->rchild,p);
	return t;
}
btree *insert(btree *root,int parent,int child,char direction)
{
	btree *p,*node;
	p=(btree*)malloc(sizeof(btree));
	p->info=child;
	p->rchild=NULL;
	p->lchild=NULL;
	if(root==NULL)
	{
		root=(btree*)malloc(sizeof(btree));
		root->info=parent;
		if(direction=='L'||direction=='l')
		{
			root->lchild=p;
			root->rchild=NULL;
		}
		else
		{
			root->rchild=p;
			root->lchild=NULL;
		}
	}
	else{
		node=find(root,parent);
		if(direction=='L'||direction=='l')
			node->lchild=p;
		else
			node->rchild=p;
	}
	return root;
}
btree *make()
{
  int parent,child;
  btree *root=NULL;
  char c;
  int n;
  cout<<"Enter total nodes excluding root:";
  cin>>n;

  while(n>0)
  {
    cout<<"Enter parent node:"<<endl;
    cin>>parent;
    cout<<"Enter child node:"<<endl;
    cin>>child;
    cout<<"l for left child and r for right child:"<<endl;
    cin>>c;
    if(c=='L'||c=='R'||c=='l'||c=='r')
      root=insert(root,parent,child,c);
    else
    {
      cout<<"INVALID INPUT"<<endl;
      break;
    }
    n--;
  }
  cout<<endl;
  return root;
}


int main()
{
	make();
return 0;
}

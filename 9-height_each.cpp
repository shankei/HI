//#include <bits/stdc++.h>
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
	int info;
	struct node *lchild,*rchild;
}btree;


int height_of_tree(btree *root,int height)
{
  if(root==NULL)return -1;
  int lc=height_of_tree(root->lchild,height);
  int rc=height_of_tree(root->rchild,height);
  height=(lc>rc)?lc+1:rc+1;
    cout<<"node : "<<root->info<<" height : "<<height<<endl;
    return height;
}

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
    cout<<"Enter parent node ,Enter child node ,l for left child and r for right child:"<<endl;
    cin>>parent;

    cin>>child;

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
	btree *root;
	root=make();
  height_of_tree(root,0);
  cout<<endl;
return 0;
}

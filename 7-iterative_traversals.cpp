//#include <bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include <stack>
using namespace std;
typedef struct node
{
  int info;
    char tm='f';
  struct node *lchild,*rchild;
}btree;

void visit(btree *x)
{
  cout<<x->info<<" ";
}


void inorder( btree *root)
{
  int tp=0;
   stack<btree*> s;
   s.push(root);
  tp++;
  root->tm='f';
  while(tp)
  {
    btree *x;
    x=s.top();
    s.pop();
    tp--;
    if(x->tm=='f')
    {
      if(x->rchild)
      {
      s.push(x->rchild);
      tp++;
      x->rchild->tm='f';
      }
      
      s.push(x);
      tp++;
      x->tm='t';

      if(x->lchild)
      {
        s.push(x->lchild);
        tp++;
        x->lchild->tm='f';
      }
    }
    else
      {
      visit(x);
      }
  }
}




void preorder(btree *root)
{
  int top=0;
   stack<btree*> s;
   s.push(root);
  top++;
  while(top)
  {
    top--;
    btree *x;
    x=s.top();
    s.pop();
    visit(x);
    if(x->rchild)
    {
    s.push(x->rchild);
    top++;
    }

    if(x->lchild)
    {
    s.push(x->lchild);
    top++;
    }
  }
}
void postorder( btree *root)
{
  int tp=0;
   stack<btree*> s;
   s.push(root);
  tp++;
  root->tm='f';
  while(tp)
  {
    btree *x;
    x=s.top();
    s.pop();
    tp--;
    if(x->tm=='f')
    {
      s.push(x);
      tp++;
      x->tm='t';
      if(x->rchild)
      {
      s.push(x->rchild);
      tp++;
      x->rchild->tm='f';
      }

      if(x->lchild)
      {
        s.push(x->lchild);
        tp++;
        x->lchild->tm='f';
      }
    }
    else
      {
      visit(x);
      }
  }
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
  p->tm='f';
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
int main()
{
	int parent,child,left,right;
	btree *root=NULL;
	char c;
	int n;
	cout<<"Enter total nodes excluding root:";
	cin>>n;

	while(n>0)
	{
    cout<<"Enter parent node Enter child node l for left child and r for right child:"<<endl;
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
  cout<<"ped bn gaya"<<endl;
    cout<<"preorder ="<<endl;
  preorder(root);
  cout<<endl;
  cout<<"inorder ="<<endl;
inorder(root);
cout<<endl;
    cout<<"postorder"<<endl;
  postorder(root);
    cout<<endl;
return 0;
}

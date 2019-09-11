//bst
// max height of trre
//min height of tree
#include<iostream>
#include<cstdlib>
using namespace std;
struct nd
{
int value;
struct nd *lchild,*rchild;
};
typedef struct nd node;
node* insert(node *head,int val)
{

	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->value=val;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		if(val>head->value)
		head->rchild=insert(head->rchild,val);
		else
		head->lchild=insert(head->lchild,val);
	}
	return head;
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int height(node *root)
{
	if(root==NULL)
	return -1;
	if(root->lchild==NULL&&root->rchild==NULL)
	return 0;
	else
	return max(height(root->lchild),height(root->rchild))+1;
}

int max_height(node *root)
{
	if(root==NULL)
	return -1;
  if(root->lchild==NULL&&root->rchild==NULL)
  return 0;
	return max(max_height(root->lchild),max_height(root->rchild))+1;
}
int min(int a,int b)
{
	if(a>b)
	return b;
	else
	return a;
}
int min_height(node *root)
{
  if(root==NULL)
  return -1;
  if(root->lchild==NULL&&root->rchild==NULL)
  return 0;
	return min(min_height(root->lchild),min_height(root->rchild))+1;
}



int main()
{
	int n,val;
	node *head=NULL;
  cout<<"enter size of list"<<endl;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		head=insert(head,val);
	}
	int h=max_height(head);
	cout<<"max height of tree= "<<h<<endl;
  int min=min_height(head);
  cout<<" min height of tree= "<<min<<endl;

  return 0;
}

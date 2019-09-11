//bst
// search node
// delete  node

// inorder predecessor
// inorder successor

#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct nd
{
int key;
struct nd *lchild,*rchild;
} node;

void inorder(node *root)
{
  if(root==NULL)return;

  inorder(root->lchild);
  cout<<root->key<<" ";
  inorder(root->rchild);
}
node* insert(node *head,int val)
{
if(head==NULL)
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->key=val;
		temp->lchild=NULL;
		temp->rchild=NULL;
		head=temp;
	}
	else
	{
		if(val>head->key)
		head->rchild=insert(head->rchild,val);
		else
		head->lchild=insert(head->lchild,val);
	}
	return head;
}

node* Search(node *root,int num)
{
  if(root)
  {
  if(root->key==num)
  return root;
  else if(root->key<num)
  return Search(root->rchild,num);
  else
  return Search(root->lchild,num);
  }
else
return NULL;
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(node *root, node*& pre, node*& suc, int key)
{
  // Base case
    if (root == NULL)  return ;
  // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->lchild != NULL)
        {
            node* tmp = root->lchild;
            while (tmp->rchild)
                tmp = tmp->rchild;
            pre = tmp ;
        }
  // the minimum value in right subtree is successor
        if (root->rchild != NULL)
        {
            node* tmp = root->rchild ;
            while (tmp->lchild)
                tmp = tmp->lchild ;
            suc = tmp ;
        }
        return ;
    }
// If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
				// set successor eqaul root beacuse it is possible that root doesnt have a right child
        findPreSuc(root->lchild, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
				// set predecessor eqaul root beacuse it is possible that root doesnt have a left child
        findPreSuc(root->rchild, pre, suc, key) ;
    }
}

 node* minValueNode(node *root)
 {
   node *current = root;

    /* loop down to find the leftmost leaf */
    while (current && current->lchild != NULL)
        current = current->lchild;

    return current;
}
node* deleten(node *root,int key)
{

  if(root==NULL)return NULL;

  if(root->key<key)
  root->rchild=deleten(root->rchild,key);
  else if(root->key>key)
  root->lchild=deleten(root->lchild,key);
else
  {
  	if(root->lchild==NULL)
  		{
    	node *temp=root->rchild;
    	free(root);
    	cout<<"node deleted"<<endl;
    	return temp;
  		}
  	else if(root->rchild==NULL)
  		{
  		node *temp=root->lchild;
    	free(root);
    	cout<<"node deleted"<<endl;
    	return temp;
  		}
		else if(root->lchild!=NULL&&root->rchild!=NULL)
			{
  		node* temp = minValueNode(root->rchild);

          // Copy the inorder successor's content to this node
          root->key = temp->key;

          // Delete the inorder successor
          root->rchild = deleten(root->rchild, temp->key);
    }
  }
      return root;
}

int main()
{
	int n,val,key;
	node *head=NULL,*pre=NULL,*suc=NULL;
  cout<<"enter size of bst"<<endl;
	cin>>n;
	int i;
	cout<<"enter bst elements"<<endl;
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		head=insert(head,val);
	}
	cout<<"inorder= "<<endl;
	inorder(head);
  cout<<"enter key to search"<<endl;
  cin>>key;
  if(Search(head,key))
  cout<<"yes node exist"<<endl;
  else
  cout<<"node does not exist"<<endl;
  cout<<"enter key to find inorder predecessor and successor"<<endl;
  cin>>key;
  if(Search(head,key)!=NULL)
  findPreSuc(head,pre,suc,key);
  else
  cout<<"node does not exist"<<endl;
  if(pre!=NULL)
  cout<<"predecessor = "<<pre->key<<endl;
  if(suc!=NULL)
  cout<<"successor = "<<suc->key<<endl;
  cout<<"enter key to delete"<<endl;
  cin>>key;
  if(Search(head,key)!=NULL)
  {
  head=deleten(head,key);
  if(Search(head,key))
  cout<<"yes node still exists"<<endl;
  else
  cout<<"I Searched now and find that node does not exist"<<endl;
  }
  else
    cout<<"node does not exist"<<endl;
		cout<<"inorder = "<<endl;
			inorder(head);
  return 0;
}

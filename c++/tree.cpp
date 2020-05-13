#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

using namespace std;

#define COUNT 10

struct node1
{
  int data;
  node1 * left;
  node1 * right;
};

int size_tree(node1* root)
{
  if (root == NULL)
    return 0;
  else
    return(size_tree(root->left) + 1 + size_tree(root->right));
}

int height_bst(node1* root)
{
  if(root==NULL)
    return -1;

  return 1+max(height_bst(root->left),height_bst(root->right));
}

void print2DUtil(node1 *root, int space)
{
  if (root == NULL)
    return;
  space += COUNT;

  print2DUtil(root->right, space);
  cout<<endl;

  for (int i = COUNT; i < space; i++)
    cout<<" ";

  cout<<root->data<<endl;
  print2DUtil(root->left, space);
}

void print2D(node1 *root)
{
  print2DUtil(root, 0);
}


node1* min_value(node1* root)
{
	while(root->left != NULL)
    root = root->left;
	return root;
}

node1* del_bst(node1* root, int v)
{
	if(root == NULL)
    return root;

  else if(v < root->data)
    root->left = del_bst(root->left,v);

  else if (v > root->data)
    root->right = del_bst(root->right,v);

  else if(v == root->data)
  {
		if(root->left == NULL && root->right == NULL)
    {
			delete root;
			root = NULL;
		}

		else if(root->left == NULL)
    {
			node1 *temp = root;
			root = root->right;
			delete temp;
		}

		else if(root->right == NULL)
    {
			node1 *temp = root;
			root = root->left;
			delete temp;
		}
		else
    {
			node1 *temp = min_value(root->right);
			root->data = temp->data;
			root->right = del_bst(root->right,temp->data);
		}
	}
	return root;
}

node1 *ins(node1 *root,int v)
{
  if(root==NULL)
  {
    root=new node1();
    root->data=v;
    root->left=root->right=NULL;
  }

  else if(v<=root->data)
    root->left=ins(root->left,v);

  else
    root->right=ins(root->right,v);

  return root;
}

void src(node1*root,int v)
{
  int c=0;
  node1 * ptr= root;
  while(ptr!=NULL)
  {
    if(v>ptr->data)
      ptr=ptr->right;

    else if(v<ptr->data)
      ptr=ptr->left;

    else if(v==ptr->data)
      {
        c=1;
        cout<<"found";
        break;
      }
    }
      if(c==0)
        cout<<"Not Found";
}

void preorder(node1 *root)
{
   if(root==NULL)
     return;

   else
   {
     cout<<root->data<<"\t";
     preorder(root->left);
     preorder(root->right);
   }
}

void inorder(node1 *root)
{
  if(root==NULL)
    return;

  else
  {
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
  }
}

void postorder(node1 *root)
{
  if(root==NULL)
    return;

  else
  {
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
  }
}

int main()
{
   node1 *root=NULL;
   int v,op,p;

   system("cls");
   cout<<"\n1.Insert\n2.Delete\n3.Height\n4.Display\n5.2D Display\n6.Size\n7.Search\n8.Exit\n";
   cin>>op;
   while(op!=8)
   {
     switch(op)
     {
        case 1:
          cin>>v;
          root=ins(root,v);
          break;

        case 2:
          cin>>v;
          root = del_bst(root,v);
          break;

        case 3:
          cout<<"\nHeight : "<<height_bst(root)<<endl;
          break;

        case 4:
          cout<<"\n1.Inordert\n2.Postorder\n3.Preorder\n";
          cin>>p;
          switch(p)
          {
            case 1:
              inorder(root);
              break;
            case 2:
              postorder(root);
              break;
            case 3:
              preorder(root);
              break;
          }
          Sleep(5000);
          break;

        case 5:
          print2D(root);
          break;

        case 6:
          cout<<endl<<"Size : "<<size_tree(root)<<endl;
          break;

        case 7:
          cin>>v;
          src(root,v);
          break;

     }
     //system("cls");
     cout<<"\n1.Insert\n2.Delete\n3.Height\n4.Display\n5.2D Display\n6.Size\n7.Search\n8.Exit\n";
     cin>>op;
   }
}

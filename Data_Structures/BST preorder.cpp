#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;
struct node* temp1;

void insrt(int value)
{
    struct node* nwnode=(struct node*)malloc(sizeof(struct node));
    nwnode->data=value;
    nwnode->left=NULL;
    nwnode->right=NULL;
    if(root==NULL)
    {
        root=nwnode;
    }
    else
    {
        struct node* temp=root;
        while(1)
        {
            if(nwnode->data <= temp->data)///condition true hole left e jabe
            {
                if(temp->left==NULL)
                {
                    temp->left=nwnode;
                    break;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=nwnode;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }
}

void preorder(struct node* r)
{
    if(r==NULL)
        return;
    vec.push_back(r->data);
    preorder(r->left);
    preorder(r->right);
}

int main()
{
   root=NULL;
   int i,j,k,l,n;
   cin>>n;         ///number of node
   for(i=1; i<=n; i++)
   {
       cin>>k;
       insrt(k);
   }
   preorder(root);   ///root-> left sub-tree-> right sub-tree
   for(i=0; i<vec.size(); i++)
       cout<<vec[i]<<" ";
   cout<<endl;
   return 0;
}


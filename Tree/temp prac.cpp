#include <iostream>
using namespace std;
class node
{
    public:
    node *left;
    node *right;
    int data;
};
class tree
{
    public:
        node *root;
        tree()
        {
            root=NULL;
        }
        void create();
        void inorder(node *root);
        void preorder(node *root);
        void postorder(node *root);
        int search (node *root,int num);
        void deletenode(node *root,int num);
};
void tree::create()
{
    int val;
    char choice;
    do
    {
        
        cout<<"Enter the value to be enetered in BST :";
        cin>>val;
        node *newnode=new node;
        newnode->left=newnode->right=NULL;
        newnode->data=val;
        if (root==NULL)
            root=newnode;
        else
        {
            node *temp=root;        
                while(1)
                {
                    if (val<temp->data)
                    {
                        if (temp->left==NULL)
                        {
                            temp->left=newnode;
                            break;
                        }
                        else
                            temp=temp->left;
                    }
                    else
                    {
                        if (temp->right==NULL)
                        {
                            temp->right=newnode;
                            break;
                        }
                        else
                        {
                            temp=temp->right;
                        }
                    }
                }
        }   
        cout<<"Any more nodes? (y/n) :";
        cin>>choice;
    }
    while (choice=='y' || choice=='Y');
}
void tree::inorder(node *root)
{
    if (root==NULL)
        return;
    node *temp=root;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}
void tree::preorder(node *root)
{
    if (root==NULL)
        return;
    node *temp=root;
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
void tree::postorder(node *root)
{
    if (root==NULL)
        return;
    node *temp=root;
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}
int tree::search(node *root,int num)
{
    if (root==NULL)
        return 0;
    if (root->data==num)
        return 1;
    else if (root->data>num)
        return search(root->left,num);
    else
        return search(root->right,num);
}
void tree::deletenode(node *root,int num)
{
    node *temp=root,*parent,*father,*r,*son;
    while (temp!=NULL && temp->data!=num)
    {
        parent=temp;
        if (num<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if (temp==NULL)
    {
        cout<<"NUmber not found!"<<endl;
        return;
    }
    if (temp->left==NULL)
        r=temp->right;
    else if (temp->right==NULL)
        r=temp->left;
    else
    {
        father=temp;
        r=temp->right;
        son=r->left;
        while (son!=NULL)
        {
            father=r;
            r=son;
            son=r->left;
        }
        if (father!=temp)
        {
            father->left=r->right;
            r->right=temp->right;
        }
        r->left=temp->left;
    }
    if (parent==NULL)
    {
        root=r;
    }
    else
    {
        if (parent->left==temp)
        {
            parent->left=r;
        }
        else
        {
            parent->right=r;
        }
    }
    delete temp;
}

int main()
{
    tree t;
    t.create();
    cout<<"Inorder :";
    t.inorder(t.root);
    cout<<"\nPreorder :";
    t.preorder(t.root);
    cout<<"\nPostorder :";
    t.postorder(t.root);

    int found = t.search(t.root,3);
    if (found==1)
        cout<<"\nNumber found";
    else if (found==0)
        cout<<"\nNumber not found";
    t.deletenode(t.root,4);
    cout<<"\nInorder after deletion :";
    t.inorder(t.root);
}
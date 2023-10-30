//tree
#include <iostream>
using namespace std;
class node
{
    public:
        node *left;
        int data;
        node *right;
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

};
void tree::create()
{
    int val;
    char choice;
    do
    {
        cout<<"Enter the data value :";
        cin>>val;
        node *newnode = new node;
        newnode->data=val;
        newnode->left=newnode->right=NULL;
        if (root==NULL)
        {
            root=newnode;
        }
        else
        {
            node *temp=root;
            while (1)
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
                        temp=temp->right;
                }
            }
        }
        cout<<"\nAny more nodes? (y/n):";
        cin>>choice;

    }
    while (choice=='Y' || choice=='y');
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
int main()
{
    tree t;
    int choice;
    do
    {
        cout<<"\n------------Menu------------"<<endl;
        cout<<"1. Create\n";
        cout<<"2. In-Order Traversal\n";
        cout<<"3. Pre-Order Traversal\n";
        cout<<"4. Post-Order Traversal\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                t.create();
                break;
            case 2:
                t.inorder(t.root);
                break;
            case 3:
                t.preorder(t.root);
                break;
            case 4:
                t.postorder(t.root);
                break;

            case 0:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Enter correct choice.";
                break;
        }

    }
    while (choice!=0);
}
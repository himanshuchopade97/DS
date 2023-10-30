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
        int search (node *root,int val);
        void deletenode (node *root,int num);

};
void tree::create()
{
    int value;
    char choice, ans;
    do
    {
        cout<<"Enter value to be inserted in BST :";
        cin>>value;
        node *newnode= new node;
        newnode->left=newnode->right=NULL;
        newnode->data=value;
        if (root==NULL)
        {
            root=newnode;
        }
        else
        {
            node *temp=root;
            while (1)
            {
                if (value<temp->data)
                {
                    if (temp->left==NULL)
                    {
                        temp->left=newnode;
                        break;
                    }
                    else
                    {
                        temp=temp->left;
                    }
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
        cout<<"Any more nodes? (y/n):";
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
int tree:: search(node *root,int val)
{
    if (root==NULL)
        return 0;
    if (root->data==val)
        return 1;
    else if (root->data<val)
        return search(root->right,val);
    else    
        return search(root->left,val);

}
void tree::deletenode(node *root, int num)
{
    node *temp = root, *parent = NULL, *father = NULL, *r = NULL, *son = NULL;
    while (temp != NULL && temp->data != num)
    {
        parent = temp;
        if (num < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        cout << "Number not found";
        return;
    }

    if (temp->left == NULL)
    {
        r = temp->right;
    }
    else if (temp->right == NULL)
    {
        r = temp->left;
    }
    else
    {
        father = temp;
        r = temp->right;
        son = r->left;
        while (son != NULL)
        {
            father = r;
            r = son;
            son = r->left;
        }

        if (father != temp)
        {
            father->left = r->right;
            r->right = temp->right;
        }

        r->left = temp->left;
    }

    if (parent == NULL)
    {
        root = r;
    }
    else
    {
        if (temp == parent->left)
        {
            parent->left = r;
        }
        else
        {
            parent->right = r;
        }
    }
    delete temp;
}


int main()
{
    tree t;
    int choice;

    do 
    {
        cout<<"---------MENU---------"<<endl;
        cout<<"1. Create a tree"<<endl;
        cout<<"2. In-Order Tranversal"<<endl;
        cout<<"3. Pre-Order Tranversal"<<endl;
        cout<<"4. Post-Order Tranversal"<<endl;
        cout<<"5. Search an element"<<endl;
        cout<<"6. Delete a node"<<endl; 
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>choice;
        switch (choice)
        {
            case 1:
                t.create();
                break;
            case 2:
                cout<<"In-Order Traversal :";
                t.inorder(t.root);
                cout<<endl;
                break;
            case 3: 
                cout<<"Pre-Order Traversal :";
                t.preorder(t.root);
                cout<<endl;
                break;    
            case 4:
                cout<<"Post-Order Traversal :";
                t.postorder(t.root);
                cout<<endl;
                break;
            case 5:
                int val;
                cout<<"Enter value to be searched :";
                cin>>val;
                int out;
                out=t.search(t.root,val);
                if (out==1)
                    cout<<"Element found in tree"<<endl;
                else if (out==0){
                    cout<<"Element not found in tree"<<endl;
                }
                break;
            case 6:
                int num;
                cout<<"Enter value to be deleted: ";
                cin >> num;
                t.deletenode(t.root, num);
                break;
            case 0:
                cout<<"Exiting..."<<endl;
                break;           
        }
    }
    while (choice!=0);
}

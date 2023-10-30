#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;
};
class list
{
    node *listptr,*temp;
    public:
        list()
        {
            listptr=NULL;
            temp=NULL;
        }
        void create();
        void display();
        void insert_at_beg();
        void insert_at_inter();
        void insert_at_end();
};
void list::create()
{
    int n, val;
    cout<<"How many nodes? :";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Enter data value for node "<<i+1<<" :";
        cin>>val;
        node *newnode = new node;
        newnode->data=val;
        newnode->next=NULL;
        if (listptr==NULL)
        {
            listptr=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    cout<<"Linked list created";
}
void list::display()
{
    temp=listptr;
    cout<<"Linked List :";
    while (temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL";
}
void list::insert_at_beg()
{
    int val;
    cout<<"Enter value to be inserted at beginning :";
    cin>>val;
    node *newnode=new node;
    newnode->data=val;
    newnode->next=listptr;

    temp=listptr;
    newnode->next=listptr;
    listptr=newnode;
}

int main()
{
    list l;
    int choice;
    do
    {
        cout<<"\n-------Menu-------"<<endl;
        cout<<"1. Create\n";
        cout<<"2. Display\n";
        cout<<"3. Insert at beginning\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                l.create(); break;
            case 2:
                l.display(); break;
            case 3:
                l.insert_at_beg(); break;
            case 0:
                cout<<"Exiting..."<<endl;
                break;
        }
    }
    while (choice!=0);

}


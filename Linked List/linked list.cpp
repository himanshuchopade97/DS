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
        void delete_at_beg();
        void delete_at_inter();
        void delete_at_end();
        void reverse();
        void search(int num);
        void concatenate(list &otherList);
        void union_list(list &otherList);
        void intersection_list (list &otherList);
        void bubble_sort();
        
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
void list::insert_at_inter()
{
    int val,pos;
    cout<<"Enter position after which you want to insert new element :";
    cin>>pos;

    cout<<"Enter value to be inserted at intermediate position :";
    cin>>val;
    node *newnode =new node;
    newnode->data=val;
    temp=listptr;
    int i=0;
    while (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void list::insert_at_end()
{
    int val;
    cout<<"Enter value to be inserted at the end of list: ";
    cin>>val;
    node *newnode =new node;
    newnode->next=NULL;
    newnode->data=val;
    temp=listptr;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void list::delete_at_beg()
{
    node *temp=listptr;
    listptr=listptr->next;
    delete temp;
    cout<<"Element at beginning was deleted ";
}
void list::delete_at_end()
{
    temp=listptr;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node *q=temp->next;
    temp->next=NULL;
    delete q;
    cout<<"element at end was deleted ";
}
void list::search(int num)
{
    temp=listptr;
    while (temp!=NULL)
    {
        if (temp->data==num)
        {
            cout<<"Element found"<<endl;
            return;
        }
        temp=temp->next;
    }
    if (temp->next==NULL)
    {
        cout<<"Number not found";
    }
}
void list::reverse()
{
    node *forward,*current=NULL,*back=NULL;
    forward=listptr;
    while (forward!=NULL)
    {
        back=current;
        current=forward;
        forward=forward->next;
        current->next=back;
    }
    listptr=current;
}
void list::concatenate(list &otherList)
{
    temp=listptr;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=otherList.listptr;
}
void list::union_list(list &otherList)
{
    concatenate(otherList);
    while (temp!=NULL)
    {
        node *q=temp;
        while (q->next!=NULL)
        {
            if (q->next->data==temp->data)
            {
                node *p=q->next;
                q->next=p->next;
                delete p;
            }
            q=q->next;
        }
        temp=temp->next;
    }
}
void list::intersection_list(list &otherList)
{
    temp=listptr;
    while (temp!=NULL)
    {
        node *temp2=otherList.listptr;
        while (temp2!=NULL)
        {
            if (temp2->data==temp->data)
            {
                cout<<temp2->data<<" -> ";
            }
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    cout<<"NULL";

}
void list::bubble_sort()
{
    if (listptr==NULL || listptr->next==NULL)
    {
        cout<<"Already sorted."<<endl;
        return;
    }
    bool swapped;
    node *ptr;
    do
    {
        swapped=false;
        ptr=listptr;
        while (ptr->next!=NULL)
        {
            if (ptr->data>ptr->next->data)
            {
                int temp=ptr->data;
                ptr->data=ptr->next->data;
                ptr->next->data=temp;
                swapped=true;
            }
            ptr=ptr->next;
        }
    }
    while (swapped);

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
        cout<<"4. Sort\n";
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
            case 4:
                l.bubble_sort();
                break;
            case 0:
                cout<<"Exiting..."<<endl;
                break;
        }
    }
    while (choice!=0);

}


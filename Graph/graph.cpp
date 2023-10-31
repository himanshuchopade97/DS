#include <iostream>
using namespace std;
class node
{
    public:
        node *next;
        int vertex;
        int weight;
        node (int v)
        {
            vertex=v;
            weight =0;
            next=NULL;
        }
        node (int v,int w)
        {
            vertex=v;
            weight=w;
            next=NULL;
        }
};
class listgraph
{
    node *list[20];         //array of pointers    //adjacency list
    bool visited[20];       //array of visited nodes
    int n;                  //no of vertices
    int adjMatrix[20][20]={0};  //adjacencyy matrix
    public:
        listgraph(int nov)
        {
            n=nov;
            for (int i=0;i<n;i++)
            {
                list[i]=NULL;
                visited[i]=false;
            }
        }
        void create();
        void list_display();
        void rec_dfs(int v);
        void matrix_display();

};
void listgraph::create()
{
    char ans;
    for (int i=0;i<n;i++)
    {
        node *temp=NULL;
        for (int j=0;j<n;j++)
        {
            cout<<"Is there any edge between "<<i+1<<" and "<<j+1<<" (y/n) :";
            cin>>ans;
            if (ans=='y' || ans=='Y')
            {   
                adjMatrix[i][j]=1;
                node *newnode= new node(j+1);
                if (list[i]==NULL)
                {
                    list[i]=newnode;
                    temp=newnode;
                }
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}
void listgraph::list_display()
{
    cout<<"Adjacency list: "<<endl;
    node *temp;
    for (int i=0;i<n;i++)
    {
        cout<<"Vertex :"<<i+1<<" -> ";
        temp=list[i];
        while (temp!=NULL)
        {
            cout<<temp->vertex<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
}
void listgraph::rec_dfs(int v)
{
    cout<<"DFS :";
    visited[v-1]=true;
    cout<<v<<" ";
    node *temp=list[v-1];
    while (temp!=NULL)
    {
        int neighbour=temp->vertex;
        if (!visited[neighbour-1])
        {
            rec_dfs(neighbour);
        }
        temp=temp->next;
    }
}
void listgraph::matrix_display()
{
    cout<<"Adjacency Matrix :"<<endl;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()          
{
    listgraph l(3);
    l.create();
    l.list_display();
    l.rec_dfs(1);
    l.matrix_display();
}
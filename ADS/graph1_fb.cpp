#include<iostream>
#include<string.h>
using namespace std;

class gnode
{
    int id;
    string name;
    gnode *next;
    friend class graph;
};

class graph
{
    gnode *head[20];
    int n;
    public:
        graph()
        {
            cout<<"Enter no of users"<<endl;
            cin>>n;
            for(int i=0;i<n;i++)
            {   
                head[i]=new gnode;
                head[i]->id=i;
                cout<<"Enter name"<<endl;
                cin>>head[i]->name;
                head[i]->next=NULL;
            }
        }
        void create()
        {
            int id1;
            string name1;
            char ch;
            for(int i=0;i<n;i++)
            {   
                gnode *temp=head[i];
                do
                {
                 
                    cout<<"Enter friend ID: "<<head[i]->id<<endl;
                    cin>>id1;
                    if(id1==i)
                        cout<<"self loop not allowed"<<endl;
                    else
                    {
                        gnode* curr=new gnode;
                        curr->id=id1;
                        curr->name=head[id1]->name;
                        curr->next=NULL;
                        temp->next=curr;
                        temp=temp->next;
                        
                    }
                    cout<<"do you want to continue(y/n)"<<endl;
                    cin>>ch;
                }
                while(ch=='y');
            }
        }           
        
        void display()
        {
            for(int i=0;i<n;i++)
            {   
                gnode *temp=head[i];
                cout<<temp->id<<" : "<<temp->name;
                temp=temp->next;
                while(temp!=NULL)
                {
                    cout<<" >> "<<temp->id<<" : "<<temp->name;
                    temp=temp->next;
                }
                cout<<endl;
            }
        }
                
};              

int main()
{
    graph g;
    g.create();
    g.display();
    return 0;
}


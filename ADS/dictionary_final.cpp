#include<iostream>
#include<string.h>
using namespace std;

class dnode
{
	char word[20];
	char meaning[20];
	dnode *right;
	dnode *left;
	friend class dictionary;
};

class dictionary
{
	dnode *root;
	public:
	void insert();
	void displayInorder();
    void remove();
	dictionary();
    void inorder_r(dnode *temp);
};

dictionary::dictionary()
{
	root=NULL;
}

void dictionary::insert()
{
	dnode *curr;
	dnode *temp;
	char choice;
	do
	{
		temp=root;
		curr=new dnode;
		cout<<"Enter a word: "<<endl;
		cin>>curr->word;
        cout<<"Enter meaning: "<<endl;
        cin>>curr->meaning;
        curr->left = NULL;
        curr->right = NULL;
        if(root==NULL)
        {
            root=curr;
        }
        else
        {
            int flag=0;
            
            while(flag==0)
            {
                int i=strcmp(curr->word,temp->word);                
                if(i<0)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=curr;
                        flag=1;
                    }
                    temp=temp->left;
                }
                else if(i>0)
                {
                    if(temp->right==NULL)
                    {
                        temp->right=curr;
                        flag=1;
                    }
                    temp=temp->right;
                }
                else
                {
                    cout<<"Word already exists"<<endl;
                    delete curr;
                    flag=1;
                }
            }
        }
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>choice;     
    }
    while(choice=='y');
}

void dictionary::remove()
{
    int flag=0;
    dnode *parent=NULL;
    dnode *temp=root;
    char b[20];
    cout<<"Enter a word to delete: "<<endl;
    cin>>b;
    while(temp!=NULL)
    {
        if(strcmp(b,temp->word)==0)
        {
            flag=1;
            break;
        }
        else if(strcmp(b,temp->word)<0)
        {
            parent=temp;
            temp=temp->left;
        }
        else
        {
            parent=temp;
            temp=temp->right;
        }
    }
    if(flag==1)
    {
        if(temp==root)
        {
            if(temp->right==NULL)
            {
                root=root->left;
            }
            else if(temp->left==NULL)
            {
                root=root->right;
            }
            else if(temp->right!=NULL && temp->left!=NULL)
            {
                dnode *curr=temp->left;
                root=temp->right;
                dnode *s=root;
                while(s->left!=NULL)
                {
                    s=s->left;
                }
                s->left=curr;
            }
            delete temp;
        }
        else if(temp->left==NULL && temp->right==NULL)
        {
            if(parent->left==temp)
            {
                parent->left=NULL;
            }
            else
            {
                parent->right=NULL;
            }
            delete temp;
        }
        else if(temp->left==NULL)
        {
            if(parent->left==temp)
            {
                parent->left=temp->right;
            }
            else
            {
                parent->right=temp->right;
            }
            delete temp;
        }
        else if(temp->right==NULL)
        {
            if(parent->left==temp)
            {
                parent->left=temp->left;
            }
            else
            {
                parent->right=temp->left;

        }
        delete temp;
        }
        else if(temp->left!=NULL && temp->right!=NULL)
        {
        dnode *curr=temp->left;
        dnode *s=temp->right;
        if(s->left==NULL)
        {
        s->left=curr;
        if(parent->left==temp)
        {
        parent->left=s;
        }
        else
        {
        parent->right=s;
        }
        delete temp;
        }
        else
        {
        dnode *p=s;
        while(p->left!=NULL)
        {
        s=p;
        p=p->left;
        }
        s->left=p->right;
        p->left=curr;
        p->right=temp->right;
        if(parent->left==temp)
        {
        parent->left=p;
        }
        else
        {
        parent->right=p;
        }
        delete temp;
        }
        }
        cout<<"Word deleted successfully"<<endl;
        }
        else
        {
        cout<<"Word not found"<<endl;
        }
        }

        void dictionary::inorder_r(dnode *temp)
        {
        if(temp!=NULL)
        {
        inorder_r(temp->left);
        cout<<temp->word<<" : "<<temp->meaning<<endl;
        inorder_r(temp->right);
        }
        }

        void dictionary::displayInorder()
        {
        inorder_r(root);
        }

        int main()
        {
        dictionary d;
        int choice;
        char ch;
        do
        {
        cout<<"\nDictionary"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
        d.insert();
        break;
        case 2:
        d.remove();
        break;
        case 3:
        d.displayInorder();
        break;
        case 4:
        return 0;
        default:
        cout<<"Invalid choice"<<endl;
        }
        cout<<"Do you want to continue? (y/n)"<<endl;
        cin>>ch;
        }
        while(ch=='y');
        return 0;
        }

        //end of the code
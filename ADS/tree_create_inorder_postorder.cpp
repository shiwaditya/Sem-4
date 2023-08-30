

#include <iostream>
using namespace std;
class treenode{
char data[10];
treenode *left;
treenode *right;
friend class tree;
 
};
	class stack{
	int top;
	treenode *data[30];
	public:
	stack(){
	top=-1;
	}
	void push(treenode *temp);
	treenode *pop();
	int empty();
	friend class tree;
	 
	};
	
void stack::push(treenode *temp)
{
	top++;
	data[top]=temp;
}
treenode * stack::pop()
{
treenode *a=data[top];
top--;
return(a);
}
int stack:: empty(){
if (top==-1){
return true;
}
else{
return false;
}
}
class tree{
treenode *root;
public:
tree(){
root= NULL;
}
void create_nr();
void create_r();
void create_r(treenode *temp);
void inorder_nr();
void preorder_nr();

};
 
void tree::create_nr()
{
		treenode *temp,*curr;
		char ans;
		if (root==NULL)
		{
			root=new treenode;
			cout<<"Enter the data"<<endl;
			cin>>root->data;
		}
		do
		{
			temp=root;
			int flag=0;
			char ch;
			curr= new treenode;
			cout<<"Enter the data for new node"<<endl;
			cin>>curr->data;
			while (flag==0)
{
			cout<<"Enter your choice r/l:";
			cin>>ch;
			if (ch == 'l')
		{
			if (temp->left==NULL)
			{
				temp->left=curr;
				flag=1;
			}
			temp=temp->left;
		}
		if (ch=='r')
		{
		if (temp->right==NULL)
			{
			temp->right=curr;
			flag=1;
			}
		temp=temp->right;
		}
		 
	}
		cout<<"Do you want to enter more node enter your choice"<<endl;
		cin>>ans;
		}
		while(ans=='y');
}
void tree:: create_r()
{
	if (root==NULL)
	{
		root=new treenode;
		cout<<"Enter the data"<<endl;
		cin>>root->data;
	}
	create_r(root);
}
void tree::create_r(treenode *temp)
{
	treenode *curr;
	char ch;
	cout<<"Enter y whether you want to add to the left "<<endl<<temp->data<<endl;
	cin>>ch;
	if (ch=='y')
	{
		curr=new treenode;
		cout<<"Enter the data for new node"<<endl;
		cin>>curr->data;
		temp->left=curr;
		create_r(curr);
 
	}
		cout<<"Enter y whether you want to add to the right"<<endl<<temp->data<<endl;
		cin>>ch;
		if(ch=='y')
	{
		curr=new treenode;
		cout<<"Enter the data for new node"<<endl;
		cin>>curr->data;
		temp->right=curr;
		create_r(curr);
        }
 
 
}
void tree::inorder_nr()
	{
		stack s;
		treenode *temp;
		temp=root;
	while(1)
	{
		while(temp !=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
			if (s.empty())
		{
			break;
		
		}
		else
		{
			temp=s.pop();
			cout<<temp->data<<"\t";
			temp=temp->right;
		}
 
	}
}

void tree::preorder_nr()
	{
		stack s;
		treenode *temp;
		temp=root;
	while(1)
	{
		while(temp !=NULL)
		{
			cout<<temp->data<<"\t";
			s.push(temp);
			temp=temp->left;
		}
			if (s.empty())
		{
			break;
		
		}
		else
		{
			temp=s.pop();
			
			temp=temp->right;
		}
 
	}
}





int main(){
int n;
tree bt;

   cout<<"Enter your case \n1.Non-Recursive Creation \n2.Recursive creation \n3.Inorder NR \nPreorder NR\n"<<endl;
   cin>>n;
switch(n)
{
case 1:
	bt.create_nr();
 	 break;
case 2:
	bt.create_r();
	
      break;
case 3:
	   bt.inorder_nr();
	   break;  
case 4:
	bt.preorder_nr();
	break;
       

       
default:{cout<<"Entry is not Reachable";
              break;}
}
 

}

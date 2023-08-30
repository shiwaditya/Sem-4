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
	stack()
	{
		top = -1;
	}
	void push(treenode *temp);
	treenode *pop();
	int empty();
	friend class tree;
};

void stack::push(treenode *temp)
{
	if(top == 30)
	{
		cout << "Stack is Full!!" << endl;
		return;
	}
	else
	{
		top++;
		data[top]=temp;
	}
}

treenode * stack::pop()
{
	if(top == -1)
	{
		cout << "Stack is Empty!!" << endl;
	}
	else
	{
		treenode *a = data[top];
		top--;
		return(a);
	}	
}

int stack:: empty()
{
	if (top==-1)
	{
	return true;
	}
	else
	{
		return false;
	}
}

class tree
{
	treenode *root;
	public:
	tree()
	{
		root= NULL;
	}

	void create_nr();
	void inorder_nr();
	void preorder_nr();
	void postorder_nr();
	void create_r(treenode *temp);
	void create_r();
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
		while (flag==0){
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

void tree::postorder_nr()
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
		if (s.data[s.top]->right ==NULL)
		{
			temp=s.pop();
			cout<<temp->data<<"\t";
		}
		while((s.top!=-1) && s.data[s.top]->right == temp)
		{
			temp=s.pop();
			cout<<temp->data<<"\t";
		}
		if (s.empty())
		{
			break;
		}
		temp=s.data[s.top]->right;
	}
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
	cout<<"Enter y whether you want to add to the left "<< endl <<temp->data << endl;
	cin>>ch;
	if (ch=='y')
	{
		curr = new treenode;
		cout<<"Enter the data for new node"<<endl;
		cin>>curr->data;
		temp->left=curr;
		create_r(curr); 
	}
	cout<<"Enter y whether you want to add to the right"<<endl<<temp->data << endl;
	cin>>ch;
	if(ch=='y')
	{
		curr = new treenode;
		cout << "Enter the data for new node"<<endl;
		cin >> curr->data;
		temp->right=curr;
	create_r(curr);
	}
}

int main()
{
	tree bt;
	

	bt.create_r();
	bt.inorder_nr();
	return 0;
}

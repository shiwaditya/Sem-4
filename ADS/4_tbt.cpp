#include<iostream>

using namespace std;

class tbtnode
{
	char data;
	int rbit;
	int lbit;
	tbtnode *rightc;
	tbtnode *leftc;
	friend class tbt;
	public:
		tbtnode();
};

tbtnode::tbtnode()
{
	lbit=1;
	rbit=1;
}

class tbt
{
	tbtnode *head;
	tbtnode *temp;
	
	public:
		tbtnode *s;
		int flag;
		void create();
		void preorder();
		tbtnode *presuccr(tbtnode *temp);
		void inorder();
		tbtnode *inordersucc(tbtnode *temp);
		tbt();
};
tbt::tbt()
{
	head = new tbtnode;
	head->rbit = 0;
	head->leftc = head;
	head->rightc = head;
}	

void tbt::create()
{	
	char ch1;
	int ch=1;
	tbtnode *root;
	
	tbtnode *curr;
	root = new tbtnode;
	cout<<"Enter Root Data"<<endl;
	cin>>root->data;
	head->lbit = 0;
	root->leftc = head;
	root->rightc= head;
	head->leftc = root;

while(ch==1)//replace with while
{
	flag = 0;
	temp = root;
	curr = new tbtnode;
	while(flag==0)
	{
	//cout<<"Enter Data"<<endl;
	//cin>>temp->data;
	cout<<"Do you want to go left(l) or right(r) of "<<temp->data<<endl;
	cin>>ch1;
	if(ch1 == 'l')
	{
		if(temp->lbit==1)
		{
			cout<<"Enter Data(left)"<<endl;
			cin>>curr->data;
			curr->rightc = temp;
			curr->leftc = temp->leftc;
			temp->leftc = curr;
			temp->lbit = 0;
			flag = 1;
		}
	else
	{
		temp = temp->leftc;
	}
	}

	if(ch1 == 'r')
			{ 
			if(temp->rbit==1)
		{
			cout<<"Enter Data(right)"<<endl;
			cin>>curr->data;
			curr->leftc = temp;
			curr->rightc = temp->rightc;
			temp->rightc = curr;
			temp->rbit = 0;
			flag = 1;
		}
	else
	{
		temp = temp->rightc;
        }
		}
	}


	cout<<"Do you want to continue(1/0)"<<endl;
	cin>>ch;
}	
}//end create



int main()
{
	tbt t1;
	t1.create();
	t1.inorder();
	
}
/*
void tbt::preorder()
{
	temp = head->leftc
	while(temp!=head)
	{
	cout<<temp->data<<endl:
	while(temp->lbit!=1)
	{	
	temp = temp->leftc;
	cout<<temp->data<<endl:
	}
	
	while(temp->rbit!=1)
	{	
	temp = temp->rightc;
	cout<<temp->data<<endl:
	}
}
*/

void tbt::inorder()
{	
	temp = head;
	while(1)
	{
	temp = inordersucc(temp);
	if(temp==head)
	break;

	cout<<temp->data<<endl;
	}
}

tbtnode* tbt::inordersucc(tbtnode *temp)
{

	s = temp->rightc;
	if(temp->rbit == 0)
	{
	while(s->lbit == 0)
		s = s->leftc;
	}

	return s;
}














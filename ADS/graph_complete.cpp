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
	private:
		gnode *head[20];
		int n;
	public:
		graph()
		{
			cout << "Enter no of users(max 20): ";
			cin >> n;
			for(int i=0; i < n;i++)
			{
				head[i] = new gnode;
				head[i]->id = i;
				cout << "Enter name: ";
				cin >> head[i]->name;
				head[i]->next = NULL;
			}

			cout << "Name    Assigned Id\n-------------------\n";
			for(int i=0; i < n;i++)
			{
				char d[20];
				sprintf(d,"%-9s%6d\n",head[i]->name.c_str(), i);
				cout << d;
			}
			cout << "----------------------\n";
		}
		void create();
		void display();
		void dfs_r();
		void dfs_r(int v, int vt[]);
		void dfs_nr();
};

class queue
{
private:
	int q[20];
	int front,rear;
public:
	queue();
	void ins(int e);
	int del();
};

queue::queue()
{
	front = rear = -1;
}

void queue::ins(int e)
{
	q[++rear] = e;
}

int queue::del()
{
	return q[front++];
}

void graph::create()
{
	for(int i=0; i < n; i++)
	{
		gnode *temp = head[i];
		int v;
		char ch = 'y';
		cout << "Current user: " << head[i]->name << "\n";

		while(ch=='y')
		{
			cout << "Enter id of this user's friend: ";
			cin >> v;
			if(v==i) cout << "User cannot be friends with themselves\n";
			else
			{
				gnode *curr = new gnode;
				curr->id = i;
				curr->name = head[v]->name;
				temp->next = curr;
				temp = temp->next;
			}
			cout << "Do you want to add another friend(y/n): ";
			cin >> ch;
		}
	}
}


void graph::display()
{
	cout << "User     ID	Friends   \n-------------------------------------------\n";

	for(int i=0; i<n; i++)
	{
		gnode *temp = head[i]->next;
		char d[100] = {0}, f[100] = {0};
		
		sprintf(d,"%-9s%3d  ", head[i]->name.c_str(),i);
		cout << d;

		while(temp != NULL)
		{
			cout << temp->name << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
}

void graph::dfs_r()
{
	int visited[n] = {0};
	int i;

	cout << "Enter id of user to start search: ";
	cin >> i;

	cout << head[i]->name << "\n";
	cout << "Starting the search with this user\n";
	dfs_r(i,visited);
}

void graph::dfs_r(int v, int vt[])
{
	cout << v << ": " << head[v]->name;
	vt[v] = 1;

	gnode *temp = head[v]->next;
	cout << "\nFriends:\n";
	while ((temp != NULL))
	{
		int j = temp->id;
		cout << j << ": " << head[j]->name << "\n";
		
		if(!vt[j])
			dfs_r(j,vt);

		temp = temp->next;
	}
}

void graph::dfs_nr()
{
	
}

int main()
{
	graph g1;
	g1.create();
	cout << "\n";
	g1.display();
	cout << "\n";
	g1.dfs_r();

	return 0;
}

#include <stdio.h>
#include <stdlib.h>



struct node 
{
	int coef;
	int exp;
	struct node *next;
};


//____________________________________________________________

void create(struct node *H);
void display(struct node *H);
void add(struct node *H1, struct node *H2, struct node *H3);

//____________________________________________________________

int main()
{
	struct node *h1, *h2, *h3;
	
	h1 = (struct node *) malloc(sizeof(struct node));
	h1->exp = -1;
	h1->next = h1;
	
	h2 = (struct node *) malloc(sizeof(struct node));
	h2->exp = -1;
	h2->next = h2;

	h3 = (struct node *) malloc(sizeof(struct node));
	h3->exp = -1;
	h3->next = h3;

	printf("Enter first Polynomial: \n");
	create(h1);
	
	display(h1);

	printf("Enter second Polynomial: \n");
	create(h2);

	display(h2);

	printf("Final Added Polynomial: ");
	add(h1, h2, h3);
	display(h3);

}

//_____________________________________________________________



void create(struct node *H)
{
	struct node *last, *curr;
	last = H;
	int ch;
	do
	{
		curr = (struct node *)malloc(sizeof(struct node));
		printf("Enter coefficient: ");
		scanf("%d", &curr->coef);
		printf("Enter exponent: ");
		scanf("%d", &curr->exp);
		last->next = curr;
		curr->next = H;
		last = curr;
		printf("Add another node? (1-yes, 2-no): ");
		scanf("%d", &ch);
	}while (ch == 1);
}

//_____________________________________________________________

void display(struct node *H)
{
	struct node *curr;
	if (H->next == H)
	{
		printf("Polynomial is empty!");
	}
	else
	{
		curr=H->next;
		while(curr->exp != -1)
		{
			if (curr->coef > 0)
			{
				printf("+");
			}
			printf("%dx^%d", curr->coef, curr->exp);
			curr = curr->next;
		}
		printf("\n");
	}
}


void add(struct node *H1, struct node *H2, struct node *H3)
{
	struct node *temp, *curr1, *curr2, *curr3;
	curr1=H1->next;
	curr2=H2->next;
	curr3=H3;
	while (curr1->exp != -1 && curr2->exp != -1)
	{
		if (curr1->exp == curr2->exp)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->next = H3;
			temp->coef = curr1->coef + curr2->coef;
			temp->exp = curr1->exp;
			curr1=curr1->next;
			curr2=curr2->next;
			curr3->next = temp;
			curr3=temp;
		}
		else
		{
			if (curr1->exp > curr2->exp)
			{
				temp = (struct node *)malloc(sizeof(struct node));
				temp->exp = curr1->exp;
				temp->coef = curr1->coef;
				temp->next=H3;
				curr3->next=temp;
				curr3=temp;
				curr1=curr1->next;
			}
			else
			{
				temp = (struct node *)malloc(sizeof(struct node));
				temp->exp = curr2->exp;
				temp->coef = curr2->coef;
				temp->next = H3;
				curr3->next=temp;
				curr3=temp;
				curr2=curr2->next;
			}
		}
	}
}
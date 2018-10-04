#include <cstdio>
#include <iostream>
using namespace std;

struct node
{	int data;
	node*next;
}*front,*rear;

class queue
{
public:
	queue()
	{	front=rear=NULL;
	}
void insert(int x)
{	node*n=new node;
	n->data=x;
	n->next=NULL;
	if(rear==NULL)
		rear=front=n;
	else
	{	rear->next=n;
		rear=n;
	}
}
int remove()
{	if(front==NULL)
	return(0);
	if(front==rear)
	{	delete front;
		front=rear=NULL;
		return(1);
	}
	node*r;
	r=front;
	front=front->next;
	delete r;
	return(1);
}
int count();
void display();
};
int queue::count()
{  	int c=0;
	if(front==NULL)
	return(c);
	node*t;
	t=front;
	while(t!=rear)
	{ 	 t=t->next;
		 c++;
	}
	c++;
	return(c);
}

void queue::display()
{	if(front==NULL)
	{
	cout<<"empty";
	exit(0);
	}
	else
	{	node*s;
		s=front;
		while(s!=NULL)
		{	cout<<s->data<<"-";
			s=s->next;
		}
	}
}

int main()
{	queue list;
	int n,r;
	char c;
	do
	{
	cout<<"ENter your choice 1.ins 2.rem 3.disp\n";
	cin>>n;
	switch(n)
	{
	 case 1:
		cout<<"enter roll no : ";
		cin>>r;
		list.insert(r);
		break;

	 case 2:
		list.remove();
		break;

	 case 3:
		list.display();
		break;

	 default :
	  exit(0);
	  }
	  cout<<"Do you wish to continue('y/Y') : ";
	  cin>>c;
	  }while(c=='y'||c=='Y');
	return 0;
}

#include <iostream>
using namespace std;

struct node{
	int number;
	int distance;
	node *ptr=NULL;
};

class graph{
	public:
		graph();
		~graph();
		node *root;
		int n;
		void insert_graph();
		void print_graph();
		bool repeat(int no);
		void insert_edg();
		void make_edg(int num,node *temp);
};

graph::graph(){
	root=NULL;
}

graph::~graph(){
	delete []root;	
}

void graph::insert_graph(){
	cout<<"Enter number of Vertixes : ";
	cin>>n;
	root=new node[n];
	node *temp=root;
	int no=1;
	for(int i=0; i<n ; i++){
		cout<<"Enter "<<i+1<<" number   : ";
		cin>>no;
		while(repeat(no)){
			cout<<"This number already exits , TRY Again :";
			cin>>no;
		}
		temp->number=no;
		temp->ptr=NULL;
		temp++;	
	}
	return;
}

bool graph::repeat(int no){
	if(root==NULL)
		return 0;
	node *temp=root;
	for(int i=0; i<n; i++){
		if(temp->number==no){
			return 1;
		}
	}
	return 0;
}

void graph::print_graph(){
	cout<<endl<<"------------------------------------"<<endl;
	node *temp=root;
	node *t;
	for(int i=0; i<n ; i++){
		cout<<"YOUR "<<i+1<<" Vertixes  : ";
		cout<<temp->number;
		t=temp;
		while(t->ptr!=NULL){
			t=t->ptr;
			cout<<"-->"<<t->number<<"("<<t->distance<<")";
		}
		cout<<endl;
		temp++;
	}
	return;
}

void graph::make_edg(int num,node *temp){
	while(temp->ptr!=NULL){
		temp=temp->ptr;
	}
	temp->ptr=new node;
	temp=temp->ptr;
	temp->number=num;
	cout<<"Enter distance : ";
	cin>>temp->distance;
	temp->ptr=NULL;
	return;
}

void graph::insert_edg(){
	int x,y;
	cout<<"Enter vertix from : ";
	cin>>x;
	cout<<"Enter vertix to    : ";
	cin>>y;
	node *temp=root;
	for(int i=0; i<n; i++){
		if(temp->number==x){
			make_edg(y,temp);
		}
		temp++;
	}
	return;
}

int main(){
	graph obj;
	obj.insert_graph();
	obj.insert_edg();
	obj.insert_edg();
	obj.insert_edg();
	obj.insert_edg();
	obj.insert_edg();
	obj.print_graph();
}

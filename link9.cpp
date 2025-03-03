#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*list =NULL;
// INSERTION OF NODE AT BEGINNING 
//Insert 85
Node* insert_at_beg(int x)
{
    Node* p=new Node;
    p->data=x;
    p->next=list;
    list=p;
}
// INSERTION OF NODE AT end of the list
Node* insert_at_end(int y){
    Node *p = new Node;
    Node *r = list;
   
    r = list;
    p->data = y;
    p->next = NULL;
    if(list == NULL){
        list = p;
    }
	else{
        while(r->next!=NULL){
            r = r->next;
        }
        r->next = p;
    }
}

// INSERTION OF NODE AT SOME POSITION
Node* insert_at_pos(int data,int n)
{
	Node* p=new Node;
	p->data=data;
	p->next=NULL;
	if(n==1)
	{
		p->next=list;
		list=p;
		return(p);
	}
	Node* q=list;
	for(int i=1; i<n-1 && q!=NULL;i++)
	{
		q=q->next;
	}
	if(q==NULL)
	{
		cout<<"position not exist";
	}
	else{
	
	p->next=q->next;
	q->next=p;
   }
}
// DELETION OF NODE AT BEGINNING
void del_at_beg()
{
	Node* p=new Node;
	if(list==NULL)
	{
		cout<<"list is empty";
	}
	else
	{
		p=list;
		list=p->next;
		delete(p);
	}
}

// DELETION OF NODE AT END
void del_at_end()
{
	Node* p=new Node;
		Node* q=new Node;
	if(list==NULL)
	{
		cout<<"list is empty";
	}
	else
	{    
	     p=list;
	     while(p->next!=NULL)
	   	{
		    	 q=p;
		         p=p->next;
	   	 }
	      q->next=NULL;
	     	delete(p); 
	}
}
// DELETION OF NODE AT SOME POSITION

void del_at_pos(int x)
{
	Node* p=new Node;
		Node* q=new Node;
	if(list==NULL)
	{
		cout<<"list is empty";
	}
	else
	{    
	     p=list;
	     if(x==1)
	     {
	     		p=list;
		list=p->next;
		delete(p);
		 }
	     else{
		 
	     for(int i=1;i<x;i++)
	     {  
	        q=p;
	     	p=p->next;
		 }
		    q->next=p->next;
		    
	     	delete(p);
		
       }
	}
}
void show()
{
    Node *p = new Node;
    p = list;
    if(list==NULL){
        cout<<"\nNothing to Display\n";
    }else{
        cout<<"\nThe contents of list\n"<<endl;
        while(p!=NULL){
            cout<<p->data<<"--> ";
            p = p->next;
        }
        cout<<"NULL";
    }
}
 
int main()
{
    int ch,x,y;
    Node *nptr;
     cout<<"\n\n1.insertatbeg\n2.insertatend\n3.insertatpos\n4.deleteatbeg\n5.deleteatend\n6.deleteatpos\n7.Display\n8.Exit";
    while(1)
    {
       
        cout<<"\nEnter your choice(1-8):";
        cin>>ch;
        
        switch(ch){
            case 1: cout<<"\nEnter data:";
                    cin>>x;
                    nptr=insert_at_beg(x);
                    break;
            
            case 2:cout<<"\nEnter data:";
                    cin>>y;
                    nptr=insert_at_end(y);
                    break;
            case 3:cout<<"\nEnter data:";
                    cin>>y;
                    cout<<"\nEnter pos:";
                    cin>>x;
                    nptr=insert_at_pos(y,x);
                    break;
            case 4:del_at_beg();
            		break;
            case 5:del_at_end();
            		break;
            case 6:cout<<"\nEnter pos:";
                    cin>>x;
		del_at_pos(x);
            		break;
            case 7:show();
                    break;
            
            case 8: exit(0);
		break;
            
            default: cout<<"\nWrong choice!!";
        }
 }
    return 0;
}

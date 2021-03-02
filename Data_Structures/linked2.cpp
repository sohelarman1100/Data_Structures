///LINKED 2

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* point;///jehetu point struct node typer ekti structure er address dharon korbe jei address
    ///er moddhe data and point ei duita variable thakbe tai point pointer ti struct node* typer hoyeche||
};

struct node* head;///head ekti pointer jeti just ekta address dharaon korbe jei address e data o point
///duita field thakbe||

int main()
{
    struct node* temp;
    struct node* temp1;
    struct node* head1;
    head=NULL;
    temp=head=(struct node*) malloc(sizeof(struct node));
    for(int i=1; i<=5; i++)
    {
        cin>>temp->data;
        if(i!=5)
        {
            temp=temp->point=(struct node*) malloc(sizeof(struct node));
            temp1=temp;///last address of linked list is inserting in temp1;
        }
        else
            temp->point=NULL;
    }
    temp=head;
    cout<<"value of linked list are:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->point;
    }
    head1=temp=temp1;
    temp=temp->point=(struct node*) malloc(sizeof(struct node));
    cout<<"enter some number you want to insert in linked list:"<<endl;
    for(int i=1; i<=3; i++)///inserting new value in linked list....these value will be insert in last
        ///position of linked list;
    {
        cin>>temp->data;
        if(i!=3)
        {
            temp=temp->point=(struct node*) malloc(sizeof(struct node));
            temp1=temp;
        }
        else
            temp->point=NULL;
    }
    temp=head;
    for(int i=1; i<=2; i++)///inserting values at the very first position of the list||
    {
        temp1=(struct node*) malloc(sizeof(struct node));
        cin>>temp1->data;
        head=temp1;
        temp1->point=temp;
        temp=head;
    }
    temp=head;
    cout<<"after insert some value in linked list:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->point;
    }
    temp=head;
    int i,n,k=0;
    cout<<"enter the node number you want to delete:"<<endl;
    cin>>n;
    if(n==1)
    {
        head=head->point;
    }
    else if(n==2)
    {
        temp1=temp->point;
        temp1=temp1->point;
        temp->point=temp1;
    }
    else
    {
        while(temp!=NULL)///deleting n'th position node from linked list
        {
            k++;
            if(k==n-2)
            {
                temp=temp->point;
                temp1=temp->point;
                temp1=temp1->point;
                temp->point=temp1;
                break;
            }
            temp=temp->point;
        }
    }
    temp=head;
    cout<<"after deleting the desire position's node the linked list became like following:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->point;
    }
    return 0;
}


#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;
        node(int d)
        {
            data=d;
            next=NULL;
        }
};
void insert_node(node* &head,node* &tail,int data)
{
    if(head==NULL)
    {
        head=tail=new node(data);
        return;
    }
    node* n=new node(data);
    tail->next=n;
    tail=n;
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL";
}
node* intersection(node* head1,node* head2)
{
    //BASE CASE
    if(head1==NULL)
        return NULL;
    //RECURSIVE CASE
    node* temp=head2;
    while(temp!=NULL)
    {
        if(head1->data==temp->data)
            return temp;
        else
        {
            temp=temp->next;
        }
    }
    return intersection(head1->next,head2);
}
int main()
{
    node* head1=NULL;
    node* tail1=NULL;
    node* head2=NULL;
    node* tail2=NULL;
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        int num1;
        cin>>num1;
        insert_node(head1,tail1,num1);
    }
    int n2;
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        int num2;
        cin>>num2;
        insert_node(head2,tail2,num2);
    }
    print(head1);
    cout<<endl;
    print(head2);
    cout<<endl;
    node* ans=intersection(head1,head2);
    if(ans==NULL)
        cout<<"-1";
    else
    {
        cout<<ans->data;
    }
    return 0;
}

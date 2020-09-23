#include <bits/stdc++.h>
#include<inttypes.h>
using namespace std;

class node
{
 public:
    int data;
    node *npx;
};

node *XOR (node *a,node *b)
{
  return (node*)((uintptr_t) (a) ^  (uintptr_t) (b));
}

void insertBeg(node **head,int key)
{
    node *new_node=new node();
    new_node->data=key;
    new_node->npx=*head;
    if(*head!=NULL)
    {
        (*head)->npx=XOR(new_node,(*head)->npx);
    }
    *head=new_node;
}


void insertEnd(node **head,int data)
{
  node *new_node=new node();
  new_node->data=data;
  if(*head==NULL){
    new_node->npx=*head;
   *head=new_node;
   }
  else{
    node *curr=*head;
    node *prev=NULL;
    node *next;
    while(XOR(prev,curr->npx)!=NULL)
    {
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }
    new_node->npx=curr;
    curr->npx=XOR(prev,new_node);
 }
}

node *deleteBeg(node *head)
{
 if(head == NULL)
  return NULL;
 node *temp=XOR(head->npx,NULL);
 temp->npx=XOR(head,temp->npx);
 free(head);
 return temp;

}

node *deleteEnd(node *head)
{
  node *curr=head;
  node *prev=NULL;
  node *next=XOR(curr->npx,prev);
  if(head == NULL)
   return NULL;

   while(next!=NULL)
   {
    prev=curr;
    curr=next;
    next=XOR(curr->npx,prev);
   }
   if(prev!=NULL)
   prev->npx=XOR(prev->npx,curr);

    free(curr);
    return head;
}

void printList(node *head)
{
    node *curr=head;
    node *prev=NULL;
    node *next;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
 }
}



int main()
{

node *head=NULL;


cout << "Enter the no. of nodes to insert at beginning: ";
int n;
cin >> n;
cout << "Enter the elements : \n";
for (int i = 0; i < n; i++){
    int data;
    cin >> data;
    insertBeg(&head, data);
}
cout << "Linked List: " << " ";
printList(head);
cout<<endl;

cout << "Enter no. of nodes to insert at the end: ";

cin >> n;
cout << "Enter the elements: \n";
for (int i = 0; i < n; i++){
    int data;
     cin >> data;
    insertEnd(&head, data);
}
cout << "Linked List: " << " ";
printList(head);
cout<< endl;

cout<<"Linked list after deletion from the beginning: "<<endl;
 head=deleteBeg(head);
 printList(head);
 cout<<endl;
 cout<<"Linked list after deletion from the end: "<<endl;
 head=deleteEnd(head);
 printList(head);

return 0;
}

#include <iostream>
using namespace std;
#define lli long long int
#define for(i,n) for(int (i)=0; i<(n); i++)
struct node
{
    int data;
    node *next;
}*head=NULL,*pre=NULL,*curr=NULL,*temp=NULL;

void addNode(int x)
{
    node *newnode = new node;
    newnode->data  = x;
    newnode->next = NULL;
    if(head==NULL)
    {
        head = newnode;
        temp = head;
    }
    else{
         temp->next = newnode;
         temp = newnode;
    }
}
node *reverse(node *x)
{
    curr = x;
    while(curr!=NULL)
    {
        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
}
node *mid(node *h)
{
    node *slow = h;
    node *fast = h;
    while(fast->next != NULL && fast->next->next !=NULL)
    {
        slow  = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void print(node *x)
{
   while(x!=NULL)
   {
    cout<<x->data<<" ";
    x=x->next;
   }
}

int main() {
   addNode(1);
   addNode(2);
   addNode(3);
   addNode(4);
   addNode(5);
   addNode(6);
   print(head);
//    cout<<endl;
//    node *rev  = reverse(head);
//    print(rev);
   cout<<mid(head)->data;
return 0;
}
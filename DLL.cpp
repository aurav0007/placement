#include <iostream>
using namespace std;
  struct Node
  {
    int data;
    Node *pre;
    Node *next;
    Node(int x)
    {
        data = x;
        pre = NULL;
        next= NULL; 
    }
  }*head,*temp;
 void addNode(int data)
 {
    Node *newnode =  new Node(data);
    if(head==NULL)
    {
        head = temp = newnode;
    }
    else{
        temp->next = newnode;
        newnode->pre = temp;
        temp = temp->next;
    }
 }
 Node *reverse(Node *h)
 {
    Node *cur  = h;
    Node *t;
    while(cur!=NULL)
    {
        Node *flag = cur->next;
        cur->next = cur->pre;
        cur->pre = flag;
        t = cur;
        cur = cur->pre;
    }
    return t;
 }
 void display(Node *h)
 {
    while(h != NULL)
    {
        cout<<h->data;
        h= h->next;
    }
    cout<<endl;
    // h = temp;
    // while(h!=NULL)
    // {
    //   cout<<h->data;
    //   h = h->pre;
    // }
 }

 int main()
 {
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    // display(head);
    Node *rev = reverse(head);
    cout<<endl;
    display(rev);
    return 0;
 }
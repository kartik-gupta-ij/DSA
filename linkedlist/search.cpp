#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

Node * search(Node *p,int key)
{
    int c = p->data;
    // c=INT_MIN;
    while (p)
    {
        if(p->data==key){
            return p;
        };
       p= p->next;
    }
    return NULL;
   
}
Node * Rsearch(Node *p,int key)
{
    if (p== 0)
    {
        return 0;
    }
    else
    {
        if(p->data==key){
            return p;
        }
        else{
            return Rsearch(p->next,key);
        }

    }
}
Node * searchMTH(Node *p,int key)
{
    int c = p->data;
    // c=INT_MIN;
    Node *q=NULL;

    while (p)
    {
        if(p->data==key){
            q->next=p->next;
            
            p->next=first; 
            first=p; 
              
            return first;

        };
        q=p;
        p=p->next;
    }
    return NULL;
   
}
void Display( Node* p){
while(p->next){
    cout<<p->data<<endl;
    p=p->next;
}
}
int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    cout << searchMTH(first,10)<<endl;
    Display(first);

    return 0;
}
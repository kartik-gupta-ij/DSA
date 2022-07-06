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
int count(Node *p)
{
    int c = 1;
    while (p->next)
    {
        c++;
        p = p->next;
    }
    return c;
}

void Insert(Node *p ,int pos){
    Node * t;
    t=new Node;
    t->data=222;
    if(pos<0 || pos>count(p)){
        return;
    }
    if(pos==0){
        t->next=first;
        first=t;
    }
    else if(pos>0){
        for(int i=0; i<pos-1;i++){
            p=p->next;
        }
        
        t->next=p->next;
        p->next=t;
    }
}

void Display( Node* p){
while(p){
    cout<<p->data<<endl;
    p=p->next;
}
}
int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A,8);
    // Display(first);

    Insert(first,0);
    Display(first);

    return 0;
}
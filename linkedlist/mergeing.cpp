
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL,*second,*third;
void create1(int A[], int n)
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
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(Node *p)
{
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

void merge(Node *p,Node*q){
    Node *last;
    if(p->data>q->data){
        third=q;
        q=q->next;
        last=third;
        third->next=NULL;

    }
    else{
        third=p;
        p=p->next;
        last=third;
        third->next=NULL;
    }
    while(p && q){
    if(p->data>q->data){
        last->next=q;
        q=q->next;
        last=last->next;
        last->next=NULL;

    }
    else{
        last->next=p;
        p=p->next;
        last=last->next;
        last->next=NULL;
    }
    }
    if(p){
        last->next=p;
    }
    else{
        last->next=q;
    }

}



int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 103,4066,44444};
    create1(A, 6);
    int B[] = {35, 54, 70, 1403, 2254,3442};
    create2(B, 6);
    merge(second,first);
   Display(third);

    return 0;
}
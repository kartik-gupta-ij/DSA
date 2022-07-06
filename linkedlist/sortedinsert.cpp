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

void Isorted(Node *p, int key)
{
    Node *q, *t;
    t = new Node;
    t->data = key;
    if(first==NULL){
        t->next=NULL;
        first=t;
    }
    while (p and p->data < key)
    {
        q = p;
        p = p->next;
    }
    if (p == first)
    {
        t->next = first;
        first = t;
    }
    else
    {
        t->next = q->next;
        q->next = t;
    }
}

void RDisplay(Node *p)
{
    if (p)
    {
        cout << p->data << "  ";
        RDisplay(p->next);
    }
}

int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25};
    create(A, 5);

    RDisplay(first);
    cout << "\n";
    Isorted(first, 1);
    RDisplay(first);

    return 0;
}
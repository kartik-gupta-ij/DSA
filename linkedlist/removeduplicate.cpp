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

void RD(Node *p)
{
    Node *q = NULL;
    q = p;
    p = p->next;
    while (p)
    {
        if (p->data == q->data)
        {
            q->next = p->next;
            delete p;
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
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
int main()
{
    struct Node *temp;
    int A[] = {5, 5, 5, 8, 8, 8, 32,32 };
    create(A, 8);

    RD(first);
    Display(first);

    return 0;
}
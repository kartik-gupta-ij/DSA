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

void Display(Node *p)
{
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
void RDisplay(Node *p)
{
    if (p)
    {
        cout << p->data << endl;
        RDisplay(p->next);
    }
}
void RRDisplay(Node *p)
{
    if (p)
    {
        RRDisplay(p->next);
        cout << p->data << endl;
    }
}

int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    RRDisplay(first);

    return 0;
}
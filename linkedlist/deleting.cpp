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

int Delete(Node *p, int pos)
{
    Node * q;   
    int x;
    if (pos < 0 || pos > count(p))
    {
        return 0;
    }
    if (pos == 1)
    {
        first = p->next;
        x=p->data;
        delete p;
        return x;
    }
    else if (pos > 0)
    {
        for (int i = 0; i < pos - 1 and p; i++)
        {
            q=p;
            p = p->next;
        }

        q->next = p->next;
        x=p->data;
        delete p;
        return x;
        
        
    }
    return 0;
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
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    // Display(first);

    Delete(first, 2);
    Display(first);

    return 0;
}
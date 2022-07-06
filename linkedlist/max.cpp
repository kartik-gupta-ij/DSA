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

int max(Node *p)
{
    int c = p->data;
    // c=INT_MIN;
    while (p)
    {
        if(p->data>c){
            c=p->data;
        };
        p = p->next;
    }
    return c;
}
int Rmax(Node *p)
{
    if (p== 0)
    {
        return 0;
    }
    else
    {
        int c=Rmax(p->next);
        if (c< p->data){
            return p->data;
        }else
    {
        return c;
    }
        
    }
}


int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    cout << max(first);

    return 0;
}
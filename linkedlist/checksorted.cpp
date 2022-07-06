
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

int Csorted(Node *p)
{
    int c=p->data;
    while (p)
    {
        if(p->data>=c){
            c=p->data;
            p=p->next;
        }
        else{
            return 0;
        }
    }
    return 1;
}



int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 103, 25,52};
    create(A, 6);

    cout << Csorted(first);

    return 0;
}
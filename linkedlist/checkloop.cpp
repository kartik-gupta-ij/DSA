#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} * first, *second, *third;

void create(Node **p, int *A, int n)
{
    Node *t, *last;
    *p = new Node;
    (*p)->data = A[0];
    (*p)->next = NULL;
    last = *p;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

bool isloop(Node *p){
    Node *q=NULL;
    q=p;
    p=p->next;
    while(p){
    if(p!=q ){
        q=q->next;
        p=p->next->next;
        }
    else{
        return true;
    }
        }
        return false;
}
int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int B[7] = {11, 12, 13, 14, 15, 16, 17};
    create(&first, A, 5);
    create(&second, B, 7);

    Node *t1,*t2;
    t1=first->next->next->next->next;
    t2=first->next->next;
    t1->next=t2;
    cout<<isloop(second);

}
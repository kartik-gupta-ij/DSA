#include <iostream>
using namespace std ;
struct Node{
    int data;
    Node *next;
}*first=NULL;

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

void reverse(Node *p,int n){
    Node *q=p;
   int i=0, ar[n]={0};
    while(p){
        ar[i]=p->data;
        p=p->next;
        i++;
    }
    i--;
    for(i;i>-1;i--){
        q->data=ar[i];
        q=q->next;
    }


}

void threepointR(Node *p){
    Node *q=0, *r=0;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;

}

void RecursiveRevese(Node *q,Node * p ){
    if(p){
        RecursiveRevese(p,p->next);
        p->next=q;
    }else{
        first=q;
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
int main(){
    struct Node *temp;
    int A[] = {3, 5, 7, 103, 25,52};
    create(A, 6);
    RecursiveRevese(0,first);
    Display(first);

}
#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLL
{
private:
    Node *first;

public:
    DoublyLL() { first = NULL; }
    DoublyLL(int A[], int n);
    ~DoublyLL();
    void Display();
    int Delete(int index);
    void insert(int x, int index);
    int length();
    void Reverse();
};
DoublyLL::DoublyLL(int A[], int n)
{
    first = new Node;
    Node *last, *t;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->next = NULL;
        t->data = A[i];
        last->next = t;
        t->prev = last;

        last = last->next;
    }
};
DoublyLL::~DoublyLL()
{
    Node *p = first;
    while (p)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void DoublyLL::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->prev << " " << p->data << "  " << p->next << "  " << endl;
        p = p->next;
    }
}

int DoublyLL::Delete(int index)
{
    Node *p = first;
    Node *q;
    int x;
    if (index < 0 || index > length())
    {
        return 0;
    }
    if (index == 1)
    {
        first = p->next;
        first->prev = NULL;
        x = p->data;
        delete p;
        return x;
    }
    else if (index > 0)
    {
        for (int i = 0; i < index - 1 and p; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        if(p->next)p->next->prev = q;
        x = p->data;
        delete p;
        return x;
    }
    return 0;
}
void DoublyLL::insert(int x, int index)
{
    Node *p = first;
    Node *t;
    t = new Node;
    t->data = x;
    if (index < 0 || index > length())
    {
        return;
    }
    if (index == 0)
    {
        t->next = first;
        first->prev = t;
        first = t;
        first->prev = NULL;
    }
    else if (index > 0)
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        t->prev = p;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}
int DoublyLL::length()
{
    Node *p = first;
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}
void DoublyLL::Reverse(){
    Node *p,*temp;
    p=first;
    while(p){
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;
        if(p!=NULL and p->next==NULL)first=p;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    DoublyLL L(A, 6);
    cout << L.length() << endl;
    L.Display();
    cout << endl;
    L.Reverse();
    L.Display();
    cout << endl;
}

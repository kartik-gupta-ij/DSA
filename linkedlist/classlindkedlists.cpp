#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Linkedlist{
    private:
        Node *first;
    public:
        Linkedlist(){first=NULL;}
        Linkedlist(int A[],int n);
        ~Linkedlist();
        void Display();
        int Delete(int index);
        void insert(int x, int index);
        int length();

};
Linkedlist::Linkedlist(int A[],int n){
    first=new Node;
    Node *last,*t;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->next=NULL;
        t->data=A[i];
        last->next=t;

        last=last->next;
    
    
    }
};
Linkedlist:: ~Linkedlist(){
    Node *p=first;
    while(p){
        first=first->next;
         delete p;
        p=first;
    }
}
        
void Linkedlist::  Display(){
    Node *p=first;
    while (p)
    {
        cout << p->data << "  ";
        p = p->next;}
    
}

int Linkedlist:: Delete(int index){
    Node *p=first;
    Node * q;   
    int x;
    if (index < 0 || index > length())
    {
        return 0;
    }
    if (index == 1)
    {
        first = p->next;
        x=p->data;
        delete p;
        return x;
    }
    else if (index > 0)
    {
        for (int i = 0; i < index - 1 and p; i++)
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
void Linkedlist::insert(int x, int index){
    Node *p=first;
    Node * t;
    t=new Node;
    t->data=x;
    if(index<0 || index>length()){
        return;
    }
    if(index==0){
        t->next=first;
        first=t;
    }
    else if(index>0){
        for(int i=0; i<index-1;i++){
            p=p->next;
        }
        
        t->next=p->next;
        p->next=t;
    }
}
int Linkedlist::length(){
    Node *p =first;    
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int main(){
    int A[]={1,2,3,4,5,6};
    Linkedlist L(A,6);
    cout<<L.length()<<endl;
    L.Display();
    cout<<endl;
    cout<<L.Delete(3)<<endl;
    L.Display();
    cout<<endl;
    L.insert(3,4);
    L.Display();
    cout<<endl;

}
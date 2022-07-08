#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class CLL{
    private:
        Node * head;
    public:
        CLL(){head=NULL;}
        CLL(int A[],int n);
        void Display();
        Node* getHead(){ return head; }
        void RDisplay(Node *p);
        void insert(int index,int x);
        int Length();
        int Delete(int index);

};

CLL::CLL(int A[],int n){
            Node *t,*last;
            t=new Node;
            t->data=A[0];
            t->next=t;
            head=last=t;
            for(int i=1;i<n;i++){
                t=new Node;
                t->data=A[i];
                t->next=head;
                last->next=t;
                last=t;
            }   
        }
void CLL::Display(){
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;

    }while(p!=head);
    cout<<endl;
}
void CLL::RDisplay(Node *p){
    static int flag=0;
    if(flag==0 || p!=head ){
        flag=1;
        cout << p->data << " -> " << flush;
        RDisplay(p->next);
    }
    
    flag=0;

}
 void CLL::insert(int index,int x){
    Node*t,*p;
    p=head;
    if(index==0){
        t=new Node;
        t->data=x;
        if(head==NULL){ 
            t->next=t;
            head=t;

        }else{
            
            while(p->next!=head){
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
    }else{
        t=new Node;
        t->data=x;
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
 }
int CLL::Length(){
    int l=0;
    Node *p;
    p=head;
    do{
        l++;
        p=p->next;
    }while(p!=head);
    return l;
}
int CLL::Delete(int index){
    Node *p,*q;
    p=head;
    int x;
    if(index<1){
        return -1;
    }
    else if(index==1){
        while(p->next!=head){
            p=p->next;
        }
        if(p==head){
            delete head;
            head=NULL;
            x=0;
            
        }
        else{
            x=head->data;
            q=head;
            head=head->next;
            p->next=head;
            delete q;
        }
    }else if(index>1 && index<Length()){
        
        for(int i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        x=q->data;
        p->next=q->next;
        delete q;

    }else{
        x=-1;
    }
    return x;
}
int main(){
    int A[]={1,2,3,4,5,6,7,8,9};
    CLL ll(A,9);
    ll.RDisplay(ll.getHead());
    cout<<endl;
    cout<<ll.Delete(10)<<endl;
    ll.RDisplay(ll.getHead());
    cout<<endl;

    
    cout<<endl;
}
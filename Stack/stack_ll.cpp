#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack(){
            top=NULL;
        }
        Stack(int arr[],int lenght){
            top=new Node;
            top->data=arr[0];
            top->next=NULL;
            Node *p,*temp=top;
            for(int i=1;i<lenght;i++){
                p=new Node;
                p->data=arr[i];
                p->next=NULL;
                temp->next=p;
                temp=temp->next;
            }
        }
        void push(int data){
            Node *p=new Node;
            if(!p){
                cout<<"OverFlow the heap"<<endl;
            }else{
                p->data=data;
                p->next=top;
                top=p;
            }
        }
        int pop(){
            Node *temp;
            int x=-1;
            if(!top){
                cout<<"UnderFlow"<<endl;
            }else{
                temp=top;
                top=top->next;
                x=temp->data;
                delete temp;
            }
            return x;
        }
        void display(){
            Node *temp=top;
            if(top==NULL){
                cout<<"Empty"<<endl;
            }else{
                cout<<"top->";
                while(temp!=NULL){
                    cout<<temp->data<<" <- ";
                    temp=temp->next;
                }
            }
        }
        int peek(int pos){
            Node *temp=top;
            if(top==NULL){
                cout<<"Empty"<<endl;
            }else{
                for(int i=1;temp&&i<pos;i++){
                    temp=temp->next;
                }
                if(temp){
                    cout<<temp->data<<endl;
                    return temp->data;
                }else{
                    cout<<-1<<endl;
                    return -1;}
            }
        }
};


int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    st.pop();
    st.display();
}
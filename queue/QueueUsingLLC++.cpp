#include <iostream>
using namespace std;

class Node{
    public:
        Node *next;
        int data;
};

class Queue{
    private:
        Node * front;
        Node * rear;

    public:
        Queue(){
            front=rear=nullptr;
        }
        void Enqueue(int x){
            Node *m=new Node;
            if(m==nullptr){
                cout<<"Queue is full"<<endl;
            }
            else{
                m->data=x;
                m->next=nullptr;

                if(front==nullptr){
                    front=m;
                    rear=m;
                }else{
                    rear->next=m;
                    rear=rear->next;
                }
            }
        }
        int Dequeue(){
            int x=-1;
            Node* m;
            if(nullptr==front){
                cout<<"Queur is Empty"<<endl;
            }else{
                x=front->data;
                m=front;
                front=front->next;
                delete m;
            }
            return x;
        }
        void Display(){
            Node *m=front; 
            while(m){
                cout<<m->data<<" ";
                m=m->next;
            }
            cout<<endl;
        }
};


int main(){
    Queue Q;
    cout<<Q.Dequeue()<<endl;
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Display();
    cout<<Q.Dequeue()<<endl;
    Q.Display();
    Q.Enqueue(3);
    Q.Enqueue(3);
    Q.Enqueue(3);
    Q.Enqueue(3);
    Q.Display();

}
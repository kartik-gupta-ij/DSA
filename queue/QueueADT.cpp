#include <iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *q;
    public:
        Queue(){
            front=rear=-1;
            size=10;
            q=new int[size];
            
        }
        Queue(int Size){
            front=rear=-1;
            size=Size;
            q=new int[size];
        }
        void Enqueue(int x){
            if(rear==size-1){
                cout<<"Queue is full"<<endl;
            }
            else{
                rear++;
                q[rear]=x;
            }
        }
        int Dequeue(){
            int x=-1;
            if(rear==front){
                cout<<"Queur is Empty"<<endl;
            }else{
                front++;
                x=q[front];
            }
            return x;
        }
        void Display(){
            for(int i=front+1;i<=rear;i++){
                cout<<q[i]<<" ";
            }
            cout<<endl;
        }
};


int main(){
    Queue Q(6);
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
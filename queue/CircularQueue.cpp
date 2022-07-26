#include <iostream>
using namespace std;

class CCQ{
    private:
        int front;
        int rear;
        int size;
        int *q;
    public:
        CCQ(){
            front=rear=-1;
            size=10;
            q=new int[size];
            
        }
        CCQ(int Size){
            front=rear=-1;
            size=Size;
            q=new int[size];
        }
        void Enqueue(int x){
            if((rear + 1) % size == front){
                cout<<"CCQ is full"<<endl;
            }
            else{
                rear=(rear+1)%size;
                q[rear]=x;
            }
        }
        int Dequeue(){
            int x=-1;
            if(rear==front){
                cout<<"Queur is Empty"<<endl;
            }else{
                front=(front+1)%size;
                x=q[front];
            }
            return x;
        }
        void Display(){
            int i=front+1;
            do{
                cout<<q[i]<<" ";
                i=(i+1)%size;
            }while((rear+1)%size!=i);
            cout<<endl;
        }
};


int main(){
    CCQ Q(6);
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
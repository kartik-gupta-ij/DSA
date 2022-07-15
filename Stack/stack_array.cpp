#include <iostream>
using namespace std ;
class Stack{
    private:
        int *ar;
        int top;
        int size;
    public:
        Stack(){
            size=10;
            top=-1;
            ar=new int[size];
        }
        Stack(int fun_size){
            size=fun_size;
            top=-1;
            ar=new int[size];
        }
        void push(int data){
            
            if(top==size-1){
                cout<<"OverFlow"<<endl;
            }else{
                top++;
                ar[top]=data;
            }
        }
        int pop(){
            int x=-1;
            if(top==-1){
                cout<<"UnderFlow"<<endl;
            }else{
                cout<<ar[top]<<" --Poped"<<endl;
                x=ar[top];
                top--;
            }
            return x;
        }
        int isFull(){
            if(top==size-1){
                cout<<"FULL"<<endl;
                return 1;
            }else{
                cout<<"Not FULL"<<endl;
                return 0;
            }
        }
        int isEmpty(){
            if(top==-1){
                cout<<"Empty"<<endl;
                return 1;
            }else{
                cout<<"Not Empty"<<endl;
                return 0;
            }
        }
        void display(){
            if(top==-1){
                cout<<"EMPTY"<<endl;
            }else{
                int i=0;
                cout<<"Top"<<endl;
                for(i=top;i>-1;i--){
                    cout<<ar[i]<<endl<<"^"<<endl<<"|"<<endl;
                }
            }
        }
        void fill(int tillpoint){
            if(!tillpoint<=size-top+1){
                cout<<"Need More space"<<endl;
            }
            else{
                int i;
                for(top;top<tillpoint;){
                    top++;
                    cout<<"Enter "<<top<<endl;
                    cin>>ar[top];
                }
            }
        }
        void tempfill(){
            int tillpoint=5;
            if(tillpoint>size-top-1){
                cout<<"Need More space"<<endl;
            }
            else{
                int i;
                for(top;top<tillpoint-1;){
                    top++;
                    ar[top]=top+2;
                }
            }
        }
        
};

int main(){
    Stack st(10);
    st.tempfill();
    st.display();
    st.pop();
    st.display();
    st.push(23);
    st.display();
}
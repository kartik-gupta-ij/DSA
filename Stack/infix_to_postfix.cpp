#include <iostream>
#include<cstring>
using namespace std;

class Node{
    public:
        char data;
        Node *next;
};

class Stack{
        
    public:
        Node *top;
        Stack(){
            top=NULL;
        }
        void push(char data){
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
            char x=-1;
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
        
};

int pre(char x){
    if(x=='*' || x=='/'){
        return 2;    }
    else if(x=='+' || x=='-'){
        return 1;    }
    else{
        return 0;
    }
}
int isoperand(char x){
    if(x=='*'||x=='/'||x=='+'||x=='-'){
        return 0;
    }else{
        return 1;
    }
}
char * infixToPostflix(char *exp){
    Stack st;

}


int main(){
    
    char E[] = "((a+b)*(c-d))";
    cout << isBalanced(E) << endl;
 
    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;
 
    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;
 
    return 0;

}
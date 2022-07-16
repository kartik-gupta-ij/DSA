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
int isBalanced(char *exp){
    Stack st;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('){
            st.push('(');
        }else if (exp[i]==')')
        {
            if(st.top==NULL){
                return 0;
            }else{
                st.pop();
            }
        }
    }
    if(st.top==NULL){
        return 1;
    }else{
        return 0;
    }

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
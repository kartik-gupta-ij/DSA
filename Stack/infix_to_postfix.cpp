#include <iostream>
#include <cstring>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class Stack
{

public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void push(char data)
    {
        Node *p = new Node;
        if (!p)
        {
            cout << "OverFlow the heap" << endl;
        }
        else
        {
            p->data = data;
            p->next = top;
            top = p;
        }
    }
    char pop()
    {
        Node *temp;
        char x = -1;
        if (!top)
        {
            cout << "UnderFlow" << endl;
        }
        else
        {
            temp = top;
            top = top->next;
            x = temp->data;
            delete temp;
        }
        return x;
    }
};

int pre(char x)
{
    if (x == '*' || x=='/')
    {
        return 2;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isoperand(char x)
{
    if (x == '*' || x=='/' || x == '+' || x == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
char *infixToPostflix(char *exp)
{
    Stack st;
    st.push('#');
    char *fexp;
    fexp= new char[strlen(exp)+2];
    int i = 0, j = 0;
    while (exp[i] != '\0')
    {
        if (isoperand(exp[i]))
        {
            fexp[j] = exp[i];
            j++;
            i++;
        }
        else
        {
            if (pre(exp[i]) <= pre(st.top->data))
            {
                fexp[j] = st.pop();
                j++;
            }
            else
            {
                st.push(exp[i]);
                i++;
            }
        }
        
    }
    while(st.top!=NULL){
            fexp[j]=st.pop();
            j++;
        }
    fexp[j]='\0';
    cout<<fexp<<endl;
    return fexp;
}

int main()
{
    char *infix="a+b*c-d/e";


    char *postfix=infixToPostflix(infix);

    cout<<postfix<<endl;

    return 0;
}
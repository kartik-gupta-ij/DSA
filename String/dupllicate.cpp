#include <iostream>
using namespace std;

int main(){
    char ar[]="abac";
    long x=0,s=0;
    int i;
    
    for(i=0;ar[i]!='\0';i++){
    
        x=1;
        x=x<<(ar[i]-97);
        if((s&x)>0){
            cout<<"duplicated "<<ar[i]<<endl;
        }else{
            s=(s|x);
        }
    }
}
#include <iostream>
using namespace std;


void per(char st[10],int k){
    static char ps[10]={0},ns[10]={0};
    int i=0;
    
    if(st[k]=='\0'){
        ps[k]='\0';
        cout<<ps<<endl;
    }else{
    for(i=0;st[i]!='\0';i++){
        if(ns[i]==0){
            ns[i]=1;
            ps[k]=st[i];
            per(st,k+1);
            ns[i]=0;
        }
    }}
}


int main(){
    char s[]="abc";
    // printf("Enter string:\n");
    // gets(string);
    per(s, 0);

}
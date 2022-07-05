#include <iostream>
using namespace std;

int main(){
    char st[]="kartik";
    char sr[]="akrtik";
    int i, ar[26]={0};
        
    for(i=0;st[i]!='\0';i++){
        ar[st[i]-97]++;

    }
    for(i=0;sr[i]!='\0';i++){
        ar[sr[i]-97]--;
    }
    for(i=0;i<26;i++){
        if(ar[i]!=0){
            cout<<"not anagram";
            return 0;
        }
    }
    cout<<"Anagram";
    return 1;

}
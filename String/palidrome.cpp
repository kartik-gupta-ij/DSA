#include <iostream>
using namespace std;

int main(){
    char ar[]="kastak";
    
    int i,j;
    

    for(j=0;ar[j]!='\0';j++){

    }
    j=j-1;
    for(i=0;j>i;i++,j--){
        if(ar[i]!=ar[j]){
            cout<<"not";
            return 0;
        }

    }
    cout<<"yes";
    return 0;
}
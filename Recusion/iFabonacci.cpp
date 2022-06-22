#include <iostream>
using namespace std;

int fab(int n){
    int s0=0,s1=1,s;
    if( n==0){
        return s0;
    }
    else if(n==1){
        return s1;
    }
    for(int i= 2;i<=n;i++){
        
        s=s0+s1;
        s0=s1;
        s1=s;
    }
    return s;
}

int main(){
    cout<<(fab(5));
}
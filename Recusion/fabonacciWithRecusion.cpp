#include <iostream>
using namespace std;

int fab(int n){
    if( n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return fab(n-2)+fab(n-1);
}

int main(){
    cout<<(fab(5));
}
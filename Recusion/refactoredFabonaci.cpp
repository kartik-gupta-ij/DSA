#include <iostream>
using namespace std;
int f[100];

int fab (int n){
if(n<2){
    f[n]=n;
    return n;
}
else{
    if(f[n-2]==-1){
        f[n-2]=fab(n-2);
    }
    if(f[n-1]==-1){
        f[n-1]=fab(n-1);
    }
    f[n]=f[n-1]+f[n-2];
    return f[n-1]+f[n-2];
}
}
int main (){
    for(int i=0;i<100;i++){
        f[i]=-1;
    }
    cout<< fab(5);
}
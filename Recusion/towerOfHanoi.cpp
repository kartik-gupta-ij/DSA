#include <iostream>

using namespace std;

void ToH(int n, int a, int b ,int c){
    if(n>0){
        ToH(n-1,a,c,b);
    cout<<"Move the disc from "<<a<<" to "<<c<<endl;
    ToH(n-1,b,a,c);
}
    }


int main(){
    ToH(3,1,2,3);
}
#include <iostream>
using namespace std;

int fact(int  n ){
    if(n<2){
        return n;
    }
    return n* fact(n-1);
}

int nCr(int n, int r){
    int num,demon;
    num=fact(n);
    demon= fact(r)*fact(n-r);
    return num/demon;

}


int main (){
    cout<< nCr(4,2);
}
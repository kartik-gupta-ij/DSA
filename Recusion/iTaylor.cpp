#include <iostream>
using namespace std;

double e(int x, int n){
    double s=1,num=1,d=1;
    for(int i=1; i<=n; i++){
        num*=x;
        d*=i;

        s= s+num/d;

    }
    return s;
}

int main (){
    cout<< e(1,10);
}


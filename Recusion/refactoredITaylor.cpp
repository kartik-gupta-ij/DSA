#include <iostream>
using namespace std;

double e(int x, int n){
    double s=1;
    for(n=n;n>0; n--){
        s=1+s*x/n;

    }
    return s;
}

int main (){
    cout<< e(1,7);
}


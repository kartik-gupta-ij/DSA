#include <iostream>
using namespace std;

struct Array
{   
    int A[100];
    int size;    
    int lenght;
};

void findmanydS(Array arr){
    int i,l=-1;
    for(i=0;i<arr.lenght;i++){
        if(arr.A[i]==arr.A[i+1] and l!=arr.A[i]){cout<<arr.A[i]<<" ";
        l=arr.A[i];
        }}

}

void findmanyUnSortedd(Array arr){
    int i=0,max=0,min=arr.A[0];
    Array arr1;
    fill(arr1.A, arr1.A+100, 0);
    
    for(i=0;i<arr.lenght;i++){
        arr1.A[arr.A[i]]++;
        if(max<arr.A[i])max=arr.A[i];
        if(min>arr.A[i])min=arr.A[i];
        
    }
    for(i=min;i<max+1;i++){
        
        if(arr1.A[i]>1)cout<<i<<" ";
        
    }
}

int main(){
    Array arr={{0,0,4,6,6,6,5,5},10,8};
    
    findmanyUnSortedd(arr);

}
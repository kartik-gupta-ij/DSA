#include <iostream>
using namespace std;

struct Array
{   
    int A[100];
    int size;    
    int lenght;
};


void sumKU(Array arr,int k){
    int i=0;
    Array arr1;
    fill(arr1.A, arr1.A+100,0);
    
    for(i=0;i<arr.lenght;i++){
        if(arr1.A[k-arr.A[i]]!=0 and arr.A[i]<k){
            cout<<arr.A[i]<<' '<<k-arr.A[i]<<endl;
        }
        arr1.A[arr.A[i]]++;
        
    }

    
}
void sumKS(Array arr,int k){
    int i=0,j=arr.lenght-1;
    
    
    while(i<j){
        if(arr.A[i]+arr.A[j]==k){
            cout<<arr.A[i]<<' '<<k-arr.A[i]<<endl;
            i++;
            j--;
        }else if(arr.A[i]+arr.A[j]<k){
            i++;
        }else{
            j--;
        }
    }

    
}
int main(){
    Array arr={{1,2,3,7,9,10},10,6};
    
    sumKS(arr,10);

}
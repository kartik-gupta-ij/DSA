#include <iostream>
using namespace std;

struct Array
{   
    int A[100];
    int size;    
    int lenght;
};

void findonemissing(Array arr){
    int i=0,diff;
    diff=arr.A[0];
    while(i<arr.lenght){
        if(arr.A[i]-diff!=i){
            cout<<arr.A[i]-1;
            diff++;
        }
        i++;
    }
}
void findmanymissing(Array arr){
    int i=0,diff;
    diff=arr.A[0];
    for(i=0;i<arr.lenght;i++){
        while(arr.A[i]-diff!=i){
            cout<<i+diff<<" ";
            diff++;
           
        }
    }
}


void findmanyUnSortedmissing(Array arr){
    int i=0,max=0,min=arr.A[0];
    Array arr1;
    fill(arr1.A, arr1.A+100, 0);
    
    for(i=0;i<arr.lenght;i++){
        arr1.A[arr.A[i]]=1;
        if(max<arr.A[i])max=arr.A[i];
        if(min>arr.A[i])min=arr.A[i];
        
    }
    for(i=min;i<max;i++){
        
        if(arr1.A[i]==0)cout<<i<<" ";
        
    }

    
}
int main(){
    Array arr={{7,15,4,80,6,9,10,16},10,8};
    
    findmanyUnSortedmissing(arr);

}
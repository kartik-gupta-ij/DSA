#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int lenght;
};

void display(struct Array *arr)
{
    int i;


    for (i = 0; i < arr->lenght; i++)
    {
        cout <<  arr->A[i] <<" ";
    }
    cout<<endl;
}

void fill(struct Array *arr){
    cout << "Enter Number of numbers" << endl;
    cin >> arr->lenght;
    for (int i = 0; i < arr->lenght; i++)
    {
        cout << "Enter the " << i << " Element" << endl;
        cin >> arr->A[i];
    }
}
void tempfill(struct Array *arr){
    arr->lenght=5;
    for (int i = 0; i < arr->lenght; i++)
    {
        
        arr->A[i]=i;
    }
}
void append(struct Array *arr){
    if(arr->lenght<arr->size){
        int x;
        cout<<"Enter the Element to be appended"<<endl;
        cin>>x;
        arr->A[arr->lenght++]=x;}
        else{
            cout<<"Array is Full"<<endl;
        }
}

void insert(struct Array *arr){
    int i,x;
    cout<<"Enter the Elemrnt";
    cin>>x;
    cout<<"Enter the index";
    cin>>i;
    if(i>-1 and arr->lenght<arr->size and arr->lenght>=i){
    for(int m=arr->lenght;m>i;m--){
        arr->A[m]=arr->A[m-1];
    }
    arr->A[i]=x;
    arr->lenght++;
    }else{
            cout<<"Array is Full or enter vaild index "<<endl;
        }
}

void del(struct Array *arr){
    int i;
    cout<<"Enter The index to be deleted "<<endl;
    cin>> i;
    cout<<"deleted "<<arr->A[i]<< endl;
    if(i<arr->lenght and i>-1){
        for(;i<arr->lenght-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->lenght--;
    }

}

void lSearch(struct Array *arr){
    int key;
    cout<<"Enter the Element to be searched : ";
    cin>>key;
    int i;


    for (i = 0; i < arr->lenght; i++)
    {
        if(arr->A[i]==key){
            cout<<"ELement found at index :"<<i<<endl;
            return;
        }
    }
    cout<<"ELement is not present in arr"<<endl;
    cout<<endl;

}
int main()
{
    struct Array arr;
    int n, i;
    cout << "Enter the size of Array" << endl;
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.lenght = 0;
    // fill(&arr);
    
    // append(&arr);
    // display(arr);
    // insert(&arr);
    // display(arr);
    tempfill(&arr);
    display(&arr);
    lSearch(&arr);
    display(&arr);


}
#include <iostream>
using namespace std;

struct Array1
{
    int *A;
    int size;
    int lenght;
};

struct Array
{   
    int A[100];
    int size;    
    int lenght;
};
void display(struct Array *arr)
{
    int i;

    for (i = 0; i < arr->lenght; i++)
    {
        cout << arr->A[i] << " ";
    }
    cout << endl;
}

void fill(struct Array *arr)
{
    cout << "Enter Number of numbers" << endl;
    cin >> arr->lenght;
    for (int i = 0; i < arr->lenght; i++)
    {
        cout << "Enter the " << i << " Element" << endl;
        cin >> arr->A[i];
    }
}
void tempfill(struct Array *arr)
{
    arr->lenght = 6;
    for (int i = 0; i < arr->lenght; i++)
    {

        arr->A[i] = i;
    }
}
void append(struct Array *arr)
{
    if (arr->lenght < arr->size)
    {
        int x;
        cout << "Enter the Element to be appended" << endl;
        cin >> x;
        arr->A[arr->lenght++] = x;
    }
    else
    {
        cout << "Array is Full" << endl;
    }
}

void insert(struct Array *arr)
{
    int i, x;
    cout << "Enter the Elemrnt";
    cin >> x;
    cout << "Enter the index";
    cin >> i;
    if (i > -1 and arr->lenght < arr->size and arr->lenght >= i)
    {
        for (int m = arr->lenght; m > i; m--)
        {
            arr->A[m] = arr->A[m - 1];
        }
        arr->A[i] = x;
        arr->lenght++;
    }
    else
    {
        cout << "Array is Full or enter vaild index " << endl;
    }
}

int del(struct Array *arr)
{
    int i, m;
    cout << "Enter The index to be deleted " << endl;
    cin >> i;
    m = arr->A[i];
    cout << "deleted " << m << endl;
    if (i < arr->lenght and i > -1)
    {
        for (; i < arr->lenght - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->lenght--;
    }
    return m;
}

int lSearch(struct Array *arr)
{
    int key;
    cout << "Enter the Element to be searched : ";
    cin >> key;
    int i;

    for (i = 0; i < arr->lenght; i++)
    {
        if (arr->A[i] == key)
        {
            cout << "ELement found at index :" << i << endl;
            return i;
        }
    }
    cout << "ELement is not present in arr" << endl;
    cout << endl;
    return -1;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int transportionLinearSearch(struct Array *arr)
{
    int key;
    cout << "Enter the Element to be searched : ";
    cin >> key;
    int i;

    for (i = 0; i < arr->lenght; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            cout << "ELement found at index :" << i - 1 << endl;
            return i - 1;
        }
    }
    cout << "ELement is not present in arr" << endl;
    cout << endl;
    return -1;
}

int moveToHeadLinearSearch(struct Array *arr)
{
    int key;
    cout << "Enter the Element to be searched : ";
    cin >> key;
    int i;

    for (i = 0; i < arr->lenght; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[0]);
            cout << "ELement found at index :" << i - 1 << endl;
            return i - 1;
        }
    }
    cout << "ELement is not present in arr" << endl;
    cout << endl;
    return -1;
}

int BinarySearch(struct Array *arr)
{
    int key;
    cout << "Enter the Element to be searched : ";
    cin >> key;
    int mid, l, h;
    h = arr->lenght;
    l = 0;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr->A[mid] == key)
        {
            cout << "ELement found at index :" << mid << endl;
            return mid;
        }
        else if (arr->A[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << "ELement is not present in arr" << endl;
    return -1;
}

int RBinarySearch(int arr[], int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == key)
        {
            cout << "ELement found at index :" << mid << endl;
            return mid;
        }
        else if (arr[mid] > key)
        {
            RBinarySearch(arr, l, mid - 1, key);
        }
        else
        {
            RBinarySearch(arr, mid + 1, h, key);
        }
    }
    else
    {

        cout << "ELement is not present in arr" << endl;
        return -1;
    }
    return 0;
}
int get(struct Array *arr)
{
    int i;
    cout << "please enter the index" << endl;
    cin >> i;
    if (i > -1 and i < arr->lenght)
    {
        cout << "the element is " << arr->A[i] << endl;
        return arr->A[i];
    }
    return -1;
}

void set(struct Array *arr)
{
    int i;
    cout << "please enter the index " << endl;
    cin >> i;
    int x;
    cout << "please enter the Element " << endl;
    cin >> x;
    if (i > -1 and i < arr->lenght)
    {
        arr->A[i] = x;
        cout << "the element is " << arr->A[i] << " at index " << i << endl;
    }
}
int max(struct Array *arr)
{
    int max = arr->A[0];

    for (int i = 0; i < arr->lenght; i++)
    {
        if (max < arr->A[i])
        {
            max = arr->A[i];
        }
    }
    cout<<max<<endl;
    return max;
}
int sum(struct Array *arr)
{
    int sum = arr->A[0];

    for (int i = 0; i < arr->lenght; i++)
    {
          sum = arr->A[i]+sum;
        
    }
    cout<<sum<<endl;
    return sum;
}
int avg(struct Array *arr)
{
    int sum = arr->A[0];

    for (int i = 0; i < arr->lenght; i++)
    {
          sum = arr->A[i]+sum;
        
    }
    cout<<(float)sum/arr->lenght<<endl;
    return (float)sum/arr->lenght;
}
void reverse(struct Array *arr){
    int i,j;
    for(i=0,j=arr->lenght-1;i<arr->lenght/2;i++,j--){
        swap(&arr->A[j],&arr->A[i]);
    }
}

int issorted(struct Array *arr){ 
    int x=arr->A[0];
    for (int i = 0; i < arr->lenght; i++)
    {   if(arr->A[i]<x){
            cout<<"unsorted"<<endl;
            return -1;}
        x=arr->A[i];
    }
    cout<<"sorted"<<endl;
    return 1;
}

void insertsorted(struct Array *arr){
    int x;
    cout<<"enter elemenrt: ";
    cin>>x;
    int i=arr->lenght-1;
    while(arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->lenght++;


}

void REarrange(struct Array *arr){
    int i,j;
    i=0;
    j=arr->lenght-1;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j--;}
        if(i<j)swap(&arr->A[i],&arr->A[j]);


    }
}

int main1()
{
    // struct Array arr;
    // int n, i;
    // cout << "Enter the size of Array" << endl;
    // cin>>arr.size;
    // arr.size=10;
    // arr.A = new int[arr.size];
    // arr.lenght = 0;
    // fill(&arr);

    // append(&arr);
    // display(arr);
    // insert(&arr);
    // display(arr);
    // RBinarySearch(arr.A,0,arr.lenght,1);
    // tempfill(&arr);
    // display(&arr);
    // REarrange(&arr);

    // display(&arr);
    return 0;
}

struct Array*  Merging(Array *a1,Array *a2){
    int i=0,j=0,k=0;
    struct Array *D;

    while(i<a1->lenght and j<a2->lenght){
        if(a1->A[i]<a2->A[j]){
            D->A[k]=a1->A[i];
            k++;
            i++;
        }else{
            D->A[k]=a2->A[j];
            k++;
            j++;
        }

    }
    for(;i<a1->lenght;i++){
         D->A[k++]=a1->A[i];
    }
    for(;j<a2->lenght;j++){
         D->A[k++]=a2->A[j];
    }
    D->lenght=a1->lenght+a2->lenght;
    D->size=100;
    return  D;
}
int main(){
    struct Array arr1={{0,2,4,6,8},10,5};
    struct Array arr2={{1,3,5,7},10,4};
    display(&arr1);
    display(&arr2);
    struct Array *arr;
    arr=Merging(&arr1,&arr2);
    display(&arr1);
    display(&arr2);
    display(arr);


}
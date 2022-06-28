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
    arr->lenght = 5;
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
    cout<<sum/arr->lenght<<endl;
    return sum/arr->lenght;
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
    // RBinarySearch(arr.A,0,arr.lenght,1);
    tempfill(&arr);
    display(&arr);
    avg(&arr);

    display(&arr);
}
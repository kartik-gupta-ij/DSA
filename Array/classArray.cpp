#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        A = new int[10];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void display();
    void fill();
    void tempfill();
    void append();
    void insert();
    int del();
    int lSearch();
    int transportionLinearSearch();
    void REarrange();
    void insertsorted();
    int issorted();
    void reverse();
    int avg();
    int sum();
    int max();
    void set();
    int get();
    int BinarySearch();
    int moveToHeadLinearSearch();
    Array *Merging(Array *a2);
    Array *Diff(Array *a2);
    Array *intersection(Array *a2);
    Array *Union(Array *a2);
};

void Array::display()
{
    int i;

    for (i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::fill()
{
    cout << "Enter Number of numbers" << endl;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << "Enter the " << i << " Element" << endl;
        cin >> A[i];
    }
}
void Array::tempfill()
{
    length = 6;
    for (int i = 0; i < length; i++)
    {

        A[i] = i;
    }
}
void Array::append()
{
    if (length < size)
    {
        int x;
        cout << "Enter the Element to be appended" << endl;
        cin >> x;
        A[length++] = x;
    }
    else
    {
        cout << "Array is Full" << endl;
    }
}

void Array::insert()
{
    int i, x;
    cout << "Enter the Elemrnt";
    cin >> x;
    cout << "Enter the index";
    cin >> i;
    if (i > -1 and length < size and length >= i)
    {
        for (int m = length; m > i; m--)
        {
            A[m] = A[m - 1];
        }
        A[i] = x;
        length++;
    }
    else
    {
        cout << "Array is Full or enter vaild index " << endl;
    }
}

int Array::del()
{
    int i, m;
    cout << "Enter The index to be deleted " << endl;
    cin >> i;
    m = A[i];
    cout << "deleted " << m << endl;
    if (i < length and i > -1)
    {
        for (; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return m;
}

int Array::lSearch()
{
    int key;
    cout << "Enter the Element to be searched : ";
    cin >> key;
    int i;

    for (i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            cout << "ELement found at index :" << i << endl;
            return i;
        }
    }
    cout << "ELement is not present in arr" << endl;
    cout << endl;
    return -1;
}
void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int Array::transportionLinearSearch()
{
    int key;
    cout << "Enter the Element to be searched : ";
    cin >> key;
    int i;

    for (i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            swap(&A[i], &A[i - 1]);
            cout << "ELement found at index :" << i - 1 << endl;
            return i - 1;
        }
    }
    cout << "ELement is not present in arr" << endl;
    cout << endl;
    return -1;
}

int Array::moveToHeadLinearSearch()
{
    int key;
    cout << "Enter the Element to be searched : ";
    cin >> key;
    int i;

    for (i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            swap(&A[i], &A[0]);
            cout << "ELement found at index :" << i - 1 << endl;
            return i - 1;
        }
    }
    cout << "ELement is not present in arr" << endl;
    cout << endl;
    return -1;
}

int Array::BinarySearch()
{
    int key;
    cout << "Enter the Element to be searched : ";
    cin >> key;
    int mid, l, h;
    h = length;
    l = 0;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (A[mid] == key)
        {
            cout << "ELement found at index :" << mid << endl;
            return mid;
        }
        else if (A[mid] > key)
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
int Array::get()
{
    int i;
    cout << "please enter the index" << endl;
    cin >> i;
    if (i > -1 and i < length)
    {
        cout << "the element is " << A[i] << endl;
        return A[i];
    }
    return -1;
}

void Array::set()
{
    int i;
    cout << "please enter the index " << endl;
    cin >> i;
    int x;
    cout << "please enter the Element " << endl;
    cin >> x;
    if (i > -1 and i < length)
    {
        A[i] = x;
        cout << "the element is " << A[i] << " at index " << i << endl;
    }
}
int Array::max()
{
    int max = A[0];

    for (int i = 0; i < length; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    cout << max << endl;
    return max;
}
int Array::sum()
{
    int sum = A[0];

    for (int i = 0; i < length; i++)
    {
        sum = A[i] + sum;
    }
    cout << sum << endl;
    return sum;
}
int Array::avg()
{
    int sum = A[0];

    for (int i = 0; i < length; i++)
    {
        sum = A[i] + sum;
    }
    cout << (float)sum / length << endl;
    return (float)sum / length;
}
void Array::reverse()
{
    int i, j;
    for (i = 0, j = length - 1; i < length / 2; i++, j--)
    {
        swap(&A[j], &A[i]);
    }
}

int Array::issorted()
{
    int x = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] < x)
        {
            cout << "unsorted" << endl;
            return -1;
        }
        x = A[i];
    }
    cout << "sorted" << endl;
    return 1;
}

void Array::insertsorted()
{
    int x;
    cout << "enter elemenrt: ";
    cin >> x;
    int i = length - 1;
    while (A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

void Array::REarrange()
{
    int i, j;
    i = 0;
    j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
        {
            i++;
        }
        while (A[j] >= 0)
        {
            j--;
        }
        if (i < j)
            swap(&A[i], &A[j]);
    }
}

Array *Array::Merging(Array *a2)
{
    int i = 0, j = 0, k = 0;
    Array *D = new Array(length + a2->length);
    while (i < length and j < a2->length)
    {
        if (A[i] < a2->A[j])
        {
            D->A[k] = A[i];
            k++;
            i++;
        }
        else
        {
            D->A[k] = a2->A[j];
            k++;
            j++;
        }
    }
    for (; i < length; i++)
    {
        D->A[k++] = A[i];
    }
    for (; j < a2->length; j++)
    {
        D->A[k++] = a2->A[j];
    }
    D->length = length + a2->length;
    D->size = 100;
    return D;
}

Array *Array::Union(Array *a2)
{
    int i = 0, j = 0, k = 0, c = 0;

    Array *D = new Array(length + a2->length);

    while (i < length and j < a2->length)
    {
        if (A[i] < a2->A[j])
        {
            D->A[k] = A[i];
            k++;
            i++;
        }
        else if (A[i] == a2->A[j])
        {
            D->A[k] = A[i];
            k++;
            i++;
            j++;
            c++;
        }
        else
        {
            D->A[k] = a2->A[j];
            k++;
            j++;
        }
    }
    for (; i < length; i++)
    {
        D->A[k++] = A[i];
    }
    for (; j < a2->length; j++)
    {
        D->A[k++] = a2->A[j];
    }
    D->length = k;
    D->size = 100;
    return D;
}

struct Array *Array::intersection(Array *a2)
{
    int i = 0, j = 0, k = 0, c = 0;
    Array *D = new Array(length + a2->length);

    while (i < length and j < a2->length)
    {
        if (A[i] < a2->A[j])
        {
            i++;
        }
        else if (A[i] == a2->A[j])
        {
            D->A[k] = A[i];
            k++;
            i++;
            j++;
            c++;
        }
        else
        {
            j++;
        }
    }

    D->length = k;
    D->size = 100;
    return D;
}

Array *Array::Diff(Array *a2)
{
    int i = 0, j = 0, k = 0, c = 0;
    Array *D = new Array(length + a2->length);

    while (i < length and j < a2->length)
    {
        if (A[i] < a2->A[j])
        {
            D->A[k] = A[i];
            k++;
            i++;
        }
        else if (A[i] == a2->A[j])
        {

            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    for (; i < length; i++)
    {
        D->A[k++] = A[i];
    }

    D->length = k;
    D->size = 100;
    return D;
}


int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of Array";
    cin>>sz;
    arr1 = new Array(sz);

    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6.Exit\n";

        cout << "enter you choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            arr1->insert();
            break;
        case 2:
            x = arr1->del();
            break;
        case 3:
            index = arr1->lSearch();
            break;
        case 4:
            cout << "Sum is " << arr1->sum();
            break;
        case 5:
            arr1->display();
        }
    } while (ch < 6);
    return 0;
}
#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int lenght;
};

void display(struct Array arr)
{
    int i;


    for (i = 0; i < arr.lenght; i++)
    {
        cout <<  arr.A[i] <<" ";
    }
}

void fill(struct Array &arr){
    cout << "Enter Number of numbers" << endl;
    cin >> arr.lenght;
    for (int i = 0; i < arr.lenght; i++)
    {
        cout << "Enter the " << i << " Element" << endl;
        cin >> arr.A[i];
    }
}
int main()
{
    struct Array arr;
    int n, i;
    cout << " Enter the size of Array" << endl;
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.lenght = 0;
    fill(arr);
    display(arr);
}
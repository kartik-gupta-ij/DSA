#include <iostream>
using namespace std;

class Rectangle{
    private:
    int lenght;
    int breadth;
    public:
    Rectangle(){
        lenght=0;
        breadth=0;
    }
    Rectangle(int l, int b){
        lenght=l;
        breadth=b;
    }
    int area()
    {
        return lenght*breadth;
    }
    int parameter()
    {
        return 2*(lenght+breadth);
    }
    void changelength(int l){
        lenght=l;
    }
    int getlenght(){
        return lenght;
    }
};

int main(){
    Rectangle r (12,10);
    cout << r.area() << endl;
    cout << r.parameter()<<endl;
}
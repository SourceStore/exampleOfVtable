#include <iostream>

using namespace std;

/*
bool check_equals(Expression const *left, Expression const *right)
{
    return (*((size_t*)left) == *((size_t*)right));
}
*/
struct A {
    virtual ~A() { cout << "~A()" << endl; }
    virtual void func1() { cout << "func1()" << endl; }
    virtual void func2() { cout << "func2()" << endl; }
    virtual void func3() { cout << "func3()" << endl; }
    virtual void func4() { cout << "func4()" << endl; }
    int a = 0x1337;
};

int main() {
    A *a = new A;
    void **vtable = *(void***)a;
    for (int i = 0; i < 5; i++) {
        cout << hex << vtable[i] << endl;
    }
    for (int i = 5; i < 10; i++) {
        cout << hex << vtable[i] << '\t' << "garbage?" << endl;
    }
    delete a;
    return 0;
}

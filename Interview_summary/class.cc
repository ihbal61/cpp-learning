#include <iostream>
using namespace std;

class Base {
public:
    Base(){};
    ~Base() = default;
    void FunctionA() {
        cout << "This is function A" << endl;
    }
    virtual void FunctionB() {
        cout << "This is function B" << endl;
    }
};

class Derived : public Base {
public:
    Derived(){};
    void FunctionB() override {
        cout << "This is Derived function B" << endl;
    }
};

// case 1
// int main() {
//     Base* p = new Derived();
//     p->FunctionA();
//     delete p;
//     p = nullptr;
//     p->FunctionA();
//     return 0;
// }

// case 2
int main() {
    Base* p = new Derived();
    p->FunctionB();
    delete p;
    p = nullptr;
    p->FunctionB(); // 报错，p指针已经被置空，无法从虚函数表中查找到functionB，运行时报错
    return 0;
}
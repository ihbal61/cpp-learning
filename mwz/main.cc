#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A() {
        cout << "con" << endl;
    }
    ~A() {
        cout << "deco" << endl;
    }
    A(const A& a) {
        cout << "copy" << endl;
    }

    void process() {
        cout << "normal" << endl;
    }
    void process() const {
        cout << "const" << endl;
    }

    void info() {}
};

class Father {
public:
    Father() {
        cout << "Father()" << endl;
    }
    virtual ~Father() {
        cout << "~Father()" << endl;
    }
    virtual void fa() {
        cout << "fa()" << endl;
    }
};

class Son : public Father {
public:
    Son() {
        cout << "Son()" << endl;
    }
    ~Son() {
        cout << "~Son()" << endl;
    }

    void fa() {
        cout << "so()" << endl;
    }
};

A testClass() {
    A var;
    return var;
}

int main() {
    cout << 1 << endl;
    cout << 2 << endl;

    int *arr = new int[10];
    arr[1] = 1;
    cout << arr[2] << endl;
    delete []arr;

    /*A a;
    a.process();
    const A c;
    c.process();*/

    Father *f = new Son();
    f->fa();
    delete f;

    cout << 9 << endl;

    return 0;
}
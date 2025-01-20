# C++新特性

## C++11新特性

### 1. auto关键字
    说明：
        - auto关键字用于自动推导变量的类型，编译器会根据变量的初始化表达式自动推导出变量的类型。
        - auto关键字只能用于局部变量，不能用于函数参数、类成员变量等。
        - 不能用于：
            - auto关键字不能用于推导数组类型，但可以用于推导指针类型。
            - auto关键字不能用于推导引用类型，但可以用于推导指针类型。
            - auto关键字不能用于推导模板参数类型。
            - auto关键字不能用于推导函数返回值类型。
            - auto关键字不能用于推导空类型。
            - auto关键字不能用于推导初始化表达式为列表的类型。
            - auto关键字不能用于推导初始化表达式为函数的类型。
    优点：
        - 简化代码，减少显式声明变量类型的冗余，特别是对于复杂类型（如容器迭代器）时尤其有用。
        - 提高代码的可维护性和可读性，避免因为类型修改而导致的重复修改。
        - 可以提高代码的灵活性，使代码更具通用性和可扩展性。

    缺点：
        - 自动推导类型可能导致代码的不明确性，特别是在复杂的表达式中，可能不容易推断出变量类型。
        - 可能降低类型安全性，增加调试和理解代码的难度。
    
    示例代码：
```C++
    auto i = 10; // 推导为int类型
    auto d = 3.14; // 推导为double类型
    auto p = new int(5); // 推导为int*类型
    std::vector<int> vec = {1, 2, 3};
    for (auto it = vec.begin(); it != vec.end(); ++it) { // 推导为迭代器类型
        std::cout << *it << " ";
    }
```

### 2. `decltype`关键字
    说明：
        - `decltype`用于获取表达式的类型，常用于模板编程和类型推导。
        - 它可以返回一个表达式的类型，而不需要显式地指定类型。

    优点：
        - 提供了一种更加灵活和安全的方式来获取类型，避免了冗长的类型声明。
        - 可与`auto`结合使用，提供更强的类型推导能力，尤其是在模板编程中。

    缺点：
        - 使用`decltype`可能让代码变得不太直观，尤其是对于复杂的类型推导时。

    解决的问题：
        - 通过提供灵活的类型推导工具，`decltype`解决了在复杂表达式中推导类型时的不便，尤其在模板编程和泛型编程中具有重要作用。
    
    示例代码：
```C++
    int x = 10;
    decltype(x) y = 20;  // y的类型是int
    std::cout << "y = " << y << std::endl;
```

### 3. 智能指针（`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`）
    说明：
        - C++11引入了智能指针来管理动态内存，避免手动管理内存带来的内存泄漏和悬挂指针问题。
        - `std::unique_ptr`：独占式智能指针，确保指针指向的资源在同一时间内只能有一个所有者。
        - `std::shared_ptr`：共享式智能指针，允许多个指针共享同一资源，引用计数来管理资源的生命周期。
        - `std::weak_ptr`：弱引用智能指针，不会影响引用计数，通常与`shared_ptr`一起使用来避免循环引用。

    优点：
        - 自动管理内存，减少了手动`delete`的错误，避免内存泄漏和悬挂指针。
        - `shared_ptr`和`weak_ptr`帮助管理复杂的对象所有权关系，特别是避免循环引用问题。
        - 智能指针使用RAII（资源获取即初始化）机制，保证在离开作用域时自动释放资源。

    缺点：
        - 由于使用引用计数和其他内部管理机制，智能指针可能带来性能开销。
        - `shared_ptr`使用时可能会增加引用计数带来的性能损耗，特别是在多线程环境中。

    解决的问题：
        - 智能指针帮助管理动态内存和资源，减少了手动内存管理带来的风险，特别是内存泄漏、双重释放等问题。

    示例代码：
```C++
    #include <memory>
    
    void example() {
        // unique_ptr示例
        std::unique_ptr<int> p1 = std::make_unique<int>(10);
        
        // shared_ptr示例
        std::shared_ptr<int> p2 = std::make_shared<int>(20);
        std::shared_ptr<int> p3 = p2;  // p2和p3共享资源
        
        // weak_ptr示例
        std::weak_ptr<int> p4 = p2;  // 不增加引用计数
    }
```

### 4. lambda表达式
    说明：
        - lambda表达式允许定义匿名函数对象，通常用于函数参数或临时函数。
        - 它提供了一种在局部范围内定义内联函数的简便方式，避免了冗长的函数声明。

    优点：
        - 代码更加简洁，避免了定义一个单独的函数来执行简单的操作。
        - 支持闭包功能，可以捕获外部变量。
    
    缺点：
        - 对新手而言，lambda表达式的语法可能较难理解。
        - 若在复杂表达式中使用lambda，可能使代码难以调试和维护。

    解决的问题：
        - lambda表达式提供了一个简洁的方式来定义临时函数，尤其在STL算法中应用广泛，避免了定义多余的函数，提高了代码的简洁性和可读性。

    示例代码：
```C++
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
```

### 5. 右值引用（Rvalue References）与`&&`语法
    说明：
        - C++11引入了右值引用（Rvalue References），通过`&&`符号来声明。
        - 右值引用使得移动语义成为可能，它允许资源的“移动”而非复制。
        - 右值引用专门用来绑定到右值（临时对象或将要被销毁的对象）。通过右值引用，可以有效避免不必要的复制，提升性能。
        - 右值引用的一个常见用例是结合`std::move`实现移动构造和移动赋值操作。

    优点：
        - 通过右值引用，可以显著减少内存和资源的复制，尤其在处理大型数据结构（如容器、文件、数据库连接等）时提高性能。
        - 与`std::move`结合使用时，能够实现高效的资源转移而非复制，尤其在返回大型对象或从容器中提取元素时非常有用。
        - 允许开发者显式控制资源的转移和管理，避免不必要的开销。

    缺点：
        - 右值引用的语法对于初学者来说较为复杂，理解起来可能需要时间。
        - 不正确使用右值引用（如移动后访问原对象）会导致潜在的错误和未定义行为。
        - 需要小心避免滥用，尤其是在复杂的类和多线程环境下，可能会使代码更难以理解和维护。

    解决的问题：
        - 右值引用解决了传统C++中对象复制带来的性能瓶颈，尤其是在需要大规模复制数据时，右值引用允许资源直接“转移”，避免了多次复制和内存分配，提升了效率。
        - 在实现移动构造和移动赋值时，右值引用提供了一种非常有效的机制，特别是在STL容器或返回临时对象时，能够显著提高性能。

    示例代码：
```C++
    #include <iostream>
    #include <vector>

    class MyClass {
    public:
        int* data;

        MyClass(int size) {
            data = new int[size];
            std::cout << "Constructor: Allocating memory" << std::endl;
        }

        ~MyClass() {
            delete[] data;
            std::cout << "Destructor: Freeing memory" << std::endl;
        }

        // 移动构造函数
        MyClass(MyClass&& other) noexcept : data(other.data) {
            other.data = nullptr; // 防止析构时删除已被移动的资源
            std::cout << "Move Constructor" << std::endl;
        }

        // 移动赋值运算符
        MyClass& operator=(MyClass&& other) noexcept {
            if (this != &other) {
                delete[] data; // 删除原来的资源
                data = other.data;
                other.data = nullptr;
                std::cout << "Move Assignment" << std::endl;
            }
            return *this;
        }
    };

    int main() {
        MyClass obj1(10);        // 调用构造函数
        MyClass obj2 = std::move(obj1);  // 调用移动构造函数
        MyClass obj3(20); 
        obj3 = std::move(obj2);  // 调用移动赋值运算符
        return 0;
    }
```

    输出：
```bash
Constructor: Allocating memory
Move Constructor
Constructor: Allocating memory
Move Assignment
Destructor: Freeing memory
Destructor: Freeing memory
Destructor: Freeing memory
```



### 6. 移动语义（Move Semantics）与`std::move`
    说明：
        - C++11引入了移动语义和`std::move`，使得对象的资源可以从一个对象转移到另一个对象，而无需进行昂贵的复制操作。
        - `std::move`并不进行实际的“移动”操作，它只是将对象转换为右值引用，允许资源的转移。
        - 移动语义通常与`std::move`配合使用来优化性能，尤其是在涉及大型数据结构时，如容器或字符串。

    优点：
        - 大大提高了性能，尤其是在需要复制大量数据的场景（如容器的拷贝操作），通过移动资源而非复制，提高了程序的效率。
        - 减少了不必要的资源复制，使得代码更加高效，尤其是在处理临时对象时。

    缺点：
        - 移动语义的使用需要对代码逻辑进行重新设计，可能会增加代码的复杂度。
        - 需要特别小心资源的管理，特别是移动后原对象的状态，避免错误的使用。

    解决的问题：
        - 通过移动语义解决了昂贵的深度复制问题，提高了性能，特别是在涉及大规模数据结构的场景下（如STL容器的拷贝和返回值优化）。
    
    示例代码：
```C++
    #include <iostream>
    #include <vector>

    void example() {
        std::vector<int> v1 = {1, 2, 3};
        std::vector<int> v2 = std::move(v1);  // v1的资源被转移到v2
        std::cout << "v1 size: " << v1.size() << std::endl;  // 输出0，v1资源被转移
        std::cout << "v2 size: " << v2.size() << std::endl;  // 输出3
    }
```

### 7. nullptr关键字
    说明：
        - nullptr是C++11引入的一个新的空指针常量，替代了传统的NULL宏。
        - nullptr的类型是`std::nullptr_t`，而NULL的类型是`int`，因此nullptr可以防止因类型不匹配导致的潜在问题。
        - nullptr可以用于指针赋值，也可以作为函数参数，避免类型歧义。

    优点：
        - 避免了NULL可能与整型0混淆的问题，增强了类型安全性。
        - 更加明确的表示指针为空。

    缺点：
        - 需要编译器支持C++11标准，老版本的编译器不支持nullptr。

    解决的问题：
        - nullptr避免了NULL作为整数0的潜在类型错误，提高了代码的安全性和可读性。

    示例代码：
```C++
    int* ptr = nullptr; // 使用nullptr初始化指针
    if (ptr == nullptr) {
        std::cout << "Pointer is null" << std::endl;
    }
```

### 8. range-based for循环
    说明：
        - C++11引入了范围基于的for循环，可以方便地遍历容器中的元素。
        - 它通过直接对容器或数组进行迭代，避免了显式使用迭代器或索引。

    优点：
        - 代码更加简洁，避免了显式的迭代器操作。
        - 提高代码的可读性，尤其在遍历容器时，减少了错误的可能性。

    缺点：
        - 对于一些复杂的遍历操作（如需要修改容器元素的值或需要访问索引等），range-based for循环不如传统的for循环灵活。

    解决的问题：
        - 避免了迭代器或索引的使用，简化了容器遍历的操作，提升了代码的可读性和可维护性。

        示例代码：
```C++
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto x : vec) {
        std::cout << x << " ";
    }
```

### 9. 类型别名（using）
    说明：
        - C++11引入了`using`关键字来定义类型别名，替代了`typedef`。
        - `using`语法相比`typedef`更加直观和易于使用，尤其在定义模板别名时。

    优点：
        - 语法更加清晰，尤其对于模板类型的别名。
        - 相比`typedef`，`using`语法更现代且易于理解。

    缺点：
        - 需要编译器支持C++11标准，老版本编译器不支持。

    解决的问题：
        - 提高代码的可读性和简洁度，尤其是在定义复杂类型时，`using`能够提供更清晰的表达。
        示例代码：
```C++
    using IntVector = std::vector<int>;
    IntVector vec = {1, 2, 3};
```

### 10. `explicit`构造函数的增强
    说明：
        - C++11允许`explicit`关键字用于防止隐式类型转换的构造函数，避免误用类型转换。
        - 通过`explicit`可以确保构造函数不会被意外地用于类型转换，而只用于显式的构造。

    优点：
        - 提高了代码的安全性，避免了意外的类型转换导致的问题。
        - 增强了类型安全，确保只有显式地调用构造函数时才会进行类型转换。

    缺点：
        - 某些情况下可能需要显式地提供构造函数调用，增加了代码的冗余。

    解决的问题：
        - 防止了隐式类型转换带来的潜在错误，尤其是在构造函数的参数类型较为复杂时，可以避免自动调用构造函数带来的困惑。

    示例代码：
```C++
    class MyClass {
    public:
        explicit MyClass(int x) { /* ... */ }
    };

    void example() {
        MyClass obj1 = 10;  // 编译错误，因为构造函数是explicit的
        MyClass obj2(10);    // 正确，显式调用构造函数
    }
```


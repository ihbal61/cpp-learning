#include <iostream>
#include <mutex>
#include <thread>

class Singleton {
public:
    // 删除拷贝构造函数和赋值操作符
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // 获取单例实例的静态方法
    static Singleton& getInstance() {
        static Singleton instance; // C++11保证静态局部变量初始化线程安全
        return instance;
    }
    // 懒汉模式
    static Singleton* getInstance2()  {
        if (instance_lazy == nullptr) { // 第一次检查
            std::lock_guard<std::mutex> lock(mtx);
            if (instance_lazy == nullptr) { // 第二次检查
                instance_lazy = new Singleton();
            }
        }
        return instance_lazy;
    }
    // 饿汉模式
    static Singleton& getInstance3() {
        return instance_hunger;
    }

    // 示例成员函数
    void doSomething() {
        // 业务逻辑
        std::cout << "This is function.." << std::endl;
    }

private:
    // 私有构造函数防止外部实例化
    Singleton() = default;
    
    // 如果需要处理资源释放，可添加析构函数
    ~Singleton() = default;

    // 懒汉模式
    static Singleton* instance_lazy;
    static std::mutex mtx;

    // 饿汉模式
    static Singleton instance_hunger;


};

void threadFunction() {
    Singleton::getInstance().doSomething();
}

int main() {
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    
    t1.join();
    t2.join();
    
    return 0;
}

#include <iostream>
#include <atomic>  // 包含原子操作头文件

template <typename T>
class my_shared_ptr {
public:
    explicit my_shared_ptr(T* ptr = nullptr) : ptr_(ptr) {
        ref_count_ = new std::atomic<size_t>(ptr ? 1 : 0);
    }

    // 拷贝构造函数
    my_shared_ptr(const my_shared_ptr& other) noexcept 
        : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        if (ptr_) {
            ref_count_->fetch_add(1, std::memory_order_relaxed);
        }
    }

    // 移动构造函数
    my_shared_ptr(my_shared_ptr&& other) noexcept 
        : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        other.ptr_ = nullptr;
        other.ref_count_ = nullptr;
    }

    // 拷贝赋值运算符
    my_shared_ptr& operator=(const my_shared_ptr& other) noexcept {
        if (this != &other) {
            release();  // 释放当前资源
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            if (ptr_) {
                ref_count_->fetch_add(1, std::memory_order_relaxed);
            }
        }
        return *this;
    }

    // 移动赋值运算符
    my_shared_ptr& operator=(my_shared_ptr&& other) noexcept {
        if (this != &other) {
            release();
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            other.ptr_ = nullptr;
            other.ref_count_ = nullptr;
        }
        return *this;
    }

    ~my_shared_ptr() {
        release();
    }

    T* get() const noexcept {
        return ptr_;
    }

    T& operator*() const noexcept {
        return *ptr_;
    }

    T* operator->() const noexcept {
        return ptr_;
    }

    size_t use_count() const noexcept {
        return ref_count_->load(std::memory_order_relaxed);
    }

    explicit operator bool() const noexcept {
        return ptr_ != nullptr;
    }

private:

    void release() {
        if (ptr_) {
            // 原子递减并检查旧值是否为1（若为1则当前线程负责清理）
            if (ref_count_->fetch_sub(1, std::memory_order_acq_rel) == 1) {
                delete ptr_;
                delete ref_count_;
            }
            ptr_ = nullptr;
            ref_count_ = nullptr;
        }
    }
    T* ptr_;
    std::atomic<size_t>* ref_count_;
};

template <typename T, typename... Args>
my_shared_ptr<T> make_shared(Args&&... args) {
    return my_shared_ptr<T>(new T(std::forward<Args>(args)...));
}

struct Foo {
    int val;
    Foo(int v) : val(v) {}
};

int main() {
    my_shared_ptr<Foo> p1 = make_shared<Foo>(42);
    my_shared_ptr<Foo> p2 = p1;  // 拷贝，引用计数+1
    my_shared_ptr<Foo> p3 = std::move(p1);  // 移动，p1失效

    std::cout << p2.use_count() << std::endl;  // 输出2
    std::cout << p3->val << std::endl;         // 输出42
    return 0;
}
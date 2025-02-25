// need C++ version >= 17
#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

// Abstract Product Interface
class Product {
public:
    virtual ~Product() = default; // Virtual destructor for proper polymorphism
    virtual void use() = 0;
};

// Concrete Product A
class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using Concrete Product A." << std::endl;
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using Concrete Product B." << std::endl;
    }
};

// Factory Class
class Factory {
public:
    enum class ProductType {
        PRODUCT_A,
        PRODUCT_B,
        UNKNOWN
    };

    static std::unique_ptr<Product> createProduct(ProductType type) {
        switch (type) {
            case ProductType::PRODUCT_A:
                return std::make_unique<ConcreteProductA>();
            case ProductType::PRODUCT_B:
                return std::make_unique<ConcreteProductB>();
            case ProductType::UNKNOWN:
            default:
                std::cout << "Unknown product type requested." << std::endl;
                return nullptr; // Or throw an exception
        }
    }
};

int main() {
    // Using the factory to create products
    std::unique_ptr<Product> productA = Factory::createProduct(Factory::ProductType::PRODUCT_A);
    if (productA) {
        productA->use(); // Output: Using Concrete Product A.
    }

    std::unique_ptr<Product> productB = Factory::createProduct(Factory::ProductType::PRODUCT_B);
    if (productB) {
        productB->use(); // Output: Using Concrete Product B.
    }

    std::unique_ptr<Product> unknownProduct = Factory::createProduct(Factory::ProductType::UNKNOWN);
    // unknownProduct will be nullptr, and "Unknown product type requested." will be printed

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>


// Author - Given Lepita
/*
 * In an online food ordering system, there are different types of restaurants, and each restaurant offers multiple types of cuisines.
 * Additionally, there are different payment options available for customers.
 * To implement this system efficiently, we can use the Abstract Factory Design Pattern.
 * 
 * 
 * The Abstract Factory Pattern is a creational design pattern that provides an interface for creating families of related or dependent objects without specifying their concrete classes.
 * It allows a client to create objects without knowing their specific implementations, promoting loose coupling between the client code and the objects it uses.
        
                        ************* Key Components of the Abstract Factory Pattern *************

 * -> Abstract Factory: This is the main interface that declares a set of methods for creating abstract products. 
 * It provides a way for the client to create families of related products without knowing their concrete classes.
 * -> Concrete Factories: These are implementations of the abstract factory interface. Each concrete factory is responsible for creating a family of related products.
 * -> Abstract Product: This is the interface for a type of product. It declares the operations that all concrete products must implement.
 * -> Concrete Products: These are the implementations of the abstract product interfaces. Each concrete product corresponds to a specific product variant produced by a concrete factory.

                        ************* Uses of the Abstract Factory Pattern *************

 * -> Encapsulation of Product Families: The pattern encapsulates the creation of related product families, 
 * ensuring that the products created by a factory are compatible and work together.
 * -> Flexibility and Extensibility: By using the abstract factory, you can easily add new variants of products
 * and their corresponding factories without modifying existing client code. This allows for easy expansion and customization of the system.
 * -> Configurable Systems: The pattern facilitates the configuration of the system by selecting the appropriate factory at runtime based on some condition
 * or configuration. This makes it easy to switch between different families of products without changing the client code.
 * -> Dependency Injection: The abstract factory pattern is commonly used in dependency injection frameworks to create objects and manage their dependencies.
*/

// Abstract Product: Cuisine
class Cuisine {
public:
    virtual void prepare() = 0;
};

// Concrete Products: IndianCuisine and ItalianCuisine
class IndianCuisine : public Cuisine {
public:
    void prepare() override {
        std::cout << "Preparing Indian Cuisine..." << std::endl;
    }
};

class ItalianCuisine : public Cuisine {
public:
    void prepare() override {
        std::cout << "Preparing Italian Cuisine..." << std::endl;
    }
};

// Abstract Product: PaymentMethod
class PaymentMethod {
public:
    virtual void pay(double amount) = 0;
};

// Concrete Products: CreditCardPayment and PayPalPayment
class CreditCardPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paying $" << amount << " using Credit Card..." << std::endl;
    }
};

class PayPalPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paying $" << amount << " using PayPal..." << std::endl;
    }
};

// Abstract Factory
class FoodOrderFactory {
public:
    virtual Cuisine* getCuisine(const std::string& type) = 0;
    virtual PaymentMethod* getPaymentMethod(const std::string& type) = 0;
};

// Concrete Factories: IndianFoodOrderFactory and ItalianFoodOrderFactory
class IndianFoodOrderFactory : public FoodOrderFactory {
public:
    Cuisine* getCuisine(const std::string& type) override {
        if (type == "vegetarian") {
            return new IndianCuisine();
        }
        return nullptr;
    }

    PaymentMethod* getPaymentMethod(const std::string& type) override {
        if (type == "credit") {
            return new CreditCardPayment();
        }
        return nullptr;
    }
};

class ItalianFoodOrderFactory : public FoodOrderFactory {
public:
    Cuisine* getCuisine(const std::string& type) override {
        if (type == "pasta") {
            return new ItalianCuisine();
        }
        return nullptr;
    }

    PaymentMethod* getPaymentMethod(const std::string& type) override {
        if (type == "paypal") {
            return new PayPalPayment();
        }
        return nullptr;
    }
};

// Utility function to perform case-insensitive string comparison
bool compareStrings(const std::string& str1, const std::string& str2) {
    return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
                      [](char a, char b) { return std::tolower(a) == std::tolower(b); });
}

int main() {
    std::cout << "Choose the type of cuisine (Indian/Italian): ";
    std::string cuisineType;
    std::cin >> cuisineType;

    std::cout << "Choose the payment method (Credit/PayPal): ";
    std::string paymentType;
    std::cin >> paymentType;

    FoodOrderFactory* factory = nullptr;

    if (compareStrings(cuisineType, "Indian")) {
        factory = new IndianFoodOrderFactory();
    } else if (compareStrings(cuisineType, "Italian")) {
        factory = new ItalianFoodOrderFactory();
    } else {
        std::cout << "Invalid cuisine type selected." << std::endl;
        return 0;
    }

    Cuisine* cuisine = factory->getCuisine(cuisineType);
    PaymentMethod* paymentMethod = factory->getPaymentMethod(paymentType);

    if (cuisine != nullptr && paymentMethod != nullptr) {
        cuisine->prepare();
        paymentMethod->pay(20.0); // Assuming the order amount is $20.0
    } else {
        std::cout << "Invalid payment method selected." << std::endl;
    }

    delete cuisine;
    delete paymentMethod;
    delete factory;

    return 0;
}

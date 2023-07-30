#include <iostream>
#include <iomanip>
#include <string>

// Author - Given Lepita
/*
 * working on a coffee shop ordering system, and you want to offer customers the ability to customize their coffee orders with various toppings and extras.
 * Instead of creating multiple classes for each combination of coffee with different toppings,
 * you decide to use the Decorator Pattern to dynamically add extras to the coffee orders.
*/

// Component Interface
class Coffee {
public:
    virtual double getCost() = 0;
    virtual std::string getDescription() = 0;
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    double getCost() override {
        return 2.0;
    }

    std::string getDescription() override {
        return "Simple Coffee";
    }
};

// Decorator Base Class
class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;

public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}

    double getCost() override {
        return decoratedCoffee->getCost();
    }

    std::string getDescription() override {
        return decoratedCoffee->getDescription();
    }
};

// Concrete Decorator - Milk
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 1.0;
    }

    std::string getDescription() override {
        return CoffeeDecorator::getDescription() + ", Milk";
    }
};

// Concrete Decorator - Caramel
class CaramelDecorator : public CoffeeDecorator {
public:
    CaramelDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double getCost() override {
        return CoffeeDecorator::getCost() + 1.5;
    }

    std::string getDescription() override {
        return CoffeeDecorator::getDescription() + ", Caramel";
    }
};

// Client Code
int main() {
    // Order a simple coffee
    Coffee* coffee = new SimpleCoffee();
    std::cout << "Order: " << coffee->getDescription() << std::endl;
    std::cout << "Cost: $" << std::fixed << std::setprecision(2) << coffee->getCost() << std::endl;

    // Order a coffee with milk
    Coffee* coffeeWithMilk = new MilkDecorator(new SimpleCoffee());
    std::cout << "\nOrder: " << coffeeWithMilk->getDescription() << std::endl;
    std::cout << "Cost: $" << std::fixed << std::setprecision(2) << coffeeWithMilk->getCost() << std::endl;

    // Order a coffee with milk and caramel
    Coffee* coffeeWithMilkAndCaramel = new CaramelDecorator(new MilkDecorator(new SimpleCoffee()));
    std::cout << "\nOrder: " << coffeeWithMilkAndCaramel->getDescription() << std::endl;
    std::cout << "Cost: $" << std::fixed << std::setprecision(2) << coffeeWithMilkAndCaramel->getCost() << std::endl;

    // Clean up memory
    delete coffee;
    delete coffeeWithMilk;
    delete coffeeWithMilkAndCaramel;

    return 0;
}

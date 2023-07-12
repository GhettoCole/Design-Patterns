#include <iostream>

// Author - Given Lepita
// Refer to the TemplateMethod.java file for a thorough explanation of the Template Method Design Pattern

// Abstract class defining the template method and the basic cooking steps
class CookingRecipe {
public:
    // Template method that defines the cooking process
    void cookRecipe() {
        prepareIngredients();
        cook();
        serve();
    }

    // Abstract methods to be implemented by subclasses
    virtual void prepareIngredients() = 0;
    virtual void cook() = 0;

    // Default implementation for serving
    void serve() {
        std::cout << "Serve the dish." << std::endl;
    }
};

// Concrete subclass implementing the cooking recipe for Pizza
class PizzaRecipe : public CookingRecipe {
public:
    void prepareIngredients() override {
        std::cout << "Gather pizza dough, sauce, cheese, and toppings." << std::endl;
    }

    void cook() override {
        std::cout << "Roll out the dough, spread the sauce, add cheese and toppings, and bake in the oven." << std::endl;
    }
};

// Concrete subclass implementing the cooking recipe for Pasta
class PastaRecipe : public CookingRecipe {
public:
    void prepareIngredients() override {
        std::cout << "Boil water, gather pasta, and prepare sauce." << std::endl;
    }

    void cook() override {
        std::cout << "Cook the pasta in boiling water, drain it, mix it with the sauce, and simmer for a while." << std::endl;
    }

    void serve() override {
        std::cout << "Serve the pasta with grated cheese and parsley." << std::endl;
    }
};

// Client code
int main() {
    CookingRecipe* pizzaRecipe = new PizzaRecipe();
    pizzaRecipe->cookRecipe();
    delete pizzaRecipe;

    std::cout << std::endl;

    CookingRecipe* pastaRecipe = new PastaRecipe();
    pastaRecipe->cookRecipe();
    delete pastaRecipe;

    return 0;
}

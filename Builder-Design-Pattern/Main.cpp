#include <iostream>
#include <string>

using namespace std;

// Pizza.h (Product)
class Pizza {
private:
    string crust;
    string sauce;
    string cheese;
    string toppings;

public:
    void setCrust(const string& crust) {
        this->crust = crust;
    }

    void setSauce(const string& sauce) {
        this->sauce = sauce;
    }

    void setCheese(const string& cheese) {
        this->cheese = cheese;
    }

    void setToppings(const string& toppings) {
        this->toppings = toppings;
    }

    friend ostream& operator<<(ostream& os, const Pizza& pizza) {
        os << "Crust: " << pizza.crust << ", Sauce: " << pizza.sauce << ", Cheese: " << pizza.cheese << ", Toppings: " << pizza.toppings;
        return os;
    }
};

// PizzaBuilder.h (Abstract Builder)
class PizzaBuilder {
protected:
    Pizza pizza;

public:
    Pizza getPizza() {
        return pizza;
    }

    void createNewPizza() {
        pizza = Pizza();
    }

    virtual void buildCrust() = 0;
    virtual void buildSauce() = 0;
    virtual void buildCheese() = 0;
    virtual void buildToppings() = 0;
};

// VeggiePizzaBuilder.h (Concrete Builder)
class VeggiePizzaBuilder : public PizzaBuilder {
public:
    void buildCrust() override {
        pizza.setCrust("Thin Crust");
    }

    void buildSauce() override {
        pizza.setSauce("Tomato Sauce");
    }

    void buildCheese() override {
        pizza.setCheese("Mozzarella Cheese");
    }

    void buildToppings() override {
        pizza.setToppings("Mushrooms, Bell Peppers, Olives, Onions");
    }
};

// MeatLoversPizzaBuilder.h (Concrete Builder)
class MeatLoversPizzaBuilder : public PizzaBuilder {
public:
    void buildCrust() override {
        pizza.setCrust("Thick Crust");
    }

    void buildSauce() override {
        pizza.setSauce("Barbecue Sauce");
    }

    void buildCheese() override {
        pizza.setCheese("Cheddar Cheese");
    }

    void buildToppings() override {
        pizza.setToppings("Pepperoni, Sausage, Bacon, Ham");
    }
};

// PizzaDirector.h
class PizzaDirector {
private:
    PizzaBuilder* pizzaBuilder;

public:
    PizzaDirector(PizzaBuilder* builder) : pizzaBuilder(builder) {}

    void setPizzaBuilder(PizzaBuilder* builder) {
        pizzaBuilder = builder;
    }

    Pizza getPizza() {
        return pizzaBuilder->getPizza();
    }

    void constructPizza() {
        pizzaBuilder->createNewPizza();
        pizzaBuilder->buildCrust();
        pizzaBuilder->buildSauce();
        pizzaBuilder->buildCheese();
        pizzaBuilder->buildToppings();
    }
};

int main() {
    // Create a pizza builder for Veggie Pizza
    PizzaBuilder* veggiePizzaBuilder = new VeggiePizzaBuilder();
    PizzaDirector director(veggiePizzaBuilder);

    // Construct a Veggie Pizza
    director.constructPizza();
    Pizza veggiePizza = director.getPizza();

    // Create a pizza builder for Meat Lovers Pizza
    PizzaBuilder* meatLoversPizzaBuilder = new MeatLoversPizzaBuilder();
    director.setPizzaBuilder(meatLoversPizzaBuilder);

    // Construct a Meat Lovers Pizza
    director.constructPizza();
    Pizza meatLoversPizza = director.getPizza();

    // Display the pizzas
    cout << "Veggie Pizza:" << endl;
    cout << veggiePizza << endl;

    cout << "\nMeat Lovers Pizza:" << endl;
    cout << meatLoversPizza << endl;

    // Clean up memory
    delete veggiePizzaBuilder;
    delete meatLoversPizzaBuilder;

    return 0;
}

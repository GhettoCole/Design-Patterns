// Author - Given Lepita
/*
 * Imagine you are tasked with developing a pizza ordering system for a restaurant.
 * The restaurant offers a wide variety of pizzas, and customers can customize their orders with different toppings, crust types, and sizes. 
 * To handle the complexity of pizza customization, you decide to use the Builder Design Pattern.

 * The Builder Design Pattern is a creational design pattern that is used to construct complex objects step by step.
 * It separates the construction of a complex object from its representation, allowing the same construction process to create different representations.
 * The main idea behind the Builder pattern is to abstract the construction of objects, so the client code can be decoupled from the actual object creation.
 * It is particularly useful when dealing with objects that have multiple optional parameters or configurations, making their direct construction cumbersome and less maintainable.

                                **************** Key components of the Builder Design Pattern ****************
 * Director -> Responsible for coordinating the object's construction using the builder interface.
 * The director is unaware of the concrete builder implementation and works with any builder that follows the builder interface.
 * Builder -> An abstract interface or class that defines the step-by-step construction process for creating the complex object.
 * It contains methods to build individual parts of the object and a method to retrieve the final constructed object.
 * Concrete Builders -> Implement the builder interface to provide specific implementations of constructing the complex object.
 * Each concrete builder provides different ways to build the final object.
 * Product -> The complex object being constructed. The product does not have to be related to the builder classes, and the builder merely assembles the product. 
*/


public class Main {
    public static void main(String[] args) {
        // Create a pizza builder for Veggie Pizza
        PizzaBuilder veggiePizzaBuilder = new VeggiePizzaBuilder();
        PizzaDirector director = new PizzaDirector(veggiePizzaBuilder);

        // Construct a Veggie Pizza
        director.constructPizza();
        Pizza veggiePizza = director.getPizza();

        // Create a pizza builder for Meat Lovers Pizza
        PizzaBuilder meatLoversPizzaBuilder = new MeatLoversPizzaBuilder();
        director.setPizzaBuilder(meatLoversPizzaBuilder);

        // Construct a Meat Lovers Pizza
        director.constructPizza();
        Pizza meatLoversPizza = director.getPizza();

        // Display the pizzas
        System.out.println("Veggie Pizza:");
        System.out.println(veggiePizza);

        System.out.println("\nMeat Lovers Pizza:");
        System.out.println(meatLoversPizza);
    }
}

// Pizza.java (Product)
class Pizza {
    private String crust;
    private String sauce;
    private String cheese;
    private String toppings;

    public void setCrust(String crust) {
        this.crust = crust;
    }

    public void setSauce(String sauce) {
        this.sauce = sauce;
    }

    public void setCheese(String cheese) {
        this.cheese = cheese;
    }

    public void setToppings(String toppings) {
        this.toppings = toppings;
    }

    @Override
    public String toString() {
        return "Crust: " + crust + ", Sauce: " + sauce + ", Cheese: " + cheese + ", Toppings: " + toppings;
    }
}

// PizzaBuilder.java (Abstract Builder)
abstract class PizzaBuilder {
    protected Pizza pizza;

    public Pizza getPizza() {
        return pizza;
    }

    public void createNewPizza() {
        pizza = new Pizza();
    }

    public abstract void buildCrust();

    public abstract void buildSauce();

    public abstract void buildCheese();

    public abstract void buildToppings();
}

// VeggiePizzaBuilder.java (Concrete Builder)
class VeggiePizzaBuilder extends PizzaBuilder {
    public void buildCrust() {
        pizza.setCrust("Thin Crust");
    }

    public void buildSauce() {
        pizza.setSauce("Tomato Sauce");
    }

    public void buildCheese() {
        pizza.setCheese("Mozzarella Cheese");
    }

    public void buildToppings() {
        pizza.setToppings("Mushrooms, Bell Peppers, Olives, Onions");
    }
}

// MeatLoversPizzaBuilder.java (Concrete Builder)
class MeatLoversPizzaBuilder extends PizzaBuilder {
    public void buildCrust() {
        pizza.setCrust("Thick Crust");
    }

    public void buildSauce() {
        pizza.setSauce("Barbecue Sauce");
    }

    public void buildCheese() {
        pizza.setCheese("Cheddar Cheese");
    }

    public void buildToppings() {
        pizza.setToppings("Pepperoni, Sausage, Bacon, Ham");
    }
}

// PizzaDirector.java
class PizzaDirector {
    private PizzaBuilder pizzaBuilder;

    public PizzaDirector(PizzaBuilder pizzaBuilder) {
        this.pizzaBuilder = pizzaBuilder;
    }

    public void setPizzaBuilder(PizzaBuilder pizzaBuilder) {
        this.pizzaBuilder = pizzaBuilder;
    }

    public Pizza getPizza() {
        return pizzaBuilder.getPizza();
    }

    public void constructPizza() {
        pizzaBuilder.createNewPizza();
        pizzaBuilder.buildCrust();
        pizzaBuilder.buildSauce();
        pizzaBuilder.buildCheese();
        pizzaBuilder.buildToppings();
    }
}

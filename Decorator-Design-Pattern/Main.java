import java.text.DecimalFormat;

// Author - Given Lepita
/*
 * working on a coffee shop ordering system, and you want to offer customers the ability to customize their coffee orders with various toppings and extras.
 * Instead of creating multiple classes for each combination of coffee with different toppings,
 * you decide to use the Decorator Pattern to dynamically add extras to the coffee orders.
*/


// Component Interface
interface Coffee {
    double getCost();
    String getDescription();
}

// Concrete Component
class SimpleCoffee implements Coffee {
    @Override
    public double getCost() {
        return 2.0;
    }

    @Override
    public String getDescription() {
        return "Simple Coffee";
    }
}

// Decorator Base Class
abstract class CoffeeDecorator implements Coffee {
    protected Coffee decoratedCoffee;

    public CoffeeDecorator(Coffee decoratedCoffee) {
        this.decoratedCoffee = decoratedCoffee;
    }

    @Override
    public double getCost() {
        return decoratedCoffee.getCost();
    }

    @Override
    public String getDescription() {
        return decoratedCoffee.getDescription();
    }
}

// Concrete Decorator - Milk
class MilkDecorator extends CoffeeDecorator {
    public MilkDecorator(Coffee decoratedCoffee) {
        super(decoratedCoffee);
    }

    @Override
    public double getCost() {
        return super.getCost() + 1.0;
    }

    @Override
    public String getDescription() {
        return super.getDescription() + ", Milk";
    }
}

// Concrete Decorator - Caramel
class CaramelDecorator extends CoffeeDecorator {
    public CaramelDecorator(Coffee decoratedCoffee) {
        super(decoratedCoffee);
    }

    @Override
    public double getCost() {
        return super.getCost() + 1.5;
    }

    @Override
    public String getDescription() {
        return super.getDescription() + ", Caramel";
    }
}

// Client Code
public class Main {
    public static void main(String[] args) {
        // Order a simple coffee
        Coffee coffee = new SimpleCoffee();
        System.out.println("Order: " + coffee.getDescription());
        System.out.println("Cost: $" + new DecimalFormat("0.00").format(coffee.getCost()));

        // Order a coffee with milk
        Coffee coffeeWithMilk = new MilkDecorator(new SimpleCoffee());
        System.out.println("\nOrder: " + coffeeWithMilk.getDescription());
        System.out.println("Cost: $" + new DecimalFormat("0.00").format(coffeeWithMilk.getCost()));

        // Order a coffee with milk and caramel
        Coffee coffeeWithMilkAndCaramel = new CaramelDecorator(new MilkDecorator(new SimpleCoffee()));
        System.out.println("\nOrder: " + coffeeWithMilkAndCaramel.getDescription());
        System.out.println("Cost: $" + new DecimalFormat("0.00").format(coffeeWithMilkAndCaramel.getCost()));
    }
}

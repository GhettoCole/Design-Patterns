import java.util.Scanner;

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
interface Cuisine {
    void prepare();
}

// Concrete Products: IndianCuisine and ItalianCuisine
class IndianCuisine implements Cuisine {
    @Override
    public void prepare() {
        System.out.println("Preparing Indian Cuisine...");
    }
}

class ItalianCuisine implements Cuisine {
    @Override
    public void prepare() {
        System.out.println("Preparing Italian Cuisine...");
    }
}

// Abstract Product: PaymentMethod
interface PaymentMethod {
    void pay(double amount);
}

// Concrete Products: CreditCardPayment and PayPalPayment
class CreditCardPayment implements PaymentMethod {
    @Override
    public void pay(double amount) {
        System.out.println("Paying $" + amount + " using Credit Card...");
    }
}

class PayPalPayment implements PaymentMethod {
    @Override
    public void pay(double amount) {
        System.out.println("Paying $" + amount + " using PayPal...");
    }
}

// Abstract Factory
interface FoodOrderFactory {
    Cuisine getCuisine(String type);
    PaymentMethod getPaymentMethod(String type);
}

// Concrete Factories: IndianFoodOrderFactory and ItalianFoodOrderFactory
class IndianFoodOrderFactory implements FoodOrderFactory {
    @Override
    public Cuisine getCuisine(String type) {
        if (type.equalsIgnoreCase("vegetarian")) {
            return new IndianCuisine();
        }
        return null;
    }

    @Override
    public PaymentMethod getPaymentMethod(String type) {
        if (type.equalsIgnoreCase("credit")) {
            return new CreditCardPayment();
        }
        return null;
    }
}

class ItalianFoodOrderFactory implements FoodOrderFactory {
    @Override
    public Cuisine getCuisine(String type) {
        if (type.equalsIgnoreCase("pasta")) {
            return new ItalianCuisine();
        }
        return null;
    }

    @Override
    public PaymentMethod getPaymentMethod(String type) {
        if (type.equalsIgnoreCase("paypal")) {
            return new PayPalPayment();
        }
        return null;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose the type of cuisine (Indian/Italian):");
        String cuisineType = scanner.nextLine().trim();

        System.out.println("Choose the payment method (Credit/PayPal):");
        String paymentType = scanner.nextLine().trim();

        FoodOrderFactory factory;

        if (cuisineType.equalsIgnoreCase("Indian")) {
            factory = new IndianFoodOrderFactory();
        } else if (cuisineType.equalsIgnoreCase("Italian")) {
            factory = new ItalianFoodOrderFactory();
        } else {
            System.out.println("Invalid cuisine type selected.");
            return;
        }

        Cuisine cuisine = factory.getCuisine(cuisineType);
        PaymentMethod paymentMethod = factory.getPaymentMethod(paymentType);

        if (cuisine != null && paymentMethod != null) {
            cuisine.prepare();
            paymentMethod.pay(20.0); // Assuming the order amount is $20.0
        } else {
            System.out.println("Invalid payment method selected.");
        }
    }
}

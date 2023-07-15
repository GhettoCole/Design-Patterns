// Author - Given Lepita
/*
                                ************ Online Order Status Tracking ************
* In an online shopping application, let's consider a scenario where users can place orders and track their order status.
* The order status can change over time, depending on various factors such as order processing, shipping, and delivery.
* To manage the changing states of an order and perform different actions based on its current state, we can utilize the State Design Pattern.
*/ 

public class Main {
    public static void main(String[] args) {
        Order order = new Order();
        order.process();  // Process the order

        order.ship();     // Ship the order
        order.process();  // Attempt to process the shipped order

        order.cancel();   // Cancel the order
        order.ship();     // Attempt to ship the cancelled order
    }
}

// Interface representing the order state
interface OrderState {
    void processOrder(Order order);
    void cancelOrder(Order order);
    void shipOrder(Order order);
}

// Concrete implementation of the "Processing" state
class ProcessingState implements OrderState {
    public void processOrder(Order order) {
        System.out.println("The order is already being processed.");
    }

    public void cancelOrder(Order order) {
        System.out.println("Cancelling the order.");
        order.setState(new CancelledState());
    }

    public void shipOrder(Order order) {
        System.out.println("Shipping the order.");
        order.setState(new ShippedState());
    }
}

// Concrete implementation of the "Shipped" state
class ShippedState implements OrderState {
    public void processOrder(Order order) {
        System.out.println("The order is already shipped and cannot be processed further.");
    }

    public void cancelOrder(Order order) {
        System.out.println("Cancelling the shipped order is not possible.");
    }

    public void shipOrder(Order order) {
        System.out.println("The order is already shipped.");
    }
}

// Concrete implementation of the "Cancelled" state
class CancelledState implements OrderState {
    public void processOrder(Order order) {
        System.out.println("Processing a cancelled order is not possible.");
    }

    public void cancelOrder(Order order) {
        System.out.println("The order is already cancelled.");
    }

    public void shipOrder(Order order) {
        System.out.println("Shipping a cancelled order is not possible.");
    }
}

// Context class representing an order
class Order {
    private OrderState state;

    public Order() {
        // Set the initial state as Processing
        state = new ProcessingState();
    }

    public void setState(OrderState state) {
        this.state = state;
    }

    public void process() {
        state.processOrder(this);
    }

    public void cancel() {
        state.cancelOrder(this);
    }

    public void ship() {
        state.shipOrder(this);
    }
}

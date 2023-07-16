// Author - Given Lepita

/* 
*****************************************  Online Order Processing System *****************************************
* Imagine you are working on an online order processing system for a large e-commerce platform.
* The system receives incoming orders from customers, and each order needs to go through a series of validation
* and processing steps before it is successfully processed and fulfilled.
* The processing steps include checking the payment method, verifying stock availability, applying discounts, calculating shipping costs,
* and finally confirming the order. Each step is a separate responsibility, and the order needs to be passed through these responsibilities in a specific sequence.

* To handle this scenario, we can use the Chain of Responsibility design pattern.
* The Chain of Responsibility pattern allows us to build a chain of handler objects, where each handler is responsible for a specific processing step.
* If a handler can process the request, it does so; otherwise, it passes the request along the chain to the next handler.
* This way, the request is processed through the chain until a handler successfully handles it or until the end of the chain is reached.
*/

// OrderHandler interface
interface OrderHandler {
    void setNextHandler(OrderHandler nextHandler);
    void processOrder(Order order);
}

// PaymentHandler
class PaymentHandler implements OrderHandler {
    private OrderHandler nextHandler;

    @Override
    public void setNextHandler(OrderHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void processOrder(Order order) {
        // Check payment method and process payment
        // If payment successful, move to the next handler
        if (order.isPaymentProcessed()) {
            System.out.println("Payment processed successfully.");
            if (nextHandler != null) {
                nextHandler.processOrder(order);
            }
        } else {
            System.out.println("Payment failed. Order processing halted.");
        }
    }
}

// StockHandler
class StockHandler implements OrderHandler {
    private OrderHandler nextHandler;

    @Override
    public void setNextHandler(OrderHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void processOrder(Order order) {
        // Check stock availability
        // If stock available, move to the next handler
        if (order.isStockAvailable()) {
            System.out.println("Stock is available.");
            if (nextHandler != null) {
                nextHandler.processOrder(order);
            }
        } else {
            System.out.println("Stock not available. Order processing halted.");
        }
    }
}

// DiscountHandler
class DiscountHandler implements OrderHandler {
    private OrderHandler nextHandler;

    @Override
    public void setNextHandler(OrderHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void processOrder(Order order) {
        // Apply discounts to the order
        System.out.println("Discounts applied.");
        if (nextHandler != null) {
            nextHandler.processOrder(order);
        }
    }
}

// ShippingHandler
class ShippingHandler implements OrderHandler {
    private OrderHandler nextHandler;

    @Override
    public void setNextHandler(OrderHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void processOrder(Order order) {
        // Calculate shipping costs
        System.out.println("Shipping costs calculated.");
        if (nextHandler != null) {
            nextHandler.processOrder(order);
        }
    }
}

// ConfirmationHandler
class ConfirmationHandler implements OrderHandler {
    private OrderHandler nextHandler;

    @Override
    public void setNextHandler(OrderHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void processOrder(Order order) {
        // Confirm the order
        order.confirmOrder();
        System.out.println("Order confirmed successfully.");
    }
}

// Order class
class Order {
    private boolean paymentProcessed;
    private boolean stockAvailable;

    public Order(boolean paymentProcessed, boolean stockAvailable) {
        this.paymentProcessed = paymentProcessed;
        this.stockAvailable = stockAvailable;
    }

    public boolean isPaymentProcessed() {
        return paymentProcessed;
    }

    public boolean isStockAvailable() {
        return stockAvailable;
    }

    public void confirmOrder() {
        // Logic to confirm the order.
        // Later to be done should need be.
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        // Sample order
        Order order = new Order(true, true);

        // Build the chain of responsibility
        OrderHandler chain = new PaymentHandler();
        chain.setNextHandler(new StockHandler());
        chain.setNextHandler(new DiscountHandler());
        chain.setNextHandler(new ShippingHandler());
        chain.setNextHandler(new ConfirmationHandler());

        // Process the order with use of the chain of responsibility
        chain.processOrder(order);
    }
}

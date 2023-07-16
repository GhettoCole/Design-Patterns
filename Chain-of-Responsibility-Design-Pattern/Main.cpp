#include <iostream>
using namespace std;

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


// Forward declaration for the Order class
class Order;

// OrderHandler interface
class OrderHandler {
public:
    virtual void setNextHandler(OrderHandler* nextHandler) = 0;
    virtual void processOrder(Order order) = 0;
};

// Order class
class Order {
private:
    bool paymentProcessed;
    bool stockAvailable;

public:
    Order(bool paymentProcessed, bool stockAvailable)
        : paymentProcessed(paymentProcessed), stockAvailable(stockAvailable) {}

    bool isPaymentProcessed() {
        return paymentProcessed;
    }

    bool isStockAvailable() {
        return stockAvailable;
    }

    void confirmOrder() {
        // Logic to confirm the order.
        // Later to be done should a need arise.
    }
};

// PaymentHandler
class PaymentHandler : public OrderHandler {
private:
    OrderHandler* nextHandler;

public:
    void setNextHandler(OrderHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    void processOrder(Order order) override {
        // Check payment method and process payment.
        // If payment successful, move to the next handler
        if (order.isPaymentProcessed()) {
            cout << "Payment processed successfully." << endl;
            if (nextHandler != nullptr) {
                nextHandler->processOrder(order);
            }
        } else {
            cout << "Payment failed. Order processing halted." << endl;
        }
    }
};

// StockHandler
class StockHandler : public OrderHandler {
private:
    OrderHandler* nextHandler;

public:
    void setNextHandler(OrderHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    void processOrder(Order order) override {
        // Check stock availability
        // If stock available, move to the next handler
        if (order.isStockAvailable()) {
            cout << "Stock is available." << endl;
            if (nextHandler != nullptr) {
                nextHandler->processOrder(order);
            }
        } else {
            cout << "Stock not available. Order processing halted." << endl;
        }
    }
};

// DiscountHandler
class DiscountHandler : public OrderHandler {
private:
    OrderHandler* nextHandler;

public:
    void setNextHandler(OrderHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    void processOrder(Order order) override {
        // Apply discounts to the order
        cout << "Discounts applied." << endl;
        if (nextHandler != nullptr) {
            nextHandler->processOrder(order);
        }
    }
};

// ShippingHandler
class ShippingHandler : public OrderHandler {
private:
    OrderHandler* nextHandler;

public:
    void setNextHandler(OrderHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    void processOrder(Order order) override {
        // Calculate shipping costs
        cout << "Shipping costs calculated." << endl;
        if (nextHandler != nullptr) {
            nextHandler->processOrder(order);
        }
    }
};

// ConfirmationHandler
class ConfirmationHandler : public OrderHandler {
private:
    OrderHandler* nextHandler;

public:
    void setNextHandler(OrderHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    void processOrder(Order order) override {
        // Confirm the order
        order.confirmOrder();
        cout << "Order confirmed successfully." << endl;
    }
};

int main() {
    // Example order
    Order order(true, true);

    // Build the chain of responsibility
    OrderHandler* chain = new PaymentHandler();
    chain->setNextHandler(new StockHandler());
    chain->setNextHandler(new DiscountHandler());
    chain->setNextHandler(new ShippingHandler());
    chain->setNextHandler(new ConfirmationHandler());

    // Process the order by use of the chain of responsibility
    chain->processOrder(order);

    // Clean up memory
    delete chain;

    return 0;
}

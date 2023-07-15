#include <iostream>
using namespace std;

// Author - Given Lepita
/*
                                ************ Online Order Status Tracking ************
* In an online shopping application, let's consider a scenario where users can place orders and track their order status.
* The order status can change over time, depending on various factors such as order processing, shipping, and delivery.
* To manage the changing states of an order and perform different actions based on its current state, we can utilize the State Design Pattern.
*/ 


// Interface representing the order state
class OrderState {
public:
    virtual void processOrder(class Order& order) = 0;
    virtual void cancelOrder(class Order& order) = 0;
    virtual void shipOrder(class Order& order) = 0;
};

// Concrete implementation of the "Processing" state
class ProcessingState : public OrderState {
public:
    void processOrder(class Order& order) override {
        cout << "The order is already being processed." << endl;
    }

    void cancelOrder(class Order& order) override;

    void shipOrder(class Order& order) override;
};

// Concrete implementation of the "Shipped" state
class ShippedState : public OrderState {
public:
    void processOrder(class Order& order) override {
        cout << "The order is already shipped and cannot be processed further." << endl;
    }

    void cancelOrder(class Order& order) override {
        cout << "Cancelling the shipped order is not possible." << endl;
    }

    void shipOrder(class Order& order) override {
        cout << "The order is already shipped." << endl;
    }
};

// Concrete implementation of the "Cancelled" state
class CancelledState : public OrderState {
public:
    void processOrder(class Order& order) override {
        cout << "Processing a cancelled order is not possible." << endl;
    }

    void cancelOrder(class Order& order) override {
        cout << "The order is already cancelled." << endl;
    }

    void shipOrder(class Order& order) override {
        cout << "Shipping a cancelled order is not possible." << endl;
    }
};

// Context class representing an order
class Order {
private:
    OrderState* state;

public:
    Order() {
        // Set the initial state as Processing
        state = new ProcessingState();
    }

    void setState(OrderState* state) {
        this->state = state;
    }

    void process() {
        state->processOrder(*this);
    }

    void cancel() {
        state->cancelOrder(*this);
    }

    void ship() {
        state->shipOrder(*this);
    }
};

void ProcessingState::cancelOrder(Order& order) {
    cout << "Cancelling the order." << endl;
    order.setState(new CancelledState());
}

void ProcessingState::shipOrder(Order& order) {
    cout << "Shipping the order." << endl;
    order.setState(new ShippedState());
}

int main() {
    Order order;
    order.process();  // Process the order

    order.ship();     // Ship the order
    order.process();  // Attempt to process the shipped order

    order.cancel();   // Cancel the order
    order.ship();     // Attempt to ship the cancelled order

    return 0;
}

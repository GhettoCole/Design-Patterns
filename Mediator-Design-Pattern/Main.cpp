#include <iostream>
#include <list>
using namespace std;


// Author - Given Lepita
/*
                                    * Mediator Design Pattern *                              
 * The Mediator design pattern is a behavioral pattern that promotes loose coupling between objects by centralizing the way they communicate.
 * It defines an object (the mediator) that encapsulates communication logic between multiple objects (colleagues).
 * Instead of direct communication between colleagues, they interact with the mediator, which then relays messages to the appropriate recipients.
 * This promotes a more organized and maintainable system, as changes to communication behavior are localized to the mediator,
 * rather than being scattered across multiple classes.

 * This code implements the Mediator design pattern in C++.
 * The Mediator interface defines a method for sending messages to other objects.
 * The ConcreteColleague classes implement the Device interface, which provides methods for sending and receiving messages.
 * The ConcreteMediator class implements the Mediator interface and uses a list to store all of the devices that are registered with it.
 * The sendMessage() method of the ConcreteMediator class iterates through the list of devices and calls the receive() method on each device. 
 * The main() function of the code creates a HomeAutomationMediator object, a Light object, and a Thermostat object.
 * The Light and Thermostat objects are then registered with the HomeAutomationMediator object.
 * The main() function then calls the send() method on the Light and Thermostat objects,
 * which causes the HomeAutomationMediator object to send messages to all of the registered devices.
 */

// Mediator interface
class Mediator {
public:
    virtual void sendMessage(void* device, string message) = 0;
};

// Colleague (Device) interface
class Device {
public:
    virtual void send(string message) = 0;

    virtual void receive(string message) = 0;
};

// ConcreteColleague classes (Devices)
class Light : public Device {
private:
    Mediator* mediator;

public:
    Light(Mediator* mediator) {
        this->mediator = mediator;
    }

    void send(string message) {
        cout << "Light sending message: " << message << endl;
        mediator->sendMessage(this, message);
    }

    void receive(string message) {
        cout << "Light received message: " << message << endl;
    }
};

class Thermostat : public Device {
private:
    Mediator* mediator;

public:
    Thermostat(Mediator* mediator) {
        this->mediator = mediator;
    }

    void send(string message) {
        cout << "Thermostat sending message: " << message << endl;
        mediator->sendMessage(this, message);
    }

    void receive(string message) {
        cout << "Thermostat received message: " << message << endl;
    }
};

// ConcreteMediator class
class HomeAutomationMediator : public Mediator {
private:
    list<Device*> devices;

public:
    HomeAutomationMediator() {
        devices = list<Device*>();
    }

    void addDevice(Device* device) {
        devices.push_back(device);
    }

    void sendMessage(void* device, string message) {
        for (Device* dev : devices) {
            if (dev != device) {
                dev->receive(message);
            }
        }
    }
};

int main() {
    // mediator and devices
    HomeAutomationMediator mediator;
    Light light = Light(&mediator);
    Thermostat thermostat = Thermostat(&mediator);

    // Add devices to the mediator
    mediator.addDevice(&light);
    mediator.addDevice(&thermostat);

    // testing communication using the mediator
    light.send("Turn on the lights");
    thermostat.send("Set the temperature to 25°C");

    return 0;
}

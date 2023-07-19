import java.util.ArrayList;
import java.util.List;

// Author - Given Lepita
/*
                                    * Mediator Design Pattern *                              
 * The Mediator design pattern is a behavioral pattern that promotes loose coupling between objects by centralizing the way they communicate.
 * It defines an object (the mediator) that encapsulates communication logic between multiple objects (colleagues).
 * Instead of direct communication between colleagues, they interact with the mediator, which then relays messages to the appropriate recipients.
 * This promotes a more organized and maintainable system, as changes to communication behavior are localized to the mediator,
 * rather than being scattered across multiple classes.

 * This code implements the Mediator design pattern in Java.
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
interface Mediator {
    void sendMessage(Device device, String message);
}

// Colleague (Device) interface
interface Device {
    void send(String message);

    void receive(String message);
}

// ConcreteColleague classes (Devices)
class Light implements Device {
    private Mediator mediator;

    public Light(Mediator mediator) {
        this.mediator = mediator;
    }

    @Override
    public void send(String message) {
        System.out.println("Light sending message: " + message);
        mediator.sendMessage(this, message);
    }

    @Override
    public void receive(String message) {
        System.out.println("Light received message: " + message);
    }
}

class Thermostat implements Device {
    private Mediator mediator;

    public Thermostat(Mediator mediator) {
        this.mediator = mediator;
    }

    @Override
    public void send(String message) {
        System.out.println("Thermostat sending message: " + message);
        mediator.sendMessage(this, message);
    }

    @Override
    public void receive(String message) {
        System.out.println("Thermostat received message: " + message);
    }
}

// ConcreteMediator class
class HomeAutomationMediator implements Mediator {
    private List<Device> devices;

    public HomeAutomationMediator() {
        devices = new ArrayList<>();
    }

    public void addDevice(Device device) {
        devices.add(device);
    }

    @Override
    public void sendMessage(Device device, String message) {
        for (Device dev : devices) {
            if (dev != device) {
                dev.receive(message);
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // mediator and devices
        HomeAutomationMediator mediator = new HomeAutomationMediator();
        Light light = new Light(mediator);
        Thermostat thermostat = new Thermostat(mediator);

        // Add devices to the mediator
        mediator.addDevice(light);
        mediator.addDevice(thermostat);

        // testing communication using the mediator
        light.send("Turn on the lights");
        thermostat.send("Set the temperature to 25°C");
    }
}

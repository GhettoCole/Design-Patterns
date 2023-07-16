#include <iostream>

// Author - Given Lepita

/*
 ******************************** Smart Home Automation System ********************************

* We will create a simple smart home automation system that allows users to control different
* electronic devices (e.g., lights, fans, and speakers) using a remote control.
* We'll use the Command design pattern to implement the functionality of the remote control's buttons and
* demonstrate how it decouples the invoker (remote control) from the receiver (devices) through commands.
----------------------------------------------------------------------------------------------------------------------

The Command design pattern is a behavioral design pattern that is used to encapsulate a request or operation as an object,
allowing for parameterization of clients with different requests, queuing of requests, and logging of the requests.
It decouples the sender (invoker) of a request from the object that performs the action (receiver)
and allows the sender to work with different requests without knowing the specific details of how the request is executed.

                                    ***** Key participants in the Command design pattern *****

1. Command: This is the interface or abstract class that declares the `execute()` method, which encapsulates the action to be performed.

2. ConcreteCommand: These are the classes that implement the `Command` interface. Each `ConcreteCommand` binds an action with a receiver and implements the `execute()` method by calling the appropriate method of the receiver.

3. Client (Invoker): The client holds the reference to the `Command` object and initiates the request. It does not know how the request is executed; it only knows the `Command` interface.

4. Receiver: The receiver knows how to perform the operation associated with the command. It's the target of the action.

5. Invoker: This is responsible for invoking the command and is unaware of the concrete commands or receivers. It simply triggers the `execute()` method of the `Command` interface.

The Command pattern is useful in various scenarios, such as:

-> Implementing undo/redo functionality: By storing commands in a stack, you can easily undo or redo operations.
-> Implementing a menu system: Each menu item can be a separate command that performs a specific action when invoked.
-> Implementing multi-level transactional systems: A series of commands can be grouped into a single high-level command to maintain consistency during the transaction.

The Command design pattern promotes loose coupling between objects and enhances flexibility, extensibility,
and maintainability of the code by allowing requests to be handled uniformly through the `Command` interface.

*/

// Command interface
class Command {
public:
    virtual void execute() = 0;
};

// Receiver: Light
class Light {
public:
    void turnOn() {
        std::cout << "Light is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "Light is OFF" << std::endl;
    }
};

// Receiver: Fan
class Fan {
public:
    void turnOn() {
        std::cout << "Fan is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "Fan is OFF" << std::endl;
    }
};

// Receiver: Speaker
class Speaker {
public:
    void turnOn() {
        std::cout << "Speaker is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "Speaker is OFF" << std::endl;
    }
};

// Concrete Command: LightOnCommand
class LightOnCommand : public Command {
private:
    Light* light;

public:
    LightOnCommand(Light* light) : light(light) {}

    void execute() override {
        light->turnOn();
    }
};

// Concrete Command: LightOffCommand
class LightOffCommand : public Command {
private:
    Light* light;

public:
    LightOffCommand(Light* light) : light(light) {}

    void execute() override {
        light->turnOff();
    }
};

// Concrete Command: FanOnCommand
class FanOnCommand : public Command {
private:
    Fan* fan;

public:
    FanOnCommand(Fan* fan) : fan(fan) {}

    void execute() override {
        fan->turnOn();
    }
};

// Concrete Command: FanOffCommand
class FanOffCommand : public Command {
private:
    Fan* fan;

public:
    FanOffCommand(Fan* fan) : fan(fan) {}

    void execute() override {
        fan->turnOff();
    }
};

// Concrete Command: SpeakerOnCommand
class SpeakerOnCommand : public Command {
private:
    Speaker* speaker;

public:
    SpeakerOnCommand(Speaker* speaker) : speaker(speaker) {}

    void execute() override {
        speaker->turnOn();
    }
};

// Concrete Command: SpeakerOffCommand
class SpeakerOffCommand : public Command {
private:
    Speaker* speaker;

public:
    SpeakerOffCommand(Speaker* speaker) : speaker(speaker) {}

    void execute() override {
        speaker->turnOff();
    }
};

// Invoker: RemoteControl
class RemoteControl {
private:
    Command* command;

public:
    void setCommand(Command* command) {
        this->command = command;
    }

    void pressButton() {
        command->execute();
    }
};

int main() {
    // Creating the devices (receivers)
    Light livingRoomLight;
    Fan bedroomFan;
    Speaker soundSystem;

    // Creating the commands with the corresponding receivers
    Command* livingRoomLightOn = new LightOnCommand(&livingRoomLight);
    Command* livingRoomLightOff = new LightOffCommand(&livingRoomLight);
    Command* bedroomFanOn = new FanOnCommand(&bedroomFan);
    Command* bedroomFanOff = new FanOffCommand(&bedroomFan);
    Command* speakerOn = new SpeakerOnCommand(&soundSystem);
    Command* speakerOff = new SpeakerOffCommand(&soundSystem);

    // Creating the remote control (invoker) and setting commands
    RemoteControl remoteControl;

    // Using the remote control to turn on/off devices
    remoteControl.setCommand(livingRoomLightOn);
    remoteControl.pressButton(); // Turns on the living room light

    remoteControl.setCommand(bedroomFanOn);
    remoteControl.pressButton(); // Turns on the bedroom fan

    remoteControl.setCommand(speakerOn);
    remoteControl.pressButton(); // Turns on the speaker system

    remoteControl.setCommand(livingRoomLightOff);
    remoteControl.pressButton(); // Turns off the living room light

    remoteControl.setCommand(bedroomFanOff);
    remoteControl.pressButton(); // Turns off the bedroom fan

    remoteControl.setCommand(speakerOff);
    remoteControl.pressButton(); // Turns off the speaker system

    // Clean up memory
    delete livingRoomLightOn;
    delete livingRoomLightOff;
    delete bedroomFanOn;
    delete bedroomFanOff;
    delete speakerOn;
    delete speakerOff;

    return 0;
}

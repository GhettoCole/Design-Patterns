#include <iostream>
using namespace std;

// Author - Given Lepita

/*
 * The Factory Method design pattern is a creational design pattern that provides an interface for creating objects,
 * but allows the subclasses to decide which class to instantiate.
 * It encapsulates object creation and delegates the responsibility of creating objects to its subclasses.

 * The main idea behind the Factory Method pattern is to promote loose coupling between the client code
 * and the concrete classes it uses. Instead of directly creating objects using constructors,
 * the client code interacts with the factory method interface to obtain instances of objects.
 * This makes the client code independent of the actual class implementations and
 * allows easy extension with new classes without modifying the existing client code.

                ******** Key components of the Factory Method pattern ********
 * Product: This is the interface or abstract class that defines the object type to be created.
 * ConcreteProduct: These are the concrete classes that implement the Product interface or extend the Product abstract class.
 * They represent the different types of objects that the factory method can produce.
 * Creator: This is the interface or abstract class that declares the factory method for creating objects of the Product type.
 * ConcreteCreator: These are the concrete classes that implement the Creator interface or extend the Creator abstract class.
 * Each ConcreteCreator class is responsible for creating a specific type of ConcreteProduct.

                ******** The interaction works as follows ********
 * The client code calls the factory method on the Creator to obtain a Product object.
 * The Creator's factory method delegates the object creation to the ConcreteCreator subclasses.
 * Each ConcreteCreator subclass instantiates and returns the appropriate ConcreteProduct object.
 
                ******** Advantages of using the Factory Method pattern ********
 * Provides a common interface for creating objects, making the client code independent of the specific object creation logic.
 * Allows the addition of new product classes without modifying existing client code.
 * Promotes loose coupling between the client and the product classes.
 * Helps manage complex object creation and supports object creation polymorphism.

 * Imagine you are developing a video game that involves different types of characters.
 * Each character has unique abilities and attributes, and you want to create them dynamically during the game.
 * To achieve this, you decide to use the Factory Method Design Pattern to create the characters based on their specific types.
 */

// Character interface representing the common methods for all characters
class Character {
public:
    virtual void attack() = 0;
    virtual void defend() = 0;
};

// Concrete implementation of a Warrior character
class Warrior : public Character {
public:
    void attack() override {
        cout << "Warrior attacks with a sword!" << endl;
    }

    void defend() override {
        cout << "Warrior defends with a shield!" << endl;
    }
};

// Concrete implementation of a Mage character
class Mage : public Character {
public:
    void attack() override {
        cout << "Mage casts a fireball!" << endl;
    }

    void defend() override {
        cout << "Mage creates a magic barrier!" << endl;
    }
};

// Character Factory interface
class CharacterFactory {
public:
    virtual Character* createCharacter() = 0;
};

// Concrete implementation of a Warrior Factory
class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter() override {
        return new Warrior();
    }
};

// Concrete implementation of a Mage Factory
class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() override {
        return new Mage();
    }
};

int main() {
    // Using the Factory Method to create characters dynamically
    CharacterFactory* warriorFactory = new WarriorFactory();
    Character* warriorCharacter = warriorFactory->createCharacter();
    warriorCharacter->attack();
    warriorCharacter->defend();

    CharacterFactory* mageFactory = new MageFactory();
    Character* mageCharacter = mageFactory->createCharacter();
    mageCharacter->attack();
    mageCharacter->defend();

    delete warriorCharacter;
    delete mageCharacter;
    delete warriorFactory;
    delete mageFactory;

    return 0;
}

#include <iostream>
#include <vector>

// Author - Given Lepita
/*
 * Suppose we are working on a graphical user interface (GUI) framework, and we need to create a system to manage different UI elements like buttons, text boxes, and containers.
 * Each UI element can have sub-elements, such as buttons inside a container.
 * We want to provide a unified way to treat individual elements and groups of elements as a single entity.
 * In such a scenario, the Composite Pattern would be a suitable design pattern to use.

                *                                                   ************** Composite Pattern ***************
 * The Composite Pattern is a structural design pattern that allows you to compose objects into tree-like structures to represent part-whole hierarchies.
 * It lets clients treat individual objects and compositions of objects uniformly.
*/

// Component interface representing the UI element
class UIElement {
public:
    virtual void draw() = 0;
};

// Leaf class representing individual UI elements like buttons or text boxes
class LeafElement : public UIElement {
private:
    std::string name;

public:
    LeafElement(const std::string& name) : name(name) {}

    void draw() override {
        std::cout << "Drawing " << name << std::endl;
    }
};

// Composite class representing a container that can hold multiple UI elements
class UIContainer : public UIElement {
private:
    std::string name;
    std::vector<UIElement*> elements;

public:
    UIContainer(const std::string& name) : name(name) {}

    void addElement(UIElement* element) {
        elements.push_back(element);
    }

    void removeElement(UIElement* element) {
        // Not implemented for simplicity in this example
    }

    void draw() override {
        std::cout << "Drawing " << name << std::endl;
        for (UIElement* element : elements) {
            element->draw();
        }
    }
};

int main() {
    // Create individual UI elements
    LeafElement button1("Button 1");
    LeafElement button2("Button 2");
    LeafElement textBox1("Text Box 1");

    // Create a container to hold multiple UI elements
    UIContainer container("Container");
    container.addElement(&button1);
    container.addElement(&textBox1);

    // Create another container with a nested container
    UIContainer nestedContainer("Nested Container");
    nestedContainer.addElement(&button2);

    container.addElement(&nestedContainer);

    // Draw the entire GUI
    container.draw();

    return 0;
}

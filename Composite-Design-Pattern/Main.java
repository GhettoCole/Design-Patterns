import java.util.ArrayList;
import java.util.List;

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
interface UIElement {
    void draw();
}

// Leaf class representing individual UI elements like buttons or text boxes
class LeafElement implements UIElement {
    private String name;

    public LeafElement(String name) {
        this.name = name;
    }

    @Override
    public void draw() {
        System.out.println("Drawing " + name);
    }
}

// Composite class representing a container that can hold multiple UI elements
class UIContainer implements UIElement {
    private String name;
    private List<UIElement> elements = new ArrayList<>();

    public UIContainer(String name) {
        this.name = name;
    }

    public void addElement(UIElement element) {
        elements.add(element);
    }

    public void removeElement(UIElement element) {
        elements.remove(element);
    }

    @Override
    public void draw() {
        System.out.println("Drawing " + name);
        for (UIElement element : elements) {
            element.draw();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Create individual UI elements
        LeafElement button1 = new LeafElement("Button 1");
        LeafElement button2 = new LeafElement("Button 2");
        LeafElement textBox1 = new LeafElement("Text Box 1");

        // Create a container to hold multiple UI elements
        UIContainer container = new UIContainer("Container");
        container.addElement(button1);
        container.addElement(textBox1);

        // Create another container with a nested container
        UIContainer nestedContainer = new UIContainer("Nested Container");
        nestedContainer.addElement(button2);

        container.addElement(nestedContainer);

        // Draw the entire GUI
        container.draw();
    }
}

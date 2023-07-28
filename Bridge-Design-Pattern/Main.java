// Author - Given Lepita

/*
 * Let's consider a scenario where we are designing a drawing application that supports multiple shapes (e.g., circles, squares, triangles)
 * and multiple rendering platforms (e.g., OpenGL, DirectX). We want to decouple the shape abstraction from its rendering implementation,
 * so we use the Bridge design pattern to achieve this separation.
 * The Bridge pattern allows us to vary and combine the shape and rendering classes independently.
*/


public class Main {
    public static void main(String[] args) {
        // Example usage of the Bridge design pattern
        // We will create circles using different rendering platforms

        // Using OpenGL for rendering
        ShapeRenderer glRenderer = new OpenGLShapeRenderer();

        Shape circle = new Circle(5, glRenderer);
        circle.draw();

        // Using DirectX for rendering
        ShapeRenderer dxRenderer = new DirectXShapeRenderer();

        Shape anotherCircle = new Circle(10, dxRenderer);
        anotherCircle.draw();

        // Now, let's create squares using different rendering platforms

        Shape square = new Square(7, glRenderer);
        square.draw();

        Shape anotherSquare = new Square(12, dxRenderer);
        anotherSquare.draw();
    }
}

// Shape interface
interface Shape {
    void draw();
}

// ShapeRenderer interface (The bridge interface)
interface ShapeRenderer {
    void renderShape(int radius);
}

// Concrete shape implementation 1 - Circle
class Circle implements Shape {
    private int radius;
    private ShapeRenderer renderer;

    public Circle(int radius, ShapeRenderer renderer) {
        this.radius = radius;
        this.renderer = renderer;
    }

    public void draw() {
        renderer.renderShape(radius);
    }
}

// Concrete shape implementation 2 - Square
class Square implements Shape {
    private int sideLength;
    private ShapeRenderer renderer;

    public Square(int sideLength, ShapeRenderer renderer) {
        this.sideLength = sideLength;
        this.renderer = renderer;
    }

    public void draw() {
        renderer.renderShape(sideLength);
    }
}

// Concrete rendering platform implementation 1 - OpenGL
class OpenGLShapeRenderer implements ShapeRenderer {
    public void renderShape(int radiusOrSideLength) {
        System.out.println("Drawing shape using OpenGL with radius/side length: " + radiusOrSideLength);
    }
}

// Concrete rendering platform implementation 2 - DirectX
class DirectXShapeRenderer implements ShapeRenderer {
    public void renderShape(int radiusOrSideLength) {
        System.out.println("Drawing shape using DirectX with radius/side length: " + radiusOrSideLength);
    }
}

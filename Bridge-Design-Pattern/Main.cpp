#include <iostream>

// Author - Given Lepita

/*
 * Let's consider a scenario where we are designing a drawing application that supports multiple shapes (e.g., circles, squares, triangles)
 * and multiple rendering platforms (e.g., OpenGL, DirectX). We want to decouple the shape abstraction from its rendering implementation,
 * so we use the Bridge design pattern to achieve this separation.
 * The Bridge pattern allows us to vary and combine the shape and rendering classes independently.
*/


// Shape interface (abstract class)
class Shape {
public:
    virtual void draw() = 0;
};

// ShapeRenderer interface (abstract class) - The bridge interface
class ShapeRenderer {
public:
    virtual void renderShape(int radius) = 0;
};

// Concrete shape implementation 1 - Circle
class Circle : public Shape {
private:
    int radius;
    ShapeRenderer* renderer;

public:
    Circle(int radius, ShapeRenderer* renderer) : radius(radius), renderer(renderer) {}

    void draw() override {
        renderer->renderShape(radius);
    }
};

// Concrete shape implementation 2 - Square
class Square : public Shape {
private:
    int sideLength;
    ShapeRenderer* renderer;

public:
    Square(int sideLength, ShapeRenderer* renderer) : sideLength(sideLength), renderer(renderer) {}

    void draw() override {
        renderer->renderShape(sideLength);
    }
};

// Concrete rendering platform implementation 1 - OpenGL
class OpenGLShapeRenderer : public ShapeRenderer {
public:
    void renderShape(int radiusOrSideLength) override {
        std::cout << "Drawing shape using OpenGL with radius/side length: " << radiusOrSideLength << std::endl;
    }
};

// Concrete rendering platform implementation 2 - DirectX
class DirectXShapeRenderer : public ShapeRenderer {
public:
    void renderShape(int radiusOrSideLength) override {
        std::cout << "Drawing shape using DirectX with radius/side length: " << radiusOrSideLength << std::endl;
    }
};

int main() {
    // Example usage of the Bridge design pattern
    // We will create circles using different rendering platforms

    // Using OpenGL for rendering
    ShapeRenderer* glRenderer = new OpenGLShapeRenderer();

    Shape* circle = new Circle(5, glRenderer);
    circle->draw();

    // Using DirectX for rendering
    ShapeRenderer* dxRenderer = new DirectXShapeRenderer();

    Shape* anotherCircle = new Circle(10, dxRenderer);
    anotherCircle->draw();

    // Now, let's create squares using different rendering platforms

    Shape* square = new Square(7, glRenderer);
    square->draw();

    Shape* anotherSquare = new Square(12, dxRenderer);
    anotherSquare->draw();

    // Clean up memory (not necessary, but good practice)
    delete glRenderer;
    delete dxRenderer;
    delete circle;
    delete anotherCircle;
    delete square;
    delete anotherSquare;

    return 0;
}

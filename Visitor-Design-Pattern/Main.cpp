#include <iostream>
#include <cmath>

// Author - Given Lepita

/*
 * Suppose we are building a program to process various shapes (e.g., circles, squares, triangles) for a graphics application.
 * Each shape has its unique properties and requires specific operations, such as calculating area, perimeter, and rendering.
 * We want to implement a system that allows us to perform different actions on these shapes without modifying their individual classes.

                                        ******** Visitor Design Pattern ********
 * The Visitor Design Pattern is used to separate the algorithms from the objects on which they operate.
 * It allows us to add new operations to the objects without modifying their classes.
 * In this scenario, we can use the Visitor pattern to define new operations (visitors) for each shape without changing their implementations.

*/

// Forward declarations of the shape classes
class Circle;
class Square;
class Triangle;

// Visitor interface
class ShapeVisitor {
public:
    virtual void visitCircle(const Circle& circle) = 0;
    virtual void visitSquare(const Square& square) = 0;
    virtual void visitTriangle(const Triangle& triangle) = 0;
};

// Define the Shape interface
class Shape {
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
};

// Concrete implementation of the Shape interface - Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getRadius() const {
        return radius;
    }

    void accept(ShapeVisitor& visitor) override {
        visitor.visitCircle(*this);
    }
};

// Concrete implementation of the Shape interface - Square
class Square : public Shape {
private:
    double side;

public:
    Square(double side) : side(side) {}

    double getSide() const {
        return side;
    }

    void accept(ShapeVisitor& visitor) override {
        visitor.visitSquare(*this);
    }
};

// Concrete implementation of the Shape interface - Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double base, double height) : base(base), height(height) {}

    double getBase() const {
        return base;
    }

    double getHeight() const {
        return height;
    }

    double calculateArea() const {
        return 0.5 * base * height;
    }

    double calculatePerimeter() const {
        // Implementation to calculate the perimeter of a triangle
        // ...
        return 0;
    }

    void accept(ShapeVisitor& visitor) override {
        visitor.visitTriangle(*this);
    }
};

// Concrete implementation of the Visitor interface to calculate the area of shapes
class AreaCalculator : public ShapeVisitor {
public:
    void visitCircle(const Circle& circle) override {
        double area = M_PI * pow(circle.getRadius(), 2);
        std::cout << "Area of Circle: " << area << std::endl;
    }

    void visitSquare(const Square& square) override {
        double area = pow(square.getSide(), 2);
        std::cout << "Area of Square: " << area << std::endl;
    }

    void visitTriangle(const Triangle& triangle) override {
        double area = triangle.calculateArea();
        std::cout << "Area of Triangle: " << area << std::endl;
    }
};

// Concrete implementation of the Visitor interface to calculate the perimeter of shapes
class PerimeterCalculator : public ShapeVisitor {
public:
    void visitCircle(const Circle& circle) override {
        double perimeter = 2 * M_PI * circle.getRadius();
        std::cout << "Perimeter of Circle: " << perimeter << std::endl;
    }

    void visitSquare(const Square& square) override {
        double perimeter = 4 * square.getSide();
        std::cout << "Perimeter of Square: " << perimeter << std::endl;
    }

    void visitTriangle(const Triangle& triangle) override {
        double perimeter = triangle.calculatePerimeter();
        std::cout << "Perimeter of Triangle: " << perimeter << std::endl;
    }
};

int main() {
    Circle circle(5.0);
    Square square(4.0);
    Triangle triangle(3.0, 4.0);

    // Using the AreaCalculator Visitor
    AreaCalculator areaCalculator;
    circle.accept(areaCalculator);
    square.accept(areaCalculator);
    triangle.accept(areaCalculator);

    // Using the PerimeterCalculator Visitor
    PerimeterCalculator perimeterCalculator;
    circle.accept(perimeterCalculator);
    square.accept(perimeterCalculator);
    triangle.accept(perimeterCalculator);

    return 0;
}

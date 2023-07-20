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

//  Visitor interface
interface ShapeVisitor {
    void visitCircle(Circle circle);
    void visitSquare(Square square);
    void visitTriangle(Triangle triangle);
}

// Concrete implementation of the Visitor interface to calculate the area of shapes
class AreaCalculator implements ShapeVisitor {
    @Override
    public void visitCircle(Circle circle) {
        double area = Math.PI * Math.pow(circle.getRadius(), 2);
        System.out.println("Area of Circle: " + area);
    }

    @Override
    public void visitSquare(Square square) {
        double area = Math.pow(square.getSide(), 2);
        System.out.println("Area of Square: " + area);
    }

    @Override
    public void visitTriangle(Triangle triangle) {
        // Assuming we have a method to calculate the area of a triangle
        double area = triangle.calculateArea();
        System.out.println("Area of Triangle: " + area);
    }
}

// Concrete implementation of the Visitor interface to calculate the perimeter of shapes
class PerimeterCalculator implements ShapeVisitor {
    @Override
    public void visitCircle(Circle circle) {
        double perimeter = 2 * Math.PI * circle.getRadius();
        System.out.println("Perimeter of Circle: " + perimeter);
    }

    @Override
    public void visitSquare(Square square) {
        double perimeter = 4 * square.getSide();
        System.out.println("Perimeter of Square: " + perimeter);
    }

    @Override
    public void visitTriangle(Triangle triangle) {
        // Assuming we have a method to calculate the perimeter of a triangle
        double perimeter = triangle.calculatePerimeter();
        System.out.println("Perimeter of Triangle: " + perimeter);
    }
}

// Define the Shape interface
interface Shape {
    void accept(ShapeVisitor visitor);
}

// Concrete implementation of the Shape interface - Circle
class Circle implements Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visitCircle(this);
    }
}

// Concrete implementation of the Shape interface - Square
class Square implements Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visitSquare(this);
    }
}

// Concrete implementation of the Shape interface - Triangle
class Triangle implements Shape {
    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double getBase() {
        return base;
    }

    public double getHeight() {
        return height;
    }

    // Assuming we have a method to calculate the area of a triangle
    public double calculateArea() {
        return 0.5 * base * height;
    }

    // Assuming we have a method to calculate the perimeter of a triangle
    public double calculatePerimeter() {
        // Implementation to calculate the perimeter of a triangle
        // ...
        return 0;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visitTriangle(this);
    }
}

public class Main {
    public static void main(String[] args) {
        Shape circle = new Circle(5.0);
        Shape square = new Square(4.0);
        Shape triangle = new Triangle(3.0, 4.0);

        // Using the AreaCalculator Visitor
        AreaCalculator areaCalculator = new AreaCalculator();
        circle.accept(areaCalculator);
        square.accept(areaCalculator);
        triangle.accept(areaCalculator);

        // Using the PerimeterCalculator Visitor
        PerimeterCalculator perimeterCalculator = new PerimeterCalculator();
        circle.accept(perimeterCalculator);
        square.accept(perimeterCalculator);
        triangle.accept(perimeterCalculator);
    }
}

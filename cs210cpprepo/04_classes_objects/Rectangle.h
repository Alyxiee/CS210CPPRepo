// TASK 04 -- Classes and Objects
//
// A class is a blueprint. It describes what data a thing carries and
// what it can do. An OBJECT is one specific instance built from that
// blueprint, sitting in memory with its own values.
//
// Analogy: "Rectangle" the class is like the word "car" as a concept.
// A specific Rectangle object, like a specific Toyota Corolla parked
// outside, has actual dimensions.

#pragma once

class Rectangle {
public:
    // A basic constructor -- we'll modernize this exact class in Task 06.
    Rectangle(double width, double height);

    double area() const;
    double perimeter() const;

    void setWidth(double width);
    void setHeight(double height);

private:
    double width_;
    double height_;
};

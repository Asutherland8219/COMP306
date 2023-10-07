//
// Created by alex on 19/08/23.
//

#include <iostream>

class Point {
private:
    double x;
    double y;
public:
   void Show() {
       std::cout << "x and y are currently set at: (" << x << "," << y << ")";
    }

    void Add( int x_change = 0, int y_change = 0) {
        // have both variables and set default to 0, because they have a default value, we can treat them as optional
        Show();

        if (x_change != 0) {
            // this means that we only want to change the y value
            y = y + y_change;
        }

        if (y_change != 0) {
            // this means we only want to change the x value
            x = x + x_change;
        }

        std::cout << "The new point values for x and y are set at: " << x << " , " << y ;

    }

    void Subtract( int x_change = 0, int y_change = 0) {
        // have both variables and set default to 0, because they have a default value, we can treat them as optional
        Show();

        if (x_change != 0) {
            // this means that we only want to change the y value
            y = y - y_change;
        }

        if (y_change != 0) {
            // this means we only want to change the x value
            x = x - x_change;
        }

        std::cout << "The new point values for x and y are set at: " << x << " , " << y ;

    }
};

class Shape {
public:
    Shape() {
        // default constructor
    }

    virtual void boundingBox() = 0;

    virtual double circumference() = 0;

    virtual double area() = 0;

    virtual void display();


};

class Circle : public Shape {;
private:
    Point center;
    double radius;
    // circumference
public:
    Circle(Point center, double radius) {
        // check that the value is positive
        if (radius <= 0) {
            cout << "Value is not possible for a circle. Please enter a number greater than 0. \n";
        }
    }

    double area() override  {

    };

    double circumference() override  {

    };

    void boundingBox() override
    {
    }

};

class Rectangle : public Shape {
    // perimeter
    double area() override  {

    };

    double circumference() override  {

    };

    void boundingBox() override
    {
    }
};

class Triangle : public Shape {
    // perimeter
    double area() override  {

    };

    double circumference() override  {

    };

    void boundingBox() override
    {
    }
};





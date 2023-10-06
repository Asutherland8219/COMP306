//
// Created by alex on 19/08/23.
//

#include <iostream>

class Point {
private:
    int x;
    int y;
public:
   void Show() {
       std::cout << "x and y are currently set at: " << x << " , " << y ;
    }

    void Add( int x_change = 10000000, int y_change = 10000000) {
        // have both variables and set default to 0, because they have a default value, we can treat them as optional
        Show();

        if (x_change == 10000000) {
            // this means that we only want to change the y value
            y = y + y_change;
        }

        if (y_change == 10000000) {
            // this means we only want to change the x value
            x = x + x_change;
        }

        else {
            x = x + x_change;
            y = y + y_change;
        }

        std::cout << "The new point values for x and y are set at: " << x << " , " << y ;

    }

    void Subtract( int x_change = 10000000, int y_change = 10000000) {

        // have both variables and set default to 0, because they have a default value, we can treat them as optional
        Show();

        if (x_change == 10000000) {
            // this means that we only want to change the y value
            y = y - y_change;
        }

        if (y_change == 10000000) {
            // this means we only want to change the x value
            x = x - x_change;
        }

        else {
            x = x - x_change;
            y = y - y_change;
        }

        std::cout << "The new point values for x and y are set at: " << x << " , " << y ;
    }

};

class Shape {
public:
    Shape() {
        // default constructor
    }

    virtual void Boundary() = 0;

    virtual void Circumference() = 0;

    virtual void Area() = 0;

    virtual void Display();

};

class Circle : public Shape {

};

class Rectangle : public Shape {

};

class Triangle : public Shape {

};





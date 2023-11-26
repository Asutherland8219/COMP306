//
// Created by alex on 19/08/23.
//

#include <iostream>
#include <vector>

class Point {
private:
    double x = 0;
    double y = 0;
public:
    Point() : x(0) , y(0)  {
            std::cout << "You have not entered any values so the default point object is created at 0,0. \n";
        };

    Point(double x, double y) : x(x), y(y) {

    }
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }

   void Show() {
       std::cout << "x and y are currently set at: (" << x << "," << y << ") \n";
    }

    void Add( int x_change = 0, int y_change = 0) {
        // have both variables and set default to 0, because they have a default value, we can treat them as optional
        Show();

        if (y_change != 0) {
            // this means that we only want to change the y value
            y = y + y_change;
        }

        if (x_change != 0) {
            // this means we only want to change the x value
            x = x + x_change;
        }

        std::cout << "The new point values for x and y are set at: " << x << " , " << y << endl;

    }

    void Subtract( int x_change = 0, int y_change = 0) {
        // have both variables and set default to 0, because they have a default value, we can treat them as optional
        Show();

        if (y_change != 0) {
            // this means that we only want to change the y value
            y = y - y_change;
        }

        if (x_change != 0) {
            // this means we only want to change the x value
            x = x - x_change;
        }

        std::cout << "The new point values for x and y are set at: " << x << " , " << y << endl;

    }
};


class Shape {
public:
    Shape() {
        // default constructor
    }

    virtual void display() {
        std::cout << "Area: " << area() << endl;
        std::cout << "Circumference: " << circumference() << endl;
        std::cout << "Bounding Box: [";
        const vector box = boundingBox();
        for (size_t i = 0; i < box.size(); ++i) {
            std::cout << "(" << box[i].getX() << ", " << box[i].getY() << ")";
            if (i < box.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    };

    virtual std::vector<Point> boundingBox() {

    };

    virtual double circumference() {

    };

    virtual double area() {

    };
};


class Circle : public Shape {;
private:
    Point center;
    double radius;
    // circumference
public:
    Circle(Point center, double radius) : center(center), radius(radius) {
        // check that the value is positive
        if (radius <= 0) {
            cout << "Value is not possible for a circle. Please enter a number greater than 0. \n";
        }
    }

    double area() override  {
        double circle_area = 3.14159 * radius * radius;
        return circle_area;
    };

    double circumference() override  {
        double circle_circumference = 2 * 3.14159 * radius;
        return circle_circumference;
    };

    std::vector<Point> boundingBox() override
    {
        // Calculate the bounding box variables
        double left_x = center.getX() - radius;
        double left_y = center.getY() - radius;
        double right_x = center.getX() + radius;
        double right_y = center.getY() + radius;

        // Create the multiple points  of the surrounding box
        Point point1 = Point(left_x, left_y);
        Point point2 = Point(right_x, left_y);
        Point point3 = Point(right_x, right_y);
        Point point4 = Point(left_x, right_y);

        return {point1, point2, point3, point4};
    };

};

class Rectangle : public Shape {
private:
    Point base_start;
    Point base_end;
    Point height_start;
    Point height_end;

public:
    Rectangle(Point base_start, Point base_end, Point height_start, Point height_end){
        if (!isValidRectangle()) {
            std::cout << " The values entered are not indicative of a rectangle \n";
            std::cout << " Remember, a rectangle must have parallel sides AND they cannot be equal.";
        }

        // Check if it's a square
        if (isSquare()) {
            std::cout << "The sides are equal! This rectangle is a square.\n";
        }
    }

    bool isValidRectangle() const {
        // Check if opposite sides are parallel, indicating a correct rectangle
        return (base_start.getX() <= base_end.getX()) &&
               (base_start.getY() <= height_start.getY()) &&
               (base_end.getY() <= height_end.getY()) &&
               (height_start.getX() <= height_end.getX());
    }

    bool isSquare() const {
        // check if the values create a square, if they do error out
        double width = std::abs(base_end.getX() - base_start.getX());
        double height = std::abs(height_end.getY() - height_start.getY());
        return width == height;
    }


    // perimeter
    double area() override  {
        double width = std::abs(base_end.getX() - base_start.getX());
        double height = std::abs(height_end.getY() - height_start.getY());
        return width * height;
    };

    double circumference() override  {
        // circumference is double the area
        double width = std::abs(base_end.getX() - base_start.getX());
        double height = std::abs(height_end.getY() - height_start.getY());
        return 2 * (width + height);
    };

    std::vector<Point> boundingBox() override
    {
      // the bounding box for a rectangle would just be the rectangle itself
        return {base_start, base_end, height_start, height_end};
    };

};

class Triangle : public Shape {
    // perimeter
private:
    Point peak;
    Point rightPoint;
    Point leftPoint;
    double area() override  {

    };

    double circumference() override  {

    };

//    std::vector<Point> boundingBox() override
//    {
//    }
};





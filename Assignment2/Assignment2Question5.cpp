/*
 Title: Assignment2Question5.cpp
 Description: Shapes
 Date: December 5th, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create a base Shape class, then create child classes for various shapes such as Circle, Rectangle and Triangle. Calculate Area and Circumference for each as well as the bounding box.
    Create a base Point class, these points are used to create the shape classes.

 Compile (assuming Cygwin is running): g++ -o Assignment2 Assignment2Question5.cpp
 Execution (assuming Cygwin is running): ./Assignment2Question5.exe

 Classes (functions):
    - Point
        - [Double] getX() : Gets the x Value
        - [Double] getY() : Gets the y value
        - [Void] Add( Double, Double) : Add to the point value
        - [Void] Subtract(Double, Double) : Subtract from the point value
        - [Void] Show() : Prints the values of the points currently


        - [Double] Distance(Point, Point)

        ** I didn't end up using this but left it because I was trying it out when doing calculations
        - [Double] Length(Point, Point)


	- Shape (Super/Parent Class)
        - [Array of doubles] Bounding Box : The points for the surrounding Box of the shape
        - [Double] Circumference : The circumference of the shape
        - [Double] Area: The area of the shape
        - [Void] Display: Print the Area, Circumference and Bounding Box

        - Inherited classes (from Shape)
            - Rectangle( Point, Point, Point, Point)  : Rectangle Class, inheriting from the parent Shape Class
                - [bool] isValidRectangle() : Check if the rectangle is valid
                - [bool] isSquare() : Check if the rectangle is ... a square

            - Triangle(Point, Point, Point) : Triangle class
                - [bool] isValidTriangle() : Check if triangle is a triangle

            - Circle(Point1, [Double] radius : Circle Class


        Each child class takes minimum 1 Point value (Circle), 3 for a triangle and 4 for a rectangle.
        Each child class also has validity checks to make sure the values enter fall under the constraints of being their respective shape.
        They also have their own versions of the calculations for each of the shape base functions (Circumference, Area, Display, BoundingBox).


 Variables:
 	Point:
 	    - [Double] x
 	    - [Double] y
 	    - [Double] x_change
 	    - [Double] y_change

 	    ## Point objects are also used as variables in the point class for the calculation of distance/length

    Shape : No variables on Shape, just child classes

    Circle:
        - [Point] center : The desired point center value of the circle
        - [Double] radius: The desired circle radius

    Rectangle:
        - [Point] topLeft : The upper left most point
        - [Point] topRight : The upper right most point
        - [Point] bottomLeft : The lower left most point
        - [Point] bottomRight : The lower right most point

    Triangle:
        - [Point] peak: The apex of the triangle
        - [Point] rightPoint : The right most point of the triangle
        - [Point] leftPoint : The left most point of the triangle


    The variable is overridden by the default output of  the child class. If no default output is given, "animal" is printed
*/

/*
 TEST PLAN

 Normal case:
 	> Point base;
 	> base.Show();
        Output: You have not entered any values so the default point object is created at 0,0.
        x and y are currently set at: (0,0)


    // Add to both
    > base.Add(1,1);
        Output: x and y are currently set at: (0,0)
                The new point values for x and y are set at: 1 , 1

    // Add to X
    > base.Add(1);
        Output: x and y are currently set at: (1,1)
                The new point values for x and y are set at: 2 , 1

    // Add to Y
    > base.Add(0,1);
        Output: x and y are currently set at: (2,1)
                The new point values for x and y are set at: 2 , 2

    // Subtract from both
    > base.Subtract(1,1);
        Output: x and y are currently set at: (2,2)
                The new point values for x and y are set at: 1 , 1

    // Subtract from x
    > base.Subtract(1);
        Output: x and y are currently set at: (1,1)
                The new point values for x and y are set at: 0 , 1

    // Subtract from Y
    > base.Subtract(0,1);
        Output: x and y are currently set at: (0,1)
                The new point values for x and y are set at: 0 , 0

    // Circle
    > Point circle_point(1,1);
    > double radius = 10
    > Circle base_circle(circle_point, radius)
    > base_circle.display()
        Output: Good Circle:
                Area: 314.159
                Circumference: 62.8318
                Bounding Box: [(-9, -9), (11, -9), (11, 11), (-9, 11)]

    > Point bottom_left_corner(4, 8);
    > Point bottom_right_corner(8,8);
    > Point upper_left_corner(4,16);
    > Point upper_right_corner(8, 16);

    // Rectangle
    > Rectangle rec(bottom_left_corner, bottom_right_corner, upper_left_corner, upper_right_corner);
    > rec.display()
        Output: Good rectangle:
                Area: 32
                Circumference: 24
                Bounding Box: [(4, 8), (8, 8), (8, 16), (4, 16)]

    > Point peak(4,8);
    > Point left_point(4,12);
    > Point right_point(8, 12);

    // Triangle
    > Triangle tri(peak, right_point, left_point);
    > tri.display()
        Output: Good Triangle:
                Area: 8
                Circumference: 13.6569
                Bounding Box: [(4, 8), (8, 8), (8, 12), (4, 12)]



 Bad Case
 	Circle:
 	    > double radius_bad = -1;
 	    > Circle bad_circle(circle_point, radius_bad)
 	        Output: Caught exception: Value is not possible for a circle. Please enter a number greater than 0.

    Rectangle:
    // Square case
     > Point bottom_left_corner_sq(4, 8);
     > Point bottom_right_corner_sq(8,8);
     > Point upper_left_corner_sq(4,12);
     > Point upper_right_corner_sq(8, 12);
     > Rectangle square(bottom_left_corner_sq, bottom_right_corner_sq, upper_left_corner_sq, upper_right_corner_sq);
        Output: Caught exception: Bad Rectangle: The sides are equal! This rectangle is a square.

    // bad rectangle case
    > Point bottom_left_corner_bad(-1, 8);
    > Point bottom_right_corner_bad(8,8);
    > Point upper_left_corner_bad(4,12);
    > Point upper_right_corner_bad(8, 12);
    > Rectangle bad_rec(bottom_left_corner_bad, bottom_right_corner_bad, upper_left_corner_bad, upper_right_corner_bad);
        Output: Caught exception: Bad Rectangle: The values entered are not indicative of a rectangle.
                Remember, a rectangle must have parallel sides, and they all cannot be equal.

    Triangle:
    > Point peak(4,8);
    > Point left_point(4,12);
    > Point right_point(8, 12);
    > Triangle tri_bad(peak_bad, right_point_bad, left_point_bad);
        Output: Caught exception: Bad Triangle: Invalid triangle coordinates. Please ensure vertices form a valid triangle.

 Discussion:
 	Program focusing on two main constructors , Point and Shape. The shape constructor has 3 child functions that are inheriting from its base functions. The each shape requires minimum one
 	Point value, with the rectangle requiring 4.

 	Each child function, the inherited shapes, has a validity check to ensure the Point and other values enter meet the requirements for the child shape function (Circle, Rectangle, Triangle)
*/

#include <iostream>
#include <vector>
#include <cmath>

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

    static double distance(Point p1, Point p2) {
        // calculate the distance between points
        double x_val = p2.x - p1.x;
        double y_val = p2.y - p1.y;
        double dist = std::sqrt(x_val * x_val + y_val * y_val);

        return dist;
    }

    static double length(const Point p1, const Point p2)  {
        return std::round(std::sqrt(p1.x * p2.x + p1.y * p2.y));
    }

   void Show() {
       std::cout << "x and y are currently set at: (" << x << "," << y << ") \n";
    }

    void Add( double x_change = 0, double y_change = 0) {
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

    void Subtract( double x_change = 0, double y_change = 0) {
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
        std::cout << "\nArea: " << area() << endl;
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
        return {};
    };

    virtual double circumference() {
        return 0.0;
    };

    virtual double area() {
        return 0.0;

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
            throw std::invalid_argument("Value is not possible for a circle. Please enter a number greater than 0. \n");
        }
    }

    double area() {
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
    Point topLeft;
    Point topRight;
    Point bottomLeft;
    Point bottomRight;

public:
    Rectangle(Point topLeft, Point topRight, Point bottomLeft, Point bottomRight)
            : topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight) {
        if (isSquare()) {
            throw std::invalid_argument("Bad Rectangle: The sides are equal! This rectangle is a square.\n");
        } else if (!isValidRectangle()) {
            throw std::invalid_argument("Bad Rectangle: The values entered are not indicative of a rectangle.\nRemember, a rectangle must have parallel sides, and they all cannot be equal.\n");
        }
    }

    bool isValidRectangle() const {
        // Check if opposite sides are parallel, indicating a correct rectangle
        return (topLeft.getX() == bottomLeft.getX() && topRight.getX() == bottomRight.getX() &&
                topLeft.getY() == topRight.getY() && bottomLeft.getY() == bottomRight.getY());
    }

    bool isSquare() const {
        double width = Point::distance(topLeft, topRight);
        double height = Point::distance(topLeft, bottomLeft);

        return width == height;
    }

    double area() override {
        double width = Point::distance(topLeft, topRight);
        double height = Point::distance(topLeft, bottomLeft);
        return width * height;
    }

    double circumference() override {
        double width = Point::distance(topLeft, topRight);
        double height = Point::distance(topLeft, bottomLeft);
        return 2 * (width + height);
    }

    std::vector<Point> boundingBox() override {
        return {topLeft, topRight, bottomRight, bottomLeft};
    }
};


class Triangle : public Shape {
    // perimeter
private:
    Point peak;
    Point rightPoint;
    Point leftPoint;
public:
    Triangle(Point peak, Point rightPoint, Point leftPoint) : peak(peak), rightPoint(rightPoint), leftPoint(leftPoint) {
        if (!isValidTriangle(peak, rightPoint, leftPoint)) {
            throw std::invalid_argument("Bad Triangle: Invalid triangle coordinates. Please ensure vertices form a valid triangle.\n");
        };

    }


    double area() override {
        // Heron's formula for the area of a triangle
        double a = Point::distance(peak, rightPoint);
        double b = Point::distance(rightPoint, leftPoint);
        double c = Point::distance(leftPoint, peak);
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double circumference() override {
        // Sum of the distances of the sides
        return Point::distance(peak, rightPoint) + Point::distance(rightPoint, leftPoint) +
               Point::distance(leftPoint, peak);
    }

    bool isValidTriangle(Point p1, Point p2, Point p3) {
        double side1 = Point::distance(p1, p2);
        double side2 = Point::distance(p2, p3);
        double side3 = Point::distance(p3, p1);

        // Check for degenerate cases where the vertices are collinear
        if (side1 + side2 > side3 && side2 + side3 > side1 && side3 + side1 > side2) {
            return true;
        } else {
            return false;
        }
    }

    std::vector<Point> boundingBox() override {
        double minX = std::min({peak.getX(), rightPoint.getX(), leftPoint.getX()});
        double minY = std::min({peak.getY(), rightPoint.getY(), leftPoint.getY()});
        double maxX = std::max({peak.getX(), rightPoint.getX(), leftPoint.getX()});
        double maxY = std::max({peak.getY(), rightPoint.getY(), leftPoint.getY()});

        // Create points for the bounding box
        Point topLeft(minX, minY);
        Point topRight(maxX, minY);
        Point bottomLeft(minX, maxY);
        Point bottomRight(maxX, maxY);

        // Return the vector of points representing the bounding box
        return {topLeft, topRight, bottomRight, bottomLeft};
    }
};





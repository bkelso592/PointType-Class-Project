#include <iostream>
#include <cmath>  // For sqrt() and pow() functions

// Template class to handle both integer and floating-point coordinates
template <typename T>
class PointType {
private:
    T x, y;  // Private member variables to store x and y coordinates

public:
    // Default constructor - initializes point at (0, 0)
    PointType() : x(0), y(0) {}

    // Parameterized constructor - initializes point at (x, y)
    PointType(T xCoord, T yCoord) : x(xCoord), y(yCoord) {}

    // Setter for x coordinate
    void setX(T value) {
        x = value;
    }

    // Setter for y coordinate
    void setY(T value) {
        y = value;
    }

    // Getter for x coordinate
    T getX() const {
        return x;
    }

    // Getter for y coordinate
    T getY() const {
        return y;
    }

    // Function to calculate the distance between this point and another point
    double distance(const PointType<T>& p) const {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }

    // Overloaded subtraction operator to calculate distance between two points
    double operator-(const PointType<T>& p) const {
        return distance(p);
    }

    // Function to display point coordinates
    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// Main function to demonstrate the PointType class functionality
int main() {
    // Create two PointType objects with integer coordinates
    PointType<int> p1(3, 4);
    PointType<int> p2(0, 0);

    // Display the points
    std::cout << "Point 1: ";
    p1.display();
    std::cout << "Point 2: ";
    p2.display();

    // Calculate and display the distance between p1 and p2 using the overloaded subtraction operator
    std::cout << "Distance between p1 and p2: " << p1 - p2 << std::endl;

    // Create two PointType objects with floating-point coordinates
    PointType<double> p3(1.5, 2.5);
    PointType<double> p4(4.0, 6.0);

    // Display the points
    std::cout << "Point 3: ";
    p3.display();
    std::cout << "Point 4: ";
    p4.display();

    // Calculate and display the distance between p3 and p4 using the overloaded subtraction operator
    std::cout << "Distance between p3 and p4: " << p3 - p4 << std::endl;

    return 0;
}
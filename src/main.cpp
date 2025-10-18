#include "include/array.h"
#include "include/point.h"
#include "include/rectangle.h"
#include "include/square.h"
#include "include/trapezoid.h"

int main() {
    Square square({0, 0}, {2, 0}, {2, 2}, {0, 2});
    Rectangle rectangle({0, 0}, {3, 0}, {3, 2}, {0, 2});
    Trapezoid trapezoid({0, 0}, {4, 0}, {3, 2}, {1, 2});

    std::cout << "Square: ";
    square.print(std::cout);
    std::cout << "Center: (" << square.getCenter().x << ", " << square.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(square) << std::endl;

    std::cout << "Rectangle: ";
    rectangle.print(std::cout);
    std::cout << "Center: (" << rectangle.getCenter().x << ", " << rectangle.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(rectangle) << std::endl;

    std::cout << "Trapezoid: ";
    trapezoid.print(std::cout);
    std::cout << "Center: (" << trapezoid.getCenter().x << ", " << trapezoid.getCenter().y << ") ";
    std::cout << "Area: " << static_cast<double>(trapezoid) << std::endl << std::endl;

    Array arr(3);
    arr.addFigure(new Square(square));
    arr.addFigure(new Rectangle(rectangle));
    arr.addFigure(new Trapezoid(trapezoid));

    arr.printFigures();

    std::cout << "Total area: " << arr.getAllArea() << std::endl;

    Figure* figure = arr[1];
    std::cout << "Figure at index 1: ";
    figure->print(std::cout);
    std::cout << "Area: " << static_cast<double>(*figure) << std::endl;

    return 0;
}

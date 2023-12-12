#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point& createPoint()
{
    Point point;

    std::cout << "\n<<<Create Point>>>\n";
    std::cout << "\nInput X coordinate (-100...100): ";
    std::cin >> point.x;

    while (std::cin.fail() || point.x > 100 || point.x < -100)
    {
      std::cin.clear();
      std::cin.ignore(32767, '\n');

      std::cout << "\nIndex is incorrect! Input correct index.\n";
      std::cin >> point.x;
    }

    std::cout << "\nInput Y coordinate (-100...100): ";
    std::cin >> point.y;

    while (std::cin.fail() || point.y > 100 || point.y < -100)
    {
      std::cin.clear();
      std::cin.ignore(32767, '\n');

      std::cout << "\nIndex is incorrect! Input correct index.\n";
      std::cin >> point.x;
    }

    return point;
}

double fractionOfOne(double coordinate) { return coordinate / 100; }
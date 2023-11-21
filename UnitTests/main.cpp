#include "../TraineeTask/Polyline.h"
#include "../TraineeTask/Polyline.cpp"
#include "../TraineeTask/Circle.h"
#include "../TraineeTask/Circle.cpp"
#include "../TraineeTask/Rectangle.h"
#include "../TraineeTask/Rectangle.cpp"
#include "../TraineeTask/Triangle.h"
#include "../TraineeTask/Triangle.cpp"
#include "../TraineeTask/Point.h"
#include "../TraineeTask/Point.cpp"
#include "../TraineeTask/Color.h"
#include "../TraineeTask/Color.cpp"
#include "../TraineeTask/BaseObject.h"
#include "../TraineeTask/BaseObject.cpp"
#include "../TraineeTask/BoundingBox.h"
#include "../TraineeTask/BoundingBox.cpp"

void TestPolyline()
{
  PolylinePtr pPolyline_1(new Polyline(Point(0, 0)));
  pPolyline_1->addPoint(Point(1, 2));
  pPolyline_1->addPoint(Point(3, 5));
  pPolyline_1->addPoint(Point(7, 1));

  PolylinePtr pPolyline_2(new Polyline(Point(9, 3)));
  pPolyline_2->addPoint(Point(1, -5));
  pPolyline_2->addPoint(Point(3, 0));
  
  { //testing point initialization
    Point testPoint(3, 5);
    Point originalPoint_1 = pPolyline_1->getpointArray()[2];

    if (originalPoint_1.x != testPoint.x || originalPoint_1.y != testPoint.y)
      std::cout << "Invalid point: original point " << "x: " << testPoint.x << " y: " << testPoint.y << " != testing point "
      << "x: " << originalPoint_1.x << " y: " << originalPoint_1.y << "\n";
    else
      std::cout << "Point is correct!\n";

    Point originalPoint_2 = pPolyline_2->getpointArray()[2];

    if (originalPoint_2.x != testPoint.x || originalPoint_2.y != testPoint.y)
      std::cout << "Point is correct!\n";
    else
      std::cout << "Invalid point: original point " << "x: " << testPoint.x << " y: " << testPoint.y << " != testing point "
      << "x: " << originalPoint_2.x << " y: " << originalPoint_2.y << "\n";
  }

  { //testing IsValid method
    std::vector<Point> aPoints;
    pPolyline_2->setPointArray(aPoints);

    if (pPolyline_1->isValid())
      std::cout << "IsValid flag is correct!\n";

    if (pPolyline_2->isValid())
      std::cout << "Invalid IsValid flag. Points array is empty! \n";
    else
      std::cout << "IsValid flag is correct!\n";
  }

  { //testing getCenter method
    Point* center_1(pPolyline_1->getCenter());
    Point* center_2 = pPolyline_2->getCenter();

    if(center_1->x != 3.5 || center_1->y != 2.5)
      std::cout << "Invalid center: original center " << "x: " << center_1->x << " y: " << center_1->y << " != testing center "
      << "x: " << 3.5 << " y: " << 2.5 << "\n";
    else
      std::cout << "Center is correct!\n";
  }
}

void TestColor()
{
  BaseObjPtr triangle(new Triangle);

  Color color(128, 200, 30);

  triangle->setColor(color);

  uint8_t red = triangle->getColor().getRed();
  uint8_t green = triangle->getColor().getGreen();
  uint8_t blue = triangle->getColor().getBlue();

  if (red != 128 || green != 200 || blue != 30)
    std::cout << "Invalid color: original: red - " << color.getRed() << ", " <<
    "green - " << color.getGreen() << ", " << "blue - " << color.getBlue() << "\n";
  else
    std::cout << "Color is correct!\n";
}

void TestBoundingBoxes()
{
  Circle circle(Point(0, 8), 8);
  Rect rectangle(Point(0, 0), Point(0, 4), Point(4, 4), Point(4, 0));
  Triangle triangle(Point(0, 0), Point(4, 5), Point(5, 0));
  Polyline polyline(Point(0, 8));
  polyline.addPoint(Point(2, 5));
  polyline.addPoint(Point(7, 1));
  
  BoundingBox circleBoundingBox = circle.boundingBox();
  BoundingBox rectangleBoundingBox = rectangle.boundingBox();
  BoundingBox triangleBoundingBox = triangle.boundingBox();
  BoundingBox polylineBoundingBox = polyline.boundingBox();
  
  if (circleBoundingBox.getMinPoint().x != -8 || circleBoundingBox.getMinPoint().y != 0 && 
    circleBoundingBox.getMaxPoint().x != 8 || circleBoundingBox.getMaxPoint().y != 16)
    std::cout << "Invalid circle bounding box: original bounding box min point - (" << circleBoundingBox.getMinPoint().x <<
    "," << circleBoundingBox.getMinPoint().y << "), max point - (" << circleBoundingBox.getMaxPoint().x << "," << 
    circleBoundingBox.getMaxPoint().y << ") != test points (" << -8 << "," << 0 << "), (" << 8 << "," << 16 << ")\n";
  else
    std::cout << "Correct circle bounding box!\n";
  
  if (rectangleBoundingBox.getMinPoint().x != 0 || rectangleBoundingBox.getMinPoint().y != 0 &&
    rectangleBoundingBox.getMaxPoint().x != 4 || rectangleBoundingBox.getMaxPoint().y != 4)
    std::cout << "Invalid rectangle bounding box: original bounding box min point - (" << rectangleBoundingBox.getMinPoint().x <<
    "," << rectangleBoundingBox.getMinPoint().y << "), max point - (" << rectangleBoundingBox.getMaxPoint().x << "," <<
    rectangleBoundingBox.getMaxPoint().y << ") != test points (" << 0 << "," << 0 << "), (" << 4 << "," << 4 << ")\n";
  else
    std::cout << "Correct rectangle bounding box!\n";
  
  if (triangleBoundingBox.getMinPoint().x != 0 || triangleBoundingBox.getMinPoint().y != 0 &&
    triangleBoundingBox.getMaxPoint().x != 5 || triangleBoundingBox.getMaxPoint().y != 5)
    std::cout << "Invalid triangle bounding box: original bounding box min point - (" << triangleBoundingBox.getMinPoint().x <<
    "," << triangleBoundingBox.getMinPoint().y << "), max point - (" << triangleBoundingBox.getMaxPoint().x << "," <<
    triangleBoundingBox.getMaxPoint().y << ") != test points (" << 0 << "," << 0 << "), (" << 5 << "," << 5 << ")\n";
  else
    std::cout << "Correct triangle bounding box!\n";
  
  if (polylineBoundingBox.getMinPoint().x != 0 || polylineBoundingBox.getMinPoint().y != 1 &&
    polylineBoundingBox.getMaxPoint().x != 7 || polylineBoundingBox.getMaxPoint().y != 8)
    std::cout << "Invalid polyline bounding box: original bounding box min point - (" << polylineBoundingBox.getMinPoint().x <<
    "," << polylineBoundingBox.getMinPoint().y << "), max point - (" << polylineBoundingBox.getMaxPoint().x << "," <<
    polylineBoundingBox.getMaxPoint().y << ") != test points (" << 0 << "," << 1 << "), (" << 7 << "," << 8 << ")\n";
  else
    std::cout << "Correct polyline bounding box!\n";
}

void TestOrientedBoundingBoxes()
{
  Rect rectangle(Point(2, 0), Point(0, 2), Point(2, 4), Point(4, 2));
  Triangle triangle(Point(3, 2), Point(4, 5), Point(5, 0));
  Polyline polyline(Point(0, 8));
  polyline.addPoint(Point(2, 5));
  polyline.addPoint(Point(7, 1));

  BoundingBox rectangleBoundingBox = rectangle.boundingBox();
  BoundingBox triangleBoundingBox = triangle.boundingBox();
  BoundingBox polylineBoundingBox = polyline.boundingBox();

  int orientation_1 = rectangleBoundingBox.calculateOrientation();
  int orientation_2 = triangleBoundingBox.calculateOrientation();
  int orientation_3 = polylineBoundingBox.calculateOrientation();

  if (orientation_1 != 45)
    std::cout << "Invalid rectangle oriented bounding box: original oriented - " << orientation_1 << 
    "!= " << "test oriented " << 45 << "degrees\n";
  else
    std::cout << "Correct rectangle oriented bounding box!\n";

  if (orientation_2 != 68)
    std::cout << "Invalid triangle oriented bounding box: original oriented - " << orientation_2 <<
    "!= " << "test oriented " << 68 << "degrees\n";
  else
    std::cout << "Correct triangle oriented bounding box!\n";

  if (orientation_3 != 45)
    std::cout << "Invalid polyline oriented bounding box: original oriented - " << orientation_3 <<
    "!= " << "test oriented " << 45 << "degrees\n";
  else
    std::cout << "Correct polyline oriented bounding box!\n";
}

int main()
{
  std::cout << "\n<<<POLYLINE CLASS TEST>>>\n\n";
  TestPolyline();

  std::cout << "\n<<<COLOR CLASS TEST>>>\n\n";
  TestColor();

  std::cout << "\n<<<BOUNDING BOXES TEST>>>\n\n";
  TestBoundingBoxes();

  std::cout << "\n<<<ORIENTED BOUNDING BOXES TEST>>>\n\n";
  TestOrientedBoundingBoxes();

  return 0;
}
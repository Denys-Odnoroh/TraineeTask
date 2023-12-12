#include "Drawer.h"

Point midpoint(const Point& p1, const Point& p2) 
{
  return { (p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0 };
}

Point findCircumcenter(const Point& A, const Point& B, const Point& C) 
{
  Point midAB = midpoint(A, B);
  Point midBC = midpoint(B, C);

  double slopeAB = -(B.x - A.x) / (B.y - A.y);
  double slopeBC = -(C.x - B.x) / (C.y - B.y);

  double cx = (slopeAB * midAB.x - slopeBC * midBC.x + midBC.y - midAB.y) / (slopeAB - slopeBC);
  double cy = slopeAB * (cx - midAB.x) + midAB.y;

  Point circumcenter = { cx, cy };
  return circumcenter;
}

void Drawer::drawTriangle(const Color color)
{
  BaseObject* pTriangle = Factory::factory(TriangleObject);
  BaseObjPtr ptrTriangle = pTriangle;
  Point point_1, point_2, point_3;
  float r, g, b;
  
  static_cast<Triangle*>(ptrTriangle.get())->set(createPoint(), createPoint(), createPoint());
  BoundingBox boundingBox = ptrTriangle->boundingBox();

  point_1 = static_cast<Rect*>(ptrTriangle.get())->getPoint1();
  point_2 = static_cast<Rect*>(ptrTriangle.get())->getPoint2();
  point_3 = static_cast<Rect*>(ptrTriangle.get())->getPoint3();

  if (ptrTriangle->isValid())
  {
    glBegin(GL_LINE_LOOP);

    r = color.getRed() * COLOR_COEFFICIENT;
    g = color.getGreen() * COLOR_COEFFICIENT;
    b = color.getBlue() * COLOR_COEFFICIENT;
    glColor3f(r, g, b);

    glVertex2d(fractionOfOne(point_1.x), fractionOfOne(point_1.y));
    glVertex2d(fractionOfOne(point_2.x), fractionOfOne(point_2.y));
    glVertex2d(fractionOfOne(point_3.x), fractionOfOne(point_3.y));

    glEnd();

    boundingBox.drawBoundingBox();

    system("cls");
    std::cout << "Triangle drawn.\n";
  }
  else
  {
    system("cls");
    std::cout << "\nTriangle in not valid!\n";
  }
}

void Drawer::drawCirce(const Color color)
{
  BaseObject* pCircle = Factory::factory(CircleObject);
  BaseObjPtr ptrCircle = pCircle;
  Point *point;
  float r, g, b;

  static_cast<Circle*>(ptrCircle.get())->set(createPoint(), inputCircleRadius());
  point = static_cast<Circle*>(ptrCircle.get())->getCenter();
  float radius = static_cast<Circle*>(ptrCircle.get())->getRadius();
  BoundingBox boundingBox = ptrCircle->boundingBox();

  if (ptrCircle->isValid())
  {
    glBegin(GL_LINE_LOOP);

    r = color.getRed() * COLOR_COEFFICIENT;
    g = color.getGreen() * COLOR_COEFFICIENT;
    b = color.getBlue() * COLOR_COEFFICIENT;
    glColor3f(r, g, b);

    for (int i = 0; i < 50; i++)
    {
      double x = fractionOfOne(radius) * sin(2 * M_PI * i / 50);
      double y = fractionOfOne(radius) * cos(2 * M_PI * i / 50);
      glVertex2f(fractionOfOne(point->x) + x, fractionOfOne(point->y) + y);
    }

    glEnd();

    boundingBox.drawBoundingBox();

    system("cls");
    std::cout << "Circle drawn.\n";
  }
  else
  {
    system("cls");
    std::cout << "\nCircle in not valid!\n";
  }
}

void Drawer::drawRectangle(const Color color)
{
  BaseObject* pRect = Factory::factory(RectangleObject);
  BaseObjPtr ptrRect = pRect;
  Point point_1, point_2, point_3, point_4;
  float r, g, b;

  static_cast<Rect*>(ptrRect.get())->set(createPoint(), createPoint(), createPoint(), createPoint());
  BoundingBox boundingBox = ptrRect->boundingBox();

  point_1 = static_cast<Rect*>(ptrRect.get())->getPoint1();
  point_2 = static_cast<Rect*>(ptrRect.get())->getPoint2();
  point_3 = static_cast<Rect*>(ptrRect.get())->getPoint3();
  point_4 = static_cast<Rect*>(ptrRect.get())->getPoint4();

  if (ptrRect->isValid())
  {
    glBegin(GL_LINE_LOOP);

    r = color.getRed() * COLOR_COEFFICIENT;
    g = color.getGreen() * COLOR_COEFFICIENT;
    b = color.getBlue() * COLOR_COEFFICIENT;
    glColor3f(r, g, b);

    glVertex2d(fractionOfOne(point_1.x), fractionOfOne(point_1.y));
    glVertex2d(fractionOfOne(point_2.x), fractionOfOne(point_2.y));
    glVertex2d(fractionOfOne(point_3.x), fractionOfOne(point_3.y));
    glVertex2d(fractionOfOne(point_4.x), fractionOfOne(point_4.y));
    glEnd();

    boundingBox.drawBoundingBox();

    system("cls");
    std::cout << "Rectangle drawn.\n";
  }
  else
  {
    system("cls");
    std::cout << "\nRectangle in not valid!\n";
  }
}

void Drawer::drawPolyline(const Color color)
{
  BaseObject* pPolyline = Factory::factory(PolylineObject);
  BaseObjPtr ptrPolyline = pPolyline;
  Point point;
  bool iAddPointFlag = true;
  float r, g, b;

  while (iAddPointFlag)
  {
    int iChooseIndex;
    std::cout << "Add a point?\n1.Yes.\n2.No.\n";
    std::cin >> iChooseIndex;

    if (iChooseIndex == 1)
    {
      std::vector<Point> aPoints = static_cast<Polyline*>(ptrPolyline.get())->getpointArray();
      Point point = createPoint();
      aPoints.push_back(point);
      static_cast<Polyline*>(ptrPolyline.get())->setPointArray(aPoints);
    }
    else if (iChooseIndex == 2)
      iAddPointFlag = false;
  }

  int iPointsCount = static_cast<Polyline*>(ptrPolyline.get())->getpointArray().size();
  BoundingBox boundingBox = ptrPolyline->boundingBox();

  if (ptrPolyline->isValid())
  {
    glBegin(GL_LINE_STRIP);

    r = color.getRed() * COLOR_COEFFICIENT;
    g = color.getGreen() * COLOR_COEFFICIENT;
    b = color.getBlue() * COLOR_COEFFICIENT;
    glColor3f(r, g, b);

    for (int i = 0; i < iPointsCount; ++i)
    {
      point = static_cast<Polyline*>(ptrPolyline.get())->getpointArray().at(i);
      glVertex2d(fractionOfOne(point.x), fractionOfOne(point.y));
    }

    glEnd();

    boundingBox.drawBoundingBox();

    system("cls");
    std::cout << "Polyline drawn.\n";
  }
  else
  {
    system("cls");
    std::cout << "\nPolyline in not valid!\n";
  }
}

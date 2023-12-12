#include "Triangle.h"

Triangle::Triangle() : m_point_1(0, 0), m_point_2(0, 0), m_point_3(0, 0) {}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
  this->m_point_1 = p1;
  this->m_point_2 = p2;
  this->m_point_3 = p3;
}

BoundingBox Triangle::boundingBox()
{
  Point min(m_point_1);
  Point max(m_point_1);

  for (int i = 0; i < 2; i++)
  {
    Point p;
    if (i == 0)
      p = m_point_2;
    else
      p = m_point_3;

    if (p.x < min.x)
      min.x = p.x;

    if (p.x > max.x)
      max.x = p.x;

    if (p.y < min.y)
      min.y = p.y;

    if (p.y > max.y)
      max.y = p.y;

  }
  BoundingBox boundingBox(min, max);

  return boundingBox;
}

void Triangle::set(const Point p1, const Point p2, const Point p3)
{
  this->m_point_1 = p1;
  this->m_point_2 = p2;
  this->m_point_3 = p3;
}

Point* Triangle::getCenter()
{
  Point center((m_point_1.x + m_point_2.x + m_point_3.x) / 3, (m_point_1.y + m_point_2.y + m_point_3.y) / 3);
  return &center;
}

bool Triangle::isValid()
{
  if((m_point_1.x != m_point_2.x || m_point_1.y != m_point_2.y)
    && (m_point_2.x != m_point_3.x || m_point_2.y != m_point_3.y)
    && (m_point_3.x != m_point_1.x || m_point_3.y != m_point_1.y))
    return true;
  else
    return false;
}

Point Triangle::getPoint1() const
{
  return this->m_point_1;
}

Point Triangle::getPoint2() const
{
  return this->m_point_2;
}

Point Triangle::getPoint3() const
{
  return this->m_point_3;
}

/*In this method, calculated the midpoints of two sides, 
then calculated the angle coefficients of the perpendiculars to the sides,
then found the coordinates of the circle center.*/
Point Triangle::getCircumcircleCenter() const
{
  Point midSide_1((m_point_1.x + m_point_2.x) / 2.0, (m_point_1.y + m_point_2.y) / 2.0);
  Point midSide_2((m_point_2.x + m_point_3.x) / 2.0, (m_point_2.y + m_point_3.y) / 2.0);

  double slopeSide_1 = (m_point_2.y - m_point_1.y) / (m_point_2.x - m_point_1.x);
  double slopeSide_2 = (m_point_3.y - m_point_2.y) / (m_point_3.x - m_point_2.x);

  double cx = (midSide_1.y - midSide_2.y + slopeSide_1 * midSide_1.x - slopeSide_2 * midSide_2.x) / (slopeSide_1 - slopeSide_2);
  double cy = slopeSide_1 * (cx - midSide_1.x) + midSide_1.y;

  Point circleCenter(cx, cy);
  return circleCenter;
}

double Triangle::getLength() const
{
  double length;

  Point vector—ordinates(m_point_2.x - m_point_1.x, m_point_2.y - m_point_1.y);
  length = (sqrt(pow(vector—ordinates.x, 2) + pow(vector—ordinates.y, 2)));

  return length;
}

double Triangle::getHeight() const
{
  double height;
  double semiperimeter;
  double vectorLength_1, vectorLength_2, vectorLength_3;

  Point vector_1—ordinates(m_point_2.x - m_point_1.x, m_point_2.y - m_point_1.y);
  Point vector_2—ordinates(m_point_3.x - m_point_2.x, m_point_3.y - m_point_2.y);
  Point vector_3—ordinates(m_point_1.x - m_point_3.x, m_point_1.y - m_point_3.y);

  vectorLength_1 = sqrt(pow(vector_1—ordinates.x, 2) + pow(vector_1—ordinates.y, 2));
  vectorLength_2 = sqrt(pow(vector_2—ordinates.x, 2) + pow(vector_2—ordinates.y, 2));
  vectorLength_3 = sqrt(pow(vector_3—ordinates.x, 2) + pow(vector_3—ordinates.y, 2));

  semiperimeter = (vectorLength_1 + vectorLength_2 + vectorLength_3) / 2;

  height = 2 / vectorLength_1 * 
    sqrt(semiperimeter * (semiperimeter - vectorLength_1) * (semiperimeter - vectorLength_2) * (semiperimeter - vectorLength_3));

  return height;
}
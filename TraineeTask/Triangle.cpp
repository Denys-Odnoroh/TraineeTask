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
  if(m_point_1.x != m_point_2.x && m_point_1.y != m_point_2.y
    && m_point_2.x != m_point_3.x && m_point_2.y != m_point_3.y
    && m_point_3.x != m_point_1.x && m_point_3.y != m_point_1.y)
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
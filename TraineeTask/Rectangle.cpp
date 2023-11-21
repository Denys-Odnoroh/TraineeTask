#include "Rectangle.h"

Rect::Rect() : m_point_1(0, 0), m_point_2(0, 0), m_point_3(0, 0), m_point_4(0, 0) {}

Rect::Rect(Point p1, Point p2, Point p3, Point p4)
{
  this->m_point_1 = p1;
  this->m_point_2 = p2;
  this->m_point_3 = p3;
  this->m_point_4 = p4;
}

BoundingBox Rect::boundingBox()
{
  Point min(m_point_1);
  Point max(m_point_1);

  for (int i = 0; i < 3; i++)
  {
    Point p;
    if (i == 0)
      p = m_point_2;
    else if (i == 1)
      p = m_point_3;
    else
      p = m_point_4;

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

void Rect::set(const Point p1, const Point p3)
{
  this->m_point_1 = p1;
  this->m_point_3 = p3;
}

void Rect::set(const Point p1, const Point p2, const Point p3, const Point p4)
{
  this->m_point_1 = p1;
  this->m_point_2 = p2;
  this->m_point_3 = p3;
  this->m_point_4 = p4;
}

Point* Rect::getCenter()
{
  Point center(m_point_1.x + ((m_point_3.x - m_point_1.x) / 2), m_point_1.y + ((m_point_3.y - m_point_1.y) / 2));
  return &center;
}

bool Rect::isValid()
{
  double height_1, height_2;
  double width_1, width_2;

  Point vector_1Ñordinates(m_point_2.x - m_point_1.x, m_point_2.y - m_point_1.y);
  Point vector_2Ñordinates(m_point_4.x - m_point_3.x, m_point_4.y - m_point_3.y);
  Point vector_3Ñordinates(m_point_4.x - m_point_1.x, m_point_4.y - m_point_1.y);
  Point vector_4Ñordinates(m_point_3.x - m_point_2.x, m_point_3.y - m_point_2.y);

  height_1 = (sqrt(pow(vector_1Ñordinates.x, 2) + pow(vector_1Ñordinates.y, 2)));
  height_2 = (sqrt(pow(vector_2Ñordinates.x, 2) + pow(vector_2Ñordinates.y, 2)));
  width_1  = (sqrt(pow(vector_3Ñordinates.x, 2) + pow(vector_3Ñordinates.y, 2)));
  width_2  = (sqrt(pow(vector_4Ñordinates.x, 2) + pow(vector_4Ñordinates.y, 2)));

  if (height_1 == height_2 && width_1 == width_2)
  {
    return true;
  }
  else return false;
}

Point Rect::getPoint1() const
{
  return this->m_point_1;
}

Point Rect::getPoint2() const
{
  return this->m_point_2;
}

Point Rect::getPoint3() const
{
  return this->m_point_3;
}

Point Rect::getPoint4() const
{
  return this->m_point_4;
}

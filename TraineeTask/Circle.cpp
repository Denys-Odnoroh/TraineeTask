#include "Circle.h"

Circle::Circle() : m_point_1(0, 0), m_fRadius(0) {}

Circle::Circle(Point p, float radius) : m_point_1(p), m_fRadius(radius) {}

BoundingBox Circle::boundingBox()
{
  Point min(m_point_1.x - this->m_fRadius, m_point_1.y - this->m_fRadius);
  Point max(m_point_1.x + this->m_fRadius, m_point_1.y + this->m_fRadius);

  BoundingBox boundingBox(min, max);

  return boundingBox;
}

Point* Circle::getCenter()
{
  return &m_point_1;
}

void Circle::set(const Point m_point_1)
{
  this->m_point_1 = m_point_1;
}

void Circle::set(const Point m_point_1, const float radius)
{
  this->m_point_1 = m_point_1;
  try
  {
    if (radius > 0)
      this->m_fRadius = radius;
    else
      throw -1;
  }
  catch (int e)
  {
    std::cout << "Incorrect radius input.";
  }
}

bool Circle::isValid()
{
  if (this->m_fRadius <= 0)
    return false;
  else return true;
}

float Circle::getRadius() const
{
  return this->m_fRadius;
}

float inputCircleRadius()
{
  float dRadius;

  std::cout << "Input radius (0.1...100): ";
  std::cin >> dRadius;

  while (std::cin.fail() || dRadius > 100 || dRadius < 0.1)
  {
    std::cin.clear();
    std::cin.ignore(32767, '\n');

    std::cout << "\nIndex is incorrect! Input correct index.\n";
    std::cin >> dRadius;
  }

  return dRadius;
}

#include "BoundingBox.h"

BoundingBox::BoundingBox() : m_minPoint(0, 0), m_maxPoint(0, 0), m_dOrientation(0) {}

BoundingBox::BoundingBox(Point minPoint, Point maxPoint)
{
  m_minPoint = minPoint; 
  m_maxPoint = maxPoint;
  m_dOrientation = 0;
}

void BoundingBox::setBoundingBox(Point minPoint, Point maxPoint)
{
  m_minPoint = minPoint;
  m_maxPoint = maxPoint;
}

Point BoundingBox::getMinPoint() const
{
  return m_minPoint;
}

Point BoundingBox::getMaxPoint() const
{
  return m_maxPoint;
}

double BoundingBox::getOrientation() const
{
  return m_dOrientation;
}

double BoundingBox::calculateOrientation(const Point p1, const Point p2, const Point p3, const Point p4)
{
  double edge1 = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

  double rad = acos((p2.x - p1.x) / edge1);
  double degrees = (180.0 / M_PI) * rad;

  return degrees;
}

double BoundingBox::calculateOrientation() const
{
  double diagonalX = m_maxPoint.x - m_minPoint.x;
  double diagonalY = m_maxPoint.y - m_minPoint.y;

  double orientation = atan2(diagonalY, diagonalX);

  orientation = (180.0 / M_PI) * orientation;

  return orientation;
}

void BoundingBox::setOrientation(const double orientation)
{
  m_dOrientation = orientation;
}

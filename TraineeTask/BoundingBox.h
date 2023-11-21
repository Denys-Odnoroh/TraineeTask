#pragma once

#include "Point.h"
#include <cmath>
#include <corecrt_math_defines.h>

class BoundingBox
{
public:
  BoundingBox();
  BoundingBox(Point minPoint, Point maxPoint);
  ~BoundingBox() {}

  static double calculateOrientation(const Point p1, const Point p2, const Point p3, const Point p4);
  double calculateOrientation() const;
  void setOrientation(const double orientation);
  void setBoundingBox(Point minPoint, Point maxPoint);
  Point getMinPoint() const;
  Point getMaxPoint() const;
  double getOrientation() const;

private:
  double m_dOrientation;
  Point m_minPoint;
  Point m_maxPoint;
};

#pragma once

#include <GLFW/glfw3.h>
#include <cmath>
#include "Point.h"

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
  void drawOrientedBoundingBox(float centerX, float centerY, float width, float height, float rotationAngle);
  void drawBoundingBox();
  Point getMinPoint() const;
  Point getMaxPoint() const;
  double getOrientation() const;

private:
  double m_dOrientation;
  Point m_minPoint;
  Point m_maxPoint;
};

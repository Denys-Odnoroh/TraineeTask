#pragma once

#include "BaseObject.h"

class Triangle : public BaseObject
{
private:
  Point m_point_1;
  Point m_point_2;
  Point m_point_3;

public:
  Triangle();
  Triangle(Point p1, Point p2, Point p3);
  virtual ~Triangle() override {};

  virtual BoundingBox boundingBox() override;
  virtual Point* getCenter() override;
  virtual bool isValid() override;

  Point getPoint1() const;
  Point getPoint2() const;
  Point getPoint3() const;

  void set(const Point p1, const  Point p2, const  Point p3);
};

typedef SmartPtr<Triangle> TrianglePtr;
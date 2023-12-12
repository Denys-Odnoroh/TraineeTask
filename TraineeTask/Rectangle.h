#pragma once

#include "BaseObject.h"
#include <math.h>

class Rect : public BaseObject
{
private:
  Point m_point_1;
  Point m_point_2;
  Point m_point_3;
  Point m_point_4;

public:
  Rect();
  Rect(Point p1, Point p2, Point p3, Point p4);
  virtual ~Rect() override {};

  virtual BoundingBox boundingBox() override;
  virtual Point* getCenter() override;
  virtual bool isValid() override;

  Point getPoint1() const;
  Point getPoint2() const;
  Point getPoint3() const;
  Point getPoint4() const;
  double calculeteLength();
  double calculeteWidth();

  void set(const Point p1,const Point p2, const Point p3, const Point p4);
  void set(const Point p1,const Point p3);
};

typedef SmartPtr<Rect> RectanglePtr;
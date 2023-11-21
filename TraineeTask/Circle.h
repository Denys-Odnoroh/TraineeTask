#pragma once

#include "BaseObject.h"

class Circle : public BaseObject
{
private:
  Point m_point_1;
  float m_fRadius;

public:
  Circle();
  Circle(Point point, float radius);
  virtual ~Circle() override {}

  virtual BoundingBox boundingBox() override;
  virtual Point* getCenter() override;
  virtual bool isValid() override;

  float getRadius() const;

  void set(const Point p1);
  void set(const Point p1, const float radius);
};

typedef SmartPtr<Circle> CirclePtr;
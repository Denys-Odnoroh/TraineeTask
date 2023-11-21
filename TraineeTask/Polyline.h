#pragma once

#include <vector>
#include "BaseObject.h"

class Polyline : public BaseObject
{
public:
  Polyline() {};
  Polyline(Point point);
  virtual ~Polyline() override {};

  virtual Point* getCenter() override;
  virtual BoundingBox boundingBox() override;
  virtual bool isValid() override;

  std::vector<Point> getpointArray() const;
  void setPointArray(const std::vector<Point> aPoints);
  void addPoint(const Point point);

private:
  std::vector<Point> m_pointArray;
};

typedef SmartPtr<Polyline> PolylinePtr;
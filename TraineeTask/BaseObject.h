#pragma once

#include "Point.h"
#include "BoundingBox.h"
#include "SmartPtr.h"
#include "Color.h"

class BaseObject
{
public:
  BaseObject() {};
  virtual ~BaseObject();

  virtual Point* getCenter() = 0;
  virtual BoundingBox boundingBox() = 0;
  virtual bool isValid() = 0;

  Color getColor() const;
  void setColor(const Color color);

protected:
  Point* m_pCenter;

private:
  Color m_color;
};

typedef SmartPtr<BaseObject> BaseObjPtr;

enum createdObjects 
{
  RectangleObject,
  CircleObject,
  TriangleObject,
  PolylineObject,
};

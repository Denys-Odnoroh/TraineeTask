#include "Factory.h"

BaseObject* Factory::factory(createdObjects objectType)
{
  BaseObject* base;

  switch (objectType)
  {
  case RectangleObject:
  {
    base = new Rect();
    return base;
  }
  case CircleObject:
  {
    base = new Circle();
    return base;
  }
  case TriangleObject:
  {
    base = new Triangle();
    return base;
  }
  case PolylineObject:
  {
    base = new Polyline(createPoint(), createPoint());
    return base;
  }
  }
  return nullptr;
}

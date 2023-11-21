#pragma once

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "SmartPtr.h"

class Factory
{
public:
	Factory() {};
	~Factory() {};
  static BaseObject* factory(createdObjects objectType);
};
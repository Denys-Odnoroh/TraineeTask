#pragma once
#include <iostream>
#include <corecrt_math_defines.h>

struct Point
{
  double x;
  double y;

  Point();
  Point(double x, double y);
};

Point& createPoint();
double fractionOfOne(double coordinate);
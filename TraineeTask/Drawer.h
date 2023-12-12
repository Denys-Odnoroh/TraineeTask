#pragma once

#include "Factory.h"
#include "Point.h"

class Drawer
{
public: 
  static void drawTriangle(const Color color);
  static void drawCirce(const Color color);
  static void drawRectangle(const Color color);
  static void drawPolyline(const Color color);
};
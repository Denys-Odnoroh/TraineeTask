#pragma once

#define COLOR_COEFFICIENT 0.003921568627451;

#include <cstdint>

class Color
{
public:
  Color();
  Color(const uint8_t r, const uint8_t g, const uint8_t b);
  ~Color() {};
  void setColor(const uint8_t r, const uint8_t g, const uint8_t b);
  uint8_t getRed() const;
  uint8_t getGreen() const;
  uint8_t getBlue() const;
  unsigned int getColor() const;

private:
  unsigned int m_color;
};


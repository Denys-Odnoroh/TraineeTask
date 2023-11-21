#include "Color.h"

Color::Color()
{
  m_color = 0;
}

Color::Color(const uint8_t r, const uint8_t g, const uint8_t b)
{
  this->setColor(r, g, b);
}

void Color::setColor(const uint8_t red, const uint8_t green, const uint8_t blue)
{
  this->m_color = red;
  this->m_color = m_color << 8;
  this->m_color |= green;
  this->m_color = m_color << 8;
  this->m_color |= blue;
}

uint8_t Color::getRed() const
{
  return (m_color >> 16) & 0xff;
}

uint8_t Color::getGreen() const
{
  return (m_color >> 8) & 0xff;
}

uint8_t Color::getBlue() const
{
  return m_color & 0xff;
}

unsigned int Color::getColor() const
{
  return m_color;
}

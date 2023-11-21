#include "BaseObject.h"

BaseObject::~BaseObject()
{
  delete this->m_pCenter;
}

Color BaseObject::getColor() const
{
  return m_color;
}

void BaseObject::setColor(const Color color)
{
  this->m_color = color;
}

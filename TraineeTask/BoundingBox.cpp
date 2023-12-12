#include "BoundingBox.h"

BoundingBox::BoundingBox() : m_minPoint(0, 0), m_maxPoint(0, 0), m_dOrientation(0) {}

BoundingBox::BoundingBox(Point minPoint, Point maxPoint)
{
  m_minPoint = minPoint; 
  m_maxPoint = maxPoint;
  m_dOrientation = 0;
}

void BoundingBox::setBoundingBox(Point minPoint, Point maxPoint)
{
  m_minPoint = minPoint;
  m_maxPoint = maxPoint;
}

void BoundingBox::drawOrientedBoundingBox(float centerX, float centerY, float width, float height, float rotationAngle)
{
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x00ff);

  {
  if (rotationAngle != 0)
    glPushMatrix();
    glTranslatef(centerX, centerY, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
  }

  float halfSide_1 = width / 2.0f;
  float halfSide_2 = height / 2.0f;

  glBegin(GL_LINE_LOOP);
  glColor3f(1, 0, 0);
  glVertex2f(centerX - halfSide_2, centerY - halfSide_1);
  glVertex2f(centerX + halfSide_2, centerY - halfSide_1);
  glVertex2f(centerX + halfSide_2, centerY + halfSide_1);
  glVertex2f(centerX - halfSide_2, centerY + halfSide_1);
  glEnd();

  if(rotationAngle != 0)
    glPopMatrix();

  glDisable(GL_LINE_STIPPLE);
}

void BoundingBox::drawBoundingBox()
{
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, 0x00ff);
  
  glBegin(GL_LINE_LOOP);
  glColor3f(1, 0, 0);
  
  glVertex2d(fractionOfOne(this->getMaxPoint().x), fractionOfOne(this->getMaxPoint().y));
  glVertex2d(fractionOfOne(this->getMaxPoint().x), fractionOfOne(this->getMinPoint().y));
  glVertex2d(fractionOfOne(this->getMinPoint().x), fractionOfOne(this->getMinPoint().y));
  glVertex2d(fractionOfOne(this->getMinPoint().x), fractionOfOne(this->getMaxPoint().y));
  
  glEnd();
  
  glDisable(GL_LINE_STIPPLE);
}

Point BoundingBox::getMinPoint() const
{
  return m_minPoint;
}

Point BoundingBox::getMaxPoint() const
{
  return m_maxPoint;
}

double BoundingBox::getOrientation() const
{
  return m_dOrientation;
}

double BoundingBox::calculateOrientation(const Point p1, const Point p2, const Point p3, const Point p4)
{
  double edge = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

  double rad = acos((p2.x - p1.x) / edge);
  double degrees = (180.0 / M_PI) * rad;

  return degrees;
}

double BoundingBox::calculateOrientation() const
{
  double diagonalX = m_maxPoint.x - m_minPoint.x;
  double diagonalY = m_maxPoint.y - m_minPoint.y;

  double orientation = atan2(diagonalY, diagonalX);

  orientation = (180.0 / M_PI) * orientation;

  return orientation;
}

void BoundingBox::setOrientation(const double orientation)
{
  m_dOrientation = orientation;
}
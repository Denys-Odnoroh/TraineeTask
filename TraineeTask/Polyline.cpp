#include "Polyline.h"

Polyline::Polyline(Point point_1, Point point_2)
{
  m_pointArray.push_back(point_2);
  m_pointArray.push_back(point_1);
}

Point* Polyline::getCenter()
{
  if (!this->getpointArray().empty())
  {
    BoundingBox boundingBox = this->boundingBox();
    Point min = boundingBox.getMinPoint();
    Point max = boundingBox.getMaxPoint();

    Point* center = new Point(min.x + ((max.x - min.x) / 2),
      min.y + ((max.y - min.y) / 2));

    return center;
  }
  else return nullptr;
}

BoundingBox Polyline::boundingBox()
{
  try
  {
    Point min = this->m_pointArray[0];
    Point max = this->m_pointArray[0];

    for (Point point : this->m_pointArray)
    {
      if (point.x <= min.x)
        min.x = point.x;
      if (point.y <= min.y)
        min.y = point.y;

      if (point.x >= max.x)
        max.x = point.x;
      if (point.y >= max.y)
        max.y = point.y;
    }

    BoundingBox boundingBox(min, max);

    return boundingBox;
  }
  catch (const std::exception& exeption)
  {
    std::cout << exeption.what() << std::endl;
  }   
}

bool Polyline::isValid()
{
  if (!(this->m_pointArray.empty()))
    return true;
  else return false;
}

std::vector<Point> Polyline::getpointArray() const
{
  return m_pointArray;
}

void Polyline::setPointArray(const std::vector<Point> aPoints)
{
  m_pointArray = aPoints;
}

void Polyline::addPoint(Point point)
{
  m_pointArray.push_back(point);
}

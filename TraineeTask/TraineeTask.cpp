#include "Factory.h"
#include <fstream>

BaseObject* read()
{
  std::ifstream inFile("data.bin", std::ios::binary);

  BaseObject* obj;

  if (!inFile.is_open())
  {
    std::cerr << "Failed to open file.\n";
  }
  else
  {
    inFile.read(reinterpret_cast<char*>(&obj), sizeof(obj));
    inFile.close();

    return obj;
  }
    
}

void write(BaseObject* obj)
{
  std::ofstream outFile("data.bin", std::ios::binary);

  if (!outFile.is_open())
    std::cout << "Failed to open file.\n";
  else
    outFile.write(reinterpret_cast<const char*>(&obj), sizeof(obj));

  outFile.close();
}

int main()
{  
  {
    BaseObject* pRect_1 = Factory::factory(RectangleObject);
    Rect* pRect_2 = new Rect();
    BaseObjPtr ptrRectsngle_1 = pRect_1;
    RectanglePtr ptrRectsngle_2 = pRect_2;

    BaseObject* pCircle_1 = Factory::factory(CircleObject);
    Circle* pCircle_2 = new Circle();
    BaseObjPtr ptrCircle_1 = pCircle_1;
    CirclePtr ptrCircle_2 = pCircle_2;


    BaseObject* pTriangle_1 = Factory::factory(TriangleObject);
    Triangle* pTriangle_2 = new Triangle();
    BaseObjPtr ptrTriangle_1 = pTriangle_1;
    TrianglePtr ptrTriangle_2 = pTriangle_2;

    {//set rect
      Point p1(1.0, 1.0);
      Point p2(1.0, 5.0);
      Point p3(5.0, 5.0);
      Point p4(5.0, 1.0);
      static_cast<Rect*>(ptrRectsngle_1.get())->set(p1, p2, p3, p4);
      ptrRectsngle_2->set(p1, p3);
    }

    {//set triangle
      Point p1(1.0, 1.0);
      Point p2(3.0, 3.0);
      Point p3(4.0, 2.0);
      static_cast<Triangle*>(ptrTriangle_1.get())->set(p1, p2, p3);
      ptrTriangle_2->set(p1, p2, p3);
    }

    {//set Circle
      Point p1(1.0, 1.0);
      static_cast<Circle*>(ptrCircle_1.get())->set(p1, 5.0);
      ptrCircle_2->set(p1, 5.0);
    }

    if (ptrRectsngle_1->getCenter()->x != 3.0 || ptrRectsngle_1->getCenter()->y != 3.0)
      printf("FAIL 1\n");

    if (ptrRectsngle_2->getCenter()->x != 3.0 || ptrRectsngle_2->getCenter()->y != 3.0)
      printf("FAIL 2\n");

    if (ptrCircle_1->getCenter()->x != 1.0 || ptrCircle_1->getCenter()->y != 1.0)
      printf("FAIL 3\n");

    if (ptrCircle_2->getCenter()->x != 1.0 || ptrCircle_2->getCenter()->y != 1.0)
      printf("FAIL 4\n");

    if (std::abs(ptrTriangle_1->getCenter()->x - 2.6) > 0.1 || ptrTriangle_1->getCenter()->y != 2.0)
      printf("FAIL 5\n");

    if (std::abs(ptrTriangle_2->getCenter()->x - 2.6) > 0.1 || ptrTriangle_2->getCenter()->y != 2.0)
      printf("FAIL 6\n");
  }
  return 0;
}

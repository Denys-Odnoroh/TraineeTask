#include "Factory.h"
#include <fstream>
#include "Drawer.h"

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
  return nullptr;
}

void write(const BaseObject* obj)
{
  std::ofstream outFile("data.bin", std::ios::binary);

  if (!outFile.is_open())
    std::cout << "Failed to open file.\n";
  else
    outFile.write(reinterpret_cast<const char*>(&obj), sizeof(obj));

  outFile.close();
}

int actionSelection()
{
  int iActionIndex;

  std::cout << "Press:\n";
  std::cout << "    1. Add Circle.\n";
  std::cout << "    2. Add Polyline.\n";
  std::cout << "    3. Add Rectangle.\n";
  std::cout << "    4. Add Triangle.\n";
  std::cout << "    5. Change drawing color.\n";

  std::cin >> iActionIndex;

  while (iActionIndex > 5 || iActionIndex < 1)
  {
    std::cout << "\nIndex is incorrect! Input correct index.\n";
    std::cin >> iActionIndex;
  }

  return iActionIndex;
}

void changeDrawingColor(Color& color)
{
  int r, g, b;

  std::cout << "\nInput red (0...255): ";
  std::cin >> r;

  while (r > 255 || r < 0)
  {
    std::cout << "\nIndex is incorrect! Input correct index.\n";
    std::cin >> r;
  }

  std::cout << "\nInput blue (0...255): ";
  std::cin >> g;

  while (g > 255 || g < 0)
  {
    std::cout << "\nIndex is incorrect! Input correct index.\n";
    std::cin >> g;
  }

  std::cout << "\nInput green (0...255): ";
  std::cin >> b;

  while (b > 255 || b < 0)
  {
    std::cout << "\nIndex is incorrect! Input correct index.\n";
    std::cin >> b;
  }

  color.setColor(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b));

  system("cls");
  std::cout << "Color changed.\n";
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

  {
    if (!glfwInit())
      return -1;

    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(1960, 1960, "Trainee task", NULL, NULL);
    glfwMakeContextCurrent(window);
    
    Color color(255, 255, 255);
    glColor3f(0, 0, 1);

    glBegin(GL_LINES);
    glVertex2d(-1, 0);
    glVertex2d(1, 0);
    glVertex2d(0, -1);
    glVertex2d(0, 1);
    glEnd();

    glColor3f(1, 1, 1);

    while (!glfwWindowShouldClose(window))
    {
      glFlush();
      glfwPollEvents();

      switch (actionSelection())
      {
      case 1:
      {
        Drawer::drawCirce(color);
        break;
      }
      case 2:
      {
        Drawer::drawPolyline(color);
        break;
      }
      case 3:
      {
        Drawer::drawRectangle(color);
        break;
      }
      case 4:
      {
        Drawer::drawTriangle(color);
        break;
      }
      case 5:
      {
        changeDrawingColor(color);
        break;
      }
      }
    }
  }
  return 0;
}

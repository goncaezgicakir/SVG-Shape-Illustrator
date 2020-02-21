#include "circle.h"
#include "shape.h"
using namespace std;
using namespace Shape_;


//------------------------------------CONSTRUCTORS AND OTHER FUNCS-------------------------------------

 //no parameter constructor
Circle::Circle(): radius(0.0), coorX(0.0), coorY(0.0){}

Circle::Circle(int coorValue1, int coorValue2)
{
    coorX = coorValue1;
    coorY = coorValue2;
}

Circle::Circle(double radiusValue)
{
    radius = radiusValue;
}

//draw function for container shape
void Circle::draw(ostream &fp)
{
    fp << "<circle cx=\" " << coorX << "\" cy=\" " << coorY << "\" r=\" " << radius <<
       "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;
}

//calculates container's perimeter length
double Circle::perimeter()
{
    double objPer = 2 * 3.14 * radius;
    shapePer = objPer;
    return shapePer;
}

//calculates container's area
double Circle::area()
{
    double objArea = 3.14 * radius * radius;
    shapeArea = objArea;
    return shapeArea;

}

//--------------------------------------OP. OVERLOADING FUNCTIONS------------------------------------------------------

//overloads << to draw container
ostream& operator <<(ostream& fp, const Circle& object)
{
    fp << "<circle cx=\" " << object.getCoorX() << "\" cy=\" " << object.getCoorY() << "\" r=\" " << object.getRadius() <<
       "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;
    return fp;
}

//overload ++ to increment coordinate -> prefix version
Shape& Circle::operator++()
{
    Shape* ptr = new Circle(coorX++, coorY++);
    return *ptr;
}

//overloads ++ to increment coordinate -> postfix version
Shape& Circle::operator++(int x)
{
    double temp1= coorX;
    double temp2 = coorY;
    coorX ++;
    coorY ++;
    Shape* ptr = new Circle(temp1, temp2);
    return *ptr;
}

//overload -- to increment coordinate -> prefix version
Shape&  Circle::operator--()
{
    Shape* ptr = new Circle(coorX--, coorY--);
    return *ptr;
}

//overloads -- to increment coordinate -> postfix version
Shape&  Circle::operator--(int x)
{
    double temp1 = coorX;
    double temp2 = coorY;
    coorX--;
    coorY--;
    Shape* ptr = new Circle(temp1, temp2);
    return *ptr;
}

//overloads + to increment length and return a new object
const Circle Circle::operator +(double value)
{
    double newRadius = radius + value;
    return Circle(newRadius);
}
//overloads - to decrement length and return a new object
const Circle Circle::operator -(double value)
{
    double newRadius = radius - value;
    return Circle(newRadius);
}

//overloads == to compare shapes respect to their areas
/*bool Circle::operator ==(const Circle& obj) const
{
    return (area == obj.area);
}

//overloads != to compare shapes respect to their areas
bool Circle::operator !=(const Circle& obj) const
{
    return (area != obj.area);
}*/

//-------------------------------GETTERS---------------------------------------------------------------

double Circle::getRadius() const
{   return radius;
}

double Circle::getCoorX() const
{   return coorX;
}

double Circle::getCoorY() const
{   return coorY;
}



//------------------------------SETTERS------------------------------------------------------------------

void Circle::setRadius(double setRadius)
{   radius = setRadius;
}

void Circle::setCoorX(double setCoorX)
{   coorX = setCoorX;
}

void Circle::setCoorY(double setCoorY)
{   coorY = setCoorY;
}


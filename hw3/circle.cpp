
#include "circle.h"


using namespace std;
//------------------------------------CIRCLE CLASS FUNCTIONS AND CONSTRUCTORS -------------------------------------

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
void Circle::draw(ostream &fp) const
{
    fp << "<circle cx=\" " << coorX << "\" cy=\" " << coorY << "\" r=\" " << radius <<
       "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;
}

//calculates container's perimeter length
double Circle::calculatePerimeterLength()
{
     double perimeterLengthC = 2 * 3.14 * radius;
     return perimeterLengthC;
}

//calculates container's area
void Circle::calculateArea()
{
    area = 3.14 * radius * radius;

}

//--------------------------------------OVERLOAD FUNCTIONS------------------------------------------------------

//overloads << to draw container
ostream& operator <<(ostream& fp, const Circle& object)
{
    fp << "<circle cx=\" " << object.coorX << "\" cy=\" " << object.coorY << "\" r=\" " << object.radius <<
       "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;
    return fp;
}

//overload ++ to increment coordinate -> prefix version
Circle Circle::operator++()
{
    return Circle(coorX++, coorY++);
}

//overloads ++ to increment coordinate -> postfix version
Circle Circle::operator++(int)
{
    double temp1= coorX;
    double temp2 = coorY;
    coorX ++;
    coorY ++;
    return Circle(temp1, temp2);
}

//overload -- to increment coordinate -> prefix version
Circle Circle::operator--()
{
    return Circle(coorX--, coorY--);
}

//overloads -- to increment coordinate -> postfix version
Circle Circle::operator--(int)
{
    double temp1 = coorX;
    double temp2 = coorY;
    coorX--;
    coorY--;
    return Circle(temp1, temp2);
}

//overloads + to increment length and return a new object
const Circle operator +(const Circle& object, double value)
{
    double newRadius = object.radius + value;
    return Circle(newRadius);
}
//overloads - to decrement length and return a new object
const Circle operator -(const Circle& object, double value)
{
    double newRadius = object.radius - value;
    return Circle(newRadius);
}

//overloads == to compare shapes respect to their areas
bool operator ==(const Circle& object1, const Circle& object2)
{
    double area1 = object1.area;
    double area2 = object2.area;
    return (area1 == area2);
}

//overloads != to compare shapes respect to their areas
bool operator !=(const Circle& object1, const Circle& object2)
{
    double area1 = object1.area;
    double area2 = object2.area;
    return (area1 != area2);
}

int Circle:: countShape = 0;

static double totalAreaCir(){
    return 0;
};
  
static double totalPerimeterCir(){
    return 0;
};
//-------------------------------CIRCLE CLASS GETTERS---------------------------------------------------------------

inline double Circle::getRadius() const
{   return radius;
}

inline double Circle::getCoorX() const
{   return coorX;
}

inline double Circle::getCoorY() const
{   return coorY;
}

//------------------------------CIRCLE CLASS SETTERS------------------------------------------------------------------

void Circle::setRadius(double setRadius)
{   radius = setRadius;
}

void Circle::setCoorX(double setCoorX)
{   coorX = setCoorX;
}

void Circle::setCoorY(double setCoorY)
{   coorY = setCoorY;
}


#include "rectangle.h"


using namespace std;



//-------------------------------------RECTANGLE CLASS FUNCTIONS AND CONSTRUCTOR----------------------------

//no parameter constructor
Rectangle::Rectangle(): height(0.0), width(0.0), coorX(0.0), coorY(0.0){};

Rectangle::Rectangle(int coorValue1, int coorValue2)
{

    coorX = coorValue1;
    coorY = coorValue2;
}

Rectangle::Rectangle(double heightValue, double widthValue)
{

    height = heightValue;
    width = widthValue;
}


//draw function for container shape
void Rectangle::draw(ostream &fp) const
{
    fp << "<rect x=\" " << coorX << "\" y=\" " << coorY << "\" width=\" " << width << "\" height=\" " << height <<
       "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\"/>" << endl;
}

//calculates containers perimeter length
double Rectangle::calculatePerimeterLength()
{
    double perimeterLengthC = 2 * ((double)height + (double)width);
    return perimeterLengthC;
}

// calculates container's area
void  Rectangle::calculateArea()
{
    area = (double)height * (double)width;

}

//-----------------------------------------OPERATOR OVERLOADING FUNCTIONS---------------------------------------

//overloads <<  to draw container rectangle
ostream& operator <<(ostream& fp, const Rectangle& object)
{
    fp << "<rect x=\" " << object.coorX << "\" y=\" " << object.coorY << "\" width=\" " << object.width << "\" height=\" "
        << object.height << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\"/>" << endl;

    return fp;
}

//overload ++ to increment coordinate -> prefix version
Rectangle Rectangle::operator++()
{
    return Rectangle(coorX++, coorY++);
}

//overloads ++ to increment coordinate -> postfix version
Rectangle Rectangle::operator++(int)
{
    int temp1 = coorX;
    int temp2 = coorY;
    coorX++;
    coorY++;
    return Rectangle(temp1, temp2);
}

//overload -- to increment coordinate -> prefix version
Rectangle Rectangle::operator--()
{
    return Rectangle(coorX--, coorY--);
}

//overloads -- to increment coordinate -> postfix version
Rectangle Rectangle::operator--(int)
{
    int temp1= coorX;
    int temp2 = coorY;
    coorX--;
    coorY--;
    return Rectangle(temp1, temp2);
}

//overloads + to increment length and return a new object
const Rectangle operator +(const Rectangle& object, double value)
{
    double newHeight = object.height + value;
    double newWidth = object.width + value;

    return Rectangle(newHeight, newWidth);
}

//overloads - to decrement length and return a new object
const Rectangle operator -(const Rectangle& object, double value)
{
    double newHeight = object.height - value;
    double newWidth = object.width - value;

    return Rectangle(newHeight, newWidth);
}

//overloads == to compare shapes respect to their areas
bool operator ==(const Rectangle& object1, const Rectangle& object2)
{
    double area1 = object1.area;
    double area2 = object2.area;
    return (area1 == area2);
}

//overloads != to compare shapes respect to their areas
bool operator !=(const Rectangle& object1, const Rectangle& object2)
{
    double area1 = object1.area;
    double area2 = object2.area;
    return (area1 != area2);
}

int Rectangle:: countShape = 0;

static double totalAreaRec(){
    return 0;
};
  
static double totalPerimeterRec(){
    return 0;
};


//--------------------------------- RECTANGLE CLASS GETTERS-------------------------------------------------------

inline double Rectangle::getHeight() const
{ return height;
}

inline double Rectangle::getWidth() const
{ return width;
}

inline double Rectangle::getCoorX() const
{   return coorX;
}

inline double Rectangle::getCoorY() const
{   return coorY;
}

//----------------------------------RECTANGLE CLASS SETTERS----------------------------------------------------------

void Rectangle::setHeight(double setHeight) {
    height=setHeight;
}

void Rectangle::setWidth(double setWidth) {
    width=setWidth;
}

void Rectangle::setCoorX(double setCoorX)
{   coorX = setCoorX;
}

void Rectangle::setCoorY(double setCoorY)
{   coorY = setCoorY;
}

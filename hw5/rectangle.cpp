#include "rectangle.h"
#include "shape.h"
using namespace std;
using namespace Shape_;


//-------------------------------------CONSTRUCTORS AND OTHER FUNCS----------------------------

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
void Rectangle::draw(ostream &fp)
{
    fp << "<rect x=\" " << getCoorX() << "\" y=\" " << getCoorY() << "\" width=\" " << getWidth() << "\" height=\" " << getHeight() <<
       "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\"/>" << endl;
}

//calculates containers perimeter length
double Rectangle::perimeter()
{
    double objPer = 2 * ((double)height + (double)width);
    shapePer = objPer;
    return shapePer;
}

// calculates container's area
double Rectangle::area()
{
    double objArea = (double)height * (double)width;
    shapeArea = objArea;
    return shapeArea;
}

//-----------------------------------------OP. OVERLOADING FUNCTIONS---------------------------------------

//overloads <<  to draw container rectangle
ostream& operator <<(ostream& fp, const Rectangle& object)
{
    fp << "<rect x=\" " << object.getCoorX() << "\" y=\" " << object.getCoorY() << "\" width=\" " << object.getWidth() << "\" height=\" "
        << object.getHeight() << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\"/>" << endl;

    return fp;
}

//overload ++ to increment coordinate -> prefix version
Shape& Rectangle::operator++()
{   
    Shape* ptr = new Rectangle(coorX++, coorY++);
    return *ptr;
}

//overloads ++ to increment coordinate -> postfix version
Shape& Rectangle::operator++(int x)
{
    int temp1 = coorX;
    int temp2 = coorY;
    coorX++;
    coorY++;
    Shape* ptr = new Rectangle(temp1, temp2);
    return *ptr;
}

//overload -- to increment coordinate -> prefix version
Shape& Rectangle::operator--()
{
    Shape* ptr = new Rectangle(coorX--, coorY--);
    return *ptr;
}

//overloads -- to increment coordinate -> postfix version
Shape& Rectangle::operator--(int x)
{
    int temp1= coorX;
    int temp2 = coorY;
    coorX--;
    coorY--;
    Shape* ptr = new Rectangle(temp1, temp2);
    return *ptr;
}

//overloads + to increment length and return a new object
const Rectangle Rectangle::operator +(double value)
{
    double newHeight = height + value;
    double newWidth = width + value;

    return Rectangle(newHeight, newWidth);
}

//overloads - to decrement length and return a new object
const Rectangle Rectangle::operator -(double value)
{
    double newHeight = height - value;
    double newWidth = width - value;

    return Rectangle(newHeight, newWidth);
}

//overloads == to compare shapes respect to their areas
/*bool Rectangle::operator ==(const Rectangle& obj) const
{
    return (area == obj.area);
}

//overloads != to compare shapes respect to their areas
bool Rectangle::operator !=(const Rectangle& obj) const
{
    return (area != obj.area);
}*/


//--------------------------------- RECTANGLE CLASS GETTERS-------------------------------------------------------

double Rectangle::getHeight() const
{ 
    return height;
}

double Rectangle::getWidth() const
{ 
    return width;
}

double Rectangle::getCoorX() const
{   
    return coorX;
}

double Rectangle::getCoorY() const
{   
    return coorY;
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

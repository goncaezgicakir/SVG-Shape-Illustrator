#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rectangle.h"


using namespace std;



//-------------------------------------RECTANGLE CLASS FUNCTIONS AND CONSTRUCTOR----------------------------

//no parameter constructor
Rectangle::Rectangle(): height(0.0), width(0.0), coorX(0.0), coorY(0.0){};

//draw function for small shape(overloaded)
void Rectangle::draw(ofstream &fp, char shapeCond)
{
    if (shapeCond == 'R')
    {
        fp << "<rect x=\" " << coorX << "\" y=\" " << coorY << "\" width=\" " << width << "\" height=\" " << height <<
           "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\"/>" << endl;
    }

}
//draw function for container shape
void Rectangle::draw(ofstream &fp)
{
    fp << "<rect x=\" " << coorX << "\" y=\" " << coorY << "\" width=\" " << width << "\" height=\" " << height <<
       "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\"/>" << endl;
}

//--------------------------------- RECTANGLE CLASS GETTERS-------------------------------------------------------

double Rectangle::getHeight() const
{ return height;
}

double Rectangle::getWidth() const
{ return width;
}

double Rectangle::getCoorX() const
{   return coorX;
}

double Rectangle::getCoorY() const
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

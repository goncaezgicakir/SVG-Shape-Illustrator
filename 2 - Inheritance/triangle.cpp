#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "triangle.h"

using namespace std;


//-----------------------------TRIANGLE CLASS FUNCTIONS AND CONSTRUCTOR---------------------------------------------

//no parameter constructor
Triangle::Triangle(): length(0.0){} //no parameter constructor

//draw function for small shape(overloaded)
void Triangle::draw(ofstream &fp, char shapeCond)
{
        if(shapeCond == 'T') {
            fp << "<polygon points=\"" << coordinate[0] << "," << coordinate[1] <<
               " " << coordinate[2] << "," << coordinate[3] << " " << coordinate[4] << ","
               << coordinate[5] << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;

            fp << "<polygon points=\"" << coordinate[0] << "," << coordinate[1] << " " << coordinate[2] << ","
               << coordinate[3] << " " << coordinate[4]
               << "," << coordinate[5] << "\" transform = \" rotate(60 " << coordinate[4] << " " << coordinate[5] <<
               ") \" fill=\"yellow\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;
        }
}

//draw function for container shape
void Triangle::draw(ofstream &fp)
{
    fp << "<polygon points=\""<<coordinate[0]<<","<<coordinate[1]<<
       " "<<coordinate[2]<<","<<coordinate[3]<<" "<<coordinate[4]<<","
       <<coordinate[5]<<"\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;
}

//---------------------------------TRIANGLE CLASS GETTERS------------------------------------------------------------

double Triangle::getLength() const
{ return length;
}

vector < double > Triangle::getCoordinate() const
{ return coordinate;
}

//--------------------------------TRIANGLE SETTERS----------------------------------------------------------------

void Triangle::setLength(double setLength) {
    length = setLength;
}

void Triangle::setCoordinate(vector < double > setCoordinate)
{
    coordinate = setCoordinate;
}

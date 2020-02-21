#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Triangle
{
public:
    Triangle(); //no parameter constructor
    double getLength() const;
    vector < double > getCoordinate() const;
    void setLength(double setLength);
    void setCoordinate( vector < double > setCoordinate);
    void draw(ofstream &fp);
    void draw(ofstream &fp, char shapeCond);

private:
    double length;      //length of triangles one side
    vector < double > coordinate;       //vector to hold coordinates of 3 nodes

};


#endif


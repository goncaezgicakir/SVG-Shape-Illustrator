#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "shape.h"
#include "polygon.h"
using namespace std;
using namespace Shape_;

class PolygonVect : public Polygon
{
public:

    //no parameter constructor
    PolygonVect();
    //constructor takes a vector of Point2D objects to represent the polygon points.
    PolygonVect(vector<Point2D> shapeVector);
    //constructor takes Rectangle objet and converts to polygon
    PolygonVect(Rectangle objRec);
    //constructor takes Circle object and converts to polygon
    PolygonVect(Circle objCir);
    //constructor takes triangle object and converts to polygon
    PolygonVect(Triangle objTri);
  
    //getters and setters
    int getNumOfPoints()const;
    vector <PolygonVect::Point2D> getVect()const;
    void setNumOfPoints(int num);
    void setPtr( vector <Point2D> vect_);

    //operator overload to return a reference from a given index (r-value)
    PolygonVect::Point2D& operator [](int idx);
    //operator overload to return a reference from a given index (l-value)
    const PolygonVect::Point2D& operator[](int idx)const;
    //operator overloads to produce SVG code
    friend ostream& operator <<(ostream& fp, const PolygonVect& objPoly);
    

private:
    int numOfPoints;
    vector <Point2D> vect;

};

#endif  
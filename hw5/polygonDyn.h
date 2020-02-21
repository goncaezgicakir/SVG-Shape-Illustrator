#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_

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

class PolygonDyn : public Polygon
{
public:

    //no parameter constructor
    PolygonDyn();
    //constructor takes a vector of Point2D objects to represent the polygon points.
    PolygonDyn(vector<Point2D> points);
    //constructor takes a POint2D
    PolygonDyn(Point2D* point);
    //constructor takes Rectangle objet and converts to polygon
    PolygonDyn(Rectangle objRec);
    //constructor takes Circle object and converts to polygon
    PolygonDyn(Circle objCir);
    //constructor takes triangle object and converts to polygon
    PolygonDyn(Triangle objTri);
  
    //getters and setters
    int getNumOfPoints()const;
    Point2D* getPtr()const;
    void setNumOfPoints(int num);
    void setPtr(Point2D* ptr_);

    //operator overload to return a reference from a given index (r-value)
    PolygonDyn::Point2D& operator [](int idx);
    //operator overload to return a reference from a given index (l-value)
    const PolygonDyn::Point2D& operator[](int idx)const;
    //operator overload to concatenate two polygon objects and return new the concatenated object
    const PolygonDyn& operator+(const PolygonDyn objPoly);
     //operator overloads to produce SVG code
    friend ostream& operator <<(ostream& fp, const PolygonDyn& objPoly);
    

private:
    int numOfPoints;
    Point2D* ptr;

};

#endif  
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "shape.h"
#include "polygon.h"
#include "polygonDyn.h"

using namespace std;
using namespace Shape_;

//------------------------------------POLYGON CLASS CONSTRUCTORS AND DESTRUCTOR----------------------------------------------------
//no parameter constructor
PolygonDyn::PolygonDyn()
{
    ptr = nullptr;
    numOfPoints = 0;
}
//constructor takes avector of Point2D objects to represent the polygon points.
PolygonDyn::PolygonDyn(vector<Point2D> points)
{}
//constructor takes a POint2D
PolygonDyn::PolygonDyn(Point2D* point)
{
    ptr = point;
}

//constructor takes Rectangle objet and converts to polygon
PolygonDyn::PolygonDyn(Rectangle objRec)
{   
    numOfPoints = 4;
    ptr = new Point2D[numOfPoints];


    ptr[0] = Point2D(objRec.getCoorX() + 0 , objRec.getCoorY() + 0);
    ptr[1] = Point2D(objRec.getCoorX() + objRec.getWidth() , objRec.getCoorY() + 0);
    ptr[2] = Point2D(objRec.getCoorX() + objRec.getWidth() , objRec.getCoorY() + objRec.getHeight());
    ptr[3] = Point2D(objRec.getCoorX() + 0 , objRec.getCoorY() + objRec.getHeight());

}

//constructor takes Circle object and converts to polygon
PolygonDyn::PolygonDyn(Circle objCir)
{
    numOfPoints = 100;
    ptr = new Point2D[numOfPoints];
    
    for(auto i=0 ; i<100 ; ++i)
    {
        ptr[i] = Point2D(objCir.getCoorX() + objCir.getRadius() + objCir.getRadius()*sin((M_PI/50.0)*i),
                        objCir.getCoorY() + objCir.getRadius() - objCir.getRadius()*cos((M_PI/50.0)*i));
    };
}

//constructor takes triangle object and converts to polygon
PolygonDyn::PolygonDyn(Triangle objTri)
{
    numOfPoints=3;
    ptr = new Point2D[numOfPoints];
  
    ptr[0] = Point2D(objTri.getCoordinate()[0],objTri.getCoordinate()[1]);
    ptr[1] = Point2D(objTri.getCoordinate()[2],objTri.getCoordinate()[3]);
    ptr[2] = Point2D(objTri.getCoordinate()[4],objTri.getCoordinate()[5]);
   
}

 


//-----------------------------------POLYGON CLASS GETTERS AND SETTERS--------------------------------------------
//getters and setters
int PolygonDyn::getNumOfPoints()const
{
    return numOfPoints;
}
void PolygonDyn::setNumOfPoints(int num)
{
    numOfPoints = num;
}


//-----------------------------------POLYGON CLASS OPERATOR OVERLOADS---------------------------------------------
//operator overload to return a reference from a given index (r-value)
PolygonDyn::Point2D& PolygonDyn::operator [](int idx)
{
    return ptr[idx];
}

//operator overload to return a reference from a given index (l-value)
const PolygonDyn::Point2D& PolygonDyn::operator[](int idx)const
{
    return ptr[idx];
}

//operator overload to concatenate two polygon objects and return new the concatenated object
const PolygonDyn& PolygonDyn::operator+(const PolygonDyn objPoly)
{   
    PolygonDyn* newObjPoly;

    int newNumOfPoints  = numOfPoints + objPoly.numOfPoints;
    Point2D* newPtr = new Point2D [newNumOfPoints];

    for(int i=0 ; i<numOfPoints ; ++i)
    {
        newPtr[i] = Point2D(ptr[i].getCoorX() , ptr[i].getCoorX());
    }    
    return *newObjPoly;
}

//operator overloads to produce SVG code
ostream& operator <<(ostream& fp, const PolygonDyn& objPoly)
{   

    if(objPoly.getNumOfPoints() == 3)
    { 

     fp << "<polygon points=\""<<objPoly.ptr[0].getCoorX()<<","<<objPoly.ptr[0].getCoorY()<<
                            " "<<objPoly.ptr[1].getCoorX()<<","<<objPoly.ptr[1].getCoorY()<<
                            " "<<objPoly.ptr[2].getCoorX()<<","<<objPoly.ptr[2].getCoorY()<<
                            "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;

    fp << "<polygon points=\""<<objPoly.ptr[0].getCoorX()<<","<<objPoly.ptr[0].getCoorY()<<
                            " "<<objPoly.ptr[1].getCoorX()<<","<<objPoly.ptr[1].getCoorY()<<
                            " "<<objPoly.ptr[2].getCoorX()<<","<<objPoly.ptr[2].getCoorY()<<
                            "\" transform = \" rotate(60 " << objPoly.ptr[2].getCoorX()<< " " << objPoly.ptr[2].getCoorY() <<
                            ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;
    }

    else if(objPoly.getNumOfPoints() == 4)
    { 
   
     fp << "<polygon points=\""<<objPoly.ptr[0].getCoorX()<<","<<objPoly.ptr[0].getCoorY()<<
                            " "<<objPoly.ptr[1].getCoorX()<<","<<objPoly.ptr[1].getCoorY()<<
                            " "<<objPoly.ptr[2].getCoorX()<<","<<objPoly.ptr[2].getCoorY()<<
                            " "<<objPoly.ptr[3].getCoorX()<<","<<objPoly.ptr[3].getCoorY()<<
                            "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;
    }

    else if(objPoly.getNumOfPoints() == 100)
    { 
       
    fp<< "<polygon points=\"";

     for(int i=0 ; i<100 ; ++i)
     {   
     fp<<objPoly.ptr[i].getCoorX()<<","<<objPoly.ptr[i].getCoorY()<<" ";
                            
      } 
      fp<< "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;                     
    }
}



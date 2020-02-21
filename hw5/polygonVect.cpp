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
#include "polygonVect.h"

using namespace std;
using namespace Shape_;

//------------------------------------POLYGON CLASS CONSTRUCTORS AND DESTRUCTOR----------------------------------------------------
//no parameter constructor
PolygonVect::PolygonVect()
{
    numOfPoints = 0;
}

//constructor takes a Point2D vector
PolygonVect::PolygonVect(vector<PolygonVect::Point2D> shapeVector)
{
    vect = shapeVector;
}

//constructor takes Rectangle objet and converts to polygon
PolygonVect::PolygonVect(Rectangle objRec)
{   
    numOfPoints = 4;
    
    vect[0] = Point2D(objRec.getCoorX() + 0 , objRec.getCoorY() + 0);
    vect[1] = Point2D(objRec.getCoorX() + objRec.getWidth() , objRec.getCoorY() + 0);
    vect[2] = Point2D(objRec.getCoorX() + objRec.getWidth() , objRec.getCoorY() + objRec.getHeight());
    vect[3] = Point2D(objRec.getCoorX() + 0 , objRec.getCoorY() + objRec.getHeight());

}

//constructor takes Circle object and converts to polygon
PolygonVect::PolygonVect(Circle objCir)
{
    numOfPoints = 100;
    
    for(auto i=0 ; i<100 ; ++i)
    {
        vect[i] = Point2D(objCir.getCoorX() + objCir.getRadius() + objCir.getRadius()*sin((M_PI/50.0)*i),
                        objCir.getCoorY() + objCir.getRadius() - objCir.getRadius()*cos((M_PI/50.0)*i));
    };
}

//constructor takes triangle object and converts to polygon
PolygonVect::PolygonVect(Triangle objTri)
{
    numOfPoints=3;
  
    vect[0] = Point2D(objTri.getCoordinate()[0],objTri.getCoordinate()[1]);
    vect[1] = Point2D(objTri.getCoordinate()[2],objTri.getCoordinate()[3]);
    vect[2] = Point2D(objTri.getCoordinate()[4],objTri.getCoordinate()[5]);
   
}


//-----------------------------------POLYGON CLASS GETTERS AND OP. OVERLOADS--------------------------------------------
//getters and setters
int PolygonVect::getNumOfPoints()const
{
    return numOfPoints;
}
vector <PolygonVect::Point2D> PolygonVect::getVect() const
{
    return vect;
}

//operator overload to return a reference from a given index (r-value)
PolygonVect::Point2D& PolygonVect::operator [](int idx)
{
    return vect[idx];
}

//operator overload to return a reference from a given index (l-value)
const PolygonVect::Point2D& PolygonVect::operator[](int idx)const
{
    return vect[idx];
}


//operator overloads to produce SVG code
ostream& operator <<(ostream& fp, const PolygonVect& objPoly)
{   

    if(objPoly.getNumOfPoints() == 3)
    { 

     fp << "<polygon points=\""<<objPoly.vect[0].getCoorX()<<","<<objPoly.vect[0].getCoorY()<<
                            " "<<objPoly.vect[1].getCoorX()<<","<<objPoly.vect[1].getCoorY()<<
                            " "<<objPoly.vect[2].getCoorX()<<","<<objPoly.vect[2].getCoorY()<<
                            "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;

    fp << "<polygon points=\""<<objPoly.vect[0].getCoorX()<<","<<objPoly.vect[0].getCoorY()<<
                            " "<<objPoly.vect[1].getCoorX()<<","<<objPoly.vect[1].getCoorY()<<
                            " "<<objPoly.vect[2].getCoorX()<<","<<objPoly.vect[2].getCoorY()<<
                            "\" transform = \" rotate(60 " << objPoly.vect[2].getCoorX()<< " " << objPoly.vect[2].getCoorY() <<
                            ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;
    }

    else if(objPoly.getNumOfPoints() == 4)
    { 
   
     fp << "<polygon points=\""<<objPoly.vect[0].getCoorX()<<","<<objPoly.vect[0].getCoorY()<<
                            " "<<objPoly.vect[1].getCoorX()<<","<<objPoly.vect[1].getCoorY()<<
                            " "<<objPoly.vect[2].getCoorX()<<","<<objPoly.vect[2].getCoorY()<<
                            " "<<objPoly.vect[3].getCoorX()<<","<<objPoly.vect[3].getCoorY()<<
                            "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;
    }

    else if(objPoly.getNumOfPoints() == 100)
    { 
       
    fp<< "<polygon points=\"";

     for(int i=0 ; i<100 ; ++i)
     {   
     fp<<objPoly.vect[i].getCoorX()<<","<<objPoly.vect[i].getCoorY()<<" ";
                            
      } 
      fp<< "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;                     
    }
}



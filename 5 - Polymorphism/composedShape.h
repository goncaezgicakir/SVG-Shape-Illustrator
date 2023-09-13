#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "polygon.h"
#include "polygonDyn.h"
using namespace std;
using namespace Shape_;

namespace Shape_
{

    class ComposedShape : public Shape
    {
    public:

        //no parameter constructor
        ComposedShape();
        //overloaded constructors
        ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3, double cnstrDimension_4);
        ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3);
        ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2);

        //gettrs
        inline char getShapeC() const{   return shapeC;}
        inline double getHeightC() const{ return heightC;}
        inline double getWidthC() const{ return widthC;}
        inline double getRadiusC() const{  return radiusC;}
        inline double getLengthC() const{ return lengthC;}
        inline char getShapeS() const{ return shapeS; }
        inline double getHeightS() const{ return heightS;}
        inline double getWidthS() const{ return widthS;}
        inline double getRadiusS() const{   return radiusS;}
        inline double getLengthS() const{ return lengthS;}
        inline int getShapeNumber() const{  return shapeCountS;}
        inline vector <PolygonDyn> getSmallShape() const{ return smallShp;}
        inline Rectangle getRectangle() const{return R;}
        inline Triangle getTriangle() const{return T;}
        inline Circle getCircle() const{ return C;}


        //setters
        void setHeightC(double setHeight);
        void setWidthC(double setWidth);
        void setRadiusC(double setRadius);
        void setLengthC(double setLength);
        void setHeightS(double setHeight);
        void setWidthS(double setWidth);
        void setRadiusS(double setRadius);
        void setLengthS(double setLength);
        void setShapeNumber(int setNumber);

        void start(ofstream& fp);
        //overloading of << operator to write composed shape to svg file
        friend ostream& operator<<(ostream& fp,  const ComposedShape& compObject);
       
        double area(){};          //pure virtual func. returns the area of shape
        double perimeter(){};     //pure virtual func. and returns the primeter of shape
        Shape& operator++(){};    //pure virtual func. overloads ++ to increment coordinate by one -> prefix version
        Shape& operator++(int){}; //pure virtual func. overloads ++ to increment coordinate by one -> postfix version
        Shape& operator--(){};    //pure virtual func. overload -- to increment coordinate by one -> prefix version
        Shape& operator--(int){}; //pure virtual func.overloads -- to increment coordinate by one -> postfix version
       
        void draw(ostream& fp){};

    
    private:

        char shapeC; //shape of container
        int heightC;  //height of container
        int widthC; //width of container
        double radiusC; //radius of container
        double lengthC; //length of container
        char shapeS;    //shape of small container
        int heightS;    //height of small container
        int widthS;     //width of small container
        double radiusS;     //radius of small container
        double lengthS;     //length of small container
        int shapeCountS;

        Rectangle R;    //object whether to create rectangle container
        Circle C;       //object whether to create circle container
        Triangle T;     //object whether to create triangle container
        vector <PolygonDyn> smallShp; //vector of object whether to create small shapes

        void optimalFit();
        void drawShp(ofstream &fp);

        void modifyR(int counter, double coorY, double coorX);
        void modifyC(int counter, double coorY, double coorX);
        void modifyT(int counter, double coorX1, double coorY1,double coorX2, double coorY2,double coorX3, double coorY3);

        void RinR();
        void TinR();
        void CinR();
        void CinC();
        void RinC();
        void TinC();
        void TinT();
        void CinT();
        void RinT();

    };

}//Shape_

#endif

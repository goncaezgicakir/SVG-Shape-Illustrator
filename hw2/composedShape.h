#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

using namespace std;


class ComposedShape
{
public:

     //no parameter constructor
     ComposedShape();
     //overloaded constructors
     ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3, double cnstrDimension_4);
     ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3);
     ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2);

     char getShapeC() const;
     double getHeightC() const;
     double getWidthC() const;
     double getRadiusC() const;
     double getLengthC() const;
     char getShapeS() const;
     double getHeightS() const;
     double getWidthS() const;
     double getRadiusS() const;
     double getLengthS() const;
     int getShapeNumber() const;
     vector < Rectangle > getSmallRectangle() const;
     vector < Circle > getSmallCircle() const;
     vector < Triangle > getSmallTriangle() const;

     void setHeightC(double setHeight);
     void setWidthC(double setWidth);
     void setRadiusC(double setRadius);
     void setLengthC(double setLength);
     void setHeightS(double setHeight);
     void setWidthS(double setWidth);
     void setRadiusS(double setRadius);
     void setLengthS(double setLength);
     void setShapeNumber(int setNumber);
     void start(ofstream &fp);

private:

    char shapeC; //shape of container
    int heightC;  //height of container
    int widthC; //width of container
    double radiusC; //radius of container
    double lengthC; //length of container
    Rectangle R;    //object whether to create rectangle container
    Circle C;       //object whether to create circle container
    Triangle T;     //object whether to create triangle container

    char shapeS;    //shape of small container
    int heightS;    //height of small container
    int widthS;     //width of small container
    double radiusS;     //radius of small container
    double lengthS;     //length of small container
    vector < Rectangle > r;     //object whether to create small rectangles
    vector < Circle > c;        //object whether to create small circles
    vector < Triangle > t;      //object whether to create small triangles
    int shapeCountS;

    void optimalFit();
    void draw(ofstream &fp);

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

#endif

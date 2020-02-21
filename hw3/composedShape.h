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

enum Shapes {rectangle, circle , triangle};

class ComposedShape
{
public:
    
    //-------------NESTED CLASS--------------------------------------------------------------------------
    class ShapeElem
    {
    public:
        //no parameter constructor
        ShapeElem();
        //constructors
        ShapeElem(const Rectangle& objectRec);
        ShapeElem(const Circle& objectCir);
        ShapeElem(const Triangle& objectTri);

        //BIG THREE
        //1.copy constructor
        ShapeElem(const ShapeElem& object);
        //2.overloaded assignment operator
        ShapeElem& operator =(const ShapeElem& assignedObject);
        //3.destructor
        ~ShapeElem();

        //getters
        void* getShapePtr() const;
        void setShapePtr(void* ptr);
        Shapes getShapeType() const;
        void setShapeType(Shapes typeOfShape);

        friend ostream& operator <<(ostream& fp, const ShapeElem& object); //overloads <<  to draw small shape

        double calculatePerimeterLength(); //calculates perimeter length
        double calculateArea(); // calculates area

    private:
        void* shapePtr;
        Shapes shapeType ;

    };
    //--------------------------------------------------------------------------------------------------------


     //no parameter constructor
     ComposedShape();
     //overloaded constructors
     ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3, double cnstrDimension_4);
     ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3);
     ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2);

     //gettrs
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

     Rectangle getRectangle() const;
     Triangle getTriangle() const;
     Circle getCircle() const;

     vector < ComposedShape::ShapeElem > getSmallShape() const;

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
     friend ostream& operator<<(ostream& fp, const ComposedShape& compObject);
     //overloading of += operator to add another object
     const ComposedShape operator +=(const ComposedShape::ShapeElem& addObject);
     //overloading [] operator to returning shape as an object (r-value)
     ComposedShape::ShapeElem& operator[](int index);
     //overloading [] operator to returning shape as an object (l-value)
     const ComposedShape::ShapeElem operator[](int index)const;
     


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
    int shapeCountS;

    vector < ComposedShape::ShapeElem > s; //vector of object whether to create small shapes

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

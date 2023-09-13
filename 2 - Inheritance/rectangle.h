#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Rectangle
{

public:
    Rectangle(); //no parameter constructor
    double getHeight() const;
    double getWidth() const;
    double getCoorX() const;
    double getCoorY() const;
    void setHeight(double setHeight);
    void setWidth(double setWidth);
    void setCoorX(double setCoorX);
    void setCoorY(double setCoorY);
    void draw(ofstream &fp, char shapeCond);
    void draw(ofstream &fp);

private:
    int height; //height of rectangle
    int width;  //width of rectangle
    double coorX;   //coorX for one node of rectangle
    double coorY;   //coorY for one node of rectangle

};
#endif


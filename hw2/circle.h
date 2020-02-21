#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Circle
{
public:
    Circle(); //no parameter constructor
    double getRadius() const;
    double getCoorX() const;
    double getCoorY() const;
    void setRadius(double setRadius);
    void setCoorX(double setCoorX);
    void setCoorY(double setCoorY);
    void draw(ofstream &fp, char shapeCond);
    void draw(ofstream &fp);

private:

    double radius; //radius of circle
    double coorX;   //coorX of circle's center
    double coorY;   //coorY of circle's center
};

#endif

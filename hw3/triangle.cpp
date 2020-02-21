
#include "triangle.h"

using namespace std;


//-----------------------------TRIANGLE CLASS FUNCTIONS AND CONSTRUCTOR---------------------------------------------

//no parameter constructor
Triangle::Triangle(): length(0.0){} //no parameter constructor


Triangle::Triangle(vector <double> coorValue)
{
    coordinate[0] = coorValue[0];
    coordinate[1] = coorValue[1];
    coordinate[2] = coorValue[2];
    coordinate[3] = coorValue[3];
    coordinate[4] = coorValue[4];
    coordinate[5] = coorValue[5];

}

Triangle::Triangle(double lengthValue)
{
    length = lengthValue;
}


void Triangle::draw(ostream &fp) const
{
    fp << "<polygon points=\""<<coordinate[0]<<","<<coordinate[1]<<
       " "<<coordinate[2]<<","<<coordinate[3]<<" "<<coordinate[4]<<","
       <<coordinate[5]<<"\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;
}

//calculates container's perimeter length
double Triangle::calculatePerimeterLength()
{
    double perimeterLengthC = 3 * length;
    return perimeterLengthC;
}

//calculates container's area
void Triangle::calculateArea()
{
     area = (length*length) * 0.433;

}
 //-----------------------------------OVERLOADING FUNCTIONS-------------------------------------------------------

//overloads << to draw container
ostream& operator << (ostream& fp, const Triangle& object)
{
    fp << "<polygon points=\""<<object.coordinate[0]<<","<<object.coordinate[1]<<
       " "<<object.coordinate[2]<<","<<object.coordinate[3]<<" "<<object.coordinate[4]<<","
       <<object.coordinate[5]<<"\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;

    fp << "<polygon points=\"" << object.coordinate[0] << "," << object.coordinate[1] << " " << object.coordinate[2] << ","
       << object.coordinate[3] << " " << object.coordinate[4]
       << "," << object.coordinate[5] << "\" transform = \" rotate(60 " << object.coordinate[4] << " " << object.coordinate[5] <<
       ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;

    return fp;
}


//overload ++ to increment coordinate -> prefix version
Triangle Triangle::operator++()
{
    double cx1 = coordinate[0] + 1;
    double cy1 = coordinate[1] + 1;
    double cx2 = coordinate[2] + 1;
    double cy2 = coordinate[3] + 1;
    double cx3 = coordinate[4] + 1;
    double cy3 = coordinate[5] + 1;

    vector<double> coordinate{cx1, cy1, cx2, cy2, cx3, cy3};

    return Triangle(coordinate);
}

//overloads ++ to increment coordinate -> postfix version
Triangle Triangle::operator++(int)
{
    double tempx1 = coordinate[0];
    double tempy1 = coordinate[1];
    double tempx2 = coordinate[2];
    double tempy2 = coordinate[3];
    double tempx3 = coordinate[4];
    double tempy3 = coordinate[5];

    double cx1 = coordinate[0] + 1;
    double cy1 = coordinate[1] + 1;
    double cx2 = coordinate[2] + 1;
    double cy2 = coordinate[3] + 1;
    double cx3 = coordinate[4] + 1;
    double cy3 = coordinate[5] + 1;

    vector<double> coordinate{cx1, cy1, cx2, cy2, cx3, cy3};
    vector<double> temp{tempx1, tempy1, tempx2, tempy2, tempx3, tempy3};
    return Triangle(temp);
}

//overload -- to increment coordinate -> prefix version
Triangle Triangle::operator--()
{
    double cx1 = coordinate[0] - 1;
    double cy1 = coordinate[1] - 1;
    double cx2 = coordinate[2] - 1;
    double cy2 = coordinate[3] - 1;
    double cx3 = coordinate[4] - 1;
    double cy3 = coordinate[5] - 1;

    vector<double> coordinate{cx1, cy1, cx2, cy2, cx3, cy3};

    return Triangle(coordinate);
}

//overloads -- to increment coordinate -> postfix version
Triangle Triangle::operator--(int)
{
    double tempx1 = coordinate[0];
    double tempy1 = coordinate[1];
    double tempx2 = coordinate[2];
    double tempy2 = coordinate[3];
    double tempx3 = coordinate[4];
    double tempy3 = coordinate[5];

    double cx1 = coordinate[0] - 1;
    double cy1 = coordinate[1] - 1;
    double cx2 = coordinate[2] - 1;
    double cy2 = coordinate[3] - 1;
    double cx3 = coordinate[4] - 1;
    double cy3 = coordinate[5] - 1;

    vector<double> coordinate{cx1, cy1, cx2, cy2, cx3, cy3};
    vector<double> temp{tempx1, tempy1, tempx2, tempy2, tempx3, tempy3};
    return Triangle(temp);
}

//overloads + to increment length and return a new object
 const Triangle operator +(const Triangle& object, double value)
{
    double newLength = object.length + value;
    return Triangle(newLength);
}

//overloads - to decrement length and return a new object
 const Triangle operator -(const Triangle& object, double value)
{
    double newLength = object.length - value;
    return Triangle(newLength);
}

//overloads == to compare shapes respect to their areas
bool operator ==(const Triangle& object1, const Triangle& object2)
{
    double area1 = object1.area;
    double area2 = object2.area;
    return (area1 == area2);
}

//overloads != to compare shapes respect to their areas
bool operator !=(const Triangle& object1, const Triangle& object2)
{
    double area1 = object1.area;
    double area2 = object2.area;
    return (area1 != area2);
}

int Triangle:: countShape = 0;

static double totalAreaTri(){
    return 0;
};
   
static double totalPerimeterTri(){
    return 0;
};


//---------------------------------TRIANGLE CLASS GETTERS------------------------------------------------------------

inline double Triangle::getLength() const
{ return length;
}

vector < double > Triangle::getCoordinate() const
{ return coordinate;
}

//--------------------------------TRIANGLE SETTERS----------------------------------------------------------------

void Triangle::setLength(double setLength) {
    length = setLength;
}

void Triangle::setCoordinate(vector < double > setCoordinate)
{
    coordinate = setCoordinate;
}

#include "triangle.h"
#include "shape.h"
using namespace std;
using namespace Shape_;


//-----------------------------CONSTRUCTORS AND OTHER FUNCS---------------------------------------------

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


void Triangle::draw(ostream &fp)
{
    vector <double> coor = getCoordinate();

    fp << "<polygon points=\""<<coor[0]<<","<<coor[1]<<
       " "<<coor[2]<<","<<coor[3]<<" "<<coor[4]<<","
       <<coor[5]<<"\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;
}

//calculates container's perimeter length
double Triangle::perimeter()
{
    double objPer = 3 * length;
    shapePer = objPer;
    return shapePer;
}

//calculates container's area
double Triangle::area()
{
    double objArea = (length*length) * 0.433;
    shapeArea = objArea;
    return shapeArea;

}
 //-----------------------------------OP. OVERLOADING FUNCTIONS-------------------------------------------------------

//overloads << to draw container
ostream& operator << (ostream& fp, const Triangle& object)
{   
    vector <double> coor_ = object.getCoordinate();


    fp << "<polygon points=\""<<coor_[0]<<","<<coor_[1]<<
       " "<<coor_[2]<<","<<coor_[3]<<" "<<coor_[4]<<","
       <<coor_[5]<<"\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" <<endl;

    fp << "<polygon points=\"" << coor_[0] << "," << coor_[1] << " " << coor_[2] << ","
       << coor_[3] << " " << coor_[4]
       << "," << coor_[5] << "\" transform = \" rotate(60 " << coor_[4] << " " << coor_[5] <<
       ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;

    return fp;
}


//overload ++ to increment coordinate -> prefix version
Shape& Triangle::operator++()
{
    double cx1 = coordinate[0] + 1;
    double cy1 = coordinate[1] + 1;
    double cx2 = coordinate[2] + 1;
    double cy2 = coordinate[3] + 1;
    double cx3 = coordinate[4] + 1;
    double cy3 = coordinate[5] + 1;

    vector<double> coordinate{cx1, cy1, cx2, cy2, cx3, cy3};
    Shape* ptr = new Triangle(coordinate);
    return *ptr;
}

//overloads ++ to increment coordinate -> postfix version
Shape& Triangle::operator++(int)
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
    Shape *ptr = new Triangle(temp);
    return *ptr;
}

//overload -- to increment coordinate -> prefix version
Shape& Triangle::operator--()
{
    double cx1 = coordinate[0] - 1;
    double cy1 = coordinate[1] - 1;
    double cx2 = coordinate[2] - 1;
    double cy2 = coordinate[3] - 1;
    double cx3 = coordinate[4] - 1;
    double cy3 = coordinate[5] - 1;

    vector<double> coordinate{cx1, cy1, cx2, cy2, cx3, cy3};
    Shape* ptr = new Triangle(coordinate);
    return *ptr;
}

//overloads -- to increment coordinate -> postfix version
Shape& Triangle::operator--(int)
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
    Shape* ptr = new Triangle(temp);
    return *ptr;
}

//overloads + to increment length and return a new object
 const Triangle Triangle::operator +(double value)
{
    double newLength = length + value;
    return Triangle(newLength);
}

//overloads - to decrement length and return a new object
 const Triangle Triangle::operator -(double value)
{
    double newLength = length - value;
    return Triangle(newLength);
}

/*//overloads == to compare shapes respect to their areas
bool Triangle::operator ==(const Triangle& obj) const
{
    return (area == obj.area);
}

//overloads != to compare shapes respect to their areas
bool Triangle::operator !=(const Triangle& obj) const
{
    return (area != obj.area);
}*/



//---------------------------------GETTERS------------------------------------------------------------

double Triangle::getLength() const
{ 
    return length;
}

vector < double > Triangle::getCoordinate() const
{ 
    return coordinate;
}


//--------------------------------SETTERS----------------------------------------------------------------

void Triangle::setLength(double setLength) {
    length = setLength;
}

void Triangle::setCoordinate(vector < double > setCoordinate)
{
    coordinate = setCoordinate;
}


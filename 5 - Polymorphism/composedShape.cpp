#include "composedShape.h"
#include "shape.h"
#include "polygonDyn.h"
#include <type_traits>
#include <typeinfo>
#include <memory>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using namespace Shape_;


//-----------------------------COMPOSED SHAPE CLASS OVERLOADED CONSTRUCTORS------------------------------------------
ComposedShape::ComposedShape()
{
    int heightC = 0.0;
    int widthC = 0.0;
    double radiusC = 0.0;
    double lengthC = 0.0;
    int heightS = 0.0;
    int widthS = 0.0;
    double radiusS = 0.0;
    double lengthS = 0.0;
}

ComposedShape::ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3, double cnstrDimension_4)
{

    if(cnstrshapeC == 'R' && cnstrshapeS == 'R')
    {

        shapeC = cnstrshapeC;
        heightC = cnstrDimension_1;
        widthC = cnstrDimension_2;

        shapeS = cnstrshapeS;
        heightS = cnstrDimension_3;
        widthS = cnstrDimension_4;
        R.setWidth(widthC);
        R.setHeight(heightC);
    }
}

ComposedShape::ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3)
{
    if (cnstrshapeC == 'R') {
        shapeC = cnstrshapeC;
        heightC = cnstrDimension_1;
        widthC = cnstrDimension_2;
        R.setWidth(widthC);
        R.setHeight(heightC);
    }
    if (cnstrshapeC == 'T') {
        vector<double> triangleC;
        shapeC = cnstrshapeC;
        lengthC = cnstrDimension_1;
        triangleC.resize(6);
        triangleC[0] = lengthC/2;
        triangleC[1]= 0.0;
        triangleC[2]= 0.0;
        triangleC[3]= 0.866*lengthC;
        triangleC[4]= lengthC;
        triangleC[5]= 0.866*lengthC;
        T.setCoordinate(triangleC);
    }

    if (cnstrshapeC == 'C') {
        shapeC = cnstrshapeC;
        radiusC = cnstrDimension_1;
        C.setRadius(radiusC);
        C.setCoorX(radiusC);
        C.setCoorY(radiusC);
    }

    if (cnstrshapeS == 'R') {
        shapeS = cnstrshapeS;
        heightS = cnstrDimension_2;
        widthS = cnstrDimension_3;
    }
    if (cnstrshapeS == 'T') {
        shapeS = cnstrshapeS;
        lengthS = cnstrDimension_3;
    }

    if (cnstrshapeS == 'C')
    {
        shapeS = cnstrshapeS;
        radiusS = cnstrDimension_3;
    }
}

ComposedShape::ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2)
{
    if (cnstrshapeC == 'T') {

        vector<double> triangleC(6);
        lengthC = cnstrDimension_1;
        shapeC = cnstrshapeC;
        triangleC.resize(6);
        triangleC[0] = lengthC/2;
        triangleC[1]= 0.0;
        triangleC[2]= 0.0;
        triangleC[3]= 0.866*lengthC;
        triangleC[4]= lengthC;
        triangleC[5]=0.866*lengthC;
        T.setCoordinate(triangleC);
    }

    if (cnstrshapeC == 'C') {

        radiusC = cnstrDimension_1;
        shapeC = cnstrshapeC;
        C.setRadius(radiusC);
        C.setCoorX(radiusC);
        C.setCoorY(radiusC);

    }

    if (cnstrshapeS == 'T')
    {
        shapeS = cnstrshapeS;
        lengthS = cnstrDimension_2;

    }

    if (cnstrshapeS == 'C')
    {
        shapeS = cnstrshapeS;
        radiusS = cnstrDimension_2;
    }


}

//-------------------------------------COMPOSED SHAPES CLASS SETTERS-------------------------------------------------------

void ComposedShape::setHeightC(double setHeight)
{   
    heightC=setHeight;
}

void ComposedShape::setWidthC(double setWidth)
{   
    widthC=setWidth;
}

void ComposedShape::setRadiusC(double setRadius)
{   
    radiusC=setRadius;
}

void ComposedShape::setLengthC(double setLength)
{  
    lengthC = setLength;
}

void ComposedShape::setHeightS(double setHeight)
{
    heightS=setHeight;
}

void ComposedShape::setWidthS(double setWidth)
{
    widthS=setWidth;
}

void ComposedShape::setRadiusS(double setRadius)
{   radiusS=setRadius;
}

void ComposedShape::setLengthS(double setLength)
{
    lengthS = setLength;
}
void ComposedShape::setShapeNumber(int setNumber)
{
    shapeCountS = setNumber;
}

//--------------------------------CoOMPOSED SHAPES OPERATOR OVERLOADING FUNCTIONS------------------------------------


ostream& operator<<(ostream& fp, const ComposedShape& compObject)
{
    
    vector <PolygonDyn> smallShp_ = compObject.getSmallShape();

    for(auto i=0; i<compObject.getShapeNumber() ; ++i)
    {   
        fp<<smallShp_[i];
    }

   return fp;
}


//--------------------------------COMPOSED SHAPES CLASS PRIVATE FUNCTIONS---------------------------------------------

//start function to create the composed shape
void ComposedShape::start(ofstream &fp)
{
    optimalFit();
    drawShp(fp);
}

//draw function for a composed shape
void ComposedShape::drawShp(ofstream &fp)
{

    int i=0;
    char containShape = getShapeC();

  

    if (containShape == 'R'){
        R.draw(fp);
        for(i=0; i<getShapeNumber() ;i++)
        {
            fp<<smallShp[i];
        }
    }

    if (containShape == 'C'){

        C.draw(fp);
        for(i=0; i<getShapeNumber() ;i++)
        {
            fp<<smallShp[i];
        }
    }


    if (containShape == 'T'){
        T.draw(fp);

       for(i=0; i<getShapeNumber() ;i++)
        {
            fp<<smallShp[i];
        }
    }

   

}

//function to detect the kind of composed shape and function calling
void ComposedShape::optimalFit ()
{
   char containShape = getShapeC();
   char smallShape = getShapeS();


    if (containShape == 'R' && smallShape == 'R')
        RinR();

    if (containShape == 'R' && smallShape == 'C')
        CinR();

    if (containShape == 'R' && smallShape == 'T')
        TinR();

    if (containShape == 'C' && smallShape == 'C')
        CinC();
    
    if (containShape == 'C' && smallShape == 'R')
        RinC();

    if (containShape == 'C' && smallShape == 'T')
        TinC();

    if (containShape == 'T' && smallShape == 'T')
        TinT();

    if (containShape == 'T' && smallShape == 'C')
        CinT();

    if (containShape == 'T' && smallShape == 'R')
        RinT();

}

//modify coordinates for rectangle objects (small shapes)
void ComposedShape::modifyR(int counter, double coorX, double coorY)
{

    Rectangle temp((double)heightS, (double)widthS);
    temp.setCoorX(coorX);
    temp.setCoorY(coorY);
    PolygonDyn objRec(temp);
    smallShp[counter] = objRec;
    
    
}

//modify coordinates for circle objects (small shapes)
void ComposedShape::modifyC(int counter, double coorX, double coorY)
{
    Circle temp(radiusS);
    temp.setCoorX(coorX - radiusS);
    temp.setCoorY(coorY - radiusS);
    PolygonDyn objCir(temp);
    smallShp[counter] = objCir;
    
}

//modify coordinates for triangle objects (small shapes)
void ComposedShape::modifyT(int counter, double coorX1, double coorY1,double coorX2, double coorY2,double coorX3, double coorY3)
{
    Triangle temp(lengthS);
    vector<double> temp2{coorX1, coorY1, coorX2, coorY2, coorX3, coorY3};
    temp.setCoordinate(temp2);
    PolygonDyn objTri(temp);
    smallShp[counter] =  objTri;
   
}

//calculation needed values to draw a rectangle in rectangle
void ComposedShape::RinR()
{

    double coorX=0;
    decltype(coorX) coorY=0;
    int counter=0;
    double cwidth = getWidthC();
    double cheight = getHeightC();
    double swidth = getWidthS();
    double sheight = getHeightS();
    smallShp.resize(5000);

    for( auto i=0 ; i<(int)(cwidth/swidth) ; ++i)
    {
        coorX = swidth*i;

        for( auto j=0 ; j<(int)(cheight/sheight) ; ++j)
        {
            coorY = sheight*j;
            modifyR(counter,coorX,coorY);
            counter++;

        }
    }

    double remainHeight = cheight-(cheight/sheight)*sheight;

    if(remainHeight>0) {

        for( auto i=0 ; i<(int)(cwidth/sheight) ; ++i)
        {
            coorX = sheight*i;

            for( auto j=0 ; j<(int)(remainHeight/swidth) ; ++j)
            {
                coorY = (cheight - remainHeight) + (swidth * j);

                modifyR(counter,coorX,coorY);
                counter++;

            }
        }
    }

    double remainWidth = cwidth - (cwidth/swidth)*swidth;

    if(remainWidth>0){

        for( auto i=0 ; i<(int)(remainWidth/sheight) ; ++i)
        {
            coorX = (cwidth - remainWidth) + (sheight*i);

            for( auto j=0 ; j<(int)(cheight/swidth) ; ++j)
            {
                coorY = swidth*j;

                modifyR(counter,coorX,coorY);
                counter++;
            }
        }
    }

    setShapeNumber(counter);

    double remainArea=0;

    remainArea = cheight*cwidth - (counter*sheight*swidth);

    if(counter == 0)
        remainArea = cheight*cwidth;

    cout<<"--Rectangle in Rectangle --"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;


}

//calculation needed values to draw a circle in rectangle

void ComposedShape::CinR()
{

    int counter=0;
    double coorX=0;
    double coorY=0;
    double cheight = getHeightC();
    double cwidth = getWidthC();
    double sradius = getRadiusS();
    smallShp.resize(5000);
    for( auto i=0; i< (int)(cheight/(sradius*1.732)); ++i)
    {

        for( auto j=0; j<(int)(cwidth/(sradius*2)); ++j)
        {

            coorY = sradius + sradius * i * 1.732;

            if (i % 2 == 0)
                coorX = sradius + sradius * j * 2;

            if (i % 2 != 0)
                coorX = 2 * sradius + sradius * j * 2;

            if (coorX + sradius < cwidth && coorY + sradius < cheight)
            {
                modifyC(counter, coorX, coorY);
                counter++;

            }
        }
    }

    setShapeNumber(counter);

    double remainArea=0;

    remainArea = cheight*cwidth - (counter*sradius*sradius*3.142);

    if(counter == 0)
        remainArea = cheight*cwidth;

    cout<<"--Circle in Rectangle --"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;

}

//calculation needed values to draw a circle in circle

void ComposedShape::CinC()
{
    
    int counter=0;
    double s_coorX=0;
    double s_coorY=0;
    double cradius = getRadiusC();
    double sradius = getRadiusS();
    double c_coorX = getRadiusC();
    double c_coorY = getRadiusC();
    smallShp.resize(5000);
    for( auto i=0 ; i<(int)((2*cradius)/(sradius*1.732)) ; ++i)
    {

        for( auto j=0 ; j<(int)((2*cradius)/(2*sradius)) ; ++j)
        {
            s_coorY = sradius + sradius*i*1.732;

            if(i%2 == 0)
                s_coorX = sradius + sradius*j*2;

            if(i%2!=0)
                s_coorX = 2*sradius + sradius*j*2;

            if(((s_coorX - c_coorX)*(s_coorX - c_coorX)) + ((s_coorY - c_coorY)*(s_coorY - c_coorY)) < (cradius-sradius)*(cradius-sradius))
            {

                modifyC(counter, s_coorX, s_coorY);
                counter++;
            }

        }
    }

    setShapeNumber(counter);
    double remainArea=0;

    remainArea = 3.142*cradius*cradius - (counter*sradius*sradius*3.142);

    if(counter == 0)
        remainArea = 3.142*cradius*cradius;

    cout<<"--Circle in Circle--"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;

}

//calculation needed values to draw a rectangle in circle
void ComposedShape::RinC()
{

    
    int counter =0;
    double s_coorX=0;
    double s_coorY=0;
    double cradius = getRadiusC();
    double swidth = getWidthS();
    double sheight = getHeightS();
    double c_coorX = getRadiusC();
    double c_coorY = getRadiusC();
    smallShp.resize(5000);

    for( auto i=0 ; i<(int)((2*cradius)/swidth); ++i)
    {
        s_coorX = swidth * i;

        for ( auto j = 0; j < (int)(2 * cradius) / sheight; ++j)
        {
            s_coorY = sheight * j;

            if ((((s_coorX - c_coorX) * (s_coorX - c_coorX)) + ((s_coorY - c_coorY) * (s_coorY - c_coorY)) <
                 cradius * cradius) &&
                (((s_coorX - c_coorX) * (s_coorX - c_coorX)) +
                 ((s_coorY - c_coorY + sheight) * (s_coorY - c_coorY + sheight)) < cradius * cradius) &&
                (((s_coorX - c_coorX + swidth) * (s_coorX - c_coorX + swidth)) +
                 ((s_coorY - c_coorY + sheight) * (s_coorY - c_coorY + sheight)) < cradius * cradius) &&
                (((s_coorX - c_coorX + swidth) * (s_coorX - c_coorX + swidth)) +
                 ((s_coorY - c_coorY ) * (s_coorY - c_coorY)) < cradius * cradius))
            {


                modifyR(counter,s_coorX,s_coorY);
                counter++;

            }
        }
    }

    setShapeNumber(counter);

    double remainArea=0;

    remainArea = cradius*cradius*3.142 - (counter*sheight*swidth);

    if(counter == 0)
        remainArea = cradius*cradius*3.142;

    cout<<"--Rectangle in Circle--"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;

}

//calculation needed values to draw a rectangle in triangle
void ComposedShape::RinT()
{
    
    int counter=0;
    double coorX=0;
    double coorY=0;
    double clength = getLengthC();
    double sheight = getHeightS();
    double swidth = getWidthS();

    double c_x1 = clength/2;
    double c_y1= 0.0;
    double c_x2 = 0.0;
    double c_y2= 0.866*clength;
    double c_x3 = clength;
    double c_y3= 0.866*clength;
    smallShp.resize(5000);


    for( auto i=0 ; i<(int)(((clength*0.866)/sheight)) ; ++i)
    {
        coorY = sheight *i;

        for ( auto j = 0; j < (int)(clength / swidth) ; ++j) {//calculates new value f x axis

            coorX = swidth * j;

            if( (((coorY - c_y1)/(clength/2 - coorX) >= (clength*0.866)/(clength/2))) &&
                (((coorY - c_y1)/(clength/2 - coorX - swidth) >= (clength*0.866)/(clength/2))) &&
                (((coorY + sheight - c_y1)/(clength/2 - coorX) >= (clength*0.866)/(clength/2))) &&
                (((coorY  + sheight - c_y1)/(clength/2 - coorX - swidth) >= (clength*0.866)/(clength/2)))
                && (coorX < clength/2))
            {

                modifyR(counter,coorX,coorY);
                counter ++;
            }

            if( (((coorY - c_y1)/(coorX - clength/2) >= (clength*0.866)/(clength/2))) &&
                (((coorY - c_y1)/(coorX + swidth - clength/2) >= (clength*0.866)/(clength/2))) &&
                (((coorY + sheight - c_y1)/(coorX - clength/2) >= (clength*0.866)/(clength/2))) &&
                (((coorY  + sheight - c_y1)/(coorX + swidth - clength/2) >= (clength*0.866)/(clength/2)))
                && (coorX + swidth > clength/2) )
            {

                modifyR(counter,coorX,coorY);
                counter ++;

            }

            if( (((coorY - c_y1)/(clength/2 - coorX) >= (clength*0.866)/(clength/2))) &&
                (((coorY - c_y1)/(coorX + swidth - clength/2) >= (clength*0.866)/(clength/2))) &&
                (((coorY + sheight - c_y1)/(clength/2 - coorX) >= (clength*0.866)/(clength/2))) &&
                (((coorY  + sheight - c_y1)/(coorX + swidth - clength/2) >= (clength*0.866)/(clength/2)))
                && (coorX < clength/2) && (coorX + swidth > clength/2))
            {
                modifyR(counter,coorX,coorY);
                counter ++;
            }

        }
    }

    setShapeNumber(counter);

    double remainArea=0;

    remainArea = clength*(clength*0.866)*0.5 - (counter*sheight*swidth);

    if(counter == 0)
        remainArea = clength*clength*0.866*0.5;

    cout<<"--Rectangle in Triangle--"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;
}

//calculation needed values to draw a circle in triangle
void ComposedShape::CinT()
{
    int counter=0;
    double s_coorX = 0;
    double s_coorY = 0;
    double clength = getLengthC();
    double sradius = getRadiusS();
    double c_x1 = clength/2;
    double c_y1= 0.0;
    double c_x2 = 0.0;
    double c_y2= 0.866*clength;
    double c_x3 = clength;
    double c_y3= 0.866*clength;
    smallShp.resize(5000);

    for( auto i=(int)((clength*0.866) /(sradius * 1.732)) ; i>0 ; --i)
    {

        for ( auto j = (int)((clength - (2 * (sradius * 1.732 - sradius))) / (2 * sradius)); j>0; --j)
        {

            if (i % 2 == 1) {
                s_coorX = clength - sradius * j * 2  + sradius*0.280;
                s_coorY = clength * 0.866 - (sradius * i * 1.732 - sradius*0.732);

                if(((s_coorY - c_y1)/(clength/2 - s_coorX) > (clength*0.867)/(clength/2)) && (s_coorX < clength/2))
                {
                    modifyC(counter, s_coorX, s_coorY);
                    counter ++;

                }

                else if(((s_coorY - c_y1)/( s_coorX - clength/2) > (clength*0.867)/(clength/2)) && (s_coorX > clength/2))
                {
                    modifyC(counter, s_coorX, s_coorY);
                    counter ++;

                }

                else if(s_coorX== clength/2)
                {
                    modifyC(counter, s_coorX, s_coorY);
                    counter ++;

                }

            } else {
                s_coorX = clength - (sradius*0.732 + sradius * j * 2);
                s_coorY = clength * 0.866 - (sradius * i * 1.732 - sradius*0.732);

                if(((s_coorY - c_y1)/(clength/2 - s_coorX) > (clength*0.867)/(clength/2)) && (s_coorX < clength/2))
                {
                    modifyC(counter, s_coorX, s_coorY);
                    counter ++;


                }

                else if(((s_coorY - c_y1)/( s_coorX - clength/2) > (clength*0.867)/(clength/2)) && (s_coorX > clength/2))
                {
                    modifyC(counter, s_coorX, s_coorY);
                    counter ++;


                }

                else if(s_coorX== clength/2)
                {
                    modifyC(counter, s_coorX, s_coorY);
                    counter ++;

                }
            }
        }
    }

    setShapeNumber(counter);

    double remainArea=0;

    remainArea = clength*(clength*0.866)*0.5 - (counter*sradius*sradius*3.142);

    if(counter == 0)
        remainArea = clength*(clength*0.866)*0.5;

    cout<<"--Circle in Triangle--"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;
}

//calculation needed values to draw a triangle in rectangle
void ComposedShape::TinR()
{

    int counter = 0;
    double cheight = getHeightC();
    double cwidth = getWidthC();
    double slength = getLengthS();
    double s_x1 = 0.0;
    double s_y1= 0.0;
    double s_x2 = 0.0;
    double s_y2= 0.0;
    double s_x3 = 0.0;
    double s_y3= 0.0;
    smallShp.resize(5000);

    for( auto i=0 ; i<(int)(cheight/(slength*1.732))  ; ++i)
    {

        for( auto j=0 ; j<(int)(cwidth/slength) ; ++j)
        {

            s_x1 = j * slength;
            s_y1 = i * slength * 1.732;
            s_x2 = slength + j * slength;
            s_y2 = i * slength * 1.732;
            s_x3 = (slength / 2) + j * slength;
            s_y3 = slength * 0.866 + i * slength * 1.732;

            if((s_x3< cwidth-slength)&&(s_y3 < cheight-slength))
            {
                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;


                if(j!=(int)((cwidth-slength)/slength) - 1)
                {
                    modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                    counter ++;


                }
            }

        }
    }

    for( auto i=0 ; i<(int)(cheight/(slength*1.732)) ; ++i)
    {

        for( auto j=0 ; j<(int)(cwidth/slength) ; ++j)
        {

            s_x1 = slength/2 + j * slength;
            s_y1 = slength*0.866 + i * slength * 1.732;
            s_x2 = j * slength;
            s_y2 = slength*1.732 + i * slength * 1.732;
            s_x3 = slength + j * slength;
            s_y3 = slength * 1.732 + i * slength * 1.732;

            if((s_x2< cwidth-slength)&&(s_y2 < cheight-slength))
            {
                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;


                if(j != (int)((cwidth-slength)/slength) - 1)
                {
                    modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                    counter ++;


                }
            }
        }
    }

    setShapeNumber(counter);

    double remainArea=0;

    remainArea = cheight*cwidth - (counter*slength*slength*0.866*0.5);

    if(counter == 0)
        remainArea = cheight*cwidth;

    cout<<"--Triangle in Rectangle --"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;

}

//calculation needed values to draw a triangle in circle
void ComposedShape::TinC()
{
    int counter=0;
    double cradius = getRadiusC();
    double slength = getLengthS();
    double c_coorX = cradius;
    double c_coorY = cradius;
    double s_x1 = 0.0;
    double s_y1= 0.0;
    double s_x2 = 0.0;
    double s_y2= 0.0;
    double s_x3 = 0.0;
    double s_y3= 0.0;
    smallShp.resize(5000);

    for( auto i=0 ; i<(int)((2*cradius)/(slength*1.732)) ; ++i)
    {

        for( auto j=0 ; j<(int)((2*cradius)/slength); ++j)
        {
            s_x1 = j * slength;
            s_y1 = i * slength * 1.732;
            s_x2 = slength + j * slength;
            s_y2 = i * slength * 1.732;
            s_x3 = (slength / 2) + j * slength;
            s_y3 = slength * 0.866 + i * slength * 1.732;

            if ((((c_coorX - s_x1) * (c_coorX - s_x1)) + ((c_coorY - s_y1) * (c_coorY - s_y1)) < ((cradius-slength)*(cradius-slength))) &&
                (((c_coorX - s_x2) * (c_coorX - s_x2)) + ((c_coorY - s_y2) * (c_coorY - s_y2)) < ((cradius-slength)*(cradius-slength))) &&
                (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) < ((cradius-slength)*(cradius-slength)))) {
                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;


            }

            if( (((c_coorX - s_x1 - slength*1.5) * (c_coorX - s_x1 - slength*1.5)) +
                ((c_coorY - s_y1 - slength*0.866) * (c_coorY - s_y1 - slength*0.866)) < ((cradius-slength)*(cradius-slength))) &&
                (((c_coorX - s_x2) * (c_coorX - s_x2)) + ((c_coorY - s_y2) * (c_coorY - s_y2)) < ((cradius-slength)*(cradius-slength))) &&
                (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) < ((cradius-slength)*(cradius-slength)))) {
                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;


            }
        }
    }

    for( auto i=0 ; i<(int)((2*cradius)/(slength*1.732)) ; ++i)
    {

        for( auto j=0 ; j<(int)((2*cradius)/slength)   ; ++j)
        {

            s_x1 = slength/2 + j * slength;
            s_y1 = slength*0.866 + i * slength * 1.732;
            s_x2 = j * slength;
            s_y2 = slength*1.732 + i * slength * 1.732;
            s_x3 = slength + j * slength;
            s_y3 = slength * 1.732 + i * slength * 1.732;

            if ( (((c_coorX - s_x1) * (c_coorX - s_x1)) + ((c_coorY - s_y1) * (c_coorY - s_y1)) <= ((cradius-slength)*(cradius-slength))) &&
                 (((c_coorX - s_x2) * (c_coorX - s_x2)) + ((c_coorY - s_y2) * (c_coorY - s_y2)) <= ((cradius-slength)*(cradius-slength))) &&
                 (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) <= ((cradius-slength)*(cradius-slength)))) {
                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;


            }
            if ( (((c_coorX - s_x1) * (c_coorX - s_x1)) + ((c_coorY - s_y1) * (c_coorY - s_y1)) <= ((cradius-slength)*(cradius-slength))) &&
                 (((c_coorX - s_x2 + 1.5*slength) * (c_coorX - s_x2 + 1.5*slength)) +
                 ((c_coorY - s_y2 + slength*0.866) * (c_coorY - s_y2 + slength*0.866)) <= ((cradius-slength)*(cradius-slength))) &&
                 (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) <= ((cradius-slength)*(cradius-slength))))
            {
                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;


            }
        }
    }

    setShapeNumber(counter);

    double remainArea=0;

    remainArea = cradius*cradius*3.142 - (counter*slength*slength*0.866*0.5);

    if(counter == 0)
        remainArea = cradius*cradius*3.142;

    cout<<"--Triangle in Circle --"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;

}

//calculation needed values to draw a triangle in triangle
void ComposedShape::TinT()
{

    int counter=0;
    double clength = getLengthC();
    double slength = getLengthS();

    double s_x1 = 0.0;
    double s_y1= 0.0;
    double s_x2 = 0.0;
    double s_y2= 0.0;
    double s_x3 = 0.0;
    double s_y3= 0.0;
    smallShp.resize(5000);
    int y = (int)((clength*0.866)/(slength*1.732));
    int x = (int)((clength)/slength);

    for( auto i=0 ; i<y ; ++i)
    {
        for( auto j=0 ; j<x; ++j)
        {
            s_x1 = j * slength+(y-i-1)*(slength);
            s_y1 = i * slength * 1.732;
            s_x2 = slength + j * slength+(y-i-1)*(slength);
            s_y2 = i * slength * 1.732;
            s_x3 = (slength / 2) + j * slength+(y-i-1)*(slength);
            s_y3 = slength * 0.866 + i * slength * 1.732;

            if((s_y3+clength*0.867)/1.732 >= s_x3 +slength/2&&
               (s_y2+clength*0.867)/1.732 >= s_x2 +slength/2&&
               (s_y1+clength*0.867)/1.732 >= s_x1+slength/2 &&
               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867) <= (clength*0.867)))
            {

                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;
                

            }
            if((s_y3+clength*0.867)/1.732 >= s_x3&&
               (s_y2+clength*0.867)/1.732 >= s_x2&&
               (s_y1+clength*0.867)/1.732 >= s_x1 &&
               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867) <= (clength*0.867)))
            {

                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;
                
            }

        }
    }

    for( auto i=0 ; i<y ; ++i)
    {

        for( auto j=0 ; j<x  ; ++j)
        {

            s_x1 = slength/2 + j * slength+(y-i-1)*(slength);
            s_y1 = slength*0.866 + i * slength * 1.732;
            s_x2 = j * slength+(y-i-1)*(slength);
            s_y2 = slength*1.732 + i * slength * 1.732;
            s_x3 = slength + j * slength+(y-i-1)*(slength);
            s_y3 = slength * 1.732 + i * slength * 1.732;



            if(((s_y3+clength*0.867)/1.732 >= s_x3 +(double)slength/2&&
                (s_y2+clength*0.867)/1.732 >= s_x2 +(double)slength/2&&
                (s_y1+clength*0.867)/1.732 >= s_x1 +(double)slength/2) &&
               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867) <= (clength*0.867)))
            {
                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;
                

            }
            if((s_y3+clength*0.867)/1.732 >= s_x3&&
               (s_y2+clength*0.867)/1.732 >= s_x2&&
               (s_y1+clength*0.867)/1.732 >= s_x1 &&
               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867) <= (clength*0.867)))
            {
                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
                counter ++;
                
            }

        }
    }

    setShapeNumber(counter);
    double remainArea=0;

    remainArea = clength*clength*0.866*0.5 - (counter*slength*slength*0.866*0.5);

    if(counter == 0)
        remainArea = clength*clength*0.866*0.5;

    cout<<"--Triangle in Triangle --"<<endl<<"Remain area:"<<remainArea<<endl<< "Number of small shapes:"<<counter<<endl<<endl;

}


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "polygon.h"
#include "polygonDyn.h"
#include "polygonVect.h"
#include "composedShape.h"
using namespace std;
using namespace Shape_;

void test();
void printAll(vector<Shape*> object);
void printPoly(vector<Shape*> object);
vector <Shape*> convertAll(vector <Shape*> shapes);
void sortShapes(vector <Shape*> shapes);


int main()
{
	test();

	return 0;
}


void test()
{
	 //creating a file and object to create and draw composed shape CinC
    ofstream myfile;
    myfile.open("outputRinC.svg");
    myfile << "<svg>" << endl;
    ComposedShape RC('C','R', 200, 10, 5);
    RC.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

    //creating a file and object to create and draw composed shape RinR
    myfile.open("outputRinR.svg");
    myfile << "<svg>" << endl;
    ComposedShape RR('R','R', 200, 100, 13, 30);
    RR.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

    //creating a file and object to create and draw composed shape CinR
    myfile.open("outputCinR.svg");
    myfile << "<svg>" << endl;
    ComposedShape CR('R','C', 400, 200, 10);
    CR.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

    //creating a file and object to create and draw composed shape CinT
    myfile.open("outputCinT.svg");
    myfile << "<svg>" << endl;
    ComposedShape CT('T','C', 200, 10);
    CT.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

    //creating a file and object to create and draw composed shape RinT
    myfile.open("outputRinT.svg");
    myfile << "<svg>" << endl;
    ComposedShape RT('T','R', 200, 10, 6);
    RT.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

    //creating a file and object to create and draw composed shape TinR
    myfile.open("outputTinR.svg");
    myfile << "<svg>" << endl;
    ComposedShape TR('R','T', 350, 300, 20);
    TR.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

    //creating a file and object to create and draw composed shape TinC
    myfile.open("outputTinC.svg");
    myfile << "<svg>" << endl;
    ComposedShape TC('C','T', 200, 10);
    TC.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();


    myfile.open("outputCinC.svg");
    myfile << "<svg>" << endl;
    ComposedShape CC('C','C', 200, 10);
    CC.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();
   
   
    //creating a file and object to create and draw composed shape TinT(there is an error of overlap!!!!!!!!)
    myfile.open("outputTinT.svg");
    myfile << "<svg>" << endl;
    ComposedShape TT('T','T', 200, 20);
    TT.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

}

//prints all shapes to SVG file
void printAll(ostream& output, vector<Shape*> object)
{	
	ofstream fp; 

	for(int i=0 ; i<object.size() ; ++i)
		object[i]->draw(fp);

}

//prints all polygon shapes to SVG file
void printPoly(ostream& output, vector<Shape*> object)
{	
	ofstream fp;
	for(int i=0 ; i<object.size() ; ++i)
	{
		if(typeid(*object[i]).name() == typeid(PolygonDyn).name() || typeid(*object[i]).name() == typeid(PolygonVect).name())
		{
			object[i]->draw(fp);
		}
	}	

}

//converts all shapes to polygon and returns a new vector with the new shapes
vector <Shape* > convertAll(vector <Shape*> shapes)
{
	vector<Shape*> newShape_;
	Shape* shape_;

	for(auto vect : shapes)
	{
		if(typeid(*vect).name() == typeid(Rectangle).name())
		{
			shape_ = new PolygonDyn((Rectangle &)*vect);
			newShape_.push_back(shape_);

		}	

		else if(typeid(*vect).name() == typeid(Circle).name())
		{
			shape_ = new PolygonDyn((Circle &)*vect);
			newShape_.push_back(shape_);
			
		}	

		else if(typeid(*vect).name() == typeid(Triangle).name())
		{
			shape_ = new PolygonDyn((Triangle &)*vect);
			newShape_.push_back(shape_);
			
		}	

		else if(typeid(*vect).name() == typeid(PolygonDyn).name() || typeid(*vect).name() == typeid(PolygonVect).name())
		{
			newShape_.push_back(vect);
			
		}	
	}

	return newShape_;

}

//increasingly sorts them with respect to their areas
void sortShapes(vector <Shape*> shapes)
{
}

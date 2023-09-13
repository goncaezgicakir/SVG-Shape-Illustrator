
//GONCA EZGI CAKIR
//151044054
//CSE241
//HW2
//28.10.2018

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "composedShape.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

using namespace std;

int main()
{
    //creating a file and object to create and draw composed shape CinC
    ofstream myfile;
    myfile.open("outputCinC.svg");
    myfile << "<svg>" << endl;
    ComposedShape CC('C', 'C', 200, 15);
    CC.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

    //creating a file and object to create and draw composed shape RinC
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

    //creating a file and object to create and draw composed shape TinT(there is an error of overlap!!!!!!!!)
    myfile.open("outputTinT.svg");
    myfile << "<svg>" << endl;
    ComposedShape TT('T','T', 200, 20);
    TT.start(myfile);
    myfile << "</svg>" << endl;
    myfile.close();

    return 0;
}
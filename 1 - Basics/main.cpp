//GONCA EZGI CAKIR
//151044054
//CSE241
//19.10.2018

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Shapes { Rectangle, Circle , Triangle};

int getInput( char &cshape, double &cwidth, double &cheight, double &clength, double &cradius,
         char &sshape, double &swidth, double &sheight, double &slength, double &sradius);

void callFunc(const char &cshape, const double &cwidth, const double &cheight, const double &clength, const double &cradius,
              const char &sshape, const double &swidth, const double &sheight, const double &slength, const double &sradius);;

void RinR(const double &cwidth, const double &cheight, const double &swidth, const double &sheight);
void CinR(const double &cwidth, const double &cheight, const double &sradius);
void CinC (const double &cradius, const double &sradius);
void CinT(const double &clength , const double &sradius);
void RinC(const double &cradius, const double &swidth, const double &sheight);
void RinT(const double &clength, const double &sheight, const double &swidth);
void TinR(const double &cwidth , const double &cheight, const double &slength);
void TinC(const double &cradius, const double &slength);
void TinT(const double &clength, const double &slength);

int main(){

    char cshape;
    char sshape;
    double cwidth;
    double cheight;
    double clength;
    double cradius;
    double swidth;
    double sheight;
    double slength;
    double sradius;

    getInput(cshape, cwidth, cheight, clength, cradius, sshape, swidth, sheight, slength, sradius);

    cout  << endl << "RESULT" << endl << "-------" << endl;

    callFunc(cshape, cwidth, cheight, clength, cradius, sshape, swidth, sheight, slength, sradius);

    return 0;

}

void callFunc(const char &cshape, const double &cwidth, const double &cheight, const double &clength, const double &cradius,
              const char &sshape, const double &swidth, const double &sheight, const double &slength, const double &sradius){
//Precondition : cshape is character to store the main cointeiner shape
//               sshape is character to store the small cointeiner shape
//               cradius is non-negative double to store the main circle cointeiner's radius
//               sradius is non-negative double to get the small circle cointeiner's radius
//               cwidth and cheight are non-negative double to hold the main rectangles's lengths
//               swidth and sheight are non-negative double to hold the small rectangles's lengths
//               clength is non-negative double to get the main triangle cointeiner's length
//               slength is non-negative double to get the small triangle cointeiner's length
//Precondition : checks condition statements to calling the valid function

    Shapes c_shape ;
    Shapes s_shape;

    if (cshape == 'R' || cshape == 'r')
        c_shape = Rectangle;

    if (cshape == 'T' || cshape == 't')
        c_shape = Triangle;

    if (cshape == 'C' || cshape == 'c')
        c_shape = Circle;

    if (sshape == 'R' || sshape == 'r')
        s_shape = Rectangle;

    if (sshape == 'T' || sshape == 't')
        s_shape = Triangle;

    if (sshape == 'C' || sshape == 'c')
        s_shape = Circle;
//***************************************************************************

    if (c_shape == Rectangle && s_shape == Rectangle)
        RinR(cwidth, cheight, swidth, sheight);

    if (c_shape == Rectangle && s_shape == Circle)
        CinR(cwidth, cheight, sradius);

    if (c_shape == Circle && s_shape == Circle)
        CinC(cradius, sradius);

    if (c_shape == Triangle && s_shape == Circle)
        CinT(clength, sradius);

    if (c_shape == Circle && s_shape == Rectangle)
        RinC(cradius, swidth, sheight);

    if (c_shape == Triangle && s_shape == Rectangle)
        RinT(clength, sheight, swidth);

    if (c_shape == Rectangle && s_shape == Triangle)
        TinR(cwidth, cheight, slength);

    if (c_shape == Circle && s_shape == Triangle)
        TinC(cradius, slength);

    if (c_shape == Triangle && s_shape == Triangle)
        TinT(clength, slength);

}
//----------------------------------------------------------------------------------------------------------------------
int getInput(char &cshape, double &cwidth, double &cheight, double &clength, double &cradius,
        char &sshape, double &swidth, double &sheight, double &slength, double &sradius){
//Precondition : cshape is character to store the main cointeiner shape
//               sshape is character to store the small cointeiner shape
//               cradius is non-negative double to store the main circle cointeiner's radius
//               sradius is non-negative double to get the small circle cointeiner's radius
//               cwidth and cheight are non-negative double to hold the main rectangles's lengths
//               swidth and sheight are non-negative double to hold the small rectangles's lengths
//               clength is non-negative double to get the main triangle cointeiner's length
//               slength is non-negative double to get the small triangle cointeiner's length
//Precondition : gets inputs from user and store them in the variables

    int error1=1;
    int error2=1;
    //variable to control invalid inputs and break the loop

    cout << "Please enter the main cointainer shape (R, C, T)" << endl;
    cin >> cshape;

    while(error1==1) {
        if (cshape == 'C' || cshape == 'c') {
            cout << "Please enter the radius" << endl;
            cin >> cradius;
            error1=2;
        }
        else if (cshape == 'T' || cshape == 't') {
            cout << "Please enter the length" << endl;
            cin >> clength;
            error1 = 2;

        }
        else if (cshape == 'R' || cshape == 'r') {
            cout << "Please enter the width" << endl;
            cin >> cwidth;
            cout << "Please enter the height" << endl;
            cin >> cheight;
            error1 = 2;


        } else {
            cout << "INVALID INPUT" << endl;
            return 0;

        }

    }
    while (error2==1 && error1!=0){

        cout << "Please enter the main small shape (R, C, T)" << endl;
        cin >> sshape;

        if (sshape == 'C' || sshape == 'c') {
            cout << "Please enter the radius" << endl;
            cin >> sradius;
            error2 = 2;

        }
        else if (sshape == 'T' || sshape == 't') {
            cout << "Please enter the length" << endl;
            cin >> slength;
            error2 = 2;

        }
        else if (sshape == 'R' || sshape == 'r') {
            cout << "Please enter the width" << endl;
            cin >> swidth;
            cout << "Please enter the height" << endl;
            cin >> sheight;
            error2 = 2;
        }
        else {
            cout << "INVALID INPUT" << endl;
            error2 = 0;

        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void RinR(const double &cwidth, const double &cheight, const double &swidth, const double &sheight){
//Precondition : cwidth and cheight are non-negative double to hold the main rectangles's lengths
//               swidth and sheight are non-negative double to hold the small rectangles's lengths
//Precondition : calculates coordinates for main rectangle container and prints them on "resultRR.svg" file
//               calculates coordinates for small rectangle containers and prints them on "resultRR.svg" file
//               in order to fill main rectangle container in maximum level

    ofstream myfile;
    myfile.open("output.svg");

    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<rect width=\" "<< cwidth <<"\" height=\" "<<cheight <<"\" fill=\"green\" />" << endl;

    int i, j;
    double coorX=0;
    double coorY=0;
    int counter=0;

    for(i=0 ; i<(int)(cwidth/swidth) ; ++i) {//calculates new value f x axis
        coorX = swidth*i;

        for(j=0 ; j<(int)(cheight/sheight) ; ++j) {//calculates new value of y axis
            coorY = sheight*j;
            myfile << "<rect x=\" "<<coorX <<"\" y=\" "<<coorY<<"\" width=\" "<< swidth <<"\" height=\" "<<sheight <<
            "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\"/>" << endl;
            counter++;
        }
    }

    double remainHeight = cheight-(cheight/sheight)*sheight;

    if(remainHeight>0) {//checks if there is any remain area

        for(i=0 ; i<(int)(cwidth/sheight) ; ++i) {//calculates new value f x axis
            coorX = sheight*i;

            for(j=0 ; j<(int)(remainHeight/swidth) ; ++j) {//calculates new value f y axis
                coorY = (cheight - remainHeight) + (swidth * j);
                myfile << "<rect x=\" " << coorX << "\" y=\" " << coorY << "\" width=\" " << sheight << "\" height=\" " << swidth <<
                "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\"/>" << endl;
                counter++;
            }
        }
    }

    double remainWidth = cwidth - (cwidth/swidth)*swidth;

    if(remainWidth>0){//checks if there is any remain area

        for(i=0 ; i<(int)(remainWidth/sheight) ; ++i){//calculates new value f x axis
            coorX = (cwidth - remainWidth) + (sheight*i);

            for(j=0 ; j<(int)(cheight/swidth) ; ++j){//calculates new value f y axis
                coorY = swidth*j;
                myfile << "<rect x=\" " << coorX << "\" y=\" " << coorY << "\" width=\" " << sheight << "\" height=\" " << swidth <<
                "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\"/>" << endl;
                counter++;
            }
        }
    }

    double remainArea=0;

    remainArea = cheight*cwidth - (counter*sheight*swidth);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = cheight*cwidth;

    cout << "I can fit at most " << counter << " small rectangles into the main container.The empty area green in container is "
            << remainArea << "." << endl;

    myfile << "</svg>" << endl;
    myfile.close();
}
//----------------------------------------------------------------------------------------------------------------------
void CinR(const double &cwidth, const double &cheight, const double &sradius){
//Precondition : sradius is non-negative double to get the small circle cointeiner's radius
//               cwidth and cheight are non-negative double to hold the main rectangles's lengths
//Precondition : calculates coordinates for main rectangle container and prints them on "resultCR.svg" file
//               calculates coordinates for small circle containers and prints them on "resultCR.svg" file
//               in order to fill main rectangle container in maximum level

    ofstream myfile;
    myfile.open("output.svg");
    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<rect width=\" " << cwidth << "\" height=\" " << cheight << "\" fill=\"green\" />" << endl;

    int i, j;
    double coorX=0;
    double coorY=0;
    int counter=0;

    for(i=0; i< (int)(cheight/(sradius*1.732)); ++i) {//calculates new value f y axis

        for(j=0; j<(int)(cwidth/(sradius*2)); ++j) {//calculates new value f x axis

            if(i%2==0) {
                coorX = sradius + sradius*j*2;
                coorY = sradius + sradius*i*1.732;

                if(coorX+sradius < cwidth && coorY+sradius<cheight) {
                    myfile << "<circle cx=\" " << coorX << "\" cy=\" " <<
                    coorY << "\" r=\" " << sradius << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                    counter ++;
                }
            }
            else{
                coorX = 2*sradius + sradius*j*2;
                coorY = sradius + sradius*i*1.732;

                if(coorX+sradius < cwidth && coorY+sradius<cheight) {
                    myfile << "<circle cx=\" " << coorX << "\" cy=\" " <<
                    coorY << "\" r=\" " << sradius << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                    counter ++;
                }
            }
        }
    }

    double remainArea=0;

    remainArea = cheight*cwidth - (counter*sradius*sradius*3.142);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = cheight*cwidth;

    cout << "I can fit at most " << counter << " small circles into the main container.The empty area green in container is "
         << remainArea << "." << endl;

    myfile << "</svg>" << endl;
    myfile.close();
}
//----------------------------------------------------------------------------------------------------------------------
void CinC (const double &cradius, const double &sradius){
//Precondition : cradius is non-negative double to store the main circle cointeiner's radius
//               sradius is non-negative double to get the small circle cointeiner's radius
//Precondition : calculates coordinates for main circle container and prints them on "resultCC.svg" file
//               calculates coordinates for small circle containers and prints them on "resultCC.svg" file
//               in order to fill main rectangle container in maximum level

    ofstream myfile;
    myfile.open("output.svg");
    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

    double c_coorX = cradius;
    double c_coorY = cradius;

    myfile << "<circle cx=\" " << c_coorX << "\" cy=\" " << c_coorY << "\" r=\" " << cradius <<
    "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

    int i, j;
    double s_coorX=0;
    double s_coorY=0;
    int counter=0;

    for(i=0 ; i<(int)((2*cradius)/(sradius*1.732)) ; ++i){//calculates new value f y axis

        for(j=0 ; j<(int)((2*cradius)/(2*sradius)) ; ++j){//calculates new value f x axis

            if(i%2 == 0){
                s_coorX = sradius + sradius*j*2;
                s_coorY = sradius + sradius*i*1.732;

                if(((s_coorX - c_coorX)*(s_coorX - c_coorX)) + ((s_coorY - c_coorY)*(s_coorY - c_coorY)) < (cradius-sradius)*(cradius-sradius)) {
                    myfile << "<circle cx=\" " << s_coorX << "\" cy=\" " <<
                    s_coorY << "\" r=\" " << sradius << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                    counter ++;
                }
            }

            else{
                s_coorX = 2*sradius + sradius*j*2;
                s_coorY = sradius + sradius*i*1.732;

                if(((s_coorX - c_coorX)*(s_coorX - c_coorX)) + ((s_coorY- c_coorY)*(s_coorY - c_coorY)) < (cradius-sradius)*(cradius-sradius)) {
                    myfile << "<circle cx=\" " << s_coorX << "\" cy=\" " <<
                    s_coorY << "\" r=\" " << sradius << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                    counter ++;
                }
            }
        }
    }

    double remainArea=0;

    remainArea = 3.142*cradius*cradius - (counter*sradius*sradius*3.142);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = 3.142*cradius*cradius;

    cout << "I can fit at most " << counter << " small circles into the main container.The empty area green in container is "
         << remainArea << "." << endl;
    myfile << "</svg>" << endl;
    myfile.close();

}
//----------------------------------------------------------------------------------------------------------------------
void CinT(const double &clength , const double &sradius){
//Precondition : sradius is non-negative double to get the small circle cointeiner's radius
//               clength is non-negative double to get the main triangle cointeiner's length
//Precondition : calculates coordinates for main triangle container and prints them on "resultCT.svg" file
//               calculates coordinates for small circle containers and prints them on "resultCT.svg" file
//               in order to fill main rectangle container in maximum level

ofstream myfile;
    myfile.open("output.svg");
    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

    double c_x1 = clength/2;
    double c_y1= 0.0;
    double c_x2 = 0.0;
    double c_y2= 0.866*clength;
    double c_x3 = clength;
    double c_y3= 0.866*clength;

    myfile << "<polygon points=\""<<c_x1<<","<<c_y1<<" "<<c_x2<<","<<c_y2<<" "<<c_x3<<","<<c_y3<<
    "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.2\" />" <<endl;

    int i,j;
    double s_coorX = 0;
    double s_coorY = 0;
    int counter=0;

    for(i=(int)((clength*0.866) /(sradius * 1.732)) ; i>0 ; --i) {//calculates new value f x axis

        for (j = (int)((clength - (2 * (sradius * 1.732 - sradius))) / (2 * sradius)); j>0; --j) {//calculates new value f y axis

            if (i % 2 == 1) {
                s_coorX = clength - sradius * j * 2  + sradius*0.280;
                s_coorY = clength * 0.866 - (sradius * i * 1.732 - sradius*0.732);

                if(((s_coorY - c_y1)/(clength/2 - s_coorX) > (clength*0.867)/(clength/2)) && (s_coorX < clength/2)) {
                    myfile << "<circle cx=\" " << s_coorX << "\" cy=\" " << s_coorY << "\" r=\" " << sradius <<
                    "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                    counter ++;
                }

                else if(((s_coorY - c_y1)/( s_coorX - clength/2) > (clength*0.867)/(clength/2)) && (s_coorX > clength/2)) {
                    myfile << "<circle cx=\" " << s_coorX << "\" cy=\" " << s_coorY << "\" r=\" " << sradius <<
                    "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                    counter ++;

                }

                else if(s_coorX== clength/2){
                    myfile << "<circle cx=\" " << s_coorX << "\" cy=\" " << s_coorY << "\" r=\" " << sradius <<
                    "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                    counter ++;
                }

            } else {
                s_coorX = clength - (sradius*0.732 + sradius * j * 2);
                s_coorY = clength * 0.866 - (sradius * i * 1.732 - sradius*0.732);

                if(((s_coorY - c_y1)/(clength/2 - s_coorX) > (clength*0.867)/(clength/2)) && (s_coorX < clength/2)) {
                    myfile << "<circle cx=\" " << s_coorX << "\" cy=\" " << s_coorY << "\" r=\" " << sradius <<
                    "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                    counter ++;

                }

                else if(((s_coorY - c_y1)/( s_coorX - clength/2) > (clength*0.867)/(clength/2)) && (s_coorX > clength/2)) {
                    myfile << "<circle cx=\" " << s_coorX << "\" cy=\" " << s_coorY << "\" r=\" " << sradius <<
                    "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                    counter ++;

                }

                else if(s_coorX== clength/2){
                    myfile << "<circle cx=\" " << s_coorX << "\" cy=\" " << s_coorY << "\" r=\" " << sradius <<
                    "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                    counter ++;
                }
            }
        }
    }

    double remainArea=0;

    remainArea = clength*(clength*0.866)*0.5 - (counter*sradius*sradius*3.142);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = clength*(clength*0.866)*0.5;

    cout << "I can fit at most " << counter << " small circles into the main container.The empty area green in container is "
         << remainArea << "." << endl;


    myfile << "</svg>" << endl;
    myfile.close();
}
 //---------------------------------------------------------------------------------------------------------------------
void RinC(const double &cradius, const double &swidth, const double &sheight){
//Precondition : sradius is non-negative double to get the small circle cointeiner's radius
//               swidth and sheight are non-negative double to hold the small rectangles's lengths
//Precondition : calculates coordinates for main circle container and prints them on "resultRC.svg" file
//               calculates coordinates for small rectangles containers and prints them on "resultRC.svg" file
//               in order to fill main rectangle container in maximum level

    ofstream myfile;
    myfile.open("output.svg");
    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

    double c_coorX = cradius;
    double c_coorY = cradius;

    myfile << "<circle cx=\" " << c_coorX << "\" cy=\" " << c_coorY << "\" r=\" " << cradius <<
    "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

    int i, j;
    int s_coorX=0;
    double s_coorY=0;
    int counter =0;

    for(i=0 ; i<(int)((2*cradius)/swidth); ++i) {//calculates new value f x axis
        s_coorX = swidth * i;

        for (j = 0; j < (int)(2 * cradius) / sheight; ++j) {//calculates new value f y axis
            s_coorY = sheight * j;

            if ((((s_coorX - c_coorX) * (s_coorX - c_coorX)) + ((s_coorY - c_coorY) * (s_coorY - c_coorY)) <
                 cradius * cradius) &&
                (((s_coorX - c_coorX) * (s_coorX - c_coorX)) +
                 ((s_coorY - c_coorY + sheight) * (s_coorY - c_coorY + sheight)) < cradius * cradius) &&
                (((s_coorX - c_coorX + swidth) * (s_coorX - c_coorX + swidth)) +
                 ((s_coorY - c_coorY + sheight) * (s_coorY - c_coorY + sheight)) < cradius * cradius) &&
                (((s_coorX - c_coorX + swidth) * (s_coorX - c_coorX + swidth)) +
                 ((s_coorY - c_coorY ) * (s_coorY - c_coorY)) < cradius * cradius)

                 ) {

                myfile << "<rect x=\" " << s_coorX << "\" y=\" " << s_coorY << "\" width=\" " << swidth
                << "\" height=\" " << sheight << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\"/>" << endl;

                counter ++;

            }
        }
    }

    double remainArea=0;

    remainArea = cradius*cradius*3.142 - (counter*sheight*swidth);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = cradius*cradius*3.142;

    cout << "I can fit at most " << counter << " small rectangles circles into the main container.The empty area green in container is "
         << remainArea << "." << endl;

    myfile << "</svg>" << endl;
    myfile.close();
}
//----------------------------------------------------------------------------------------------------------------------
void RinT(const double &clength, const double &sheight, const double &swidth){
//Precondition : swidth and sheight are non-negative double to hold the small rectangles's lengths
//               clength is non-negative double to get the main triangle cointeiner's length
//Precondition : calculates coordinates for main triangle container and prints them on "resultRT.svg" file
//               calculates coordinates for small rectangles containers and prints them on "resultRT.svg" file
//               in order to fill main rectangle container in maximum level

ofstream myfile;
    myfile.open("output.svg");
    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

    double c_x1 = clength/2;
    double c_y1= 0.0;
    double c_x2 = 0.0;
    double c_y2= 0.866*clength;
    double c_x3 = clength;
    double c_y3= 0.866*clength;

    myfile << "<polygon points=\""<<c_x1<<","<<c_y1<<" "<<c_x2<<","<<c_y2<<" "<<c_x3<<","<<c_y3<<
    "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.2\" />" <<endl;

    int i, j;
    int counter=0;
    int coorX=0;
    double coorY=0;

    for(i=0 ; i<(int)(((clength*0.866)/sheight)) ; ++i) {//calculates new value f y axis
        coorY = sheight *i;

        for (j = 0; j < (int)(clength / swidth) ; ++j) {//calculates new value f x axis

            coorX = swidth * j;

            if( (((coorY - c_y1)/(clength/2 - coorX) >= (clength*0.866)/(clength/2))) &&
                (((coorY - c_y1)/(clength/2 - coorX - swidth) >= (clength*0.866)/(clength/2))) &&
                (((coorY + sheight - c_y1)/(clength/2 - coorX) >= (clength*0.866)/(clength/2))) &&
                (((coorY  + sheight - c_y1)/(clength/2 - coorX - swidth) >= (clength*0.866)/(clength/2)))
                && (coorX < clength/2)){

                myfile << "<rect x=\" " << coorX << "\" y=\" " << coorY << "\" width=\" " << swidth
                       << "\" height=\" " << sheight << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\"/>" << endl;

                counter ++;
            }

            if( (((coorY - c_y1)/(coorX - clength/2) >= (clength*0.866)/(clength/2))) &&
                (((coorY - c_y1)/(coorX + swidth - clength/2) >= (clength*0.866)/(clength/2))) &&
                (((coorY + sheight - c_y1)/(coorX - clength/2) >= (clength*0.866)/(clength/2))) &&
                (((coorY  + sheight - c_y1)/(coorX + swidth - clength/2) >= (clength*0.866)/(clength/2)))
                && (coorX + swidth > clength/2) ){

                myfile << "<rect x=\" " << coorX << "\" y=\" " << coorY << "\" width=\" " << swidth
                       << "\" height=\" " << sheight << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\"/>" << endl;

                counter ++;

            }

            if( (((coorY - c_y1)/(clength/2 - coorX) >= (clength*0.866)/(clength/2))) &&
                (((coorY - c_y1)/(coorX + swidth - clength/2) >= (clength*0.866)/(clength/2))) &&
                (((coorY + sheight - c_y1)/(clength/2 - coorX) >= (clength*0.866)/(clength/2))) &&
                (((coorY  + sheight - c_y1)/(coorX + swidth - clength/2) >= (clength*0.866)/(clength/2)))
                && (coorX < clength/2) && (coorX + swidth > clength/2)){

                myfile << "<rect x=\" " << coorX << "\" y=\" " << coorY << "\" width=\" " << swidth
                       << "\" height=\" " << sheight << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\"/>" << endl;

                counter ++;
            }



        }
    }

    double remainArea=0;

    remainArea = clength*(clength*0.866)*0.5 - (counter*sheight*swidth);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = clength*clength*0.866*0.5;

    cout << "I can fit at most " << counter << " small triangles into the main container.The empty area green in container is "
         << remainArea << "." << endl;

    myfile << "</svg>" << endl;
    myfile.close();
}
//----------------------------------------------------------------------------------------------------------------------
void TinR(const double &cwidth , const double &cheight, const double &slength){
//Precondition : cwidth and cheight are non-negative double to hold the main rectangles's lengths
//               slength is non-negative double to get the small triangle cointeiner's length
//Precondition : calculates coordinates for main rectangle container and prints them on "resultTR.svg" file
//               calculates coordinates for small triangle containers and prints them on "resultTR.svg" file
//               in order to fill main rectangle container in maximum level

    ofstream myfile;
    myfile.open("output.svg");
    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    myfile << "<rect width=\" "<< cwidth <<"\" height=\" "<<cheight <<"\" fill=\"green\" />" << endl;

    int i,j;
    int counter = 0;

    double s_x1 = 0.0;
    double s_y1= 0.0;
    double s_x2 = 0.0;
    double s_y2= 0.0;
    double s_x3 = 0.0;
    double s_y3= 0.0;


    for(i=0 ; i<(int)(cheight/(slength*1.732)) ; ++i){//calculates new value f y axis

        for(j=0 ; j<(int)(cwidth/slength) ; ++j) {//calculates new value f x axis

            s_x1 = j * slength;
            s_y1 = i * slength * 1.732;
            s_x2 = slength + j * slength;
            s_y2 = i * slength * 1.732;
            s_x3 = (slength / 2) + j * slength;
            s_y3 = slength * 0.866 + i * slength * 1.732;

            if((s_x3< cwidth)&&(s_y3 < cheight)) {
                myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                       << "," << s_y3 << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                        counter ++;

                if(j!=(int)(cwidth/slength) - 1) {
                    myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                           << "," << s_y3 << "\" transform = \" rotate(60 " << s_x3 << " " << s_y3 <<
                           ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                        counter ++;
                }
            }

        }
    }

    for(i=0 ; i<(int)(cheight/(slength*1.732)) ; ++i){//calculates new value f y axis

        for(j=0 ; j<(int)(cwidth/slength); ++j) {//calculates new value f x axis

            s_x1 = slength/2 + j * slength;
            s_y1 = slength*0.866 + i * slength * 1.732;
            s_x2 = j * slength;
            s_y2 = slength*1.732 + i * slength * 1.732;
            s_x3 = slength + j * slength;
            s_y3 = slength * 1.732 + i * slength * 1.732;

            if((s_x2< cwidth)&&(s_y2 < cheight)) {
                myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                       << ","
                       << s_y3 << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                    counter ++;

                if(j != (int)(cwidth/slength) - 1) {
                    myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                           << "," << s_y3 << "\" transform = \" rotate(300 " << s_x1 << " " << s_y1 <<
                           ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                    counter ++;
                }
            }
        }
    }

    double remainArea=0;

    remainArea = cheight*cwidth - (counter*slength*slength*0.866*0.5);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = cheight*cwidth;

    cout << "I can fit at most " << counter << " small rectangles into the main container.The empty area green in container is "
         << remainArea << "." << endl;


    myfile << "</svg>" << endl;
    myfile.close();
}
//----------------------------------------------------------------------------------------------------------------------
void TinC(const double &cradius, const double &slength){
//Precondition : cradius is non-negative double to store the main circle cointeiner's radius
//               slength is non-negative double to get the small triangle cointeiner's length
//Precondition : calculates coordinates for main circle container and prints them on "resultTC.svg" file
//               calculates coordinates for small triangles containers and prints them on "resultTC.svg" file
//               in order to fill main rectangle container in maximum level


    ofstream myfile;
    myfile.open("output.svg");
    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

    double c_coorX = cradius;
    double c_coorY = cradius;
    myfile << "<circle cx=\" " << c_coorX << "\" cy=\" " << c_coorY << "\" r=\" " << cradius <<
    "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

    int i,j;
    int counter=0;

    double s_x1 = 0.0;
    double s_y1= 0.0;
    double s_x2 = 0.0;
    double s_y2= 0.0;
    double s_x3 = 0.0;
    double s_y3= 0.0;

    for(i=0 ; i<(int)((2*cradius)/(slength*1.732)) ; ++i){//calculates new value f y axis

        for(j=0 ; j<(int)((2*cradius)/slength); ++j) {//calculates new value f x axis

            s_x1 = j * slength;
            s_y1 = i * slength * 1.732;
            s_x2 = slength + j * slength;
            s_y2 = i * slength * 1.732;
            s_x3 = (slength / 2) + j * slength;
            s_y3 = slength * 0.866 + i * slength * 1.732;

            if ((((c_coorX - s_x1) * (c_coorX - s_x1)) + ((c_coorY - s_y1) * (c_coorY - s_y1)) < cradius * cradius) &&
                (((c_coorX - s_x2) * (c_coorX - s_x2)) + ((c_coorY - s_y2) * (c_coorY - s_y2)) < cradius * cradius) &&
                (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) < cradius * cradius)) {


                myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                       << "," << s_y3 << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                counter ++;
            }

            if( (((c_coorX - s_x1 - slength*1.5) * (c_coorX - s_x1 - slength*1.5)) + ((c_coorY - s_y1 - slength*0.866) * (c_coorY - s_y1 - slength*0.866)) < cradius * cradius) &&
                (((c_coorX - s_x2) * (c_coorX - s_x2)) + ((c_coorY - s_y2) * (c_coorY - s_y2)) < cradius * cradius) &&
                (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) < cradius * cradius)) {

                myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                    << "," << s_y3 << "\" transform = \" rotate(60 " << s_x3 << " " << s_y3 <<
                    ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                counter ++;

            }
        }
    }

    for(i=0 ; i<(int)((2*cradius)/(slength*1.732)) ; ++i){//calculates new value f y axis

        for(j=0 ; j<(int)((2*cradius)/slength)   ; ++j) {//calculates new value f x axis

            s_x1 = slength/2 + j * slength;
            s_y1 = slength*0.866 + i * slength * 1.732;
            s_x2 = j * slength;
            s_y2 = slength*1.732 + i * slength * 1.732;
            s_x3 = slength + j * slength;
            s_y3 = slength * 1.732 + i * slength * 1.732;

            if ( (((c_coorX - s_x1) * (c_coorX - s_x1)) + ((c_coorY - s_y1) * (c_coorY - s_y1)) <= cradius * cradius) &&
                (((c_coorX - s_x2) * (c_coorX - s_x2)) + ((c_coorY - s_y2) * (c_coorY - s_y2)) <= cradius * cradius) &&
                (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) <= cradius * cradius)) {


                myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                       << ","
                       << s_y3 << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                counter ++;
            }
            if ( (((c_coorX - s_x1) * (c_coorX - s_x1)) + ((c_coorY - s_y1) * (c_coorY - s_y1)) <= cradius * cradius) &&
                (((c_coorX - s_x2 + 1.5*slength) * (c_coorX - s_x2 + 1.5*slength)) + ((c_coorY - s_y2 + slength*0.866) * (c_coorY - s_y2 + slength*0.866)) <= cradius * cradius) &&
                (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) <= cradius * cradius)) {

                myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                        << "," << s_y3 << "\" transform = \" rotate(60 " << s_x1 << " " << s_y1 <<
                         ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                counter ++;

            }
        }
    }
    double remainArea=0;

    remainArea = cradius*cradius*3.142 - (counter*slength*slength*0.866*0.5);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = cradius*cradius*3.142;

    cout << "I can fit at most " << counter << " small rectangles into the main container.The empty area green in container is "
         << remainArea << "." << endl;

    myfile << "</svg>" << endl;
    myfile.close();
}
//----------------------------------------------------------------------------------------------------------------------
void TinT(const double &clength, const double &slength){
//Precondition : clength is non-negative double to get the main triangle cointeiner's length
//               slength is non-negative double to get the small triangle cointeiner's length
//Precondition : calculates coordinates for main triangle container and prints them on "resultTT.svg" file
//               calculates coordinates for small triangle containers and prints them on "resultTT.svg" file
//               in order to fill main rectangle container in maximum level

    ofstream myfile;
    myfile.open("output.svg");
    myfile << "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

    double c_x1 = clength/2;
    double c_y1= 0.0;
    double c_x2 = 0.0;
    double c_y2= 0.866*clength;
    double c_x3 = clength;
    double c_y3= 0.866*clength;

    myfile << "<polygon points=\""<<c_x1<<","<<c_y1<<" "<<c_x2<<","<<c_y2<<" "<<c_x3<<","<<c_y3<<"\" fill=\"green\" stroke=\"black\" stroke-width=\"0.2\" />" <<endl;

    int i,j;
    int counter=0;

    double s_x1 = 0.0;
    double s_y1= 0.0;
    double s_x2 = 0.0;
    double s_y2= 0.0;
    double s_x3 = 0.0;
    double s_y3= 0.0;

    double y = (clength*0.866)/(slength*1.732);
    double x = (clength)/slength;

    for(i=0 ; i<y ; ++i){

        for(j=0 ; j<x; ++j) {

            s_x1 = j * slength+(y-i-1)*(slength);
            s_y1 = i * slength * 1.732;
            s_x2 = slength + j * slength+(y-i-1)*(slength);
            s_y2 = i * slength * 1.732;
            s_x3 = (slength / 2) + j * slength+(y-i-1)*(slength);
            s_y3 = slength * 0.866 + i * slength * 1.732;

            if((s_y3+(double)clength*0.867)/1.732 >= s_x3 +slength/2&&
               (s_y2+(double)clength*0.867)/1.732 >= s_x2 +slength/2&&
               (s_y1+(double)clength*0.867)/1.732 >= s_x1+slength/2 &&
               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867) && 1 <= (clength*0.867)))
            {
                myfile << "<polygon points=\"" << (double)(s_x1 +slength)<< "," << s_y1 << " " << (double)(s_x2 +slength)<< "," << s_y2 << " "
                << (double)(s_x3 +slength)<< "," << s_y3 << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;

                counter ++;

            }
            if((s_y3+(double)clength*0.867)/1.732 >= s_x3&&
               (s_y2+(double)clength*0.867)/1.732 >= s_x2&&
               (s_y1+(double)clength*0.867)/1.732 >= s_x1 &&
               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867) && 1 <= (clength*0.867)))
            {

                myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                       << "," << s_y3 << "\" transform = \" rotate(60 " << s_x3 << " " << s_y3
                       << ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                counter ++;
            }

        }
    }

    for(i=0 ; i<y ; ++i){

        for(j=0 ; j<x   ; ++j) {

            s_x1 = slength/2 + j * slength+(y-i-1)*(slength);
            s_y1 = slength*0.866 + i * slength * 1.732;
            s_x2 = j * slength+(y-i-1)*(slength);
            s_y2 = slength*1.732 + i * slength * 1.732;
            s_x3 = slength + j * slength+(y-i-1)*(slength);
            s_y3 = slength * 1.732 + i * slength * 1.732;



            if(((s_y3+(double)clength*0.867)/1.732 >= s_x3 +(double)slength/2&&
                (s_y2+(double)clength*0.867)/1.732 >= s_x2 +(double)slength/2&&
                (s_y1+(double)clength*0.867)/1.732 >= s_x1 +(double)slength/2) &&
               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867) && 1 <= (clength*0.867)))
            {
                myfile << "<polygon points=\"" << s_x1 << "," << s_y1 << " " << s_x2 << "," << s_y2 << " " << s_x3
                       << "," << s_y3 << "\" transform = \" rotate(60 " << s_x3 << " " << s_y3
                       << ") \" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                counter ++;

            }
            if((s_y3+(double)clength*0.867)/1.732 >= s_x3&&
               (s_y2+(double)clength*0.867)/1.732 >= s_x2&&
               (s_y1+(double)clength*0.867)/1.732 >= s_x1 &&
               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867) && 1 <= (clength*0.867)))
            {
                myfile << "<polygon points=\"" << s_x1<< "," << s_y1 << " " << s_x2<< "," << s_y2 << " " << s_x3
                       << "," << s_y3 << "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.2\" />" << endl;
                counter ++;

            }

        }
    }

    double remainArea=0;

    remainArea = clength*clength*0.866*0.5 - (counter*slength*slength*0.866*0.5);

    if(counter == 0)//if there is no small container, remain area is equal to main container's area
        remainArea = clength*clength*0.866*0.5;

    cout << "I can fit at most " << counter << " small rectangles into the main container.The empty area green in container is "
         << remainArea << "." << endl;

    myfile << "</svg>" << endl;
    myfile.close();
}


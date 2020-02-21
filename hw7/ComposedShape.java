import java.util.Vector;
import java.awt.Color;
import java.awt.Graphics;

/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public class ComposedShape implements Shape
{	
	//shape of container
	private char shapeC; 
	//height of container
	private int heightC; 
    //width of container
	private int widthC;  
    //radius of container
	private double radiusC; 
    //length of container
	private double lengthC; 
    //shape of small container
	private char shapeS; 
    //height of small container
	private int heightS; 
    //width of small container
	private int widthS; 
    //radius of small container
	private double radiusS; 
    //length of small container
	private double lengthS; 
    
	private int shapeCountS;
    //object whether to create rectangle container
	private Rectangle R;
    //object whether to create circle container
	private Circle C; 
    //object whether to create triangle container
	private Triangle T;  
    //vector of object whether to create small shapes  
	private Vector <Shape> smallShp; 
	
	/**
	 * constructor
	 */
	public ComposedShape()
	{
		smallShp = new Vector<Shape>();
	    @SuppressWarnings("unused")
		int heightC = (int) 0.0;
	    @SuppressWarnings("unused")
		int widthC = (int) 0.0;
	    @SuppressWarnings("unused")
		double radiusC = 0.0;
	    @SuppressWarnings("unused")
		double lengthC = 0.0;
	    @SuppressWarnings("unused")
		int heightS = (int) 0.0;
	    @SuppressWarnings("unused")
		int widthS = (int) 0.0;
	    @SuppressWarnings("unused")
		double radiusS = 0.0;
	    @SuppressWarnings("unused")
		double lengthS = 0.0;
	}
	
	/**
	 * 
	 * @param cnstrshapeC char
	 * @param cnstrshapeS char
	 * @param cnstrDimension_1 integer
	 * @param cnstrDimension_2 integer
	 * @param cnstrDimension_3 integer
	 * @param cnstrDimension_4 integer
	 */
	public ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3, double cnstrDimension_4)
	{
		smallShp = new Vector<Shape>();
	    if(cnstrshapeC == 'R' && cnstrshapeS == 'R')
	    {
	    	R = new Rectangle();
	        shapeC = cnstrshapeC;
	        heightC = (int) cnstrDimension_1;
	        widthC = (int) cnstrDimension_2;
	        shapeS = cnstrshapeS;
	        heightS = (int) cnstrDimension_3;
	        widthS = (int) cnstrDimension_4;
	        R.setWidth(widthC);
	        R.setHeight(heightC);
	    }
	}
	
	/**
	 * constructor
	 * @param cnstrshapeC char
	 * @param cnstrshapeS char
	 * @param cnstrDimension_1 integer
	 * @param cnstrDimension_2 integer
	 * @param cnstrDimension_3 integer
	 */
	public ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2, double cnstrDimension_3)
	{
		smallShp = new Vector<Shape>();
	    if (cnstrshapeC == 'R') {
	    	R = new Rectangle();
	        shapeC = cnstrshapeC;
	        heightC = (int) cnstrDimension_1;
	        widthC = (int) cnstrDimension_2;
	        R.setWidth(widthC);
	        R.setHeight(heightC);
	    }
	    if (cnstrshapeC == 'T') {
	    	T = new Triangle();
	        Vector<Double> triangleC = new Vector <Double>();
	        shapeC = cnstrshapeC;
	        lengthC = cnstrDimension_1;
	        
	        triangleC.add(0,lengthC/2) ;
	        triangleC.add(1,0.0);
	        triangleC.add(2,0.0);
	        triangleC.add(3,0.866*lengthC);
	        triangleC.add(4,lengthC);
	        triangleC.add(5,0.866*lengthC);
	        T.setCoordinate(triangleC);
	    }
	
	    if (cnstrshapeC == 'C') {
	    	C = new Circle();
	    	C.setFlag(true);
	        shapeC = cnstrshapeC;
	        radiusC = cnstrDimension_1;
	        C.setRadius(radiusC);
	        C.setCoorX(radiusC);
	        C.setCoorY(radiusC);
	    }
	
	    if (cnstrshapeS == 'R') {
	        shapeS = cnstrshapeS;
	        heightS = (int) cnstrDimension_2;
	        widthS = (int) cnstrDimension_3;
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
	
	/**
	 * constructor
	 * @param cnstrshapeC char
	 * @param cnstrshapeS char
	 * @param cnstrDimension_1 integer
	 * @param cnstrDimension_2 integer
	 */
	public ComposedShape(char cnstrshapeC, char cnstrshapeS, double cnstrDimension_1, double cnstrDimension_2)
	{
		smallShp = new Vector<Shape>();
	    if (cnstrshapeC == 'T') {
	    	T = new Triangle();
	        Vector<Double> triangleC = new Vector <Double>();
	        lengthC = cnstrDimension_1;
	        shapeC = cnstrshapeC;
	        triangleC.add(0,lengthC/2);
	        triangleC.add(1,0.0);
	        triangleC.add(2,0.0);
	        triangleC.add(3,0.866*lengthC);
	        triangleC.add(4,lengthC);
	        triangleC.add(5,0.866*lengthC);
	        T.setCoordinate(triangleC);
	    }
	
	    if (cnstrshapeC == 'C') {
	    	C = new Circle();
	    	C.setFlag(true);
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
	
	//--------------------------- GETTERS------------------------------------------------------------
	 /**
	  * getter for shapeC
	  * @return char
	  */
	public char getShapeC()
	{   return shapeC;
	}
	
	/**
	 * getter for heightC
	 * @return double
	 */
	public double getHeightC()
	{ return heightC;
	}
	
	/**
	 * getter for widthC
	 * @return double
	 */
	public double getWidthC()
	{ return widthC;
	}
	
	/**
	 * getter for radiusC
	 * @return double
	 */
	public double getRadiusC()
	{   return radiusC;
	}
	
	/**
	 * getter for lengthC
	 * @return double
	 */
	public double getLengthC()
	{ return lengthC;
	}
	
	/**
	 * getter for shapeS
	 * @return char
	 */
	public char getShapeS()
	{
	  return shapeS;
	}
	
	/**
	 * getter for heigthS
	 * @return double
	 */
	public double getHeightS()
	{ return heightS;
	}
	
	/**
	 * getter for widthS
	 * @return double
	 */
	public double getWidthS()
	{ return widthS;
	}
	
	/**
	 * getter for radiusS
	 * @return double
	 */
	public double getRadiusS() 
	{   return radiusS;
	}
	/**
	 * getter for lengthS
	 * @return double
	 */
	public double getLengthS()
	{ return lengthS;
	}
	
	/**
	 * getter for shapeCounts
	 * @return int
	 */
	public int getShapeNumber()
	{
	  return shapeCountS;
	}
	
	/**
	 * getter for  R
	 * @return Rectangle reference
	 */
	public  Rectangle getRectangle() 
	{
	  return R;
	}
	
	/**
	 * getter for reference T
	 * @return Triangle reference
	 */
	public Triangle getTriangle() 
	{
	  return T;
	}
	
	/**
	 * getter for reference C
	 * @return Circle reference
	 */
	public Circle getCircle()
	{
	  return C;
	}
	
	//-------------------------------------COMPOSED SHAPES CLASS SETTERS-------------------------------------------------------
	
	/**
	 * setter for heightC
	 * @param setHeight double
	 */
	public void setHeightC(double setHeight)
	{   
	    heightC=(int) setHeight;
	}
	
	/**
	 * setter for widthC
	 * @param setWidth double
	 */
	public void setWidthC(double setWidth)
	{   
	    widthC=(int) setWidth;
	}
	
	/**
	 * setter for radiusC
	 * @param setRadius double
	 */
	public void setRadiusC(double setRadius)
	{   
	    radiusC=setRadius;
	}
	
	/**
	 * setter for lengthC
	 * @param setLength double
	 */
	public void setLengthC(double setLength)
	{  
	    lengthC = setLength;
	}
	
	/**
	 * setter for heigthS
	 * @param setHeight double
	 */
	public void setHeightS(double setHeight)
	{
	    heightS=(int) setHeight;
	}
	
	/**
	 * setter for widthS
	 * @param setWidth double
	 */
	public void setWidthS(double setWidth)
	{
	    widthS=(int) setWidth;
	}
	
	/**
	 * setter for radiusS
	 * @param setRadius double
	 */
	public void setRadiusS(double setRadius)
	{   radiusS=setRadius;
	}
	
	/**
	 * setter for lengthS
	 * @param setLength double
	 */
	public void setLengthS(double setLength)
	{
	    lengthS = setLength;
	}
	
	/**
	 * setter for shapeCountS
	 * @param setNumber int
	 */
	public void setShapeNumber(int setNumber)
	{
	    shapeCountS = setNumber;
	}
	
	
	//--------------------------------COMPOSED SHAPES CLASS PRIVATE FUNCTIONS---------------------------------------------
	
	/**
	 * optimalFit function
	 */
	public void optimalFit ()
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
	
	/**
	 * modifyR function
	 * @param counter int
	 * @param coorX double
	 * @param coorY double
	 */
	private void modifyR(int counter, double coorX, double coorY)
	{
	    Rectangle objRec = new Rectangle((double)heightS, (double)widthS);
	    objRec.setCoorX(coorX);
	    objRec.setCoorY(coorY);
	    smallShp.add( objRec);  
	}
	
	/**
	 * modifyC function
	 * @param counter int
	 * @param coorX double
	 * @param coorY double
	 */
	private void modifyC(int counter, double coorX, double coorY)
	{	
		Circle objCir = new Circle(radiusS);
	    objCir.setCoorX(coorX - radiusS);
	    objCir.setCoorY(coorY - radiusS);
	    smallShp.add( objCir);
	    
	}
	
	/**
	 * modifyT function
	 * @param counter int
	 * @param coorX double
	 * @param coorY double
	 */
	private void modifyT(int counter, double coorX1, double coorY1,double coorX2, double coorY2,double coorX3, double coorY3)
	{
		Triangle objTri = new Triangle(lengthS);
	    Vector<Double> temp2 = new Vector<Double>();
	    temp2.add(0,coorX1);
	    temp2.add(1,coorY1);
	    temp2.add(2,coorX2);
	    temp2.add(3,coorY2);
	    temp2.add(4,coorX3);
	    temp2.add(5,coorY3);
	    objTri.setCoordinate(temp2);
	    smallShp.add(objTri);
	    
	   
	}
	
	/**
	 * RinR function
	 */
	private void RinR()
	{
	
	    double coorX=0;
	    double coorY=0;
	    int counter=0;
	    double cwidth = getWidthC();
	    double cheight = getHeightC();
	    double swidth = getWidthS();
	    double sheight = getHeightS();
	
	    for(int i=0 ; i<(int)(cwidth/swidth) ; ++i)
	    {
	        coorX = swidth*i;
	
	        for(int j=0 ; j<(int)(cheight/sheight) ; ++j)
	        {
	            coorY = sheight*j;
	            modifyR(counter,coorX,coorY);
	            counter++;
	
	        }
	    }
	
	    double remainHeight = cheight-(cheight/sheight)*sheight;
	
	    if(remainHeight>0) {
	
	        for(int i=0 ; i<(int)(cwidth/sheight) ; ++i)
	        {
	            coorX = sheight*i;
	
	            for(int j=0 ; j<(int)(remainHeight/swidth) ; ++j)
	            {
	                coorY = (cheight - remainHeight) + (swidth * j);
	
	                modifyR(counter,coorX,coorY);
	                counter++;
	
	            }
	        }
	    }
	
	    double remainWidth = cwidth - (cwidth/swidth)*swidth;
	
	    if(remainWidth>0){
	
	        for(int i=0 ; i<(int)(remainWidth/sheight) ; ++i)
	        {
	            coorX = (cwidth - remainWidth) + (sheight*i);
	
	            for(int j=0 ; j<(int)(cheight/swidth) ; ++j)
	            {
	                coorY = swidth*j;
	
	                modifyR(counter,coorX,coorY);
	                counter++;
	            }
	        }
	    }
	
	    setShapeNumber(counter);
	
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = cheight*cwidth - (counter*sheight*swidth);
	
	    if(counter == 0)
	        remainArea = cheight*cwidth;
	

	
	}
	
	/**
	 * CinR function
	 */
	private void CinR()
	{
	
	    int counter=0;
	    double coorX=0;
	    double coorY=0;
	    double cheight = getHeightC();
	    double cwidth = getWidthC();
	    double sradius = getRadiusS();
	    
	    for(int i=0; i< (int)(cheight/(sradius*1.732)); ++i)
	    {
	
	        for(int j=0; j<(int)(cwidth/(sradius*2)); ++j)
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
	
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = cheight*cwidth - (counter*sradius*sradius*3.142);
	
	    if(counter == 0)
	        remainArea = cheight*cwidth;
	

	}
	
	/**
	 * CinC function
	 */
	private void CinC()
	{
	    
	    int counter=0;
	    double s_coorX=0;
	    double s_coorY=0;
	    double cradius = getRadiusC();
	    double sradius = getRadiusS();
	    double c_coorX = getRadiusC();
	    double c_coorY = getRadiusC();
	    
	    for(int i=0 ; i<(int)((2*cradius)/(sradius*1.732)) ; ++i)
	    {
	
	        for(int j=0 ; j<(int)((2*cradius)/(2*sradius)) ; ++j)
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
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = 3.142*cradius*cradius - (counter*sradius*sradius*3.142);
	
	    if(counter == 0)
	        remainArea = 3.142*cradius*cradius;
	

	}
	
	/**
	 * RinC function
	 */
	private void RinC()
	{
	
	    
	    int counter =0;
	    double s_coorX=0;
	    double s_coorY=0;
	    double cradius = getRadiusC();
	    double swidth = getWidthS();
	    double sheight = getHeightS();
	    double c_coorX = getRadiusC();
	    double c_coorY = getRadiusC();
	    
	
	    for(int i=0 ; i<(int)((2*cradius)/swidth); ++i)
	    {
	        s_coorX = swidth * i;
	
	        for (int j = 0; j < (int)(2 * cradius) / sheight; ++j)
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
	
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = cradius*cradius*3.142 - (counter*sheight*swidth);
	
	    if(counter == 0)
	        remainArea = cradius*cradius*3.142;
	

	}
	
	/**
	 * RinT function
	 */
	private void RinT()
	{
	    
	    int counter=0;
	    double coorX=0;
	    double coorY=0;
	    double clength = getLengthC();
	    double sheight = getHeightS();
	    double swidth = getWidthS();
	
	    double c_y1= 0.0;
	   
	
	
	    for(int i=0 ; i<(int)(((clength*0.866)/sheight)) ; ++i)
	    {
	        coorY = sheight *i;
	
	        for (int j = 0; j < (int)(clength / swidth) ; ++j) {//calculates new value f x axis
	
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
	
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = clength*(clength*0.866)*0.5 - (counter*sheight*swidth);
	
	    if(counter == 0)
	        remainArea = clength*clength*0.866*0.5;
	

	}
	
	/**
	 * CinT function
	 */
	private void CinT()
	{
	    int counter=0;
	    double s_coorX = 0;
	    double s_coorY = 0;
	    double clength = getLengthC();
	    double sradius = getRadiusS();
	    double c_y1= 0.0;
	    
	    
	
	    for(int i=(int)((clength*0.866) /(sradius * 1.732)) ; i>0 ; --i)
	    {
	
	        for (int j = (int)((clength - (2 * (sradius * 1.732 - sradius))) / (2 * sradius)); j>0; --j)
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
	
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = clength*(clength*0.866)*0.5 - (counter*sradius*sradius*3.142);
	
	    if(counter == 0)
	        remainArea = clength*(clength*0.866)*0.5;
	

	}
	
	/**
	 * TinR function
	 */
	private void TinR()
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
	    
	
	    for(int i=0 ; i<(int)(cheight/(slength*1.732))  ; ++i)
	    {
	
	        for(int j=0 ; j<(int)(cwidth/slength) ; ++j)
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
	                modifyT(counter, s_x3, s_y3, s_x2, s_y2, s_x3 + lengthS, s_y3);
	                counter ++;

	
	
	                if(j!=(int)((cwidth-slength)/slength) - 1)
	                {
	                    modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
	                    counter ++;
		                modifyT(counter, s_x3, s_y3, s_x2, s_y2, s_x3 + lengthS, s_y3);
		                counter ++;
	
	
	                }
	            }
	
	        }
	    }
	
	    for(int i=0 ; i<(int)(cheight/(slength*1.732)) ; ++i)
	    {
	
	        for(int j=0 ; j<(int)(cwidth/slength) ; ++j)
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
	                modifyT(counter, s_x1, s_y1, s_x3, s_y3, s_x1 + lengthS, s_y1);
	                counter ++;

	
	                if(j != (int)((cwidth-slength)/slength) - 1)
	                {
	                    modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
	                    counter ++;
		                modifyT(counter, s_x1, s_y1, s_x3, s_y3, s_x1 + lengthS, s_y1);
		                counter ++;

	
	                }
	            }
	        }
	    }
	
	    setShapeNumber(counter);
	
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = cheight*cwidth - (counter*slength*slength*0.866*0.5);
	
	    if(counter == 0)
	        remainArea = cheight*cwidth;
	

	}
	
	/**
	 * TinC function
	 */
	private void TinC()
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
	    
	
	    for(int i=0 ; i<(int)((2*cradius)/(slength*1.732)) ; ++i)
	    {
	
	        for(int j=0 ; j<(int)((2*cradius)/slength); ++j)
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
	                modifyT(counter, s_x3, s_y3, s_x2, s_y2, s_x3 + lengthS, s_y3);
	                counter ++;
	
	
	            }
	
	            if( (((c_coorX - s_x1 - slength*1.5) * (c_coorX - s_x1 - slength*1.5)) +
	                ((c_coorY - s_y1 - slength*0.866) * (c_coorY - s_y1 - slength*0.866)) < ((cradius-slength)*(cradius-slength))) &&
	                (((c_coorX - s_x2) * (c_coorX - s_x2)) + ((c_coorY - s_y2) * (c_coorY - s_y2)) < ((cradius-slength)*(cradius-slength))) &&
	                (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) < ((cradius-slength)*(cradius-slength)))) {
	                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
	                counter ++;
	                modifyT(counter, s_x3, s_y3, s_x2, s_y2, s_x3 + lengthS, s_y3);
	                counter ++;
	
	
	            }
	        }
	    }
	
	    for(int i=0 ; i<(int)((2*cradius)/(slength*1.732)) ; ++i)
	    {
	
	        for(int j=0 ; j<(int)((2*cradius)/slength)   ; ++j)
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
	                modifyT(counter, s_x1, s_y1, s_x3, s_y3, s_x1 + lengthS, s_y1);
	                counter ++;


	
	
	            }
	            if ( (((c_coorX - s_x1) * (c_coorX - s_x1)) + ((c_coorY - s_y1) * (c_coorY - s_y1)) <= ((cradius-slength)*(cradius-slength))) &&
	                 (((c_coorX - s_x2 + 1.5*slength) * (c_coorX - s_x2 + 1.5*slength)) +
	                 ((c_coorY - s_y2 + slength*0.866) * (c_coorY - s_y2 + slength*0.866)) <= ((cradius-slength)*(cradius-slength))) &&
	                 (((c_coorX - s_x3) * (c_coorX - s_x3)) + ((c_coorY - s_y3) * (c_coorY - s_y3)) <= ((cradius-slength)*(cradius-slength))))
	            {
	                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
	                counter ++;
	                modifyT(counter, s_x1, s_y1, s_x3, s_y3, s_x1 + lengthS, s_y1);
	                counter ++;

	
	
	            }
	        }
	    }
	
	    setShapeNumber(counter);
	
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = cradius*cradius*3.142 - (counter*slength*slength*0.866*0.5);
	
	    if(counter == 0)
	        remainArea = cradius*cradius*3.142;
	

	}
	
	/**
	 * TinT function
	 */
	private void TinT()
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
	   
	    int y = (int)((clength*0.866)/(slength*1.732));
	    int x = (int)((clength)/slength);
	
	    for(int i=0 ; i<y ; ++i)
	    {
	        for(int j=0 ; j<x; ++j)
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
	               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867)))
	            {
	
	                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
	                counter ++;
	                modifyT(counter, s_x3, s_y3, s_x2, s_y2, s_x3 + lengthS, s_y3);
	                counter ++;

	                
	
	            }
	            if((s_y3+clength*0.867)/1.732 >= s_x3&&
	               (s_y2+clength*0.867)/1.732 >= s_x2&&
	               (s_y1+clength*0.867)/1.732 >= s_x1 &&
	               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867)))
	            {
	
	                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
	                counter ++;
	                modifyT(counter, s_x3, s_y3, s_x2, s_y2, s_x3 + lengthS, s_y3);
	                counter ++;

	                
	            }
	
	        }
	    }
	
	    for(int i=0 ; i<y ; ++i)
	    {
	
	        for(int j=0 ; j<x  ; ++j)
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
	               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867)))
	            {
	                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
	                counter ++;
	                modifyT(counter, s_x1, s_y1, s_x3, s_y3, s_x1 + lengthS, s_y1);
	                counter ++;


	                
	
	            }
	            if((s_y3+clength*0.867)/1.732 >= s_x3&&
	               (s_y2+clength*0.867)/1.732 >= s_x2&&
	               (s_y1+clength*0.867)/1.732 >= s_x1 &&
	               (s_y3 <= (clength*0.867) && s_y2 <= (clength*0.867)))
	            {
	                modifyT(counter, s_x1, s_y1, s_x2, s_y2, s_x3, s_y3);
	                counter ++;
	                modifyT(counter, s_x1, s_y1, s_x3, s_y3, s_x1 + lengthS, s_y1);
	                counter ++;


	                
	            }
	
	        }
	    }
	
	    setShapeNumber(counter);
	    @SuppressWarnings("unused")
		double remainArea=0;
	
	    remainArea = clength*clength*0.866*0.5 - (counter*slength*slength*0.866*0.5);
	
	    if(counter == 0)
	        remainArea = clength*clength*0.866*0.5;
	
	}

	//----------------------------------------------------------------------------------------------------

	@Override
	/**
	 * area function
	 * @return double
	 */

	public double area() {
		return 0;
	}

	@Override
	/**
	 * perimeter function
	 * @return double
	 */
	public double perimeter() {
		return 0;
	}

	@Override
	/**
	 * draw function
	 * @param obj Graphics refrence
	 */
	public void draw(Graphics obj) 
	{  
		char containShape = getShapeC();

	    

	    if (containShape == 'R')
	    {
	    	R.draw(obj);
	    }	
	    	
	    else if	(containShape == 'T')	    	
	    {
	    	T.draw(obj);
	    }	
	    
	    else if	(containShape == 'C')	    	
	    {
	    	C.draw(obj);
	    }	
	    
	    for(int i=0; i<smallShp.size();++i)
	    {	
	    	obj.setColor(Color.RED);
	    	smallShp.get(i).draw(obj);
	    }
	
		
	}

	@Override
	/**
	 * increment function
	 * @param obj Graphics refrence
	 */
	public void increment(Shape obj) {}

	@Override
	/**
	 * decrement function
	 * @param obj Graphics refrence
	 */
	public void decrement(Shape obj) {}
	
	
	
}
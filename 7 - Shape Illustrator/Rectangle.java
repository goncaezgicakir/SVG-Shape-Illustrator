import java.awt.Color;
import java.awt.Graphics;
/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public class Rectangle implements Shape
{
	 //height of rectangle
	 private int height;
	 //width of rectangle
	 private int width; 
     //coorX for one node of rectangle
	 private double coorX;
     //coorY for one node of rectangle
	 private double coorY;   

	 /**
	  * constructor
	  */
	 public Rectangle() 
	{ 	
		height = (int) 0.0;
		width = (int) 0.0;
		coorX = 0.0;
		coorY = 0.0;
	}
	
	 /**
	  * constructor
	  * @param coorValue1 int
	  * @param coorValue2 int
	  */
	 public Rectangle(int coorValue1, int coorValue2)
	{
	    coorX = coorValue1;
	    coorY = coorValue2;
	}
	
	/**
	 * constructor
	 * @param heightValue double
	 * @param widthValue double
	 */
	public Rectangle(double heightValue, double widthValue)
	{
	    height = (int) heightValue;
	    width = (int) widthValue;
	}
	
	
	
	
	//----------------------------------GETTERS-------------------------------------------------------
	/**
	 * getter for height
	 * @return double
	 */
	public double getHeight()
	{ 
	    return height;
	}
	
	/**
	 * getter for width
	 * @return double
	 */
	public double getWidth()
	{ 
	    return width;
	}
	
	/**
	 * getter for coorX
	 * @return double
	 */
	public double getCoorX()
	{   
	    return coorX;
	}
	
	/**
	 * getter for coorY
	 * @return double
	 */
	public double getCoorY()
	{   
	    return coorY;
	}
	
	//-----------------------------------SETTERS----------------------------------------------------------
	
	/**
	 * setter for height
	 * @param setHeight double
	 */
	public void setHeight(double setHeight) {
	    height=(int) setHeight;
	}
	
	/**
	 * setter for width
	 * @param setWidth double
	 */
	public void setWidth(double setWidth) {
	    width=(int) setWidth;
	}
	
	/**
	 * setterfor coorX
	 * @param setCoorX double
	 */
	public void setCoorX(double setCoorX)
	{   coorX = setCoorX;
	}
	
	/**
	 * setter for coorY
	 * @param setCoorY double
	 */
	public void setCoorY(double setCoorY)
	{   coorY = setCoorY;
	}
	
	//---------------------------------------------------------------------------------------------------

	@Override
	/**
	 * area function
	 * @return double
	 */

	public double area()
	{
		 double objArea = (double)height * (double)width;
		 return objArea;
	}
	
	@Override
	/**
	 * perimeter function
	 * @return double
	 */
	public double perimeter() 
	{
		 double objPer = 2 * ((double)height + (double)width);
		 return objPer;
	}

	@Override
	public void draw(Graphics obj) {
		obj.fillRect((int)coorX, (int)coorY, (int)width, (int)height);
		obj.setColor(Color.BLACK);
		obj.drawRect((int)coorX, (int)coorY, (int)width, (int)height);
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
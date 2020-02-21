import java.awt.Color;
import java.awt.Graphics;
/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public class Circle implements Shape
{
	@SuppressWarnings("unused")
	private static final String Graphic2D = null;
	//radius of circle
	private double radius;
	//coorX of circle's center
	private double coorX; 
	//coorY of circle's center  
	private double coorY; 
	private boolean flag;
	
	/**
	 * constructor
	 */
	public Circle()
	{
		radius = 0.0;
		coorX = 0.0;
		coorY = 0.0;
		flag = false;
	}

	/**
	 * constructor
	 * @param coorValue1 int
	 * @param coorValue2 int
	 */
	public Circle(int coorValue1, int coorValue2)
	{
	    coorX = coorValue1;
	    coorY = coorValue2;
	    flag = false;
	}

	/**
	 * constructor
	 * @param radiusValue double
	 */
	public Circle(double radiusValue)
	{
	    radius = radiusValue;
	    flag = false;
	}
	

	
	//-------------------------------GETTERS---------------------------------------------------------------
	
	
	/**
	 * getter for radius
	 * @return double
	 */
	public double getRadius()
	{   return radius;
	}
	
	/**
	 * getter for coorX
	 * @return double
	 */
	public double getCoorX()
	{   return coorX;
	}
	
	/**
	 * getter for coorY
	 * @return double
	 */
	public double getCoorY()
	{   return coorY;
	}

	//-------------------------------SETTERS---------------------------------------------------------------
	/**
	 * setter for radius
	 * @param setRadius double
	 */
	public void setRadius(double setRadius)
	{   radius = setRadius;
	}
	
	/**
	 * setter for coorX
	 * @param setCoorX double
	 */
	public void setCoorX(double setCoorX)
	{   coorX = setCoorX;
	}
	
	/**
	 * setter coorY
	 * @param setCoorY double
	 */
	public void setCoorY(double setCoorY)
	{   coorY = setCoorY;
	}
	
	/**
	 * setter for flag
	 * @param val boolean
	 */
	public void setFlag(boolean val)
	{
		flag = val;
	}
	

	//---------------------------------------------------------------------------------------------------
	@Override
	/**
	 * area function
	 * @return double
	 */

	public double area() 
	{
		 double objArea = 3.14 * radius * radius;
		 return objArea;	
	}

	@Override
	/**
	 * perimeter function
	 * @return double
	 */
	public double perimeter() 
	{
	    double objPer = 2 * 3.14 * radius;
	    return objPer;	
	}

	@Override
	/**
	 * draw function
	 * @param obj Graphics refrence
	 */

	public void draw(Graphics obj){
		if(flag)
		{
			obj.fillOval((int)(coorX-radius), (int)(coorY-radius), (int)(radius*2), (int)(radius*2));
			obj.setColor(Color.BLACK);
			obj.fillOval((int)(coorX-radius), (int)(coorY-radius), (int)(radius*2), (int)(radius*2));
		}
		else
		{
			obj.fillOval((int)(coorX), (int)(coorY), (int)(radius*2), (int)(radius*2));
			obj.setColor(Color.BLACK);
			obj.drawOval((int)(coorX), (int)(coorY), (int)(radius*2), (int)(radius*2));
		}
		
	}

	@Override
	/**
	 * increment function
	 * @param obj Graphics refrence
	 */
	public void increment(Shape obj){}

	@Override
	/**
	 * decrement function
	 * @param obj Graphics refrence
	 */
	public void decrement(Shape obj){}
	
	
	
}

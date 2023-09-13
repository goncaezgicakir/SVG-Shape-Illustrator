import java.awt.Graphics;
/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public abstract class Polygon implements Shape
{	
	/**
	 * 
	 * @author GONCA EZGI CAKIR
	 *
	 */
	public static class Point2D
	{	
		 private double coorX;
	     private double coorY;

		//---------------------------INNER CLASS POINT2D CONSTRUCTORS-----------------------------------------------
		
	     /**
	      * constructor
	      */
	    public Point2D()
		{
			coorX = 0;
			coorY = 0;
		}
		
		/**
		 * constructor
		 * @param x double
		 * @param y double
		 */
		public Point2D(double x, double y)
		{
		    coorX = x;
		    coorY = y;
		}
		
		
		
		//--------------------------GETTERS AND SETTERS------------------------------------------
		
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
		
		/**
		 * setter for coorX
		 * @param x double
		 */
		public void setCoorX(double x)
		{
		    coorX = x;
		}
		
		/**
		 * setter for coorY
		 * @param y double
		 */
		public void setCoorY(double y)
		{
		    coorY = y;
		}
		
	}
	
	//----------------------------------------------------------------------------------------
	
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

	public void draw(Graphics obj) {}

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

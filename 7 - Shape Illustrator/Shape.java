import java.awt.Graphics;

/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public interface Shape extends Comparable <Shape>
{
	/**
	 * area function
	 * @return double
	 */
	public double area();
	
	/**
	 * perimeter function
	 * @return double
	 */
	public double perimeter();
	
	/**
	 * draw function
	 * @param obj Graphics refrence
	 */
	public void draw(Graphics obj);
	
	/**
	 * increment function
	 * @param obj Graphics refrence
	 */
	public void increment(Shape obj);
	
	/**
	 * decrement function
	 * @param obj Graphics refrence
	 */
	public void decrement(Shape obj);
   
	@Override
	/**
	 * compareTo function
	 */
	public default int compareTo(Shape obj)
	{	
		if(obj.area() >= area())
			return 1;
		
		else
			return 0;
		
	}
   
}
    
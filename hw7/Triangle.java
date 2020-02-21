import java.util.Vector;
import java.awt.Color;
import java.awt.Graphics;
/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public class Triangle implements Shape
{	
	
	//length of triangles one side
	private  double length;       

	//vector to hold coordinates of 3 nodes           
	private  Vector <Double> coordinate;   

	//no parameter constructor
	public Triangle() 
	{ 
		coordinate = new Vector<Double>();
		length = 0.0;
	}
	
	/**
	 * constructor
	 * @param coorValue double vector
	 */
	public Triangle(Vector <Double> coorValue)
	{
		coordinate = new Vector<Double>();
		
		for(int i=0; i<coorValue.size();++i)
		{
			coordinate.add(coorValue.get(i));
		}
	}

	/**
	 * constructor
	 * @param lengthValue double
	 */
	public Triangle(double lengthValue)
	{
		coordinate = new Vector<Double>();
	    length = lengthValue;
	}



	//---------------------------------GETTERS------------------------------------------------------------
	/**
	 * getter for length
	 * @return double
	 */
	public double getLength()
	{ 
	    return length;
	}
	
	/**
	 * getter for coordinate
	 * @return double vector
	 */
	public Vector <Double> getCoordinate()
	{ 
	    return coordinate;
	}

	//---------------------------------SETTERS--------------------------------------------------------------
	/**
	 * setter for length
	 * @param setLength double
	 */
	public void setLength(double setLength) 
	{
	    length = setLength;
	}
	
	/**
	 * setter for coordinate
	 * @param setCoordinate double vector
	 */
	public void setCoordinate(Vector < Double > setCoordinate)
	{
		
		coordinate.clear();
		for(int i=0; i<setCoordinate.size();++i)
		{
			coordinate.add(setCoordinate.get(i));
		}
	}

	//--------------------------------------------------------------------------------------------------------
	
	@Override
	/**
	 * area function
	 * @return double
	 */

	public double area()
	{
		double objArea = (length*length) * 0.433;
	    return objArea;
	}

	@Override
	/**
	 * perimeter function
	 * @return double
	 */
	public double perimeter() 
	{
		double objPer = 3 * length;
	    return objPer;
	}

	@Override
	/**
	 * draw function
	 * @param obj Graphics refrence
	 */

	public void draw(Graphics obj) {
		java.awt.Polygon poly = new java.awt.Polygon();
		poly.addPoint(coordinate.get(0).intValue(), coordinate.get(1).intValue());
		poly.addPoint(coordinate.get(2).intValue(), coordinate.get(3).intValue());
		poly.addPoint(coordinate.get(4).intValue(), coordinate.get(5).intValue());
		
		obj.fillPolygon(poly);
		obj.setColor(Color.BLACK);
		obj.drawPolygon(poly);
		

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

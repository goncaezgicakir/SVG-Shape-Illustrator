import java.util.ArrayList;

/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public class PolygonVect extends Polygon
{	

	private static final double M_PI = 3.14;
	@SuppressWarnings("unused")
	private int numOfPoints;
	private ArrayList<Point2D> vect;
	
	/**
	 * constructor
	 */
	public PolygonVect()
	{
		vect = new ArrayList<Point2D>();
	    numOfPoints = 0;
	}
	
	/**
	 * constructor
	 * @param shapeVector Point2D arraylist
	 */
	public PolygonVect(ArrayList<Point2D> shapeVector)
	{
		vect = new ArrayList<Point2D>(shapeVector);
	}
	
	/**
	 * constructor to convert Rectangle to Polygon
	 * @param objRec Rectangle reference
	 */
	public PolygonVect(Rectangle objRec)
	{   
		vect = new ArrayList<Point2D>();
	    numOfPoints = 4;
	    
	    vect.add(new Point2D(objRec.getCoorX() + 0 , objRec.getCoorY() + 0));
	    vect.add(new Point2D(objRec.getCoorX() + objRec.getWidth() , objRec.getCoorY() + 0));
	    vect.add(new Point2D(objRec.getCoorX() + objRec.getWidth() , objRec.getCoorY() + objRec.getHeight()));
	    vect.add(new Point2D(objRec.getCoorX() + 0 , objRec.getCoorY() + objRec.getHeight()));

	}
	
	/**
	* constructor to convert Circle to Polygon
	* @param objCir Circle reference
	*/
	public PolygonVect(Circle objCir)
	{
	    numOfPoints = 100;
	    
	    for(int i=0 ; i<100 ; ++i)
	    {
	        vect.add(new Point2D(objCir.getCoorX() + objCir.getRadius() + objCir.getRadius()*Math.sin((M_PI/50.0)*i),
	                        objCir.getCoorY() + objCir.getRadius() - objCir.getRadius()*Math.cos((M_PI/50.0)*i)));
	    };
	}
	
	/**
	 * constructor to convert Triangle to Polygon
	 * @param objTri Triangle reference
	 */
	public PolygonVect(Triangle objTri)
	{
	    numOfPoints=3;
	  
	    vect.add(new Point2D(objTri.getCoordinate().get(0),objTri.getCoordinate().get(1)));
	    vect.add(new Point2D(objTri.getCoordinate().get(2),objTri.getCoordinate().get(3)));
	    vect.add(new Point2D(objTri.getCoordinate().get(4),objTri.getCoordinate().get(5)));
	   
	}
	
	//----------------------------------GETTERS AND SETTERS--------------------------------------------
	/**
	 * getter for numOfPoints
	 * @return int value 
	 */
	public int getNumOfPoints()
	{
	    return numOfPoints;
	}
	
	/**
	 * setter for numOfPoints
	 * @param num integer
	 */
	public void setNumOfPoints(int num)
	{
	    numOfPoints = num;
	}
	
	
	//---------------------------------------------------------------------------------------------------
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
	
}



/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public class PolygonDyn extends Polygon
{	
	private static final double M_PI = 3.14;
	private int numOfPoints;
	private Point2D[] ptr;
	    
	    
	/**
	 * no parameter constructor
	 */
	public PolygonDyn()
	{
	    ptr = new Point2D[1]; 
	    numOfPoints = 0;
	}
	
	/**
	 * constructor
	 * @param point Point2D reference
	 */
	public PolygonDyn(Point2D point)
	{
		ptr = new Point2D[1];
		ptr[0].setCoorX(point.getCoorX());
		ptr[0].setCoorY(point.getCoorY());
	}
	
	/**
	 * constructor converts Rectangle to Polygon
	 * @param objRec Rectangle refrence
	 */
	public PolygonDyn(Rectangle objRec)
	{   
	    numOfPoints = 4;
	    ptr = new Point2D[numOfPoints];
	
	
	    ptr[0] = new Point2D(objRec.getCoorX() + 0 , objRec.getCoorY() + 0);
	    ptr[1] = new Point2D(objRec.getCoorX() + objRec.getWidth() , objRec.getCoorY() + 0);
	    ptr[2] = new Point2D(objRec.getCoorX() + objRec.getWidth() , objRec.getCoorY() + objRec.getHeight());
	    ptr[3] = new Point2D(objRec.getCoorX() + 0 , objRec.getCoorY() + objRec.getHeight());
	
	}
	
	/**
     * constructor converts Circle to Polygon
	 * @param objCir Circle refrence
	 */
	public PolygonDyn(Circle objCir)
	{
	    numOfPoints = 100;
	    ptr = new Point2D[numOfPoints];
	    
	    for(int i=0 ; i<100 ; ++i)
	    {
	        ptr[i] = new Point2D(objCir.getCoorX() + objCir.getRadius() + objCir.getRadius()*Math.sin((M_PI/50.0)*i),
	                        objCir.getCoorY() + objCir.getRadius() - objCir.getRadius()*Math.cos((M_PI/50.0)*i));
	    };
	}
	
	/**
	 * constructor converts Triangle to Polygon
	 * @param objTri Triangle refrence
	 */
	public PolygonDyn(Triangle objTri)
	{
	    numOfPoints = 3;
	    ptr = new Point2D[numOfPoints];
	  
	    ptr[0] = new Point2D(objTri.getCoordinate().get(0),objTri.getCoordinate().get(1));
	    ptr[1] = new Point2D(objTri.getCoordinate().get(2),objTri.getCoordinate().get(3));
	    ptr[2] = new Point2D(objTri.getCoordinate().get(4),objTri.getCoordinate().get(5));
	   
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
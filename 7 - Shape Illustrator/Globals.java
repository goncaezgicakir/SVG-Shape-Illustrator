import javax.swing.JFrame;
/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public class Globals {

	/**
	 * drawall function
	 * @param drawShape shape array
	 */
	public static void drawAll(Shape[] drawShape)
	{
		JFrame draw = new JFrame("Draws");
		draw.setBounds(100, 100, 400, 300);
		draw.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		ExtendedJPanel pane = new ExtendedJPanel(drawShape);
		draw.add(pane);
		draw.setVisible(true);
	}
	/**
	 * convertAll function
	 * @param convertShape - Shape array
	 * @return Polygon array
	 */
	public static Polygon[] convertAll(Shape [] convertShape)
	{   
		Polygon[] converted = new Polygon [convertShape.length];
		
		for(int i=0 ; i< convertShape.length ; ++i)
		{	
			Circle tempCir;
			Rectangle tempRec;
			Triangle tempTri;

			
			if(convertShape[i] instanceof Rectangle)
			{	
				tempRec = new Rectangle();
			    tempRec = (Rectangle) convertShape[i];
			    converted[i] = new  PolygonVect(tempRec);
			}
		
			else if(convertShape[i] instanceof Circle)
			{
				tempCir = new Circle();
			    tempCir = (Circle) convertShape[i];
				converted[i] = new PolygonVect(tempCir);
			}
		
			else if(convertShape[i] instanceof Triangle)
			{
				tempTri = new Triangle();
			    tempTri = (Triangle) convertShape[i];
			    converted[i] = new PolygonVect(tempTri);
			}
		}	
			
		return converted;
	}
	
	
	/**
	 * sortShapes function
	 * @param sortShape Shape array
	 * @return Shape array
	 */
	public static Shape[] sortShapes(Shape [] sortShape)
	{	
		 int range1 = sortShape.length;
	        int k;
	        for (int m = range1; m >= 0; m--) {
	            for (int i = 0; i < range1 - 1; i++) {
	                k = i + 1;
	                if (sortShape[i].area() > sortShape[k].area()) {
	                    swapValues(i, k, sortShape);
	                }
	            }

	        }
	        
	        return sortShape;
	}
	
	/**
	 * swapValues function
	 * @param i for loop index
	 * @param j for loop index
	 * @param arr Shape array
	 */
	public static void swapValues(int i, int j, Shape[] arr) {
		  
        Shape temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
  

}

/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
public class Main {
	/**
	 * main function
	 * @param args String array
	 */
	public static void main(String[] args) {
		
		UserInterface newInterface = new UserInterface(); //---------> FOR USER INTERFACE
		newInterface.setVisible(true);
		
		
		
		Shape[] temp = new Shape[3];
		Rectangle tmpRec1 = new Rectangle(50,50);
		Rectangle tmpRec2 = new Rectangle(220,100);
		Circle tmpCirc = new Circle(100,150);

		tmpRec1.setWidth(100);
		tmpRec1.setHeight(50);
		tmpRec2.setWidth(70);
		tmpRec2.setHeight(100);
		tmpCirc.setRadius(30);
		temp[0] = tmpRec1;
		temp[1] = tmpRec2;
		temp[2] = tmpCirc;
		
		//Globals.drawAll(temp); //---------------> CLEAR COMMENT FOR GLOBAL "drawAll" FUNCTION

	}

}

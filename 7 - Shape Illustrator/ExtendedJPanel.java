import java.awt.Graphics;

import javax.swing.JPanel;

@SuppressWarnings("serial")
public class ExtendedJPanel extends JPanel {
	
	/**
	 * ExtendedJPanel function
	 */
	public ExtendedJPanel()
	{
		super();
		data = new ComposedShape();
		choice = 1;
	}
	
	/**
	 * ExtendedJPanel function
	 * @param draw Shape array
	 */
	public ExtendedJPanel(Shape[] draw)
	{
		super();
		data2 = draw;
		choice = 2;
	}

	@Override
	/**
	 * paintComponent function
	 * @param g Graphics reference
	 */
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		if(choice == 1)
			data.draw(g);
		else
		{
			for(int i=0; i<data2.length;++i)
			{
				data2[i].draw(g);
			}
		}
	}
	
	/**
	 * setComposedShapefunction
	 * @param obj ComposedShape reference
	 */
	public void setComposedShape(ComposedShape obj)
	{
		data = obj;
	}
	private ComposedShape data;
	private Shape[] data2;
	private int choice;
}

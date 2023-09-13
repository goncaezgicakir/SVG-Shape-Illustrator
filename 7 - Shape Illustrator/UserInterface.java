import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.GridLayout;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 * 
 * @author GONCA EZGI CAKIR
 *
 */
@SuppressWarnings("serial")
public class UserInterface extends JFrame implements ActionListener{

	private JTextField textField_4;
	private JTextField textField_5;
	private JTextField textField_6;
	private JTextField textField_7;

	/**
	 * UserInterface function
	 */
	public UserInterface() {
		new JFrame();
		setBounds(100, 100, 600, 600);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new BorderLayout(0, 0));
		
		ExtendedJPanel panel_9 = new ExtendedJPanel();
		add(panel_9, BorderLayout.CENTER);
		
		JPanel panel = new JPanel();
		add(panel, BorderLayout.NORTH);
		panel.setLayout(new GridLayout(0, 2, 0, 0));
		
		
		
		JPanel panel_1 = new JPanel();
		panel.add(panel_1);
		panel_1.setLayout(new GridLayout(0, 1, 0, 0));
		
		JPanel panel_3 = new JPanel();
		panel_1.add(panel_3);
		panel_3.setLayout(new BorderLayout(0, 0));
		
		JLabel lblNewLabel = new JLabel("                          COMPOSED SHAPE");
		panel_3.add(lblNewLabel,BorderLayout.NORTH);
		
		JComboBox<String> comboBox = new JComboBox<String>();
		comboBox.addItem("Rectangle");
		comboBox.addItem("Triangle");
		comboBox.addItem("Circle");
		comboBox.setSelectedIndex(0);
		panel_3.add(comboBox, BorderLayout.CENTER);
		
		JLabel lblNewLabel_2 = new JLabel("         LENGTH1                           LENGTH2");
		panel_3.add(lblNewLabel_2, BorderLayout.SOUTH);
		
		JPanel panel_7 = new JPanel();
		panel_1.add(panel_7);
		panel_7.setLayout(new BorderLayout(0, 0));
		
		textField_4 = new JTextField();
		panel_7.add(textField_4, BorderLayout.WEST);
		textField_4.setColumns(10);
		
		textField_5 = new JTextField();
		panel_7.add(textField_5, BorderLayout.EAST);
		textField_5.setColumns(10);
		
		
		
		
		JPanel panel_4 = new JPanel();
		panel_1.add(panel_4);
		panel_4.setLayout(new BorderLayout(0, 0));
		
		JLabel lblNewLabel_1 = new JLabel("                              INNER SHAPE");
		panel_4.add(lblNewLabel_1,BorderLayout.NORTH);
		
		JComboBox<String> comboBox_1 = new JComboBox<String>();
		comboBox_1.addItem("Rectangle");
		comboBox_1.addItem("Triangle");
		comboBox_1.addItem("Circle");
		comboBox_1.setSelectedIndex(0);
		panel_4.add(comboBox_1,BorderLayout.CENTER);
		
		JLabel lblNewLabel_3 = new JLabel("         LENGTH1                            LENGTH2");
		panel_4.add(lblNewLabel_3, BorderLayout.SOUTH);
		
		JPanel panel_8 = new JPanel();
		panel_1.add(panel_8);
		panel_8.setLayout(new BorderLayout(0, 0));
		
		textField_6 = new JTextField();
		panel_8.add(textField_6, BorderLayout.WEST);
		textField_6.setColumns(10);
		
		textField_7 = new JTextField();
		panel_8.add(textField_7, BorderLayout.EAST);
		textField_7.setColumns(10);
		
		
		
		JPanel panel_2 = new JPanel();
		panel.add(panel_2);
		panel_2.setLayout(new GridLayout(0, 1, 0, 0));
		
		JPanel panel_5 = new JPanel();
		panel_2.add(panel_5);
		panel_5.setLayout(new BorderLayout(0, 0));
		
		
		
		JButton btnNewButton = new JButton("DRAW");
		panel_5.add(btnNewButton, BorderLayout.CENTER);
		JLabel warn = new JLabel();
		warn.setText("Check Values!");
		warn.setVisible(false);
		panel_5.add(warn,BorderLayout.SOUTH);

		btnNewButton.addMouseListener(new MouseAdapter()
			{
				@Override
				/**
				 * mousePressed function for buttons
				 */
				public void mousePressed(MouseEvent event)
				{
					warn.setVisible(false);
					try {
						String containerShape = (String)comboBox.getSelectedItem();
						String innerShape = (String)comboBox_1.getSelectedItem();
						ComposedShape shape=null;
						
						if(containerShape.equals("Rectangle") && innerShape.equals("Rectangle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double contDemn2 =  Double.parseDouble(textField_5.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							double InnDemn2 = Double.parseDouble(textField_7.getText());
							
							shape = new ComposedShape('R', 'R', contDemn1, contDemn2, InnDemn1, InnDemn2);
							shape.optimalFit();
						}
						
						else if(containerShape.equals("Rectangle") && innerShape.equals("Circle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double contDemn2 =  Double.parseDouble(textField_5.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							
							shape = new ComposedShape('R', 'C', contDemn1, contDemn2, InnDemn1);
							shape.optimalFit();
						}
						
						else if(containerShape.equals("Rectangle") && innerShape.equals("Triangle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double contDemn2 =  Double.parseDouble(textField_5.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							
							shape = new ComposedShape('R', 'T', contDemn1, contDemn2, InnDemn1);
							shape.optimalFit();
						}
						
						else if(containerShape.equals("Circle") && innerShape.equals("Rectangle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							double InnDemn2 = Double.parseDouble(textField_7.getText());
							
							shape = new ComposedShape('C', 'R', contDemn1, InnDemn1, InnDemn2);
							shape.optimalFit();
						}
						
						else if(containerShape.equals("Circle") && innerShape.equals("Circle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							
							shape = new ComposedShape('C', 'C', contDemn1, InnDemn1);
							shape.optimalFit();
						}
						
						else if(containerShape.equals("Circle") && innerShape.equals("Triangle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							
							shape = new ComposedShape('C', 'T', contDemn1, InnDemn1);
							shape.optimalFit();
						}
						
						else if(containerShape.equals("Triangle") && innerShape.equals("Rectangle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							double InnDemn2 = Double.parseDouble(textField_7.getText());
							
							shape = new ComposedShape('T', 'R', contDemn1, InnDemn1, InnDemn2);
							shape.optimalFit();
						}
						
						else if(containerShape.equals("Triangle") && innerShape.equals("Circle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							
							shape = new ComposedShape('T', 'C', contDemn1, InnDemn1);
							shape.optimalFit();
						}
						
						else if(containerShape.equals("Triangle") && innerShape.equals("Triangle"))
						{
							double contDemn1 = Double.parseDouble(textField_4.getText());
							double InnDemn1 = Double.parseDouble(textField_6.getText());
							
							shape = new ComposedShape('T', 'T', contDemn1, InnDemn1);
							shape.optimalFit();
						}
						panel_9.setComposedShape(shape);
						panel_9.repaint();
					} catch (NumberFormatException e) {
						warn.setVisible(true);
					}
				}
			});
		
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {		
	}

}

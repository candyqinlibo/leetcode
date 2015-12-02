package GUI;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class SimpleAnimation {
	int x = 0;
	int y = 0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SimpleAnimation gui = new SimpleAnimation();
		gui.go();
	}
	
	public void go(){
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		MyDrawPanel drawPanel = new MyDrawPanel();
		
		frame.getContentPane().add(drawPanel);
		frame.setSize(300, 300);
		frame.setVisible(true);
		
		for (int i = 0; i < 250; i++) {
			x++;
			y++;
			
			drawPanel.repaint();
			
			try{
				Thread.sleep(50);
			}catch(Exception e){}
		}
	}
	
	@SuppressWarnings("serial")
	class MyDrawPanel extends JPanel{
		public void paintComponent(Graphics g){
			g.setColor(Color.white);
			g.fillRect(0, 0, getWidth(), getHeight());
			g.setColor(Color.green);
			g.fillOval(x, y, 10, 10);
		}
	}
}

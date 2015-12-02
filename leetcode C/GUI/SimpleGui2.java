package GUI;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class SimpleGui2 implements ActionListener {
	JButton button;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SimpleGui2 gui2 = new SimpleGui2();
		gui2.go();
	}
	
	public void go(){
		JFrame frame = new JFrame();
		button = new JButton("Click me");
		button.addActionListener(this);
		
		frame.getContentPane().add(BorderLayout.CENTER,button);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300, 300);
		frame.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}

}
